"""
A plot accessor for RbDataFrame

This allows to hook into method.plot.*() for inherited pd.DataFrame
methods.
"""

___author___ = 'Thomas Sturm'
___contact___ = 'https://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__ = 'CC BY-NC-ND'
___version___ = '$Rev: 6156 $'

import base64
import io
import matplotlib.pyplot as plt
from matplotlib.dates import DateFormatter
import matplotlib.markers
from matplotlib.transforms import Bbox
import pandas as pd
from pandas.plotting import PlotAccessor

# Values less than 5 lead to trouble with the Bbox in axes_to_b64()
default_figsize = (5, 5)
default_double_figsize = (2 * default_figsize[0], 2 * default_figsize[1])

def plot_scatter(rbdf, **keywords):
    if 'alpha' not in keywords:
        keywords['alpha'] = 0.25
    if 'figsize' not in keywords:
        keywords['figsize'] = default_figsize
    if 'grid' not in keywords:
        keywords['grid'] = True
    if 'loglog' not in keywords:
        keywords['loglog'] = True
    if keywords['loglog']:
        rbdf = rbdf.replace(to_replace=0.0, value=0.005)
    ax = PlotAccessor(rbdf)(kind='scatter', **keywords)
    low_x, high_x = ax.get_xlim()
    low_y, high_y = ax.get_ylim()
    low = max(low_x, low_y)
    high = min(high_x, high_y)
    ax.axline([low, low],[high, high], c='k', linewidth=0.1)
    return ax

def plot_scatter2(rbdf, *, x: str, y: str, c1: str, c2: str, color1: str = None,
        color2: str = None, **keywords):
    l0 = rbdf.columns.levels[0]
    l1 = rbdf.columns.levels[1]
    fig, ax = plt.subplots()
    if x in l0 and y in l0 and c1 in l1 and c2 in l1:
        plot_scatter(rbdf, x=(x, c1), y=(y, c1), ax=ax, color=color1 or 'r', **keywords)
        plot_scatter(rbdf, x=(x, c2), y=(y, c2), ax=ax, color=color2 or 'b', **keywords)
    elif x in l1 and y in l1 and c1 in l0 and c2 in l0:
        plot_scatter(rbdf, x=(c1, x), y=(c1, y), ax=ax, color=color1 or 'g', **keywords)
        plot_scatter(rbdf, x=(c2, x), y=(c2, y), ax=ax, color=color2 or 'm', **keywords)
    else:
        raise ValueError('bad choice of x, y, c1, c2')
    ax.set_xlabel(x)
    ax.set_ylabel(y)
    return ax

def plot_schedule(rbdf, *, key0: str = None, figsize: tuple = default_figsize,
        linewidth: float = 1, title: str = None, zorder: int = 100, **keywords):
    if key0 is None:
        l0 = rbdf.columns.levels[0]
        if len(l0) > 1:
            raise ValueError(f'specify one of {str(list(l0))[1:-1]} as keyword argument key0')
        key0 = l0[0]
    rbdf = rbdf.xs(key0, level=0, axis=1)
    csl_rows = rbdf[['start_csl', 'end_csl']]
    csl_rows = csl_rows.rename({'start_csl': 'start', 'end_csl': 'end'}, axis=1)
    csl_rows = csl_rows.assign(color='r')
    psl_rows = rbdf[['start_psl', 'end_psl']]
    psl_rows = psl_rows.rename({'start_psl': 'start', 'end_psl': 'end'}, axis=1)
    psl_rows = psl_rows.assign(color='b')
    all_rows = csl_rows.append(psl_rows, ignore_index=True).sort_values(['start', 'end'])
    t0 = all_rows['start'].min()
    all_rows['start_sec'] = all_rows.apply(lambda df: (df['start'] - t0).total_seconds() + 1, axis=1)
    all_rows['end_sec'] = all_rows.apply(lambda df: (df['end'] - t0).total_seconds() + 1, axis=1)
    n = list(range(len(all_rows)))
    start = list(all_rows['start_sec'])
    end = list(all_rows['end_sec'])
    color = list(all_rows['color'])
    fig, ax = plt.subplots(figsize=figsize)
    ax.set_title(title)
    ax.set_xlabel('wall clock time')
    ax.set_ylabel('jobs')
    ax.set_xscale('log')
    ax.grid(which='major', axis='x')
    ax.grid(which='minor', axis='x', linewidth=0.1)
    ax.hlines(n, start, end, color, linewidth=linewidth, **keywords)
    ax.scatter(y=n, x=start, marker=matplotlib.markers.TICKRIGHT, linewidth=linewidth, color=color,
        alpha=0.25, zorder=0)
    return ax

def axes_to_b64(ax, bbox_inches='tight') -> str:
    img = io.BytesIO()
    fig = ax.get_figure()
    fig.savefig(img, format='png', bbox_inches=bbox_inches)
    plt.close(fig)
    img.seek(0)
    fig_b64 = base64.encodebytes(img.getvalue()).decode('utf-8')
    return fig_b64

class RbPlotAccessor(PlotAccessor):
    _pandas_kinds = PlotAccessor._all_kinds

    def __call__(self, *arguments, **keywords):
        data = self._parent.copy()
        kind = keywords.pop('kind', 'scatter')
        if kind == 'scatter':
            return plot_scatter(data, *arguments, **keywords)
        elif kind == 'scatter2':
            return plot_scatter2(data, *arguments, **keywords)
        elif kind == 'schedule':
            return plot_schedule(data, *arguments, **keywords)
        elif kind in self._pandas_kinds:
            return PlotAccessor(data)(kind=kind, **keywords)
        else:
            raise ValueError(f'{kind} is not a valid plot kind')

    def scatter2(self, *arguments, **keywords):
        return self(kind='scatter2', *arguments, **keywords)

    def schedule(self, *arguments, **keywords):
        return self(kind='schedule', *arguments, **keywords)
