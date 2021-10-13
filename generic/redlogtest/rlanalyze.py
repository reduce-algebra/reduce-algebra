#!/usr/bin/env python3

import argparse
import datetime
import json
import os
import pandas
import pprint
import statistics
import sys

class Benchmark(dict):
    def __init__(self, dictionary: dict = {}):
        super().__init__(dictionary)

    def update_ref_data(self, regressions: str):
        for lisp in "csl", "psl":
            with open(os.path.join(regressions, self["name"]) + "." + lisp + "time", 'r') as file:
                for line in file.readlines():
                    if "Time" in line:
                        line = line.split()
                        self.update({"cpu_ref_" + lisp: int(line[3])})
                        try:
                            gc_ref = int(line[8])
                        except IndexError:
                            gc_ref = 0
                        self.update({"gc_ref_" + lisp: gc_ref})
        cpu_ref_mean = statistics.mean([self["cpu_ref_csl"], self["cpu_ref_psl"]])
        gc_ref_mean = statistics.mean([self["gc_ref_csl"], self["gc_ref_psl"]])
        self.update({"cpu_ref_mean": cpu_ref_mean, "gc_ref_mean": gc_ref_mean})
        return self

    def update_now_data(self, timings: str):
        for lisp in "csl", "psl":
            with open(os.path.join(timings, lisp + "-times", self["name"] + ".time"), 'r') as file:
                for line in file.readlines():
                    if "Time" in line:
                        line = line.split()
                        self.update({"cpu_now_" + lisp: int(line[3])})
                        try:
                            gc = int(line[8])
                        except IndexError:
                            gc = 0
                        self.update({"gc_now_" + lisp: gc})
        cpu_now_mean = statistics.mean([self["cpu_now_csl"], self["cpu_now_psl"]])
        gc_now_mean = statistics.mean([self["gc_now_csl"], self["gc_now_psl"]])
        self.update({"cpu_now_mean": cpu_now_mean, "gc_now_mean": gc_now_mean})
        return self

    def update_delta_data(self):
        cpu_delta_csl = self["cpu_now_csl"] - self["cpu_ref_csl"]
        cpu_delta_psl = self["cpu_now_psl"] - self["cpu_ref_psl"]
        cpu_delta_mean = self["cpu_now_mean"] - self["cpu_ref_mean"]
        gc_delta_csl = self["gc_now_csl"] - self["gc_ref_csl"]
        gc_delta_psl = self["gc_now_psl"] - self["gc_ref_psl"]
        gc_delta_mean = self["gc_now_mean"] - self["gc_ref_mean"]
        self.update({"cpu_delta_csl": cpu_delta_csl, "cpu_delta_psl": cpu_delta_psl, "cpu_delta_mean": cpu_delta_mean,
                     "gc_delta_csl": gc_delta_csl, "gc_delta_psl": gc_delta_psl, "gc_delta_mean": gc_delta_mean})
        return self

    def update_ratio_data(self):
        def _div(x: int, y: int) -> float:
            assert x >= 0
            try:
                return x / y
            except ZeroDivisionError:
                if x == 0:
                    return float("nan")
                else:
                    return float("inf")
        cpu_ratio_csl = _div(self["cpu_now_csl"], self["cpu_ref_csl"])
        cpu_ratio_psl = _div(self["cpu_now_psl"], self["cpu_ref_psl"])
        cpu_ratio_mean = _div(self["cpu_now_mean"], self["cpu_ref_mean"])
        gc_ratio_csl = _div(self["gc_now_csl"], self["gc_ref_csl"])
        gc_ratio_psl = _div(self["gc_now_psl"], self["gc_ref_psl"])
        gc_ratio_mean = _div(self["gc_now_mean"], self["gc_ref_mean"])
        self.update({"cpu_ratio_csl": cpu_ratio_csl, "cpu_ratio_psl": cpu_ratio_psl, "cpu_ratio_mean": cpu_ratio_mean,
                     "gc_ratio_csl": gc_ratio_csl, "gc_ratio_psl": gc_ratio_psl, "gc_ratio_mean": gc_ratio_mean})
        return self

    def select(self, columns: list):
        return Benchmark({key: self[key] for key in columns})

    def html(self) -> str:
        def _to_percent(x: float) -> str:
            try:
                return str(round(100 * x)) + "%"
            except (OverflowError, ValueError):
                return str(x)
        row = '<tr>'
        for key, value in self.items():
            if key == "name":
                alignment = "left"
            else:
                alignment = "right"
            if "_ratio_" in key:
                data = _to_percent(value)
            else:
                data = str(value)
            row += '<td align="' + alignment + '">' + data + '</td>'
        row += '</tr>'
        return row

