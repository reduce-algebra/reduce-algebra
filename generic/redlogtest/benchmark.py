#!/usr/bin/env python3

import argparse
import datetime
import json
import os
import pandas as pd
from pprint import pprint
import statistics

class Row(dict):
    def __init__(self, *arguments, **keywords):
        super().__init__(*arguments, **keywords)

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
                        elif stem in ('heapsize', 'revision'):
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

class Benchmark(pd.DataFrame):
    def __getitem__(self, *arguments, **keywords):
        item = super().__getitem__(*arguments, **keywords)
        if type(item) == pd.DataFrame:
            item = Benchmark(item)
        return item

    def add_mean(self):
        def _valid_mean(self):
            a = self['valid_csl']
            b = self['valid_psl']
            if a is True and b is True:
                return pd.Series([True], index=['valid_mean'])
            elif a is False or b is False:
                return pd.Series([False], index=['valid_mean'])
            else:
                return pd.Series([None], index=['valid_mean'])
        self['cpu_mean'] = self[['cpu_csl', 'cpu_psl']].mean(axis=1)
        self['gc_mean'] = self[['gc_csl', 'gc_psl']].mean(axis=1)
        self['valid_mean'] = self.apply(_valid_mean, axis=1)
        return self

    def select(self, selectors):
        def matches(selector, column):
            if type(column) == tuple:
                return selector in column[1]
            else:
                return selector in column
        if type(selectors) == str:
            selectors = [selectors]
        selection = []
        for column in self.columns:
            for selector in selectors:
                if matches(selector, column):
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
    for row in rows:
        names.append(row["name"])
        del row["name"]
    df = pd.DataFrame(rows, names)
    columns = []
    for postfix in '_csl', '_psl':
        for stem in 'start', 'cpu', 'gc', 'heapsize', 'valid', 'end':
            columns.append(stem + postfix)
    benchmark = Benchmark(df[columns].sort_index())
    for path, directories, files in os.walk(os.path.join(root, 'GLOBAL')):
        for file_name in files:
            basename, extension = file_name.split('.')
            if extension != 'txt':
                continue
            with open(os.path.join(path, file_name)) as file:
                benchmark.attrs[basename] = file.read().rstrip()
    return benchmark

def combine2(a: Benchmark, b: Benchmark, *, keys: list = None):
    if keys is None:
        keys = ['r' + a.attrs['revision_csl'], 'r' + b.attrs['revision_csl']]
    return Benchmark(pd.concat([a, b], axis=1, keys=keys))

def dump_filetree(now: Benchmark, format: str, selectors, ref: Benchmark = None):
    benchmark = read_filetree(now).add_mean()

