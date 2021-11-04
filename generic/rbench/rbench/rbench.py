#!/usr/bin/env python3

"""
Pandas-based data analytics for Reduce benchmarks

A script interface to rbench. Supports automated parallel computation of
benchmark sets, cron jobs, and generation and display of an HTML
summary.
"""

___author___ = 'Thomas Sturm'
___contact___ = 'https://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__ = 'CC BY-NC-ND'
___version___ = '$Rev$'

import argparse
import os
import sys

import analytics
import computation

def setup_parser(parser):
    subparsers = parser.add_subparsers(dest='subcommand', help='sub-commands')
    parser_cron = subparsers.add_parser(
        'cron',
        help='Combine run and summary for use in cron jobs',
        description='Combine run and summary for use in cron jobs')
    setup_parser_cron(parser_cron)
    parser_run = subparsers.add_parser(
        'run',
        help='Run a Reduce benchmark set',
        description='Run a Reduce benchmark set')
    setup_parser_run(parser_run)
    parser_summary = subparsers.add_parser(
        'summary',
        help='Create an HTML summary comapring two benchmark runs.',
        description='Create an HTML summary comapring two benchmark runs. The summary is written '
                    'to NOW/summary.html')
    setup_parser_summary(parser_summary)

def setup_parser_cron(parser):
    """
    Subparser for bench.py cron ...
    """
    _add_source(parser)
    _add_result(parser)
    _add_force(parser)
    _add_jobs(parser)
    _add_psl_heapsize(parser)
    _add_log_cron(parser)
    _addgroup_incl_excl(parser)
    _add_exclude_by_time(parser)
    _addgroup_reduce(parser)
    _add_revision(parser)

def setup_parser_run(parser):
    """
    Subparser for bench.py run ...
    """
    _add_source(parser)
    _add_result(parser)
    _add_force(parser)
    _add_jobs(parser)
    _add_dry_run(parser)
    _add_psl_heapsize(parser)
    _add_log_run(parser)
    _add_bar(parser)
    _addgroup_incl_excl(parser)
    _add_exclude_by_time(parser)
    _addgroup_reduce(parser)
    _add_revision(parser)

def setup_parser_summary(parser):
    """
    Subparser for bench.py summary ...
    """
    _add_now(parser)
    _add_dump(parser)
    _add_display(parser)
    _add_ref(parser)

def _add_source(parser):
    parser.add_argument(
        'source', metavar='SOURCE',
        type=str,
        help=('An existing benchmark directory. *.red files are used as input. If present, '
                '*.pslheap is used to override --psl-heapsize SIZE, '
                'and rlg_csl.txt and rlg_psl.txt are used for comparison'))

def _add_result(parser):
    parser.add_argument(
        'result', metavar='RESULT',
        help='The benchmark directory to be created. *.red and *.pslheap are copied from SOURCE')

def _add_force(parser):
    parser.add_argument(
        '-f', '--force',
        action='store_true',
        help=("Overwrite existing directories specified via '--svn-reduce DIR' and 'RESULT' "
                "without prompting for confirmation"))

def _add_jobs(parser):
    parser.add_argument(
        '-j', '--jobs', metavar='N',
        type=int,
        default=1,
        help='Run up to N jobs in parallel')

def _add_dry_run(parser):
    parser.add_argument(
        '-n', '--dry-run',
        action='store_true',
        help=('Pass --dry-run on to to generated GNU parallel command. '
                'Note that RESULT is still generated and initialized with input'))

def _add_psl_heapsize(parser):
    parser.add_argument(
        '-td', '--psl-heapsize', metavar='SIZE',
        type=int,
        default=4000,
        help='Allocate SIZE MiB for PSL heap(s)')

def _add_log_cron(parser):
    parser.add_argument(
        '--log',
        choices=['debug', 'info', 'warning', 'error', 'critical'],
        default='info',
        help=('Report benchmarks found: +, - indicate inclusion, exclusion, '
                'i, e, t stand for --include, --exclude, --exclude-by-time, respectively. '
                'The generated GNU parallel command is printed before execution'))