class Benchmarks(list):
    def __init__(self, init: list = None):
        super().__init__(self)
        if init:
            self.extend(init)

    def from_file_system(self, regressions: str, timings: str):
        for path, directories, files in os.walk(regressions):
            for file in files:
                benchmark = Benchmark()
                try:
                    basename, extension = file.split('.')
                except ValueError:
                    continue
                if extension != "tst":
                    continue
                benchmark.update({"name": os.path.join(os.path.relpath(path, regressions), basename)})
                benchmark.update_ref_data(regressions)
                benchmark.update_now_data(timings)
                benchmark.update_delta_data()
                benchmark.update_ratio_data()
                self.append(benchmark)
        return self

    def summarize(self) -> Benchmark:
        summary = Benchmark({"name": "Summary"})
        for column in "cpu_ref_csl", "cpu_now_csl", "cpu_ref_psl", "cpu_now_psl", "cpu_ref_mean", "cpu_now_mean",\
                      "gc_ref_csl", "gc_now_csl", "gc_ref_psl", "gc_now_psl", "gc_ref_mean", "gc_now_mean":
            summary.update({column: sum(map(lambda benchmark: benchmark[column], self))})
        summary.update_delta_data()
        summary.update_ratio_data()
        return summary

    def select(self, columns: list):
        return Benchmarks(list(map(lambda benchmark: benchmark.select(columns), self)))

    def sort(self, *, column: str, reverse: bool = False):
        super().sort(key=lambda x: x[column], reverse=reverse)
        return self

    def txt_view(self, summary: Benchmark) -> str:
        pandas.set_option('display.max_rows', None)
        pandas.set_option('display.expand_frame_repr', False)
        print(summary)
        self.extend([summary])
        names = list(map(lambda benchmark: benchmark["name"], self))
        for benchmark in self:
            del benchmark["name"]
        return pandas.DataFrame(self, names)

    def html_view(self, summary: Benchmark, *, full: bool = False) -> str:
        def _translate(column: str) -> str:
            if "ref" in column:
                if "cpu" in column:
                    return 'CPU<sub>ref</sub>'
                elif "gc" in column:
                    return 'GC<sub>ref</sub>'
            elif "now" in column:
                if "cpu" in column:
                    return 'CPU'
                elif "gc" in column:
                    return "GC"
            elif column == "name":
                return ''
            elif "delta" in column:
                return '&Delta;<sub>abs</sub>'
            elif "ratio" in column:
                return '&Delta;<sub>rel</sub>'
            else:
                return column
        if full:
            html_doc = html_begin()
        else:
            html_doc = ''
        html_doc += '<table class="table table-bordered table-striped table-sm">' + os.linesep
        html_doc += '<caption>Created by rlanalyze.py on ' 
        html_doc += datetime.date.today().strftime("%Y-%m-%d")
        html_doc += '. All times in ms</caption>' + os.linesep
        html_doc += '<thead>' + os.linesep
        html_doc += '<tr>'
        if len(self[0]) == 13:
            html_doc += '<th style="text-align:left;">Benchmark</th>'
            for section in "CSL", "PSL", "Mean":
                html_doc += '<th style="text-align:center;" colspan="4">' + section + '</th>'
        elif len(self[0]) == 25:
            html_doc += '<th style="text-align:left;">Benchmark</th>'
            for section in "CSL", "PSL", "Mean", "CSL", "PSL", "Mean":
                html_doc += '<th style="text-align:center;" colspan="4">' + section + '</th>'
        html_doc += '</tr>' + os.linesep
        html_doc += '<tr>'
        for column in self[0].keys():
            html_doc += '<th style="text-align: right;">'
            if len(self[0]) in {13, 25}:
                html_doc += _translate(column)
            else:
                html_doc += column
            html_doc += '</th>'
        html_doc += '</tr>' + os.linesep
        html_doc += '</thead>' + os.linesep
        html_doc += '<tbody>' + os.linesep
        for benchmark in self:
            html_doc += benchmark.html()
            html_doc += os.linesep
        html_doc += '</tbody>' + os.linesep
        html_doc += '<foot>' + os.linesep
        html_doc += summary.html() + os.linesep
        html_doc += '</foot>' + os.linesep
        html_doc += '</table>' + os.linesep
        if full:
            html_doc += html_end()
        return html_doc

