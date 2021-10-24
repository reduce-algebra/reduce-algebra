#!/usr/bin/env python3

import argparse
import os
import shutil
import subprocess
import sys

class Continue(Exception):
    pass

def parse_args():
    parser = argparse.ArgumentParser(description='Run Reduce benchmarks')
    parser.add_argument('ref', metavar='SOURCE', help='a directory containing benchmark sources')
    parser.add_argument('now', metavar='RESULT',
        help='the root of the result tree; will be created if it does not exist')
    parser.add_argument('-f', '--force', action='store_true',
        help="overwrite existing --svn-reduce DIR and RESULT without prompting for confirmation")
    parser.add_argument('-j', '--jobs', metavar='N', type=int, default=1,
        help='run up to N jobs in parallel')
    parser.add_argument('-n', '--dry-run', action='store_true',
        help='pass --dry-run on to generated parallel command; note that the NOW tree is generated')
    parser.add_argument('-td', '--psl-heapsize', metavar="SIZE", default=4000,
        help='allocate SIZE MiB for PSL heap(s)')
    parser.add_argument('-v', '--verbose', action='store_true',
        help=('report benchmarks found: +, - indicate inclusion, exclusion, '
              'i, e, t stand for --include, --exclude, --exclude-by-time, respectively; '
              'the generated parallel command is printed before execution'))
    parser.add_argument('--bar', action='store_true', help='show progress as a progress bar')
    incl_excl_group = parser.add_mutually_exclusive_group()
    incl_excl_group.add_argument('--exclude', metavar="SUBSTRING", type=str,
        help='exclude benchmarks containing SUBSTRING')
    incl_excl_group.add_argument('--include', metavar="SUBSTRING", type=str,
        help='include only benchmarks containing SUBSTRING')
    parser.add_argument('--exclude-by-time', metavar='SECONDS', type=int,
        help='exclude benchmarks with a cpu time record larger than SECONDS in SOURCE')
    reduce_group = parser.add_mutually_exclusive_group(required=True)
    reduce_group.add_argument('--reduce', metavar='DIR', type=str,
        help='use existing reduce DIR')
    reduce_group.add_argument('--svn-reduce', metavar='DIR', type=str,
        help='svn check out into DIR, compile, and use')
    parser.add_argument('-r', '--revision', metavar='REF', type=str,
        help='use svn revision REV instead of HEAD')
    return parser.parse_args()

def init_now_dir(ref: str, now: str, force: bool, include: str, exclude: str, timelimit: int, verbose: bool) -> list:
    if os.path.exists(now):
        if force:
            shutil.rmtree(now)
        else:
            sys.stderr.write('error: delete existing ' + now + ' or use -f, --force' + os.linesep)
            exit(1)
    os.makedirs(os.path.join(now, 'GLOBAL'))
    for lisp in 'csl', 'psl':
        with open(os.path.join(now, 'GLOBAL', 'revision_' + lisp + '.txt'), 'w') as file:
            subprocess.run(['svn', 'info', '--show-item', 'revision', os.path.join(bin, 'red' + lisp)], stdout=file)
    with open(os.path.join(now, 'GLOBAL', 'uname.txt'), 'w') as file:
        subprocess.run(['uname', '-mnrs'], stdout=file)
    rel_red_files = []
    for path, directories, files in os.walk(ref):
        relpath = os.path.relpath(path, ref)
        for file in files:
            try:
                basename, extension = file.split('.')
            except ValueError:
                continue
            if extension != "red":
                continue
            ref_red_file = os.path.join(path, file)
            rel_red_file = os.path.join(relpath, file)
            now_red_file = os.path.join(now, relpath, file)
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
            if timelimit:
                try:
                    for lisp in 'csl', 'psl':
                        cpu_file = 'cpu_' + lisp + '.txt'
                        ref_cpu_file = os.path.join(path, cpu_file)
                        if os.path.exists(ref_cpu_file):
                            with open(ref_cpu_file, 'r') as file:
                                if int(file.read().rstrip()) > 1000 * timelimit:
                                    if verbose:
                                        sys.stderr.write('- t ' + rel_red_file + os.linesep)
                                    raise Continue
                        else:
                            sys.stderr.write('warning: ignoring timelimit for ' + rel_red_file +
                                             ' - ' + cpu_file + ' does not exist' + os.linesep)
                            break
                except Continue:
                    continue
            if verbose:
                if include:
                    sys.stderr.write('+ i ' + rel_red_file + os.linesep)
                else: 
                    sys.stderr.write('+   ' + rel_red_file + os.linesep)
            os.makedirs(os.path.join(now, relpath), exist_ok=True)
            shutil.copy(ref_red_file, now_red_file)
            ref_pslheap_file = os.path.join(path, basename + '.pslheap')
            now_pslheap_file = os.path.join(now, relpath, basename + '.pslheap')
            if os.path.exists(ref_pslheap_file):
                shutil.copy(ref_pslheap_file, now_pslheap_file)
            rel_red_files.append(rel_red_file)
    if not rel_red_files:
        sys.stderr.write('warning: no benchmarks found, exiting' + os.linesep)
        exit(0)
    return rel_red_files

def build_parallel_command(dry_run: bool, bar: bool, jobs: int, reduce: str, psl_heapsize: int, ref: str, now: str, rel_red_files: list) -> str:
    parallel_args = ''
    if dry_run:
        parallel_args += ' --dry-run'
    parallel_args += ' --lb -j' + str(jobs)
    if bar:
        parallel_args += ' --bar'
    parallel_cmd = ' benchmark-job.sh'
    parallel_cmd_args  = ' '
    if bar:
        parallel_cmd_args += ' -q'
    one = 'csl psl'
    two = str(psl_heapsize)
    three = ' '.join(rel_red_files)
    parallel_cmd_args += ' ' + os.path.join(reduce, bin, 'red{1}') + ' {2} ' + now + ' {3} ' + ref
    parallel_cmd_args += ' ::: ' + one + ' ::: ' + two + ' ::: ' + three
    cmd = 'parallel' + parallel_args + parallel_cmd + parallel_cmd_args
    return cmd

if __name__ == '__main__':
    args = parse_args()
    reduce = os.path.abspath(args.reduce)
    ref = os.path.abspath(args.ref)
    now = os.path.abspath(args.now)
    rel_red_files = init_now_dir(ref, now, args.force, args.include, args.exclude, args.timelimit, args.verbose)
    cmd = build_parallel_command(args.dry_run, args.bar, args.jobs, reduce, args.psl_heapsize, ref, now, rel_red_files)
    if args.verbose:
        sys.stderr.write(cmd)
    with open(os.path.join(now, 'GLOBAL', 'start.txt'), 'w') as file:
        subprocess.run(['date', '-R'], stdout=file)
    subprocess.run(cmd, shell=True)
    with open(os.path.join(now, 'GLOBAL', 'end.txt'), 'w') as file:
        subprocess.run(['date', '-R'], stdout=file)
