#!/usr/bin/env python3

import argparse
from datetime import datetime
import os
import pprint
import shutil
import subprocess
import sys

class Continue(Exception):
    pass

def _log(msg: str, *, cwd: str = os.getcwd()):
    print(datetime.now().strftime('%Y-%m-%d %H:%M:%S') + ' [' + cwd + '] ' + msg)

def setup_parser(parser):
    parser.add_argument(
        'source', metavar='SOURCE',
        help=('An existing benchmark directory. *.red files are used as input. If present, '
              '*.pslheap is used to override --psl-heapsize SIZE, '
              'and rlg_csl.txt and rlg_psl.txt are used for comparison'))
    parser.add_argument(
        'result', metavar='RESULT',
        help='The benchmark directory to be created. *.red and *.pslheap are copied from SOURCE')
    parser.add_argument(
        '-f', '--force',
        action='store_true',
        help=('Overwrite existing directories specified via \'--svn-reduce DIR\' and \'RESULT\' '
              'without prompting for confirmation'))
    parser.add_argument(
        '-j', '--jobs', metavar='N',
        type=int, default=1,
        help='Run up to N jobs in parallel')
    parser.add_argument(
        '-n', '--dry-run',
        action='store_true',
        help=('Pass --dry-run on to to generated GNU parallel command. '
              'Note that RESULT is still generated and initialized with input'))
    parser.add_argument('-td', '--psl-heapsize', metavar="SIZE",
        default=4000,
        help='Allocate SIZE MiB for PSL heap(s)')
    parser.add_argument('-v', '--verbose',
        action='store_true',
        help=('Report benchmarks found: +, - indicate inclusion, exclusion, '
              'i, e, t stand for --include, --exclude, --exclude-by-time, respectively. '
              'The generated GNU parallel command is printed before execution'))
    parser.add_argument('--bar',
        action='store_true',
        help='Show progress as a progress bar')
    incl_excl_group = parser.add_mutually_exclusive_group()
    incl_excl_group.add_argument(
        '--exclude', metavar="SUBSTRING",
        type=str,
        help='Exclude benchmarks containing SUBSTRING')
    incl_excl_group.add_argument(
        '--include', metavar="SUBSTRING",
        type=str,
        help='Include only benchmarks containing SUBSTRING')
    parser.add_argument(
        '--exclude-by-time', metavar='SECONDS',
        type=int,
        help=('Exclude benchmarks with a cpu time record (cpu_csl.txt, cpu_psl.txt) larger than '
              'SECONDS in SOURCE'))
    reduce_group = parser.add_mutually_exclusive_group(
        required=True)
    reduce_group.add_argument(
        '--reduce', metavar='DIR',
        type=str,
        help='Use existing Reduce directory DIR')
    reduce_group.add_argument(
        '--svn-reduce', metavar='DIR',
        type=str,
        help='svn check out into DIR, compile, and use as Reduce directory')
    parser.add_argument(
        '-r', '--revision', metavar='REV',
        type=str,
        default='HEAD',
        help='Check out SVN revision REV instead of HEAD')