def html_begin() -> str:
    return """<!DOCTYPE html>
<html>
<head>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3"
      crossorigin="anonymous">
</head>
<body>
"""

def html_end() -> str:
    return """<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" 
        integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" 
        crossorigin="anonymous">
</script>
<script src="https://cdn.jsdelivr.net/npm/boottrap@5.1.3/dist/js/bootstrap.min.js" 
        integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9TZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" 
        crossorigin="anonymous">
</script>
</body>
</html>"""

def parse_args():
    parser = argparse.ArgumentParser(description="generate a digest of Redlog benchmarking")
    parser.add_argument("regressions", help="the regressions directory (typically inside packages/redlog)")
    parser.add_argument("timings", help="the timing directory (which contains csl-times, psl-times)")
    parser.add_argument("--columns", choices=["all", "gc"], help="select GC data or full (CPU + GC) data; default is CPU data")
    parser.add_argument("--format", choices=["html", "html_table", "csv", "json", "py"],
        help=("output an html table, a full html document, comma-separated values, json, "
        "or a python list of dictionaries; default is text"))
    parser.add_argument("--sort", choices=["cpu_now", "cpu_ratio"],
        help='sort by mean "CPU" time or ratio "Reference CPU" : "CPU"; default is alphabetic sorting by names')
    return parser.parse_args()

def column_list(select_arg: str) -> list:
    if select_arg == None or select_arg == "cpu":
        return ["name", "cpu_ref_csl", "cpu_now_csl", "cpu_delta_csl",\
                "cpu_ratio_csl", "cpu_ref_psl", "cpu_now_psl", "cpu_delta_psl", "cpu_ratio_psl",\
                "cpu_ref_mean", "cpu_now_mean", "cpu_delta_mean", "cpu_ratio_mean"]
    elif select_arg == "gc":
        return ["name", "gc_ref_csl", "gc_now_csl", "gc_delta_csl",\
                "gc_ratio_csl", "gc_ref_psl", "gc_now_psl", "gc_delta_psl", "gc_ratio_psl",\
                "gc_ref_mean", "gc_now_mean", "gc_delta_mean", "gc_ratio_mean"]
    elif select_arg == "all":
        return [*column_list("cpu"), *column_list("gc")]

if __name__ == "__main__":
    args = parse_args()
    data = Benchmarks().from_file_system(args.regressions, args.timings)
    summary = data.summarize()
    # Sorting before selecting allows to sort w.r.t. unselected columns
    if args.sort == "cpu":
        data.sort(column="cpu_now_mean")
    elif args.sort == "cpu_ratio":
        data.sort(column="cpu_ratio_mean")
    else:
        data.sort(column="name")
    columns = column_list(args.columns)
    data = data.select(columns)
    summary = summary.select(columns)
    format = args.format
    if format == "html":
        print(data.html_view(summary, full=True))
    elif format == "html_table":
        print(data.html_view(summary, full=False))
    elif format == "csv":
        print("not implemented")
    elif format == None or format == "txt":
        print(data.txt_view(summary))
    elif format == "json":
        print(json.dumps(data, indent=2))
    elif format == "py":
        pprint.pprint(data)
