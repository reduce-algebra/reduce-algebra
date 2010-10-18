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

import os
import sys

from types import StringType
from types import IntType

from PySide.QtCore import Qt
from PySide.QtCore import Signal
from PySide.QtCore import QObject
from PySide.QtCore import QSettings

from PySide.QtGui import QTextEdit
from PySide.QtGui import QFont
from PySide.QtGui import QFontInfo
from PySide.QtGui import QTextCursor
from PySide.QtGui import QMessageBox
from PySide.QtGui import QFontDatabase

from qrlogging import signalLogger
from qrlogging import traceLogger

from reduce import QtReduce

from qrdefaults import QtReduceDefaults

from qrformats import ReduceInputBlockFormat
from qrformats import ReduceResultBlockFormat
from qrformats import ReduceNoResultBlockFormat
from qrformats import ReduceErrorBlockFormat

from qrxml import ReduceXmlReader
from qrxml import ReduceXmlWriter

from types import DictType
from types import StringType
from types import IntType
from types import BooleanType


class QtReduceWorksheet(QTextEdit):
    fileName = ''
    fileNameChanged = Signal(StringType)
    startComputation = Signal(object)
    endComputation = Signal(object)
    modified = Signal(BooleanType)

    def __init__(self,parent=None):
        QTextEdit.__init__(self)
        self.parent = parent
        self.__initSignals()
        self.__initFont()
        self.__initFirstBlock()

    def __initSignals(self):
        self.textChanged.connect(self.textChangedHandler,
                                 type=Qt.DirectConnection)
        self.cursorPositionChanged.connect(self.cursorPositionChangedHandler,
                                           type=Qt.DirectConnection)

    def __initFont(self):
        self.zoomDef()

    def setupFont(self,size=None,step=1):
        traceLogger.debug("size=%s, step=%s" % (size,step))
        if not size:
            size = self.font().pixelSize()
        font = self.font()
        font.setFamily(QSettings().value("worksheet/fontfamily",
                                         QtReduceDefaults.FONTFAMILY))
        font.setFixedPitch(True)
        font.setKerning(0)
        font.setWeight(QFont.Normal)
        font.setItalic(False)
        font.setPixelSize(self.__nextGoodFontSize(font,size,step))
        self.setFont(font)

    def __nextGoodFontSize(self,font,size,step):
        info = QFontInfo(font)
        family = info.family()
        fontDatabase = QFontDatabase()
        styleStr = fontDatabase.styleString(font)
        traceLogger.debug("family=%s, style=%s" % (family,styleStr))
        if fontDatabase.isSmoothlyScalable(family,styleStr):
            sizes = QFontDatabase.standardSizes()
        else:
            sizes = fontDatabase.smoothSizes(family,styleStr)
        traceLogger.debug("looking for %s in %s" % (size,sizes))
        nSize = size
        while (nSize not in sizes) and sizes[0] <= nSize and nSize <= sizes[-1]:
            nSize += step
        if nSize < sizes[0]:
            traceLogger.debug("out of range - returning %s" % sizes[0])
            return sizes[0]
        if sizes[-1] < nSize:
            traceLogger.debug("out of range - returning %s" % sizes[-1])
            return sizes[-1]
        traceLogger.debug("found %s" % nSize)
        return nSize

    def currentFontChangedHandler(self,newFont):
        QSettings().setValue("worksheet/fontfamily",newFont.family())
        self.setupFont()
        self.ensureCursorVisible()

    def currentSizeChangedHandler(self,newSize):
        newSize = int(newSize)
        traceLogger.debug("newSize=%s (%s)" % (newSize,type(newSize)))
        QSettings().setValue("worksheet/fontsize",newSize)

    def initialize(self):
        self.__initReduce()
        self.reduce.initialize()

    def __initReduce(self):
        traceLogger.debug("entering")
        binary = QSettings().value("computation/reduce",
                                   QtReduceDefaults.REDUCE)
        if not os.path.exists(sys.path[0] + "/" + binary):
            tit = self.tr("Unable to Connect to Reduce")
            txt = self.tr("The binary ")
            txt += '"' + binary + '" '
            txt += self.tr("does not exist.")
            itxt = self.tr("Using the default binary ")
            itxt += '"' + QtReduceDefaults.REDUCE + '"'
            itxt += self.tr(". ")
            itxt += self.tr("Please check the Preferences.")
            mbox = QMessageBox(self)
            mbox.setIcon(QMessageBox.Warning)
            mbox.setWindowModality(Qt.WindowModal)
            mbox.setWindowTitle(tit)
            mbox.setText(txt)
            mbox.setInformativeText(itxt)
            mbox.exec_()
            binary = QtReduceDefaults.REDUCE
        self.reduce = QtReduce(binary)
        self.reduce.endComputation.connect(self.endComputationHandler,
                                      type=Qt.DirectConnection)
        self.reduce.startComputation.connect(self.startComputationHandler,
                                           type=Qt.DirectConnection)

    def compute(self,c,silent=False):
        self.reduce.compute(c,silent)

    def startComputationHandler(self,rc):
        signalLogger.debug("catching command=%s" % rc.currentCommand)
        self.__startComputationCursor = self.textCursor()
        self.setReadOnly(True)
        self.startComputation.emit(rc)

    def endComputationHandler(self,rc):
        signalLogger.debug("catching newReduceResult=%s" % rc.statCounter)
        if not rc.silent:
            self.__renderOutput(rc,self.__startComputationCursor)
        self.setReadOnly(False)
        self.endComputation.emit(rc)

    def __initFirstBlock(self):
        traceLogger.debug("entering")
        cursor = self.textCursor()
        cursor.movePosition(QTextCursor.Start)
        self.labelBlock(cursor,0)
        self.setTextCursor(cursor)

    def keyPressEvent(self,ev):
        state = self.textCursor().block().userState()
        if state == 0:
            return self.__keyPressEvent0(ev)
        if state >= 1 and state <= 3:
            return self.__keyPressEvent1(ev)
        traceLogger.error("state = %s" % state)

    def __keyPressEvent0(self,ev):
        if ev.key() == Qt.Key_Backspace:
            cursor = self.textCursor()
            block = cursor.block()
            if cursor.position()==block.position():
                return
        if (ev.key() == Qt.Key_Return or ev.key() == Qt.Key_Enter) and \
                not (ev.modifiers() & Qt.ShiftModifier):
            return self.__keyPressEvent0Return(ev)
        QTextEdit.keyPressEvent(self,ev)

    def __keyPressEvent0Return(self,ev):
        cursor = self.textCursor()
        block = cursor.block()