def _add_log_run(parser):
    parser.add_argument(
        '--log',
        choices=['debug', 'info', 'warning', 'error', 'critical'],
        default='warning',
        help=('Report benchmarks found: +, - indicate inclusion, exclusion, '
                'i, e, t stand for --include, --exclude, --exclude-by-time, respectively. '
                'The generated GNU parallel command is printed before execution'))

def _add_bar(parser):
    parser.add_argument(
        '--bar',
        action='store_true',
        help='Show progress as a progress bar')

def _addgroup_incl_excl(parser):
    incl_excl_group = parser.add_mutually_exclusive_group()
    incl_excl_group.add_argument(
        '--exclude', metavar='SUBSTRING',
        type=str,
        help='Exclude benchmarks containing SUBSTRING')
    incl_excl_group.add_argument(
        '--include', metavar='SUBSTRING',
        type=str,
        help='Include only benchmarks containing SUBSTRING')

def _add_exclude_by_time(parser):
    parser.add_argument(
        '--exclude-by-time', metavar='SECONDS',
        type=int,
        help=('Exclude benchmarks with a cpu time record (cpu_csl.txt, cpu_psl.txt) larger than '
                'SECONDS in SOURCE'))

def _addgroup_reduce(parser):
    reduce_group = parser.add_mutually_exclusive_group(required = True)
    reduce_group.add_argument(
        '--reduce', metavar='DIR',
        type=str,
        help='Use existing Reduce directory DIR')
    reduce_group.add_argument(
        '--svn-reduce', metavar='DIR',
        type=str,
        help='svn check out into DIR, compile, and use as Reduce directory')

def _add_revision(parser):
    parser.add_argument(
        '-r', '--revision', metavar='REV',
        type=str,
        default='HEAD',
        help='Check out SVN revision REV instead of HEAD')

def _add_ref(parser):
    parser.add_argument(
        '-r', '--ref', metavar='REF',
        help="Reference directory for comparison. If REF is not specified and "
             "NOW is the RESULT of some 'rbench.py run SOURCE RESULT' and the "
             "corresponding SOURCE still exsists, then RED defaults to that SOURCE.")

def _add_now(parser):
    parser.add_argument(
        'now', metavar='NOW',
        help="Directory with benchmark results, typically obtained as RESULT from 'rbench.py run'")

def _add_dump(parser):
    parser.add_argument(
        '-d', '--dump',
        action='store_true',
        help='Dump the generated NOW/summary.html to stdout')

def _add_display(parser):
    parser.add_argument(
        '-y', '--display',
        action='store_true',
        help='Open the generated NOW/summary.html in the default web browser')

def cron(args):
    computation.cron(source=args.source,
                     result=args.result,
                     force=args.force,
                     jobs=args.jobs,
                     psl_heapsize=args.psl_heapsize,
                     log=args.log,
                     exclude=args.exclude,
                     include=args.include,
                     exclude_by_time=args.exclude_by_time,
                     reduce=args.reduce,
                     svn_reduce=args.svn_reduce,
                     revision=args.revision)

def run(args):
    computation.run(source=args.source,
                    result=args.result,
                    force=args.force,
                    jobs=args.jobs,
                    dry_run=args.dry_run,
                    psl_heapsize=args.psl_heapsize,
                    log=args.log,
                    bar=args.bar,
                    exclude=args.exclude,
                    include=args.include,
                    exclude_by_time=args.exclude_by_time,
                    reduce=args.reduce,
                    svn_reduce=args.svn_reduce,
                    revision=args.revision)

def summary(args):
    analytics.summary(ref=args.ref,
                      now=args.now,
                      display=args.display,
                      dump=args.dump,
                      full_html=True)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='rbench.py')
    setup_parser(parser)
    args = parser.parse_args()
    if args.subcommand is None:
        sys.stderr.write("Type 'rbench.py -h' for usage." + os.linesep)
    elif args.subcommand == 'cron':
        cron(args)
    elif args.subcommand == 'run':
        run(args)
    elif args.subcommand == 'summary':
        summary(args)
    sys.exit(0)
