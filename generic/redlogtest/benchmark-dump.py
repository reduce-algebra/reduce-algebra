#!/usr/bin/env python3

import argparse
import datetime
import json
import os
import pandas as pd
from pprint import pprint
import statistics

class Row(dict):
    def __init__(self, dictionary: dict = {}):
        super().__init__(dictionary)

    def read(self, root: str):
        for stem in 'cpu', 'end', 'gc', 'heapsize', 'start', 'valid':
            for lisp in 'csl', 'psl':
                key = '_'.join([stem, lisp])
                key_file_name = os.path.join(root, self['name'], stem + '_' + lisp + '.txt')
                if os.path.exists(key_file_name):
                    with open(key_file_name) as file:
                        entry = file.read().rstrip()
                        if stem in ('cpu', 'gc', 'heapsize', 'revision'):
                            entry = int(entry)
                        elif stem == 'valid':
                            if entry == "True":
                                entry = store_true
                            elif entry == "False":
                                entry = False
                            else:
                                entry = None
                else:
                    entry = None
                self.update({key: entry})
        return self

    def compute_means(self):
        if self['valid_csl'] is True and self['valid_csl'] is True:
            self.update({'valid_mean': True})
        elif self['valid_csl'] is False or self['valid_csl'] is False:
            self.update({'valid_mean': False})
        else:
            self.update({'valid_mean': None})
        for stem in 'cpu', 'gc':
            csl_key = '_'.join([stem, 'csl'])
            psl_key = '_'.join([stem, 'psl'])
            key = '_'.join([stem, 'mean'])
            if self[csl_key] is not None and self[psl_key] is not None:
                entry = statistics.mean([self[csl_key], self[psl_key]])
            else:
                entry = None
            self.update({key: entry})
        return self

    def compute_deltas_and_ratios(self, ref: str = 'ref', now: str = 'now'):
        def _difference(x: int, y: int) -> int:
            try:
                return x - y
            except TypeError:
                return None
        def _quotient(x: int, y: int) -> float:
            assert x >= 0
            try:
                return x / y
            except ZeroDivisionError:
                if x == 0:
                    return float("nan")
                else:
                    return float("inf")
            except TypeError:
                return None
        for stem in 'cpu', 'gc':
            for lisp in 'csl', 'psl', 'mean':
                ref_key = '_'.join([stem, lisp, ref])
                now_key = '_'.join([stem, lisp, now])
                delta_key = '_'.join([stem, lisp, 'delta'])
                ratio_key = '_'.join([stem, lisp, 'ratio'])
                delta_entry = _difference(self[now_key], self[ref_key])
                ratio_entry = _quotient(self[now_key], self[ref_key])
                self.update({delta_key: delta_entry, ratio_key: ratio_entry})
        return self

    def select(self, columns: list):
        return Row({key: self[key] for key in columns})

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

