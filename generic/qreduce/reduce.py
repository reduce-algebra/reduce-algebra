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

from PySide.QtCore import QThread
from PySide.QtCore import SIGNAL

from RedPy import procNew, procDelete, ansNew, ansDelete

class Reduce(QThread):
    def __init__(self,reduce='/Users/sturm/reduce/SourceForge/reduce-algebra/trunk/bin/redpsl'):
        QThread.__init__(self)
        self.process = procNew(reduce)
        self.time = 0
        self.gcTime = 0

    def __del__(self):
#        print "in Reduce.__del__"
        procDelete(self.process)

    def compute(self,c,silent=False):
        self.wait()
        self.currentCommand = c
        self.silent = silent
        self.start()

    def run(self):
        c = self.currentCommand
        a = ansNew(self.process,c)
        ansDelete(a['handle'])
        a = a['data']
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
            a['errortext'] = s
        if a['time'] != -1:
            self.time += a['time']
        if a['gctime'] != -1:
            self.gcTime += a['gctime']
        self.emit(SIGNAL("newReduceResult()"),a)
