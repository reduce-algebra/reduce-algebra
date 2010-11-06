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
        self.charFormat = QTextCharFormat()
        self.frameFormat = QTextFrameFormat()


class QtReduceInput(QtReduceFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceInput,self).__init__()

            self.blockFormat.setAlignment(Qt.AlignLeft)
            self.blockFormat.setBackground(QtReduceFormat.GRAY)
            #self.blockFormat.setRightMargin(-3)

            self.charFormat.setForeground(QBrush(QtReduceFormat.DARKRED))

            self.frameFormat.setLeftMargin(15)
            self.frameFormat.setBorder(1)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_None)
            self.frameFormat.setPosition(QTextFrameFormat.InFlow)

            self._ready = True


class QtReduceResult(QtReduceFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceResult,self).__init__()

            self.blockFormat.setAlignment(Qt.AlignLeft)
            self.blockFormat.setNonBreakableLines(True)

            self.charFormat.setForeground(QtReduceFormat.DARKBLUE)

            self.frameFormat.setLeftMargin(15)
            self.frameFormat.setBorder(1)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_None)
            self.frameFormat.setPosition(QTextFrameFormat.InFlow)

            self._ready = True


class QtReduceNoResult(QtReduceFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceNoResult,self).__init__()

            self.blockFormat.setAlignment(Qt.AlignLeft)
            self.blockFormat.setNonBreakableLines(True)

            self.charFormat.setForeground(QtReduceFormat.DARKGRAY)

            self.frameFormat.setLeftMargin(15)
            self.frameFormat.setBorder(1)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_None)
            self.frameFormat.setPosition(QTextFrameFormat.InFlow)

            self._ready = True


class QtReduceError(QtReduceFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceFormat.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceError,self).__init__()

            self.blockFormat.setAlignment(Qt.AlignLeft)
            self.blockFormat.setNonBreakableLines(True)
            self.blockFormat.setBackground(QtReduceFormat.RED)

            self.charFormat.setForeground(Qt.black)

            self.frameFormat.setLeftMargin(15)
            self.frameFormat.setBorder(1)
            self.frameFormat.setBorderStyle(QTextFrameFormat.BorderStyle_None)
            self.frameFormat.setPosition(QTextFrameFormat.InFlow)

            self._ready = True


class QtReduceInvalid(QtReduceFormat):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QtReduceFormat.__new__(type)
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

            self.setBorder(0.2)
            self.setBorderStyle(QTextFrameFormat.BorderStyle_Solid)
            self.setPosition(QTextFrameFormat.InFlow)
            self.setLeftMargin(10)
            self.setRightMargin(-4)

            self._ready = True
