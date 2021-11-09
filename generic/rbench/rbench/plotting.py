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
import pandas as pd
from pandas.plotting import PlotAccessor

def plot_scatter(benchmark, **keywords):
    if 'alpha' not in keywords:
        keywords['alpha'] = 0.25
    if 'figsize' not in keywords:
        keywords['figsize'] = (5,5)
    if 'grid' not in keywords:
        keywords['grid'] = True
    if 'loglog' not in keywords:
        keywords['loglog'] = True
    if keywords['loglog']:
        benchmark = benchmark.replace(to_replace=0.0, value=0.005)
    ax = PlotAccessor(benchmark)(kind='scatter', **keywords)
    low_x, high_x = ax.get_xlim()
    low_y, high_y = ax.get_ylim()
    low = max(low_x, low_y)
    high = min(high_x, high_y)
    ax.axline([low, low],[high, high], c='gray', linewidth=0.3)
    return ax

def plot_scatter2(benchmark, *, x: str, y: str, c1: str, c2: str, color1: str = None,
        color2: str = None, **keywords):
    l0 = benchmark.columns.levels[0]
    l1 = benchmark.columns.levels[1]
    fig, ax = plt.subplots()
    if x in l0 and y in l0 and c1 in l1 and c2 in l1:
        plot_scatter(benchmark, x=(x, c1), y=(y, c1), ax=ax, color=color1 or 'r', **keywords)
        plot_scatter(benchmark, x=(x, c2), y=(y, c2), ax=ax, color=color2 or 'b', **keywords)
    elif x in l1 and y in l1 and c1 in l0 and c2 in l0:
        plot_scatter(benchmark, x=(c1, x), y=(c1, y), ax=ax, color=color1 or 'g', **keywords)
        plot_scatter(benchmark, x=(c2, x), y=(c2, y), ax=ax, color=color2 or 'm', **keywords)
    else:
        raise ValueError('bad choice of x, y, c1, c2')
    ax.set_xlabel(x)
    ax.set_ylabel(y)
    return ax

def axes_to_b64(ax) -> str:
    img = io.BytesIO()
    fig = ax.get_figure()
    fig.savefig(img, format='png', bbox_inches='tight')
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
        elif kind in self._pandas_kinds:
            return PlotAccessor(data)(kind=kind, **keywords)
        else:
            raise ValueError(f'{kind} is not a valid plot kind')

    def scatter2(self, *arguments, **keywords):
        return self(kind='scatter2', *arguments, **keywords)
