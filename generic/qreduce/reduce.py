# ----------------------------------------------------------------------
# $Id$
# ----------------------------------------------------------------------
# Copyright (c) 2009 T. Sturm, 2010 T. Sturm, C. Zengler
# ----------------------------------------------------------------------
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#    * Redistributions of source code must retain the relevant
#      copyright notice, this list of conditions and the following
#      disclaimer.
#    * Redistributions in binary form must reproduce the above
#      copyright notice, this list of conditions and the following
#      disclaimer in the documentation and/or other materials provided
#      with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

import sys
import os

from PySide.QtCore import QObject
from PySide.QtCore import QSettings
from PySide.QtCore import QThread
from PySide.QtCore import QThread
from PySide.QtCore import Signal

from PySide.QtGui import QMessageBox

from qrlogging import signalLogger
from qrlogging import traceLogger

from qrdefaults import QtReduceDefaults

from RedPy import procNew, procDelete, ansNew, ansDelete


class Reduce(object):
    def __init__(self,reduce='../../bin/redpsl'):
        self.__process = procNew(sys.path[0] + "/" + reduce)
        self.__processId = self.__process['processId']
        self.__process = self.__process['handle']

    def __del__(self):
        procDelete(self.__process)

    def compute(self,c):
        a = ansNew(self.__process,c)
        ansDelete(a['handle'])
        return(a['data'])

    def signal(self,c):
        signalLogger.debug("c=%s" % c)
        os.system('/bin/kill -' + c + ' ' + str(self.__processId))


class QtReduce(QThread):
    # currently only works with 'object' type, not with 'ReduceComputation'
    startComputation = Signal(object)
    endComputation = Signal(object)

    def __init__(self,binary):
        QThread.__init__(self)
        self.reduce = Reduce(binary)
        self.computation = ReduceComputation()
        self.started.connect(self.startedHandler)
        self.finished.connect(self.finishedHandler)

    def initialize(self):
        self.compute("load_package utf8;",True)
        self.compute("on utf8;",True)
        self.compute("on utf8exp;",True)
        self.compute("off utf82d;",True)
        self.compute("on utf8pad;",True)
        self.compute('lisp procedure lr_aprint(u); mathprint u;',True)
        self.compute("lisp if 'psl memq lispsystem!* then remd 'break;",True)

    def startedHandler(self):
        self.startComputation.emit(self.computation)

    def finishedHandler(self):
        self.endComputation.emit(self.computation)

    def compute(self,c,silent=False):
        self.wait()
        traceLogger.debug("after wait, computing %s" % c)
        self.computation.evaluating = True
        self.computation.silent = silent
        self.computation.currentCommand = c
        self.start()

    def run(self):
        c = self.computation.currentCommand
        traceLogger.debug("computing %s" % c)
        a = self.reduce.compute(c)
        self.__processAnswer(a)
        self.computation.evaluating = False
        signalLogger.debug("emitting newReduceResult %s" % self.computation)

    def __processAnswer(self,a):
        self.computation.statCounter = a['statcounter']
        self.computation.symbolic = a['symbolic']
        self.computation.result = a['result']
        self.computation.nextPrompt = a['nextpompt']
        if a['error']:
            s = a['pretext'] or ''
            if s.find('Time:') != -1:
                l = s.split("Time:")
                l1 = l[-1].split("time:")
                a['time'] = int(l1[0].strip().split(" ")[0])
                if len(l1) != 1:
                    a['gctime'] = int(l1[-1].strip().split(" ")[0])
                s = ""
                for ss in l[:-1]:
                    s += ss
                s = s.strip()
            self.computation.errorText = s
        if a['time'] != -1:
            self.computation.time = a['time']
            self.computation.accTime += self.computation.time
        if a['gctime'] != -1:
            self.computation.gcTime = a['gctime']
            self.computation.accGcTime += self.computation.gcTime
        self.computation.error = a['error']

    def abortEvaluation(self):
        signalLogger.debug("entering")
        self.reduce.signal("SIGINT")


class ReduceComputation(QObject):

    def __init__(self):
        self.statCounter = 0
        self.currentCommand = None
        self.symbolic = False
        self.result = None
        self.nextPrompt = None
        self.time = 0
        self.gcTime = 0
        self.accTime = 0
        self.accGcTime = 0
        self.errorText = None
        self.error = False
        self.evaluating = False
        self.silent = False

    def __repr__(self):
        string = "[----\n\tReduce Computation " + str(self.statCounter)
        string += "\n\tCommand:\t" + str(self.currentCommand)
        string += "\n\tSymbolic:\t" + str(self.symbolic)
        string += "\n\tResult:\t\t" + str(self.result)
        string += "\n\tNext Prompt:\t" + str(self.nextPrompt)
        string += "\n\tTime:\t\t" + str(self.time)
        string += "\n\tGC Time:\t" + str(self.gcTime)
        string += "\n\tError Text:\t" + str(self.errorText)
        string += "\n\tError:\t\t" + str(self.error)
        string += "\n\tSilent:\t" + str(self.silent)
        string += "\n\tEvaluating:\t" + str(self.evaluating) + "\n----]"
        return string