def setup_reduce(reduce: str, svn_reduce: str, revision: str, force: bool) -> str:
    def dump_and_exit(file_name: str, completed_process):
        if completed_process.stderr != b'':
            sys.stderr.write(completed_process.stderr.decode())
        sys.stderr.write('error: dumping command output to ' + file_name + ' and exiting' + os.linesep)
        with open(file_name, 'r') as file:
            file.write(completed_process.stdout.decode())
        sys.exit(completed_process.returncode)

    def checkout(rev: str, reduce: str, force: bool):
        url = 'svn://svn.code.sf.net/p/reduce-algebra/code/trunk'
        sample_file = os.path.join(reduce, 'packages/redlog/rl/redlog.red')
        if os.path.exists(reduce):
            if force:
                shutil.rmtree(reduce)
            else:
                sys.stderr.write('error: delete existing ' + reduce + ' or use -f, --force' + os.linesep)
                sys.exit(17)
        cmd = ['svn', 'co', '-q', '-r', rev, url, reduce]
        _log(' '.join(cmd))
        completed_process = subprocess.run(cmd, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('svn.log', completed_process)
        if not os.path.exists(sample_file):
            sys.stderr.write('error: missing sample file ' + sample_file)
            dump_and_exit('svn.log', completed_process)

    def configure(reduce: str, lisp: str = 'both'):
        cmd = ['./configure', '--with-csl', '--without-gui']
        _log(' '.join(cmd), cwd=reduce)
        completed_process = subprocess.run(cmd, cwd=reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('configure.log', completed_process)
        cmd = ['./configure', '--with-psl']
        _log(' '.join(cmd), cwd=reduce)
        completed_process = subprocess.run(cmd, cwd=reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('configure.log', completed_process)
        completed_process = subprocess.run('./scripts/findhost.sh $(./config.guess)',
            shell=True, cwd=reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('symlink.log', completed_process)
        host = completed_process.stdout.decode().rstrip()
        cslbuild = os.path.join(reduce, 'cslbuild')
        cmd = ['ln', '-s', host + '-nogui', host]
        _log(' '.join(cmd), cwd=cslbuild)
        completed_process = subprocess.run(cmd, cwd=cslbuild)
        if completed_process.returncode != 0:
            dump_and_exit('symlink.log', completed_process)

    def compile(reduce: str):
        _log('make', cwd=reduce)
        completed_process = subprocess.run(['make'], cwd=reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('make.log', completed_process)

    if reduce is not None:
        return os.path.abspath(reduce)
    reduce = os.path.abspath(svn_reduce)
    checkout(revision, reduce, force)
    configure(reduce)
    compile(reduce)
    return reduce

def init_result_dir(source: str, result: str, force: bool, include: str, exclude: str, exclude_by_time: int, reduce: str, verbose: bool) -> list:
    _log('initializing RESULT directory ' + result)
    if os.path.exists(result):
        if force:
            shutil.rmtree(result)
        else:
            sys.stderr.write('error: delete existing ' + result + ' or use -f, --force' + os.linesep)
            sys.exit(17)
    os.makedirs(os.path.join(result, 'GLOBAL'))
    with open(os.path.join(result, 'GLOBAL', 'revision.txt'), 'w') as file:
        subprocess.run(['svn', 'info', '--show-item', 'revision', reduce], stdout=file)
    with open(os.path.join(result, 'GLOBAL', 'uname.txt'), 'w') as file:
        subprocess.run(['uname', '-mnrs'], stdout=file)
    rel_red_files = []
    for path, directories, files in os.walk(source):
        relpath = os.path.relpath(path, source)
        for file in files:
            try:
                basename, extension = file.split('.')
            except ValueError:
                continue
            if extension != "red":
                continue
            source_red_file = os.path.join(path, file)
            rel_red_file = os.path.join(relpath, file)
            result_red_file = os.path.join(result, relpath, file)
            if basename != os.path.basename(relpath):
                sys.stderr.write('warning: skipping ' + rel_red_file +
                                 ' - basename does not match directory name' + os.linesep)
                continue
            if include is not None and include not in rel_red_file:
                if verbose:
                    sys.stderr.write('-   ' + rel_red_file + os.linesep)
                continue
            if exclude is not None and exclude in rel_red_file:
                if verbose:
                    sys.stderr.write('- x ' + rel_red_file + os.linesep)
                continue
            if exclude_by_time:
                try:
                    for lisp in 'csl', 'psl':
                        cpu_file = 'cpu_' + lisp + '.txt'
                        source_cpu_file = os.path.join(path, cpu_file)
                        if os.path.exists(source_cpu_file):
                            with open(source_cpu_file, 'r') as file:
                                if int(file.read().rstrip()) > 1000 * exclude_by_time:
                                    if verbose:
                                        sys.stderr.write('- t ' + rel_red_file + os.linesep)
                                    raise Continue
                        else:
                            sys.stderr.write('warning: ignoring exclude_by_time for ' + rel_red_file +
                                             ' - ' + cpu_file + ' does not exist' + os.linesep)
                            break
                except Continue:
                    continue
            if verbose:
                if include:
                    sys.stderr.write('+ i ' + rel_red_file + os.linesep)
                else: 
                    sys.stderr.write('+   ' + rel_red_file + os.linesep)
            os.makedirs(os.path.join(result, relpath), exist_ok=True)
            shutil.copy(source_red_file, result_red_file)
            source_pslheap_file = os.path.join(path, basename + '.pslheap')
            result_pslheap_file = os.path.join(result, relpath, basename + '.pslheap')
            if os.path.exists(source_pslheap_file):
                shutil.copy(source_pslheap_file, result_pslheap_file)
            rel_red_files.append(rel_red_file)
    if not rel_red_files:
        sys.stderr.write('warning: no benchmarks found, exiting' + os.linesep)
        sys.exit(0)
    return rel_red_files

def build_parallel_command(dry_run: bool, bar: bool, verbose: bool, jobs: int, reduce: str, psl_heapsize: int, source: str, result: str, rel_red_files: list) -> str:
    _log('building GNU parallel command')
    parallel_args = ''
    if dry_run:
        parallel_args += ' --dry-run'
    parallel_args += ' --lb -j' + str(jobs)
    if bar:
        parallel_args += ' --bar'
    parallel_cmd = ' benchmark-job.sh'
    parallel_cmd_args  = ' '
    if bar or not verbose:
        parallel_cmd_args += ' -q'
    one = 'csl psl'
    two = str(psl_heapsize)
    three = ' '.join(rel_red_files)
    parallel_cmd_args += ' ' + os.path.join(reduce, 'bin', 'red{1}') + ' {2} ' + result + ' {3} ' + source
    parallel_cmd_args += ' ::: ' + one + ' ::: ' + two + ' ::: ' + three
    cmd = 'parallel' + parallel_args + parallel_cmd + parallel_cmd_args
    return cmd

def benchmark_run(args):
    reduce = setup_reduce(args.reduce, args.svn_reduce, args.revision, args.force)
    source = os.path.abspath(args.source)
    result = os.path.abspath(args.result)
    rel_red_files = init_result_dir(source, result, args.force, args.include, args.exclude, args.exclude_by_time, reduce, args.verbose)
    with open(os.path.join(result, 'GLOBAL', 'parse_args.txt'), 'w') as file:
        file.write(str(args))
    parallel_cmd = build_parallel_command(args.dry_run, args.bar, args.verbose, args.jobs, reduce, args.psl_heapsize, source, result, rel_red_files)
    if args.verbose:
        sys.stderr.write(parallel_cmd)
    _log('starting computation')
    with open(os.path.join(result, 'GLOBAL', 'start.txt'), 'w') as file:
        subprocess.run(['date', '-R'], stdout=file)
    subprocess.run(parallel_cmd, shell=True)
    with open(os.path.join(result, 'GLOBAL', 'end.txt'), 'w') as file:
        subprocess.run(['date', '-R'], stdout=file)
    _log('computation finished')
