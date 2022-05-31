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
from pandas.core.accessor import CachedAccessor
import pathlib
import webbrowser

from . import html
from . import plotting

class RbDataFrame(pd.DataFrame):
    plot = CachedAccessor('plot', plotting.RbPlotAccessor)

    @property
    def _constructor(self):
        return RbDataFrame

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

    def deselect(self, selectors):
        """
        Remove columns by substring match in any level.
        """
        if type(selectors) == str:
            selectors = [selectors]
        selection = []
        for column in self.columns:
            select = True
            for selector in selectors:
                if selector in column[0] or selector in column[1]:
                    select = False
                    break
            if select:
                selection.append(column)
        return self[selection]

    def fast(self, max: float = 0.5):
        """
        Select rows where all CPU times are < max. Note that fast() and
        slow() complement each other.
        """
        level0 = list(self.columns.levels[0])
        query = True
        for index0 in level0:
            try:
                cpu_csl = self[(index0, 'cpu_csl')]
                query &= (cpu_csl < max)
            except KeyError:
                pass
            try:
                cpu_psl = self[(index0, 'cpu_psl')]
                query &= (cpu_psl < max)
            except KeyError:
                pass
            try:
                cpu_boot = self[(index0, 'cpu_boot')]
                query &= (cpu_boot < max)
            except KeyError:
                pass
        return self[query]

    def slow(self, min: float = 0.5):
        """
        Select rows where at least one CPU time is >= min. Note that
        fast() and slow() complement each other.
        """
        level0 = list(self.columns.levels[0])
        query = False
        for index0 in level0:
            try:
                cpu_csl = self[(index0, 'cpu_csl')]
                sigxcpu_csl = self[(index0, 'sigxcpu_csl')]
                query |=  (min <= cpu_csl) | (min <= sigxcpu_csl)
            except KeyError:
                pass
            try:
                cpu_psl = self[(index0, 'cpu_psl')]
                sigxcpu_psl = self[(index0, 'sigxcpu_psl')]
                query |=  (min <= cpu_psl) | (min <= sigxcpu_psl)
            except KeyError:
                pass
            try:
                cpu_boot = self[(index0, 'cpu_boot')]
                sigxcpu_boot = self[(index0, 'sigxcpu_boot')]
                query |=  (min <= cpu_boot) | (min <= sigxcpu_boot)
            except KeyError:
                pass
        return self[query]

def read_filetree(root: str, key0: str = None):
    class Row(dict):
        def read(self, root: str):
            for stem in 'cpu', 'end', 'gc', 'sigxcpu', 'heapsize', 'start', 'valid':
                for lisp in 'csl', 'psl', 'boot':
                    key = '_'.join([stem, lisp])
                    key_file_name = os.path.join(root, self['name'], stem + '_' + lisp + '.txt')
                    if os.path.exists(key_file_name):
                        with open(key_file_name) as file:
                            entry = file.read().rstrip()
                            if stem in ('cpu', 'gc'):
                                entry = float(entry) / 1000
                            elif stem in ('sigxcpu'):
                                entry = float(entry)
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
        for directory in directories:
            if directory == 'SUPPORT':
                directories.remove(directory)
                break
        for file in files:
            if '.red' not in file:
                continue
            row = Row()
            name = os.path.relpath(path, root)
            row.update({"name": name})
            row.read(root)
            rows.append(row)
    columns = []
    for postfix in '_csl', '_psl', '_boot':
        for stem in 'start', 'cpu', 'gc', 'sigxcpu', 'heapsize', 'valid', 'end':
            columns.append(stem + postfix)
    rbdf = RbDataFrame(rows, columns=['name'] + columns)
    rbdf.set_index('name', inplace=True)
    rbdf.rename_axis(None, inplace=True)
    rbdf.sort_index(inplace=True)
    rbdf.columns = pd.MultiIndex.from_tuples([(key0 or attrs['revision'], c) for c in rbdf.columns])
    rbdf.attrs = attrs
    return rbdf

