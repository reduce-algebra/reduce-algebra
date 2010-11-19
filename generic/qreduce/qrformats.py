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

from PySide.QtCore import Qt

from PySide.QtGui import QBrush
from PySide.QtGui import QTextBlockFormat
from PySide.QtGui import QTextFrameFormat
from PySide.QtGui import QColor
from PySide.QtGui import QFont
from PySide.QtGui import qRgb
from PySide.QtGui import QTextCharFormat
from PySide.QtGui import QTextBlockUserData
from PySide.QtGui import QTextFormat

# 0 = Input
# 1 = Result
# 2 = No Result
# 3 = Error

class QtReduceFormat(object):
    GRAY = QColor(qRgb(235,235,238))
    #    red = QColor(qRgb(250,220,220))
    RED = QColor(qRgb(250,230,230))
    DARKRED = QColor(qRgb(204,0,0))
    DARKBLUE = QColor(qRgb(0,0,0xcc))
    DARKGRAY = QColor(qRgb(0xa0,0xa0,0xa0))

    def __init__(self):
        self.blockFormat = QTextBlockFormat()
        self.blockFormat.setAlignment(Qt.AlignLeft)
        self.charFormat = QTextCharFormat()
        self.frameFormat = QTextFrameFormat()
        self.frameFormat.setTopMargin(0)
        self.frameFormat.setBottomMargin(0)
        self.frameFormat.setLeftMargin(0)
        self.frameFormat.setPosition(QTextFrameFormat.InFlow)


class QtReduceInput(QtReduceFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceInput,self).__init__()
            self.charFormat.setForeground(QBrush(QtReduceFormat.DARKRED))
            self.showFrames(False)
            self._ready = True

    def showFrames(self,b=False):
        if b:
            self.blockFormat.setBackground(QtReduceFormat.GRAY)
            self.frameFormat.setBorder(1)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_None)
        else:
            self.blockFormat.setBackground(Qt.white)
            self.frameFormat.setBorder(0)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_None)


class QtReduceOutput(QtReduceFormat):

    def __init__(self):
        super(QtReduceOutput,self).__init__()
        self.blockFormat.setNonBreakableLines(True)

    def showFrames(self,b=False):
        if b:
            self.frameFormat.setBorder(1)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_Solid)
        else:
            self.frameFormat.setBorder(0)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_None)


class QtReduceResult(QtReduceOutput):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceOutput.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceResult,self).__init__()
            self.charFormat.setForeground(QtReduceFormat.DARKBLUE)
            self._ready = True


class QtReduceNoResult(QtReduceOutput):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceOutput.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceNoResult,self).__init__()
            self.charFormat.setForeground(QtReduceFormat.DARKGRAY)
            self._ready = True


class QtReduceError(QtReduceOutput):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceOutput.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceError,self).__init__()
            self.blockFormat.setBackground(QtReduceFormat.RED)
            self.charFormat.setForeground(Qt.black)
            self._ready = True


class QtReduceInvalid(QtReduceFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceOutput.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceInvalid,self).__init__()
            self.blockFormat.setBackground(Qt.yellow)
            self._ready = True


class QtReduceRowFormat(QTextFrameFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QTextFrameFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceRowFormat,self).__init__()
            self.setPosition(QTextFrameFormat.InFlow)
            self.setLeftMargin(25)
            self.showFrames(False)
            self._ready = True

    def showFrames(self,b=True):
        if b:
            self.setBorder(0.2)
            self.setBorderStyle(QTextFrameFormat.BorderStyle_Solid)
            self.setRightMargin(-4)
        else:
            self.setBorder(0)
            self.setBorderStyle(QTextFrameFormat.BorderStyle_None)
            self.setRightMargin(0)