class Benchmark(pd.DataFrame):
    def read_filetree(root: str):
        rows = []
        for path, directories, files in os.walk(root):
            for file in files:
                if '.red' not in file:
                    continue
                benchmark = Row()
                name = os.path.relpath(path, root)
                benchmark.update({"name": name})
                benchmark.read(root)
                rows.append(benchmark)
        names = []
        for benchmark in rows:
            names.append(benchmark["name"])
            del benchmark["name"]
        return Benchmark(pd.DataFrame(rows, names))

    def summarize(self) -> Row:
        summary = Row({'name': 'Summary'})
        for lisp in 'csl', 'psl', 'mean':
            key = '_'.join(['valid', lisp])
            entry = True
            for benchmark in self:
                if benchmark[key] is True:
                    continue
                elif benchmark[key] is False:
                    entry = False
                    break
                elif benchmark[key] is None:
                    entry = None
                    continue
            summary.update({key: entry})
            for stem in 'cpu', 'gc':
                key = '_'.join([stem, lisp])
                entry = 0
                for benchmark in self:
                    if benchmark[key] is not None:
                        entry += benchmark[key]
                    else:
                        entry = None
                        break
                summary.update({key: entry})
        summary.compute_means()
        return summary

    def select(self, columns: list):
        selection = Benchmark()
        for benchmark in self:
            selection.append(benchmark.select(columns))
        return selection

    def sort(self, *, column: str, reverse: bool = False):
        def _column(benchmark: Row):
            return benchmark[column]
        super().sort(key=_column, reverse=reverse)
        return self

    def txt_view(self, summary: Row) -> str:
        pd.set_option('display.max_rows', None)
        pd.set_option('display.expand_frame_repr', False)
        self.extend([summary])
        names = list(map(lambda benchmark: benchmark["name"], self))
        for benchmark in self:
            del benchmark["name"]
        return pd.DataFrame(self, names)

    def html_view(self, summary: Row, *, full: bool = False) -> str:
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
        html_doc += '<caption>Created by benchmark-dump.py on '
        html_doc += datetime.date.today().strftime("%Y-%m-%d")
        html_doc += '. All times in ms</caption>' + os.linesep
        html_doc += '<thead>' + os.linesep
        html_doc += '<tr>'
        if len(self[0]) == 13:
            html_doc += '<th style="text-align:left;">Row</th>'
            for section in "CSL", "PSL", "Mean":
                html_doc += '<th style="text-align:center;" colspan="4">' + section + '</th>'
        elif len(self[0]) == 25:
            html_doc += '<th style="text-align:left;">Row</th>'
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
    parser = argparse.ArgumentParser(
        description="Dump Reduce benchmarks",
        epilog = ("A call without optional arguments defaults to: "
                  "benchmark-dump.py --columns=cpu --format=txt --sort=name"))
    parser.add_argument('now', metavar='NOW', type=str,
        help='the root of the result tree (typically generated by benchmark-run)')
    parser.add_argument("--columns", choices=["all", "cpu", "gc", "global"], type=str,
        help="select all data (cpu and gc), only cpu, or only gc")
    parser.add_argument("--format", choices=["csv", "html", "html_table", "json", "py", "txt"],
        type=str, help=("generate comma-separated values, an html table, a full html document, "
                        "json, a python list of dictionaries, or plain text"))
    parser.add_argument("--sort", choices=["name", "cpu_now", "cpu_ratio"], type=str,
        help="sort by benchmark basename, mean CPU time, or the ratio between Reference CPU time and CPU time")
    parser.add_argument('--ref', metavar='REF', type=str, help='another root of a result tree for comparison')
    return parser.parse_args()

def column_list(select_arg: str, suffixes: list = None) -> list:
    if select_arg == 'all':
        stems = ['cpu', 'gc']
    else:
        stems = [select_arg]
    if suffixes is not None:
        suffixes = map(lambda s: '_' + s, suffixes)
    else:
        suffixes = ['']
    columns = ['name']
    for suffix in suffixes:
        for lisp in 'csl', 'psl', 'mean':
            columns.append('_'.join(['valid', lisp]) + suffix)
            for stem in stems:
                columns.append('_'.join([stem, lisp]) + suffix)
    return columns

if __name__ == "__main__":
    args = parse_args()
    data = Benchmark().read(args.now)
    
    summary = data.summarize()
    # Sorting before selecting allows to sort w.r.t. unselected columns
    # sort = args.sort or "name"
    # if sort == "cpu_now":
    #     data.sort(column="cpu_now_mean")
    # elif sort == "cpu_ratio":
    #     data.sort(column="cpu_ratio_mean")
    # elif sort == "name":
    #     data.sort(column="name")
    columns = column_list(args.columns or 'cpu')
    data = data.select(columns)
    summary = summary.select(columns)
    format = args.format or "txt"
    if format == "html":
        print(data.html_view(summary, full=True))
    elif format == "html_table":
        print(data.html_view(summary, full=False))
    elif format == "csv":
        print("not implemented")
    elif format == "json":
        print(json.dumps(data, indent=2))
    elif format == "py":
        pprint.pprint(data)
    elif format == "txt":
        print(data.txt_view(summary))
