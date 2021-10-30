#!/usr/bin/env python3

import argparse
import benchmark_run
import datetime
import json
import matplotlib.pyplot as plt
import os
import sys
import pandas as pd
from pprint import pprint
import statistics

class Row(dict):
    def read(self, root: str):
        for stem in 'cpu', 'end', 'gc', 'heapsize', 'start', 'valid':
            for lisp in 'csl', 'psl':
                key = '_'.join([stem, lisp])
                key_file_name = os.path.join(root, self['name'], stem + '_' + lisp + '.txt')
                if os.path.exists(key_file_name):
                    with open(key_file_name) as file:
                        entry = file.read().rstrip()
                        if stem in ('cpu', 'gc'):
                            entry = float(entry) / 1000
                        elif stem in ('heapsize'):
                            entry = int(entry)
                        elif stem in ('start', 'end'):
                            entry = pd.to_datetime(entry)
                        elif stem == 'valid':
                            if entry == "True":
                                entry = True
                            elif entry == "False":
                                entry = False
                            else:
                                entry = None
                else:
                    entry = None
                self.update({key: entry})
        return self

class Benchmark(pd.DataFrame):
    def __getitem__(self, *arguments, **keywords):
        item = super().__getitem__(*arguments, **keywords)
        if type(item) == pd.DataFrame:
            item = Benchmark(item)
        return item

    def add_means(self):
        def _valid_mean(self, key0):
            a = self[(key0, 'valid_csl')]
            b = self[(key0, 'valid_psl')]
            if a is True and b is True:
                return pd.Series([True], index=['valid_mean'])
            elif a is False or b is False:
                return pd.Series([False], index=['valid_mean'])
            else:
                return pd.Series([None], index=['valid_mean'])
        for key0 in self.columns.levels[0]:
            self[(key0, 'cpu_mean')] = self[[(key0, 'cpu_csl'), (key0, 'cpu_psl')]].mean(axis=1)
            self[(key0, 'gc_mean')] = self[[(key0, 'gc_csl'), (key0, 'gc_psl')]].mean(axis=1)
            self[(key0, 'valid_mean')] = self.apply(_valid_mean, args=(key0,), axis=1)
        return self

    def select(self, selectors):
        if type(selectors) == str:
            selectors = [selectors]
        selection = []
        for column in self.columns:
            for selector in selectors:
                if selector in column[0] or selector in column[1]:
                    selection.append(column)
                    break
        return self[selection]

    def plot_scatter(self, *arguments, **keywords):
        if 'alpha' not in keywords:
            keywords['alpha'] = 0.25
        if 'figsize' not in keywords:
            keywords['figsize'] = (6,6)
        if 'grid' not in keywords:
            keywords['grid'] = True
        if 'loglog' not in keywords:
            keywords['loglog'] = True
        p = self.plot.scatter(*arguments, **keywords, zorder=1)
        low_x, high_x = p.get_xlim()
        low_y, high_y = p.get_ylim()
        low = max(low_x, low_y)
        high = min(high_x, high_y)
        return p.plot([low, high], [low, high], c='k', zorder=0, linewidth=0.1)

    def plot_scatter_csl_psl(self, **keywords):
        csl_rows = self.xs('cpu_csl', level=1, axis=1)
        csl_rows = csl_rows.assign(csl=True)
        psl_rows = self.xs('cpu_psl', level=1, axis=1)
        psl_rows = psl_rows.assign(csl=False)
        all_rows = pd.concat([csl_rows, psl_rows], ignore_index=True)
        p = Benchmark(all_rows).plot_scatter(c='csl', colormap='bwr', sharex=False, include_bool=True, **keywords)
        return p

def read_filetree(root: str, key0: str = None):
    global_attributes = ['uname', 'revision', 'start', 'end', 'parse_args']
    attrs = {}
    for attribute in global_attributes:
        filename = os.path.join(root, 'GLOBAL', attribute + '.txt')
        try:
            with open(filename) as file:
                entry = file.read().rstrip()
                if attribute in ['start', 'end']:
                    entry = pd.to_datetime(entry)
        except FileNotFoundError:
            entry = None
        attrs[attribute] = entry
    rows = []
    for path, directories, files in os.walk(root):
        for file in files:
            if '.red' not in file:
                continue
            row = Row()
            name = os.path.relpath(path, root)
            row.update({"name": name})
            row.read(root)
            rows.append(row)
    columns = []
    for postfix in '_csl', '_psl':
        for stem in 'start', 'cpu', 'gc', 'heapsize', 'valid', 'end':
            columns.append(stem + postfix)
    df = Benchmark(rows, columns=['name'] + columns)
    df.set_index('name', inplace=True)
    df.rename_axis(None, inplace=True)
    df.sort_index(inplace=True)
    df.columns = pd.MultiIndex.from_tuples([(key0 or attrs['revision'], c) for c in df.columns])
    df.attrs = attrs
    return df

