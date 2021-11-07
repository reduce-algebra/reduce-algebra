"""
Pandas-based data analytics for Reduce benchmarks
"""

___author___ = 'Thomas Sturm'
___contact___ = 'https://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__ = 'CC BY-NC-ND'
___version___ = '$Rev$'

import IPython.core.display
import os
import sys
import pandas as pd
import pathlib
import webbrowser

from . import html

class Benchmark(pd.DataFrame):
    def __getitem__(self, *arguments, **keywords):
        """
        Overload in order to cast to Benchmark in case a new DataFrame
        is created.
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

    def join(self, *arguments, **keywords):
        item = super().join(*arguments, **keywords)
        if type(item) == pd.DataFrame:
            item = Benchmark(item)
        return item

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

    def fast(self, max: float = 0.5):
        """
        Select rows where all CPU times are < max. Note that fast() and
        slow() complement each other.
        """
        level0 = list(self.columns.levels[0])
        query = True
        for index0 in level0:
            cpu_csl = self[(index0, 'cpu_csl')]
            cpu_psl = self[(index0, 'cpu_psl')]
            query &= (cpu_csl < max) & (cpu_psl < max)
        return self[query]

    def slow(self, min: float = 0.5):
        """
        Select rows where at least one CPU time is >= min. Note that
        fast() and slow() complement each other.
        """
        level0 = list(self.columns.levels[0])
        query = False
        for index0 in level0:
            cpu_csl = self[(index0, 'cpu_csl')]
            cpu_psl = self[(index0, 'cpu_psl')]
            query |= (min <= cpu_csl) | (min <= cpu_psl)
        return self[query]

    def plot_scatter(self, *arguments, **keywords):
        if 'alpha' not in keywords:
            keywords['alpha'] = 0.25
        if 'figsize' not in keywords:
            keywords['figsize'] = (6,6)
        if 'grid' not in keywords:
            keywords['grid'] = True
        if 'loglog' not in keywords:
            keywords['loglog'] = True
        if keywords['loglog']:
            self = self.replace(to_replace=0.0, value=0.005)
        ax = self.plot.scatter(*arguments, **keywords)
        low_x, high_x = ax.get_xlim()
        low_y, high_y = ax.get_ylim()
        low = max(low_x, low_y)
        high = min(high_x, high_y)
        return ax.axline([low, low],[high, high], c='gray', linewidth=0.3)

    def plot_scatter_csl_psl(self, **keywords):
        if 'colorbar' not in keywords:
            keywords['colorbar'] = False
        csl_rows = self.xs('cpu_csl', level=1, axis=1)
        csl_rows = csl_rows.assign(csl=True)
        psl_rows = self.xs('cpu_psl', level=1, axis=1)
        psl_rows = psl_rows.assign(csl=False)
        all_rows = pd.concat([csl_rows, psl_rows], ignore_index=True)
        b = Benchmark(all_rows)
        p = b.plot_scatter(c='csl', colormap='bwr', include_bool=True, **keywords)
        return p

    def plot_scatter_ref_now(self, ref: str = 'ref', now: str = 'now', **keywords):
        ref_rows = self.xs(ref, level=0, axis=1)
        ref_rows = ref_rows.assign(ref=True)
        now_rows = self.xs(now, level=0, axis=1)
        now_rows = now_rows.assign(ref=False)
        all_rows = pd.concat([ref_rows, now_rows], ignore_index=True)
        b = Benchmark(all_rows)
        if 'colorbar' not in keywords:
            keywords['colorbar'] = False
        p = b.plot_scatter(c='ref', colormap='Dark2', sharex=False, include_bool=True, **keywords)
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

def summary(now: str, ref: str = None, display: bool = False, dump: bool = False,
            full_html: bool = False):
    if ref is None:
        with open(os.path.join(now, 'GLOBAL', 'source.txt')) as file:
            ref = file.read()
    summary_html = os.path.abspath(os.path.join(now, 'summary.html'))
    with open(summary_html, mode='w') as summary:
        if full_html:
            summary.write(html.begin)
        global_attributes = ['uname', 'revision', 'start', 'end']
        ref = read_filetree(ref, 'ref').add_means()
        ref_attrs = pd.DataFrame(ref.attrs.values(), index=ref.attrs.keys(), columns=['ref'])
        now = read_filetree(now, 'now').add_means()
        now_attrs = pd.DataFrame(now.attrs.values(), index=now.attrs.keys(), columns=['now'])
        combo = ref.join(now, how='inner').select(['cpu', 'valid_mean'])
        combo_attrs = combine2(ref_attrs, now_attrs).reindex(global_attributes)
        summary.write(html.h3('Global Information'))
        summary.write(html.p(combo_attrs.to_html()))
        summary.write(html.h3('Scatter Plots'))
        summary.write(html.p("""
