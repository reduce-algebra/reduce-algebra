"""
Pandas-based data analytics for Reduce benchmarks
"""

___author___ = 'Thomas Sturm'
___contact___ = 'https://science.thomas-sturm.de/'
___copyright__ = 'Copyright 2021, Thomas Sturm, Germany'
___license__ = 'CC BY-NC-ND'
___version___ = '$Rev$'

import contextlib
import datetime
import inspect
import io
import logging
import os
import shutil
import subprocess
import sys
import tempfile

from . import analytics
from . import html

formatter = logging.Formatter('%(asctime)s - %(levelname)s - %(message)s')

stderr_handler = logging.StreamHandler(stream=sys.stderr)
stderr_handler.setLevel(0)
stderr_handler.setFormatter(formatter)

logger = logging.getLogger(__name__)
logger.setLevel(logging.WARNING)
logger.addHandler(stderr_handler)

def _now():
    return datetime.datetime.now().astimezone().strftime('%Y-%m-%d %H:%M:%S%z')

def _install_reduce(svn_reduce: str, revision: str, force: bool) -> str:
    def dump_and_exit(file_name: str, completed_process):
        if completed_process.stderr != b'':
            logger.critical(completed_process.stderr.decode())
        logger.critical('dumping command output to ' + file_name + ' and exiting')
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
                logger.critical('found existing ' + svn_reduce + ' - delete or use -f, --force')
                sys.exit(17)
        cmd = ['svn', 'co', '-q', '-r', str(rev), url, svn_reduce]
        logger.info(' '.join(cmd))
        completed_process = subprocess.run(cmd, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('svn.log', completed_process)
        if not os.path.exists(sample_file):
            logger.critical('missing sample file ' + sample_file)
            dump_and_exit('svn.log', completed_process)

    def configure(svn_reduce: str, lisp: str = 'both'):
        cmd = ['./configure', '--with-csl', '--without-gui']
        logger.info(' '.join(cmd) + ' in ' + svn_reduce)
        completed_process = subprocess.run(cmd, cwd=svn_reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('configure.log', completed_process)
        cmd = ['./configure', '--with-psl']
        logger.info(' '.join(cmd) + ' in ' + svn_reduce)
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
        logger.info(' '.join(cmd) + ' in ' + cslbuild)
        completed_process = subprocess.run(cmd, cwd=cslbuild)
        if completed_process.returncode != 0:
            dump_and_exit('symlink.log', completed_process)

    def compile(svn_reduce: str):
        cmd = ['make']
        logger.info(' '.join(cmd) + ' in ' + svn_reduce)
        completed_process = subprocess.run(cmd, cwd=svn_reduce, capture_output=True)
        if completed_process.returncode != 0:
            dump_and_exit('make.log', completed_process)

    checkout(revision, svn_reduce, force)
    configure(svn_reduce)
    compile(svn_reduce)

def _init_result(source: str, result: str, force: bool, include: str, exclude: str,
                 exclude_by_time: int, reduce: str) -> list:
    class Continue(Exception):
        pass
    logger.info('initializing RESULT directory ' + result)
    if os.path.exists(result):
        if force:
            shutil.rmtree(result)
        else:
            logger.critical('found existing ' + result + ' - delete or use -f, --force')
            sys.exit(17)
    os.makedirs(os.path.join(result, 'GLOBAL'))
    completed_process = subprocess.run(['svnversion'], cwd=reduce, capture_output=True)
    revision = completed_process.stdout.decode()
    if ':' in revision:
        _, revision = revision.split(':')
    with open(os.path.join(result, 'GLOBAL', 'revision.txt'), 'w') as file:
        file.write(revision)
    with open(os.path.join(result, 'GLOBAL', 'uname.txt'), 'w') as file:
        subprocess.run(['uname', '-mnrs'], stdout=file)
    red_files = []
    for path, directories, files in os.walk(source):
        relpath = os.path.relpath(path, source)
        for directory in directories:
            if directory == 'SUPPORT':
                shutil.copytree(os.path.join(path, directory), os.path.join(result, relpath, directory),
                    dirs_exist_ok=True)
                directories.remove(directory)
                break
        for file in files:
            try:
                basename, extension = file.split('.')
            except ValueError:
                continue
            if extension != "red":
                continue
            source_red_file = os.path.join(path, file)
            red_file = os.path.join(relpath, file)
            result_red_file = os.path.join(result, relpath, file)
            if basename != os.path.basename(relpath):
                logger.warning('skipping ' + red_file + ' - basename does not match directory name')
                continue
            if include is not None and include not in red_file:
                logger.debug('  -' + red_file)
                continue
            if exclude is not None and exclude in red_file:
                logger.debug('x -' + red_file)
                continue
            if exclude_by_time:
                try:
                    for lisp in 'csl', 'psl':
                        cpu_file = 'cpu_' + lisp + '.txt'
                        source_cpu_file = os.path.join(path, cpu_file)
                        if os.path.exists(source_cpu_file):
                            with open(source_cpu_file, 'r') as file:
                                if int(file.read().rstrip()) > 1000 * exclude_by_time:
                                    logger.debug('t -' + red_file)
                                    raise Continue
                        else:
                            logger.warning('ignoring exclude_by_time for ' + red_file + ' - ' +
                                           cpu_file + ' does not exist')
                            break
                except Continue:
                    continue
            if include:
                logger.debug('i +' + red_file)
            else:
                logger.debug('  +' + red_file)
            os.makedirs(os.path.join(result, relpath), exist_ok=True)
            shutil.copy(source_red_file, result_red_file)
            source_pslheap_file = os.path.join(path, basename + '.pslheap')
            result_pslheap_file = os.path.join(result, relpath, basename + '.pslheap')
            if os.path.exists(source_pslheap_file):
                shutil.copy(source_pslheap_file, result_pslheap_file)
            red_files.append(red_file)
    if not red_files:
        logger.warning('no benchmarks found, exiting')
        sys.exit(0)
    return red_files

def _run_using_gnu_parallel(dry_run: bool, bar: bool, jobs: int, reduce: str, psl_heapsize: int,
                            source: str, result: str, red_files: list) -> str:
    def _parallel_command() -> str:
        logger.info('building GNU parallel command')
        parallel_args = ''
        if dry_run:
            parallel_args += ' --dry-run'
        parallel_args += ' --lb -j' + str(jobs)
        if bar:
            parallel_args += ' --bar'
        parallel_cmd = ' ' + os.path.join(os.path.dirname(__file__), 'bash_scripts', 'job.sh')
        parallel_cmd_args  = ' '
        if bar or logger.getEffectiveLevel() > logging.DEBUG:
            parallel_cmd_args += ' -q'
        one = 'csl psl'
        two = str(psl_heapsize)
        three = ' '.join(red_files)
        parallel_cmd_args += ' ' + os.path.join(reduce, 'bin', 'red{1}') \
                             + ' {2} ' + result + ' {3} ' + source
        parallel_cmd_args += ' ::: ' + one + ' ::: ' + two + ' ::: ' + three
        cmd = 'parallel' + parallel_args + parallel_cmd + parallel_cmd_args
        return cmd

    cmd = _parallel_command()
    logger.debug(cmd)
    logger.info('starting GNU parallel computation')
    subprocess.run(cmd, shell=True)
    logger.info('computation finished')

def cron(source: str, result: str, force: bool = False, jobs: int = 1, psl_heapsize: int = 4000,
         log: str = 'info', exclude: str = None, include: str = None, exclude_by_time: int = None,
         reduce: str = None, svn_reduce: str = None, revision: str = None):
    stderr_log = io.StringIO()
    formatter = logging.Formatter('<tr><td class="timestamp">%(asctime)s</td>'
                                  '<td class="level">%(levelname)s</td>'
                                  '<td>%(message)s</td></tr>')
    handler = logging.StreamHandler(stream=stderr_log)
    handler.setLevel(0)
    handler.setFormatter(formatter)
    logger.addHandler(handler)
    logger.removeHandler(stderr_handler)
    try:
        run(source=source,
            result=result,
            force=force,
            jobs=jobs,
            dry_run=False,
            psl_heapsize=psl_heapsize,
            log=log,
            bar=False,
            exclude=exclude,
            include=include,
            exclude_by_time=exclude_by_time,
            reduce=reduce,
            svn_reduce=svn_reduce,
            revision=revision)
    except:
        logger.addHandler(stderr_handler)
        logger.removeHandler(handler)
        raise
    else:
        logger.addHandler(stderr_handler)
        logger.removeHandler(handler)
    print(html.begin)
    analytics.summary(now=result,
                      dump=True,
                      full_html=False)
    print(html.h3('Computation Log'))
    level = logger.getEffectiveLevel()
    level_name = logging.getLevelName(level)
    print(html.p(html.logger_table(stderr_log.getvalue().rstrip())))
    print(html.p('Logging level was {} ({:d}).'.format(level_name, level)))
    print(html.end)


def run(source: str, result: str, force: bool = False, jobs: int = 1, dry_run: bool = False,
        psl_heapsize: int = 4000, log: str = 'warning', bar: bool = False, exclude: str = None,
        include: str = None, exclude_by_time: int = None, reduce: str = None,
        svn_reduce: str = None, revision: str = None):
    """
    Run a Reduce benchmark set.
    """
    logger.setLevel(getattr(logging, log.upper()))
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
    red_files = _init_result(source=source, result=result, force=force, include=include,
        exclude=exclude, exclude_by_time=exclude_by_time, reduce=reduce)
    with open(os.path.join(result, 'GLOBAL', 'call.txt'), 'w') as file:
        myframe = inspect.currentframe()
        funcname = myframe.f_code.co_name
        file.write(funcname + inspect.formatargvalues(*inspect.getargvalues(myframe)))
    with open(os.path.join(result,'GLOBAL', 'source.txt'), 'w') as file:
        file.write(source)
    with open(os.path.join(result, 'GLOBAL', 'start.txt'), 'w') as file:
        file.write(_now())
    _run_using_gnu_parallel(dry_run=dry_run, bar=bar, jobs=jobs, reduce=reduce,
        psl_heapsize=psl_heapsize, source=source, result=result, red_files=red_files)
    with open(os.path.join(result, 'GLOBAL', 'end.txt'), 'w') as file:
        file.write(_now())