def combine2(a: Benchmark, b: Benchmark, *, keys: list = None):
    return Benchmark(pd.concat([a, b], axis=1))

def cron(args):
    args.dry_run = False
    args.bar = False
    print(html_begin())
    print('<pre>')
    print('<code>')
    benchmark_run.benchmark_run(args)
    print('</code>')
    print('</pre>')
    summary_body(args.source, args.result)
    print(html_end())

def summary(ref: Benchmark, now: Benchmark):
    print(html_begin())
    summary_body(ref, now)
    print(html_end())

def summary_body(ref: Benchmark, now: Benchmark):
    def fig_to_img(df):
        import base64
        import io
        fig, ax = plt.subplots()
        df.plot_scatter_csl_psl(x='ref', y='now', figsize=(5, 5), ax=ax, colorbar=False)
        img = io.BytesIO()
        fig.savefig(img, format='png', bbox_inches='tight')
        img.seek(0)
        fig_b64 = base64.encodebytes(img.getvalue())
        return '<img src="data:image/png;base64, {}">'.format(fig_b64.decode('utf-8'))
    def html_p(html: str):
        return '<p>' + html + '</p>'
    global_attributes = ['uname', 'revision', 'start', 'end']
    ref = read_filetree(ref, 'ref').add_means()
    ref_attrs = pd.DataFrame(ref.attrs.values(), index=ref.attrs.keys(), columns=['ref'])
    now = read_filetree(now, 'now').add_means()
    now_attrs = pd.DataFrame(now.attrs.values(), index=now.attrs.keys(), columns=['now'])
    combo = combine2(ref, now).select(['cpu', 'valid_mean'])
    combo_attrs = combine2(ref_attrs, now_attrs).reindex(global_attributes)
    combo_bad = combo[(combo[('now', 'valid_mean')] == False)]
    combo_fast = combo[(combo[('ref', 'cpu_mean')] <= 0.5) & (combo[('now', 'cpu_mean')] <= 0.5)]
    combo_slow = combo[(combo[('ref', 'cpu_mean')] > 0.5) | (combo[('now', 'cpu_mean')] > 0.5)]
    print('<h3>Global Information</h3>')
    print(html_p(combo_attrs.to_html()))
    if not combo_bad.empty:
        print('<h3>Possible Problems</h3>')
        print(html_p('Benchmark problems with existing "now" logs that were tested different from existing "ref" logs:'))
        print(html_p(combo_bad.to_html(show_dimensions=True)))
    print('<h3>Scatter Plots</h3>')
    print(html_p('Plots are split into "fast" (average of the CSL and PSL CPU times &le; 0.5 s) and "slow". '
                 'Red and blue dots correspond to CSL and PSL, respectively. '
                 'The scales are logarithmic. All times are in seconds.'))
    print('<div style="text-align:center">')
    print(fig_to_img(combo_fast) + fig_to_img(combo_slow))
    print('</div>')
    print('<h3>Detailed CPU Times</h3>')
    print('<h3>Fast</h3>')
    print(html_p('Benchmark problems with an average of CSL and PSL CPU times &le; 0.5 s. All times are in seconds.'))
    print(html_p(combo_fast.to_html(show_dimensions=True)))
    print('<h3>Slow</h3>')
    print(html_p('Benchmark problems with an average of CSL and PSL CPU times &gt; 0.5 s. All times are in seconds.'))
    print(html_p(combo_slow.to_html(show_dimensions=True)))

def html_begin() -> str:
    return """<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<style>
    body {font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Helvetica, Arial, sans-serif;}
    h1 {text-align:center;font-size: 185.7%; margin: 1.08em 0 0 0; font-weight: bold; line-height: 1.0;}
    h2 {text-align:center;font-size: 157.1%; margin: 1.27em 0 0 0; font-weight: bold; line-height: 1.0;}
    h3 {text-align:center;font-size: 128.6%; margin: 1.55em 0 0 0; font-weight: bold; line-height: 1.0;}
    h4 {text-align:center;font-size: 100%; margin: 2em 0 0 0; font-weight: bold; line-height: 1.0;}
    h5 {text-align:center;font-size: 100%; margin: 2em 0 0 0; font-weight: bold; line-height: 1.0; font-style: italic;}
    h6 {text-align:center;font-size: 100%; margin: 2em 0 0 0; font-weight: bold; line-height: 1.0; font-style: italic;}
    h1:first-child {margin-top: 0.538em;}
    h2:first-child {margin-top: 0.636em;}
    h3:first-child {margin-top: 0.777em;}
    h4:first-child {margin-top: 1em;}
    h5:first-child {margin-top: 1em;}
    h6:first-child {margin-top: 1em;}
    pre {
        padding: 5px;
        background-color: #eeffcc;
        color: #333333;
        border: 1px solid #ac9;
        border-left: none;
        border-right: none;
        border-radius: 3px;
        border: 1px solid #ac9;
    }
    code {
        font-size: 13px;
        font-family: "Courier New";
    }
    table {
        margin-left: auto;
        margin-right: auto;
        border: none;
        border-collapse: collapse;
        border-spacing: 0;
        color: black;
        font-size: 12px;
        table-layout: fixed;
    }
    thead {
        border-bottom: 1px solid black;
        vertical-align: bottom;
    }
    tr, th, td {
        text-align: right;
        vertical-align: middle;
        padding: 0.5em 0.5em;
        line-height: normal;
        white-space: normal;
        max-width: none;
        border: none;
    }
    th {
        font-weight: bold;
    }
    tbody tr:nth-child(odd) {
        background: #f5f5f5;
    }
    tbody tr:hover {
        background: rgba(66, 165, 245, 0.2);
    }
</style>
</head>
<body>
"""

