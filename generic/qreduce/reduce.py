#!/usr/bin/env python

# ----------------------------------------------------------------------
# $Id$
# ----------------------------------------------------------------------
# Copyright (c) 2009-2010 Thomas Sturm
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

from os import system

from PySide.QtCore import QThread
from PySide.QtCore import Signal
from PySide.QtCore import QObject

from RedPy import procNew, procDelete, ansNew, ansDelete


class Reduce(QThread):
    # currently only works with 'object' type, not with 'ReduceComputation' 
    startComputation = Signal(object)
    endComputation = Signal(object)
    
    def __init__(self,parent=None,reduce='../../bin/redpsl'):
        QThread.__init__(self)
        self.parent = parent
        self.process = procNew(reduce)
        self.processId = self.process['processId']
        self.process = self.process['handle']
        self.computation = ReduceComputation()
        
    def __del__(self):
        procDelete(self.process)

    def compute(self,c,silent=False):
        print "computing...."
        self.computation.evaluating = True
        if not silent:
            self.startComputation.emit(self.computation)
        self.wait()
        self.currentCommand = c
        self.silent = silent
        self.start()

    def run(self):
        c = self.currentCommand
        a = ansNew(self.process,c)
        ansDelete(a['handle'])
        self.__processAnswer(a['data'])
        self.computation.evaluating = False
        if not self.silent:
            print "emitting newReduceResult", self.computation
            self.endComputation.emit(self.computation)
        else:
            if self.computation.error:
                print "There was a problem initializing Reduce: ", self.computation

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
        system('/bin/kill -SIGINT ' + str(self.processId))

class ReduceComputation(QObject):
    
    def __init__(self):
        self.statCounter = 0
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

    def __repr__(self):
        string = "[----\n\tReduce Computation " + str(self.statCounter)
        string += "\n\tSymbolic:\t" + str(self.symbolic)
        string += "\n\tResult:\t\t" + str(self.result)
        string += "\n\tNext Prompt:\t" + str(self.nextPrompt)
        string += "\n\tTime:\t\t" + str(self.time)
        string += "\n\tGC Time:\t" + str(self.gcTime)
        string += "\n\tError Text:\t" + str(self.errorText)
        string += "\n\tError:\t\t" + str(self.error)
        string += "\n\tEvaluating:\t" + str(self.evaluating) + "\n----]"
        return string
