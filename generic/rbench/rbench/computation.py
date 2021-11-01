"""
Pandas-based data analytics for Reduce benchmarks
"""

___author___   = 'Thomas Sturm, http://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__   = 'CC BY-NC-ND'
___version___  = '$Rev$'

import datetime
import inspect
import os
import shutil
import subprocess
import sys

class Continue(Exception):
    pass

def _now():
    return datetime.datetime.now().astimezone().strftime('%Y-%m-%d %H:%M:%S%z')

def _log(msg: str, *, cwd: str = os.getcwd()):
    print(_now() + ' [' + cwd + '] ' + msg)

def _install_reduce(svn_reduce: str, revision: str, force: bool) -> str:
    def dump_and_exit(file_name: str, completed_process):
        if completed_process.stderr != b'':
            sys.stderr.write(completed_process.stderr.decode())
        sys.stderr.write('error: dumping command output to ' + file_name + ' and exiting' + os.linesep)
        with open(file_name, 'r') as file:
            file.write(completed_process.stdout.decode())
        sys.exit(completed_process.returncode)

    def checkout(rev: int, svn_reduce: str, force: bool):
        url = 'svn://svn.code.sf.net/p/reduce-algebra/code/trunk'
        sample_file = os.path.join(svn_reduce, 'packages/redlog/rl/redlog.red')
        if os.path.exists(svn_reduce):
            if force:
                shutil.rmtree(svn_reduce)
            else:
                sys.stderr.write('error: delete existing ' + svn_reduce + ' or use -f, --force' + os.linesep)
                sys.exit(17)
        cmd = ['svn', 'co', '-q', '-r', str(rev), url, svn_reduce]
        _log(' '.join(cmd))
        completed_process = subprocess.run(cmd, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('svn.log', completed_process)
        if not os.path.exists(sample_file):
            sys.stderr.write('error: missing sample file ' + sample_file)
            dump_and_exit('svn.log', completed_process)

    def configure(svn_reduce: str, lisp: str = 'both'):
        cmd = ['./configure', '--with-csl', '--without-gui']
        _log(' '.join(cmd), cwd=svn_reduce)
        completed_process = subprocess.run(cmd, cwd=svn_reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('configure.log', completed_process)
        cmd = ['./configure', '--with-psl']
        _log(' '.join(cmd), cwd=svn_reduce)
        completed_process = subprocess.run(cmd, cwd=svn_reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('configure.log', completed_process)
        completed_process = subprocess.run('./scripts/findhost.sh $(./config.guess)',
            shell=True, cwd=svn_reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('symlink.log', completed_process)
        host = completed_process.stdout.decode().rstrip()
        cslbuild = os.path.join(svn_reduce, 'cslbuild')
        cmd = ['ln', '-s', host + '-nogui', host]
        _log(' '.join(cmd), cwd=cslbuild)
        completed_process = subprocess.run(cmd, cwd=cslbuild)
        if completed_process.returncode != 0:
            dump_and_exit('symlink.log', completed_process)

    def compile(svn_reduce: str):
        cmd = ['make']
        _log(' '.join(cmd), cwd=svn_reduce)
        completed_process = subprocess.run(cmd, cwd=svn_reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('make.log', completed_process)

    checkout(revision, svn_reduce, force)
    configure(svn_reduce)
    compile(svn_reduce)

def _init_result(source: str, result: str, force: bool, verbose: bool, include: str, exclude: str,
        exclude_by_time: int, reduce: str) -> list:
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
    red_files = []
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
            red_files.append(rel_red_file)
    if not red_files:
        sys.stderr.write('warning: no benchmarks found, exiting' + os.linesep)
        sys.exit(0)
    return red_files

def _run_using_gnu_parallel(dry_run: bool, bar: bool, verbose: bool, jobs: int, reduce: str,
        psl_heapsize: int, source: str, result: str, red_files: list) -> str:
    def _parallel_command() -> str:
        _log('building GNU parallel command')
        parallel_args = ''
        if dry_run:
            parallel_args += ' --dry-run'
        parallel_args += ' --lb -j' + str(jobs)
        if bar:
            parallel_args += ' --bar'
        parallel_cmd = ' ' + os.path.join(os.path.dirname(__file__), 'bash_scripts', 'job.sh')
        parallel_cmd_args  = ' '
        if bar or not verbose:
            parallel_cmd_args += ' -q'
        one = 'csl psl'
        two = str(psl_heapsize)
        three = ' '.join(red_files)
        parallel_cmd_args += ' ' + os.path.join(reduce, 'bin', 'red{1}') + ' {2} ' + result + ' {3} ' + source
        parallel_cmd_args += ' ::: ' + one + ' ::: ' + two + ' ::: ' + three
        cmd = 'parallel' + parallel_args + parallel_cmd + parallel_cmd_args
        return cmd

    cmd = _parallel_command()
    if verbose:
        sys.stderr.write(cmd)
    _log('starting GNU parallel computation')
    subprocess.run(cmd, shell=True)
    _log('computation finished')

def run(source: str, result: str, force: bool = False, jobs: int = 1 , dry_run: bool = False,
        psl_heapsize: int = 4000, verbose: bool = False, bar: bool = False, exclude: str = None,
        include: str = None, exclude_by_time: int = None, reduce: str = None,
        svn_reduce: str = None, revision: str = None):
    """
    Run a Reduce benchmark set.
    """
    if exclude is not None and include is not None:
        raise ValueError('exclude and include are mutally exclusive')
    if reduce is not None and svn_reduce is not None:
        raise ValueError('reduce and svn_reduce are mutally exclusive')
    if reduce is None and svn_reduce is None:
        raise ValueError('one of reduce, svn_reduce must be specified')
    source = os.path.abspath(source)
    result = os.path.abspath(result)
    if reduce is not None:
        reduce = os.path.abspath(reduce)
    else:
        svn_reduce = os.path.abspath(svn_reduce)
        _install_reduce(svn_reduce, revision, force)
        reduce = svn_reduce
    red_files = _init_result(source=source, result=result, force=force, verbose=verbose,
        include=include, exclude=exclude, exclude_by_time=exclude_by_time, reduce=reduce)
    with open(os.path.join(result, 'GLOBAL', 'call.txt'), 'w') as file:
        myframe = inspect.currentframe()
        funcname = myframe.f_code.co_name
        file.write(funcname + inspect.formatargvalues(*inspect.getargvalues(myframe)))
    with open(os.path.join(result, 'GLOBAL', 'start.txt'), 'w') as file:
        file.write(_now())
    _run_using_gnu_parallel(dry_run=dry_run, bar=bar, verbose=verbose, jobs=jobs, reduce=reduce,
        psl_heapsize=psl_heapsize, source=source, result=result, red_files=red_files)
    with open(os.path.join(result, 'GLOBAL', 'end.txt'), 'w') as file:
        file.write(_now())