def html_end() -> str:
    return """</body>
</html>"""

def html_begin_bootstrap() -> str:
    return """<!DOCTYPE html>
<html>
<head>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css"
      rel="stylesheet"
      integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3"
      crossorigin="anonymous">
<style>td,th{text-align:right;}</style>
</head>
<body>
"""

def html_end_bootstrap() -> str:
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

if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='benchmark')
    subparsers = parser.add_subparsers(dest='subcommand', help='sub-commands')
    parser_cron = subparsers.add_parser(
        'cron',
        help='Combine run and summary for use in cron jobs',
        description='Combine run and summary for use in cron jobs')
    parser_cron.add_argument(
        'source', metavar='SOURCE',
        help=('An existing benchmark directory. *.red files are used as input. If present, '
              '*.pslheap is used to override --psl-heapsize SIZE, '
              'and rlg_csl.txt and rlg_psl.txt are used for comparison'))
    parser_cron.add_argument(
        'result', metavar='RESULT',
        help='The benchmark directory to be created. *.red and *.pslheap are copied from SOURCE')
    parser_cron.add_argument(
        '-f', '--force',
        action='store_true',
        help=('Overwrite existing directories specified via \'--svn-reduce DIR\' and \'RESULT\' '
              'without prompting for confirmation'))
    parser_cron.add_argument(
        '-j', '--jobs', metavar='N',
        type=int, default=1,
        help='Run up to N jobs in parallel')
    parser_cron.add_argument('-td', '--psl-heapsize', metavar="SIZE",
        default=4000,
        help='Allocate SIZE MiB for PSL heap(s)')
    parser_cron.add_argument('-v', '--verbose',
        action='store_true',
        help=('Report benchmarks found: +, - indicate inclusion, exclusion, '
              'i, e, t stand for --include, --exclude, --exclude-by-time, respectively. '
              'The generated GNU parallel command is printed before execution'))
    incl_excl_group = parser_cron.add_mutually_exclusive_group()
    incl_excl_group.add_argument(
        '--exclude', metavar="SUBSTRING",
        type=str,
        help='Exclude benchmarks containing SUBSTRING')
    incl_excl_group.add_argument(
        '--include', metavar="SUBSTRING",
        type=str,
        help='Include only benchmarks containing SUBSTRING')
    parser_cron.add_argument(
        '--exclude-by-time', metavar='SECONDS',
        type=int,
        help=('Exclude benchmarks with a cpu time record (cpu_csl.txt, cpu_psl.txt) larger than '
              'SECONDS in SOURCE'))
    reduce_group = parser_cron.add_mutually_exclusive_group(
        required=True)
    reduce_group.add_argument(
        '--reduce', metavar='DIR',
        type=str,
        help='Use existing Reduce directory DIR')
    reduce_group.add_argument(
        '--svn-reduce', metavar='DIR',
        type=str,
        help='svn check out into DIR, compile, and use as Reduce directory')
    parser_cron.add_argument(
        '-r', '--revision', metavar='REV',
        type=str,
        default='HEAD',
        help='Check out SVN revision REV instead of HEAD')
    parser_run = subparsers.add_parser(
        'run',
        help='Run a Reduce benchmark set',
        description='Run a Reduce benchmark set')
    benchmark_run.setup_parser(parser_run)
    parser_summary = subparsers.add_parser(
        'summary',
        help='Dump HTML summary to stdout',
        description='Dump HTML summary to stdout')
    parser_summary.add_argument(
        'ref', metavar='REF',
        help="Reference directory, typically used as SOURCE with 'benchmark run'")
    parser_summary.add_argument(
        'now', metavar='NOW',
        help="Directory with current data, typically obtained as RESULT with 'benchmark run'")
    args = parser.parse_args()
    if args.subcommand is None:
        sys.stderr.write("Type 'benchmark -h' for usage." + os.linesep)
    elif args.subcommand == 'cron':
        cron(args)
    elif args.subcommand == 'run':
        benchmark_run.benchmark_run(args)
    elif args.subcommand == 'summary':
       summary(args.ref, args.now)
    sys.exit(0)