#        command = block.text().simplified().__str__().strip()
        command = block.text().__str__().strip()
        if command != '' and not command[-1] in [';','$']:
            command += ';'
        traceLogger.debug("before self.compute(command)")
        output = self.compute(command)

    def __renderOutput(self,computation,cursor=None):
        if not cursor:
            cursor = self.textCursor()
        here = cursor.position()
        block = cursor.block()
        nextblock = self.__getNextBlock(cursor,[1,2,3])
        if computation.error:
            self.labelBlock(cursor,3)
            outp = computation.errorText
            outp = self.__filterOutput(outp)
            outp = self.__colorOutput(outp,"black")
            cursor.insertHtml(outp)
            cursor.setPosition(here)
            self.setTextCursor(cursor)
            return
        if computation.result:
            self.labelBlock(cursor,1)
            outp = computation.result
            outp = outp.decode('utf-8')
            outp = self.__filterOutput(outp)
            outp = self.__colorOutput(outp,"blue")
            cursor.insertHtml(outp)
        else:
            self.labelBlock(cursor,2)
            outp = self.__colorOutput(self.tr("[no output]"),"gray")
            nextblock.setUserState(2)
            cursor.insertHtml(outp)
        nextblock = self.__getNextBlock(cursor,[0])
        self.labelBlock(cursor,0)
        cursor.setPosition(nextblock.position())
        self.setTextCursor(cursor)

    def __keyPressEvent1(self,ev):
        if ev.key() in [Qt.Key_Left,Qt.Key_Up,Qt.Key_Right,Qt.Key_Down]:
            QTextEdit.keyPressEvent(self,ev)
        return

    def __getNextBlock(self,cursor,format):
        cursor.movePosition(QTextCursor.EndOfBlock)
        block = cursor.block()
        nextblock = block.next()
        if nextblock and nextblock.userState() in format:
            cursor.movePosition(QTextCursor.Right)
            traceLogger.debug("reusing block %s (%s)" % (nextblock, nextblock.userState()))
        else:
            cursor.insertBlock()
            nextblock = cursor.block()
            traceLogger.debug("created new block %s (%s)" % (nextblock, format))
        cursor.movePosition(QTextCursor.EndOfBlock)
        cursor.movePosition(QTextCursor.StartOfBlock,QTextCursor.KeepAnchor)
	return nextblock

    def __filterOutput(self,s):
        result = ""
        for c in s:
            if c == '\n':
                result += "<br>"
            elif c == ' ':
                result += "&nbsp;"
            elif c == '<':
                result += "&lt;"
            else:
                result += c
        return result

    def __colorOutput(self,s,c):
        if c == "blue":
            color = "color:#0000cc;"
        elif c == "gray":
            color = "color:#a0a0a0;"
        else:
            color = "color:black;"
        fontFamily = "" # "font-family:Courier,monospace;"
        size = "" # "size:14;"
        return '<span style="' + color + fontFamily + size + '">' + s + "</span>"

    def open(self,fileName):
        tempFileName = fileName
        if tempFileName == '':
            tempFileName = self.fileName
        xmlReader = ReduceXmlReader(self.document())
        try:
            xmlReader.open(tempFileName)
        except:
            QMessageBox.information(self,self.tr("Unable to open file"),
                                    str(sys.exc_info()[1]))
            return False
        self.modified.emit(False)
        self.fileName = tempFileName
        self.fileNameChanged.emit(self.fileName)
        self.parent.statusBar().showMessage(self.tr("Read ") + self.fileName)
        self.ensureCursorVisible()
        return True

    def save(self,fileName):
        tempFileName = fileName
        if tempFileName == '':
            tempFileName = self.fileName
        xmlWriter = ReduceXmlWriter(self.document())
        try:
            xmlWriter.save(tempFileName)
        except:
            QMessageBox.information(self,self.tr("Unable to save file"),
                                    str(sys.exc_info()[1]))
            return False
        self.modified.emit(False)
        self.fileName = tempFileName
        self.fileNameChanged.emit(self.fileName)
        self.parent.statusBar().showMessage(self.tr("Wrote ") + self.fileName)
        return True

    def textChangedHandler(self):
        self.modified.emit(True)
        # traceLogger.debug("self.modified=%s" % self.modified)
        # if not self.modified:
        #     self.modified = True
        #     self.parent.setWindowModified(True)
        #     self.parent.setTitle(self.fileName,1)

    def cursorPositionChangedHandler(self):
        self.parent.statusBar().clearMessage()

    def abortEvaluation(self):
        self.reduce.abortEvaluation()

    def labelBlock(self,cursor,label):
        traceLogger.debug("cursor.block()=%s, label=%s" % (cursor.block(), label))
        if label == 0:
            f = ReduceInputBlockFormat()
        elif label == 1:
            f = ReduceResultBlockFormat()
        elif label == 2:
            f = ReduceNoResultBlockFormat()
        else:
            f = ReduceErrorBlockFormat()

        cursor.block().setUserState(label)
        cursor.setBlockCharFormat(f.charFormat)
        cursor.setBlockFormat(f.blockFormat)

    def zoomDef(self):
        self.setupFont(QSettings().value("worksheet/fontsize",
                                         QtReduceDefaults.FONTSIZE))


# Python 2.5.4 (r254:67916, Jul  7 2009, 23:51:24)
# [GCC 4.2.1 (Apple Inc. build 5646)] on darwin
# Type "help", "copyright", "credits" or "license" for more information.
# >>> import sys
# >>> from PySide import QtCore, QtGui
# >>> app = QtGui.QApplication(sys.argv)
# >>> ed = QtGui.QPlainTextEdit()
# >>> b = ed.textCursor().block()
# >>> b.setUserState(42)
# >>> b.userState()
# 42
# >>> print b.userState()
# 42