All times are in seconds.
For each benchmark problem we have 4 CPU times: "ref/cpu_csl",
"ref/cpu_psl", "now/cpu_csl", "now/cpu_psl". We plot "now" against
"ref" using red and blue dots for "cpu_csl" and "cpu_psl", respectively.
Thus each problem produces one red and one blue dot. The scales are
logarithmic. Formal CPU times of 0 s are plotted here as as 0.005 s, but
the 0 entries in the tables below are left unchanged.
"""))
        summary.write('<div style="text-align:center">')
        combo_1 = combo.fast(1)
        n_1 = len(combo_1.index)
        title_1 = '{:d} problems with all CPU times < 1 s'.format(n_1)
        combo_60 = combo.slow(1).fast(60)
        n_60 = len(combo_60.index)
        title_60 = ('{:d} problems with at least one CPU time $\\geq$ 1 s\n'
                    'and all CPU times < 60 s').format(n_60)
        combo_rest = combo.slow(60)
        n_rest = len(combo_rest.index)
        title_rest = '{:d} problems with at least 1 CPU time $\\geq$ 60 s'.format(n_rest)
        title='All computed problems ({:d})'.format(n_1 + n_60 + n_rest)
        summary.write(html.plot_scatter(combo, title=title))
        if not combo_1.empty:
            summary.write(html.plot_scatter(combo_1, title=title_1))
        if not combo_60.empty:
            summary.write(html.plot_scatter(combo_60, title=title_60))
        if not combo_rest.empty:
            summary.write(html.plot_scatter(combo_rest, title=title_rest))
        summary.write('</div>')
        summary.write(html.p("""
Next we plot "cpu_psl" against "cpu_csl" using gray and green for "ref"
and "now", respectively. Every problem produces one gray and one green
dot.
"""))
        summary.write('<div style="text-align:center">')
        summary.write(html.plot_scatter_ref_now(combo, title=title))
        if not combo_1.empty:
            summary.write(html.plot_scatter_ref_now(combo_1, title=title_1))
        if not combo_60.empty:
            summary.write(html.plot_scatter_ref_now(combo_60, title=title_60))
        if not combo_rest.empty:
            summary.write(html.plot_scatter_ref_now(combo_rest, title=title_rest))
        summary.write('</div>')
        summary.write(html.h3('Detailed CPU Times and Validity'))
        summary.write(html.p("""
Validity follows a three-valued logic. Each problem in "ref" may but
need not provide reference logs "rlg_csl.txt", "rlg_psl.txt". In the
positive case, "valid_csl" and "valid_psl" indicate equality modulo
"diff -Bqw" as True or False. In the negative case they are None.
Together they yield "valid_mean", which is True if both are True, False
if at least one is False, and None otherwise. Thus valid_mean = True
indicates evidence that nothing has changed with either Lisp,
valid_mean = False indicates evidence for changes with at least one of
the two.
"""))
        combo_bad = combo[(combo[('now', 'valid_mean')] == False)]
        if not combo_bad.empty:
            summary.write(html.h4('Problems with Validity Issues'))
            summary.write(html.p(combo_bad.to_html(show_dimensions=True)))
        if not combo_1.empty:
            summary.write(html.h4(title_1.replace('$\\geq$', '&ge;')))
            summary.write(html.p(combo_1.to_html(show_dimensions=True)))
        if not combo_60.empty:
            summary.write(html.h4(title_60.replace('$\\geq$', '&ge;')))
            summary.write(html.p(combo_60.to_html(show_dimensions=True)))
        if not combo_rest.empty:
            summary.write(html.h4(title_rest.replace('$\\geq$', '&ge;')))
            summary.write(html.p(combo_rest.to_html(show_dimensions=True)))
        if full_html:
            summary.write(html.end)
    if dump:
        with open(summary_html, mode = 'r') as summary:
            try:
                __IPYTHON__
                IPython.core.display.display(IPython.core.display.HTML(summary.read()))
            except NameError:
                print(summary.read())

    elif display:
        webbrowser.open(pathlib.Path(summary_html).as_uri(), new=1)