#!/usr/bin/env python3

import argparse
import datetime
import json
import os
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

    def html(self, columns: list) -> str:
        def _to_percent(x: float) -> str:
            try:
                return str(round(100 * x)) + "%"
            except (OverflowError, ValueError):
                return str(x)
        row = '<tr>'
        for column in columns:
            if column == "name":
                alignment = "left"
            else:
                alignment = "right"
            if "_ratio_" in column:
                value = _to_percent(self[column])
            else:
                value = str(self[column])
            row += '<td align="' + alignment + '">' + value + '</td>'
        row += '</tr>'
        return row

class Benchmarks(list):
    def __init__(self, regressions: str, timings: str):    
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

    def summarize(self) -> Benchmark:
        summary = Benchmark({"name": "Summary"})
        for column in "cpu_ref_csl", "cpu_now_csl", "cpu_ref_psl", "cpu_now_psl", "cpu_ref_mean", "cpu_now_mean",\
                      "gc_ref_csl", "gc_now_csl", "gc_ref_psl", "gc_now_psl", "gc_ref_mean", "gc_now_mean":
            summary.update({column: sum(map(lambda benchmark: benchmark[column], self))})
        summary.update_delta_data()
        summary.update_ratio_data()
        return summary

    def sort(self, *, column: str, reverse: bool = False):
        super().sort(key=lambda x: x[column], reverse=reverse)
        return self

    def html_view(self, select: str, *, full: bool = False) -> str:
        if full:
            html_doc = '<html>' + os.linesep + '<head>' + os.linesep + '<link '
            html_doc += 'href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" '
            html_doc += 'rel="stylesheet" '
            html_doc += 'integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" '
            html_doc += 'crossorigin="anonymous">' + os.linesep
            html_doc += '</head>' + os.linesep + '<body>'
        html_doc += '<table class="table table-bordered table-striped">' + os.linesep
        html_doc += '<caption>All times in ms</caption>' + os.linesep
        if select in ["cpu", None]:
            html_doc += self.html_view_1(["name", "cpu_ref_csl", "cpu_now_csl", "cpu_delta_csl",\
                "cpu_ratio_csl", "cpu_ref_psl", "cpu_now_psl", "cpu_delta_psl", "cpu_ratio_psl",\
                "cpu_ref_mean", "cpu_now_mean", "cpu_delta_mean", "cpu_ratio_mean"])
        if select in ["gc", None]:
            html_doc += self.html_view_1(["name", "gc_ref_csl", "gc_now_csl", "gc_delta_csl",\
                "gc_ratio_csl", "gc_ref_psl", "gc_now_psl", "gc_delta_psl", "gc_ratio_psl",\
                "gc_ref_mean", "gc_now_mean", "gc_delta_mean", "gc_ratio_mean"])
        html_doc += '</table>' + os.linesep
        if full:
            html_doc += '<script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js" '
            html_doc += 'integrity="sha384-7+zCNj/IqJ95wo16oMtfsKbZ9ccEh31eOz1HGyDuCQ6wgnyJNSYdrPa03rtR1zdB" '
            html_doc += 'crossorigin="anonymous"></script>' + os.linesep
            html_doc += '<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.min.js" '
            html_doc += 'integrity="sha384-QJHtvGhmr9XOIpI6YVutG+2QOK9T+ZnN4kzFN1RtK3zEFEIsxhlmWl5/YESvpZ13" '
            html_doc += 'crossorigin="anonymous"></script>' + os.linesep + '</body>' + os.linesep + '</html>'
        return html_doc

    def html_view_1(self, columns: list) -> str:
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
        table = ''
        table += '<thead>' + os.linesep
        table += '<tr>'
        table += '<th style="text-align:left;">Benchmark</th>'
        for section in "CSL", "PSL", "Mean":
            table += '<th style="text-align:center;" colspan="4">' + section + '</th>'
        table += '</tr>' + os.linesep
        table += '<tr>'
        for column in columns:
            table += '<th style="text-align: right;">'
            table += _translate(column)
            table += '</th>'
        table += '</tr>' + os.linesep
        table += '</thead>' + os.linesep
        table += '<tbody>' + os.linesep
        for benchmark in self:
            table += benchmark.html(columns)
            table += os.linesep
        table += '</tbody>' + os.linesep
        table += '<thead>' + os.linesep
        table += self.summarize().html(columns) + os.linesep
        table += '</thead>' + os.linesep
        return table

def parse_args():
    parser = argparse.ArgumentParser(description="Generate a digest of Redlog benchmarking")
    parser.add_argument("regressions", help="the regressions directory (typically inside packages/redlog)")
    parser.add_argument("timings", help="the timing directory (which contains csl-times, psl-times)")
    parser.add_argument("--format", choices=["txt", "html", "html_table", "csv", "json", "py"],
        default="txt", help=("output text (default), a full html document, an html table, "
        "comma-separated values, json, or a python list of dictionaries"))
    parser.add_argument("--select", choices=["cpu", "gc"], help="include only cpu times or only gc times")
    parser.add_argument("--sort", choices=["alpha", "speed"], default="names",
        help="sort alphabetically (default) or by relative mean speedup")
    return parser.parse_args()

if __name__ == "__main__":
    args = parse_args()
    date = datetime.date.today().strftime("%Y-%m-%d")
    data = Benchmarks(args.regressions, args.timings)
    if args.sort == "speed":
        data.sort(column="cpu_ratio_mean")
    format = args.format
    if format == "html":
        print(data.html_view(args.select, full=True))
    elif format == "html_table":
        print(data.html_view(args.select, full=False))
    elif format == "csv":
        print("not implemented")
    elif format == "txt":
        print("not implemented")
    elif format == "json":
        print(json.dumps(data, indent=2))
    elif format == "py":
        pprint.pprint(data)
