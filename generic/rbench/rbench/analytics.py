"""
Pandas-based data analytics for Reduce benchmarks
"""

___author___   = 'Thomas Sturm, http://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__   = 'CC BY-NC-ND'
___version___  = '$Rev$'

import os
import sys
import pandas as pd
import pathlib
import webbrowser

import html

class Benchmark(pd.DataFrame):
    def __getitem__(self, *arguments, **keywords):
        """
        Overload in order to cast to Benchmark in case a new DataFrame is created.
        """
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
        """
        Select columns by substring match in any level.
        """
        if type(selectors) == str:
            selectors = [selectors]
        selection = []
        for column in self.columns:
            for selector in selectors:
                if selector in column[0] or selector in column[1]:
                    selection.append(column)
                    break
        return self[selection]

    def fast(self, seconds: float = 0.5):
        """
        Select rows where all CPU mean times are <= seconds. Note that fast() and slow() complement
        each other.
        """
        level0 = list(self.columns.levels[0])
        if len(level0) == 1:
            return self[(self[(level0[0], 'cpu_mean')] <= seconds)]
        elif len(level0) == 2:
            return self[(self[(level0[0], 'cpu_mean')] <= seconds) &
                        (self[(level0[1], 'cpu_mean')] <= seconds)]
        else:
            return self

    def slow(self, seconds: float = 0.5):
        """
        Select rows where at least one CPU mean time is greater than seconds. Note that fast()
        and slow() complement each other.
        """
        level0 = list(self.columns.levels[0])
        if len(level0) == 1:
            return self[(self[(level0[0], 'cpu_mean')] > seconds)]
        elif len(level0) == 2:
            return self[(self[(level0[0], 'cpu_mean')] > seconds) |
                        (self[(level0[1], 'cpu_mean')] > seconds)]
        else:
            return self

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

def summary(ref: Benchmark, now: Benchmark, dump: bool, full_html: bool = False):
    if not dump:
        summary_html = os.path.join(now, 'summary.html')
        sys.stdout = open(summary_html, mode='w')
    if full_html:
        print(html.begin)
    global_attributes = ['uname', 'revision', 'start', 'end']
    ref = read_filetree(ref, 'ref').add_means()
    ref_attrs = pd.DataFrame(ref.attrs.values(), index=ref.attrs.keys(), columns=['ref'])
    now = read_filetree(now, 'now').add_means()
    now_attrs = pd.DataFrame(now.attrs.values(), index=now.attrs.keys(), columns=['now'])
    combo = combine2(ref, now).select(['cpu', 'valid_mean'])
    combo_attrs = combine2(ref_attrs, now_attrs).reindex(global_attributes)
    combo_bad = combo[(combo[('now', 'valid_mean')] == False)]
    print(html.h3('Global Information'))
    print(html.p(combo_attrs.to_html()))
    if not combo_bad.empty:
        print(html.h3('Possible Problems'))
        print(html.p('Benchmark problems with existing "now" logs that were tested different from '
                     'existing "ref" logs:'))
        print(html.p(combo_bad.to_html(show_dimensions=True)))
    print(html.h3('Scatter Plots'))
    print(html.p('Plots are split into "fast" (average of the CSL and PSL CPU times &le; 0.5 s) '
                 'and "slow". Red and blue dots correspond to CSL and PSL, respectively. '
                 'The scales are logarithmic. All times are in seconds.'))
    print('<div style="text-align:center">')
    print(html.plot_scatter(combo.fast()))
    print(html.plot_scatter(combo.slow()))
    print('</div>')
    print(html.h3('Detailed CPU Times'))
    print(html.h3('Fast'))
    print(html.p('Benchmark problems with an average of CSL and PSL CPU times &le; 0.5 s. '
                 'All times are in seconds.'))
    print(html.p(combo.fast().to_html(show_dimensions=True)))
    print(html.h3('Slow'))
    print(html.p('Benchmark problems with an average of CSL and PSL CPU times &gt; 0.5 s. '
                 'All times are in seconds.'))
    print(html.p(combo.slow().to_html(show_dimensions=True)))
    if full_html:
        print(html.end)
    if not dump:
        webbrowser.open(pathlib.Path(os.path.abspath(summary_html)).as_uri(), new=1)
        sys.stdout.close()