def combine2(a: RbDataFrame, b: RbDataFrame, *, keys: list = None):
    return RbDataFrame(pd.concat([a, b], axis=1))

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
# Computation before printing
        combo = ref.join(now, how='inner').select(['cpu', 'valid_mean'])
        combo_attrs = combine2(ref_attrs, now_attrs).reindex(global_attributes)
        combos = []
        _ = combo.slow(0)
        combos.append((_, f'All computed problems ({len(_.index):d})'))
        _ = combo.fast(1)
        combos.append((_, f'{len(_.index):d} problems with all CPU times < 1 s'))
        _ = combo.slow(1).fast(60)
        combos.append((_, f'{len(_.index):d} problems with at least one CPU time $\\geq$ 1 s\n'
            'and all CPU times < 60 s'))
        _ = combo.slow(60)
        combos.append((_, f'{len(_.index):d} problems with at least 1 CPU time $\\geq$ 60 s'))
# Global information
        summary.write(html.h3('Global Information'))
        summary.write(html.p(combo_attrs.to_html()))
# Scatter plots
        summary.write(html.h3('Scatter Plots'))
        summary.write(html.p("""
All times are in seconds. For each benchmark problem we have 4 CPU
times: "ref/cpu_csl", "ref/cpu_psl", "now/cpu_csl", "now/cpu_psl". We
plot "now" against "ref" using red and blue dots for "cpu_csl" and
"cpu_psl", respectively. Thus each problem produces one red and one blue
dot. The scales are logarithmic. Formal CPU times of 0 s are plotted
here as as 0.005 s, but the 0 entries in the tables below are left
unchanged.
 """))
        summary.write('<div style="text-align:left;">')
        for (c, t) in combos:
            if not c.empty:
                ax = c.plot.scatter2(x='ref', y='now', c1='cpu_csl', c2='cpu_psl', title=t)
                summary.write(html.img(ax))
        summary.write('</div>')
        summary.write(html.p("""
Next we plot "cpu_psl" against "cpu_csl" using green and magenta for
"ref" and "now", respectively. Every problem produces one green and one
magenta dot.
"""))
        summary.write('<div style="text-align:left;">')
        for (c, t) in combos:
            if not c.empty:
                ax = c.plot.scatter2(c1='ref', c2='now', x='cpu_csl', y='cpu_psl', title=t)
                summary.write(html.img(ax))
        summary.write('</div>')
# Schedule
        n = len(combo.slow(0).index)
        t0 = min(now.xs(('now', 'start_csl'), axis=1).min(),
                 now.xs(('now', 'start_psl'), axis=1).min())
        end = max(now.xs(('now', 'end_csl'), axis=1).max(),
                  now.xs(('now', 'end_psl'), axis=1).max())
        summary.write(html.h3('Parallel Job Execution over Time'))
        summary.write(html.p(f"""
Time slots allocated by {n:d} CSL (red) and {n:d} PSL (blue) "now" jobs.
Let t<sub>0</sub> be the wall clock start time of the first job. The
x-axis shows the wall clock time in seconds relative to  t<sub>0</sub>
&minus; 1 second, on a logarithmic scale. The labels of the y-axis are
an ordinal numbering of jobs, which are lexicographically sorted by
(start time, end time). Jobs appearing in pale color have zero duration
on the time scale used and are located at the left of their plot.
"""))
        t = f'$t_0$ = {str(t0)}\nend at {str(end)}'
        ax = now.plot.schedule(title=t)
        summary.write(html.img(ax))
# Tables
        summary.write(html.h3('Detailed CPU Times and Validity'))
        summary.write(html.p("""
Validity follows a three-valued logic. Each problem in "ref" may but
need not provide reference logs "rlg_csl.txt", "rlg_psl.txt". In the
positive case, "valid_csl" and "valid_psl" indicate equality modulo
"diff -Bqw" as True or False. In the negative case they are None.
Together they yield "valid_mean", which is True if both are True, False
if at least one is False, and None otherwise. Thus valid_mean = True
indicates evidence that nothing has changed with either Lisp, valid_mean
= False indicates evidence for changes with at least one of the two.
"""))
        combo_bad = combo[(combo[('now', 'valid_mean')] == False)]
        if not combo_bad.empty:
            summary.write(html.h4('Problems with Validity Issues'))
            summary.write(html.p(combo_bad.to_html(show_dimensions=True)))
        for (c, t) in combos:
            if not c.empty:
                summary.write(html.h4(t))
                summary.write(html.p(c.to_html(show_dimensions=True)))
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