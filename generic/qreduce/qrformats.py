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


class ReduceBlockFormat(QTextBlockFormat):
    gray = QColor(qRgb(230,230,230))
    red = QColor(qRgb(250,220,220))

    def __init__(self,type):
        QTextBlockFormat.__init__(self)
        if type == 0:
            self.setAlignment(Qt.AlignLeft)
#            self.setBackground(Qt.yellow)
            self.setTopMargin(10)
            self.setBottomMargin(3)
        if type == 1 or type == 2:
            self.setAlignment(Qt.AlignCenter)
            self.setBackground(self.gray)
        if type == 3:
            self.setAlignment(Qt.AlignLeft)
            self.setBackground(self.red)

    @staticmethod
    def labelBlock(cursor,label):
#        print "set ", cursor.block(), label
        cursor.block().setUserState(label)
        cursor.setBlockCharFormat(ReduceCharFormat(label))
        cursor.setBlockFormat(ReduceBlockFormat(label))


class ReduceCharFormat(QTextCharFormat):
    RED = QColor(qRgb(204,0,0))
    BLUE = QColor(qRgb(0,0,0xcc))
    GRAY = QColor(qRgb(0xa0,0xa0,0xa0))

    def __init__(self,type):
        QTextCharFormat.__init__(self)
        if type == 0:
            self.setForeground(ReduceCharFormat.RED)
        if type == 1:
            self.setForeground(ReduceCharFormat.BLUE)
        if type == 2:
            self.setForeground(ReduceCharFormat.GRAY)
        if type == 3:
            self.setForeground(Qt.black)


class QReduceBlockData(QTextBlockUserData):

    def __init__(self,n):
        QTextBlockUserData.__init__(self)
        self.message = "Hallo" + str(n)

    def __del__(self):
        self.message = None
        QTextBlockUserData.__del__(self)
