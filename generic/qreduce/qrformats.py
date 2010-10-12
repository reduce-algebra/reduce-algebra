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

from PySide.QtCore import Qt

from PySide.QtGui import QTextBlockFormat
from PySide.QtGui import QColor
from PySide.QtGui import qRgb
from PySide.QtGui import QTextCharFormat
from PySide.QtGui import QTextBlockUserData

# 0 = Input
# 1 = Result
# 2 = No Result
# 3 = Error

class ReduceBlockFormat(object):
    GRAY = QColor(qRgb(235,235,238))
    #    red = QColor(qRgb(250,220,220))
    RED = QColor(qRgb(250,230,230))
    DARKRED = QColor(qRgb(204,0,0))
    DARKBLUE = QColor(qRgb(0,0,0xcc))
    DARKGRAY = QColor(qRgb(0xa0,0xa0,0xa0))

    def __init__(self):
        self.blockFormat = QTextBlockFormat()
        self.charFormat = QTextCharFormat()


class ReduceInputBlockFormat(ReduceBlockFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = ReduceBlockFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(ReduceInputBlockFormat,self).__init__()
            self.blockFormat.setAlignment(Qt.AlignLeft)
            # self.blockFormat.setBackground(Qt.yellow)
            self.blockFormat.setTopMargin(15)
            self.blockFormat.setBottomMargin(8)
            self.charFormat.setForeground(ReduceBlockFormat.DARKRED)
            self._ready = True


class ReduceResultBlockFormat(ReduceBlockFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = ReduceBlockFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(ReduceResultBlockFormat,self).__init__()
            self.blockFormat.setAlignment(Qt.AlignLeft)
            self.blockFormat.setLeftMargin(15)
            self.blockFormat.setNonBreakableLines(True)
            self.blockFormat.setBackground(ReduceBlockFormat.GRAY)
            self.charFormat.setForeground(ReduceBlockFormat.DARKBLUE)
            self._ready = True


class ReduceNoResultBlockFormat(ReduceBlockFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = ReduceBlockFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(ReduceNoResultBlockFormat,self).__init__()
            self.blockFormat.setAlignment(Qt.AlignLeft)
            self.blockFormat.setLeftMargin(15)
            self.blockFormat.setNonBreakableLines(True)
            self.blockFormat.setBackground(ReduceBlockFormat.GRAY)
            self.charFormat.setForeground(ReduceBlockFormat.DARKGRAY)
            self._ready = True


class ReduceErrorBlockFormat(ReduceBlockFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = ReduceBlockFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(ReduceErrorBlockFormat,self).__init__()
            self.blockFormat.setAlignment(Qt.AlignLeft)
            self.blockFormat.setLeftMargin(15)
            self.blockFormat.setNonBreakableLines(True)
            self.blockFormat.setBackground(ReduceBlockFormat.RED)
            self.charFormat.setForeground(Qt.black)
            self._ready = True
