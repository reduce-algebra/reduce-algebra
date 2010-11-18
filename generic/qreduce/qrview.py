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

from types import IntType
from types import BooleanType

from PySide.QtCore import Qt
from PySide.QtCore import Signal
from PySide.QtCore import QSettings

from PySide.QtGui import QTextEdit
from PySide.QtGui import QFont
from PySide.QtGui import QFontDatabase
from PySide.QtGui import QFontInfo
from PySide.QtGui import QFrame
from PySide.QtGui import QMessageBox
from PySide.QtGui import QPainter
from PySide.QtGui import QTextCursor

from qrlogging import fontLogger
from qrlogging import signalLogger
from qrlogging import traceLogger

from qrdefaults import QtReduceDefaults

from qrformats import QtReduceInput
from qrformats import QtReduceResult
from qrformats import QtReduceNoResult
from qrformats import QtReduceError
from qrformats import QtReduceRowFormat


class QtReduceTextEdit(QTextEdit):

    computationRequest = Signal(IntType)
    modified = Signal(BooleanType)

    def __init__(self,parent=None):
        super(QtReduceTextEdit,self).__init__(parent)

        self.textChanged.connect(self.textChangedHandler)

        self.setupFont(int(QSettings().value("worksheet/fontsize",
                                         QtReduceDefaults.FONTSIZE)))

    def __nextGoodFontSize(self,font,size,step):
        info = QFontInfo(font)
        family = info.family()
        fontDatabase = QFontDatabase()
        styleStr = fontDatabase.styleString(font)
        fontLogger.debug("family=%s, style=%s" % (family,styleStr))
        if fontDatabase.isSmoothlyScalable(family,styleStr):
            sizes = QFontDatabase.standardSizes()
        else:
            sizes = fontDatabase.smoothSizes(family,styleStr)
        fontLogger.debug("looking for %s in %s step %d" % (size,sizes,step))
        nSize = size
        while nSize not in sizes and sizes[0] <= nSize and nSize <= sizes[-1]:
            nSize += step
        if nSize < sizes[0]:
            fontLogger.debug("out of range - returning %s" % sizes[0])
            return sizes[0]
        if sizes[-1] < nSize:
            fontLogger.debug("out of range - returning %s" % sizes[-1])
            return sizes[-1]
        fontLogger.debug("found %s" % nSize)
        return nSize

    def setupFont(self,size=None,step=1):
        traceLogger.debug("size=%s, step=%s" % (size,step))
        if not size:
            size = self.font().pointSize()
        font = self.font()
        font.setFamily(QSettings().value("worksheet/fontfamily",
                                         QtReduceDefaults.FONTFAMILY))
        font.setFixedPitch(True)
        font.setKerning(0)
        font.setWeight(QFont.Normal)
        font.setItalic(False)
        font.setPointSize(self.__nextGoodFontSize(font,size,step))
        self.setFont(font)

    def currentFontChangedHandler(self,newFont):
        QSettings().setValue("worksheet/fontfamily",newFont.family())
        self.setupFont()
        self.ensureCursorVisible()

    def currentSizeChangedHandler(self,newSize):
        newSize = int(newSize)
        traceLogger.debug("newSize=%s (%s)" % (newSize,type(newSize)))
        QSettings().setValue("worksheet/fontsize",newSize)
        self.setupFont(newSize)

    def textChangedHandler(self):
        self.modified.emit(True)

    def zoomDef(self):
        self.setupFont(int(QSettings().value("worksheet/fontsize",
                                         QtReduceDefaults.FONTSIZE)))

    def zoomIn(self):
        currentSize = self.font().pointSize()
        self.setupFont(currentSize + 1)

    def zoomOut(self):
        currentSize = self.font().pointSize()
        self.setupFont(currentSize - 1,step=-1)


class QtReduceFrameView(QtReduceTextEdit):
    Evaluated = 'EVALUATED'
    NotEvaluated = '...'
    leftRow = Signal(IntType)

    def __init__(self,parent=None):
        super(QtReduceFrameView,self).__init__(parent)
        self.setUndoRedoEnabled(False)
        self.selectionChanged.connect(self.pruneSelection)

    def atEnd(self):
        return self.textCursor().atEnd()

    def atStart(self):
        return self.textCursor().atStart()

    def gotoNextInputPosition(self):
        cursor = self.textCursor()
        if not cursor.atEnd():
            cursor.movePosition(QTextCursor.NextBlock)
            while not cursor.atEnd() and not self.__isInputPosition(cursor):
                cursor.movePosition(QTextCursor.NextBlock)
            self.setTextCursor(cursor)

    def gotoPreviousInputPosition(self):
        cursor = self.textCursor()
        if not cursor.atStart():
            cursor.movePosition(QTextCursor.PreviousBlock)
            while not cursor.atStart() and not self.__isInputPosition(cursor):
                cursor.movePosition(QTextCursor.PreviousBlock)
            self.setTextCursor(cursor)

    def gotoRow(self,row):
        rows = self.document().rootFrame().childFrames()
        if row >= len(rows):
            traceLogger.critical("invalid row %d > %d" % (row,len(rows)-1))
            row = len(rows)
        cursor = QTextCursor(rows[row].lastCursorPosition())
        cursor.movePosition(QTextCursor.NextBlock)
        self.setTextCursor(cursor)
        self.ensureCursorVisible()
        cursor = QTextCursor(rows[row].childFrames()[0])
        self.setTextCursor(cursor)
        self.ensureCursorVisible()

    def insertRow(self,row):
        document = self.document()
        rootFrame = document.rootFrame()
        rows = rootFrame.childFrames()
        if row > len(rows):
            traceLogger.critical("invalid row %d > %d" % (row,len(rows)))
            row = len(rows)
        if row == len(rows):
            cursor = QTextCursor(document)
            cursor.movePosition(QTextCursor.End)
        elif rows:
            cursor = QTextCursor(rows[row].firstCursorPosition())
            cursor.movePosition(QTextCursor.PreviousBlock)
        cursor.insertFrame(QtReduceRowFormat())
        cursor.insertFrame(QtReduceInput().frameFormat)
        position = cursor.position()
        cursor.clearSelection()
        cursor.setBlockFormat(QtReduceInput().blockFormat)
        cursor.setBlockCharFormat(QtReduceInput().charFormat)
        cursor.movePosition(QTextCursor.NextBlock)
        cursor.insertFrame(QtReduceNoResult().frameFormat)
        cursor.setBlockFormat(QtReduceNoResult().blockFormat)
        cursor.setBlockCharFormat(QtReduceNoResult().charFormat)
        cursor.insertText(QtReduceFrameView.NotEvaluated)
        cursor.setPosition(position)

    def insertRows(self,start,end):
        for row in range(start, end + 1):
            self.insertRow(row)

    def input(self,row):
        rows = self.document().rootFrame().childFrames()
        if row >= len(rows):
            traceLogger.critical("invalid row %d > %d" % (row,len(rows)-1))
            row = len(rows)
        inputFrame = rows[row].childFrames()[0]
        cursor = QTextCursor(inputFrame)
        cursor.setPosition(inputFrame.lastPosition(),QTextCursor.KeepAnchor)
        command = cursor.selectedText()
        command = command.replace(u'\u2028',u'\n')
        command = command.replace(u'\u2029',u'\n')
        if command != '' and not command[-1] in [';','$']:
            command += ';'
        return command

    def keyPressEvent(self,e):
        if e.key() == Qt.Key_Tab:
            self.gotoNextInputPosition()
            return
        if e.key() == Qt.Key_Backtab:
            self.gotoPreviousInputPosition()
            return
        if self.__isReadOnlyPosition():
            if e.key() not in [Qt.Key_Left,Qt.Key_Right,Qt.Key_Up,Qt.Key_Down]:
                return
        if self.__isInputPosition():
            if (e.key() == Qt.Key_Return or e.key() == Qt.Key_Enter) and \
                   not (e.modifiers() & Qt.ShiftModifier):
                signalLogger.debug("emitting computationRequest")
                self.computationRequest.emit(self.row())
                return
        super(QtReduceTextEdit,self).keyPressEvent(e)

    def paintEvent(self,e):
        print e
        #painter = QPainter(self)
        # pen = painter.pen()
        # pen.setCosmetic(True)
        # pen.setWidth(0.0)
        # painter.setPen(pen)
        # painter.setRenderHint(QPainter.Antialiasing, False)
        # height = self.verticalScrollBar().sliderPosition()
        # for group in self.document().rootFrame().childFrames():
        #     iblock = group.childFrames()[0].firstCursorPosition().block()
        #     rect = iblock.layout().boundingRect()
        #     position = iblock.layout().position()
        #     self.__drawBracket(painter, position.y() + 1 - height, position.y()
        #                 + rect.height() - 2 - height)
        # painter.end()
        super(QtReduceFrameView,self).paintEvent(e)

    def pruneSelection(self):
        cursor = self.textCursor()
        if not cursor.hasSelection():
            return
        if cursor.hasComplexSelection():
            cursor.clearSelection()
            self.setTextCursor(cursor)
            return
        s = cursor.selectionStart()
        e = cursor.selectionEnd()
        sp = self.__positionPair(s)
        ep = self.__positionPair(e)
        traceLogger.debug("start=%d in %s, end=%d in %s" % (s,sp,e,ep))
        if sp == ep:
            return
        c = cursor.position()
        cp = self.__positionPair(c)
        traceLogger.debug("cursor=%d in %s" % (c,cp))
        cursor.clearSelection()
        self.setTextCursor(cursor)
        return

    def rowOrNextRow(self,cursor=None):
        if not cursor:
            cursor = self.textCursor()
        row = self.row(cursor)
        if row >= 0:
            return row
        if cursor.atEnd():
            return -1
        cursor.movePosition(QTextCursor.Right)
        row = self.row(cursor)
        if row >= 0:
            return row
        traceLogger.critical("unexpected negative row index")

    def rowOrPreviousRow(self,cursor=None):
        if not cursor:
            cursor = self.textCursor()
        row = self.row(cursor)
        if row >= 0:
            return row
        if cursor.atStart():
            return -1
        cursor.movePosition(QTextCursor.Left)
        row = self.row(cursor)
        if row >= 0:
            return row
        traceLogger.critical("unexpected negative row index")

    def removeRows(self,start,end):
        document = self.document()
        rootFrame = document.rootFrame()
        rows = rootFrame.childFrames()
        if end >= len(rows):
            traceLogger.critical("invalid row %d >= %d" % (end,len(rows)))
        cursor = rows[start].firstCursorPosition()
        cursor.setPosition(rows[end].lastPosition()+1,QTextCursor.KeepAnchor)
        cursor.deleteChar()

    def row(self,cursor=None):
        if not cursor:
            cursor = self.textCursor()
        rootFrame = self.document().rootFrame()
        frames = rootFrame.childFrames()
        frame = cursor.currentFrame()
        if frame == rootFrame:
            return -1
        p = frame.parentFrame()
        if p != rootFrame:
            frame = p
        return frames.index(frame)

    def rowCount(self):
        return len(self.document().rootFrame().childFrames())

    def setError(self,row,text):
        self.__setOutput(row,text,QtReduceError())

    def setInput(self,row,text):
        rows = self.document().rootFrame().childFrames()
        if row >= len(rows):
            traceLogger.critical("invalid row %d > %d" % (row,len(rows)-1))
            return
        rowFrames = rows[row].childFrames()
        if len(rowFrames) != 2:
            traceLogger.critical("%d subframes in row %d", len(rowFrames), row)
            return
        text = text.rstrip(';')
        inputFrame = rowFrames[0]
        cursor = inputFrame.firstCursorPosition()
        cursor.setPosition(inputFrame.lastPosition(),QTextCursor.KeepAnchor)
        cursor.setBlockFormat(QtReduceInput().blockFormat)
        cursor.insertText(text,QtReduceInput().charFormat)

    def setNoResult(self,row):
        self.__setOutput(row,self.tr(QtReduceFrameView.Evaluated),QtReduceNoResult())

    def setNotEvaluated(self,row):
        self.__setOutput(row,self.tr(QtReduceFrameView.NotEvaluated),QtReduceNoResult())

    def setResult(self,row,text):
        self.__setOutput(row,text,QtReduceResult())

    def __drawBracket(self,painter,start,end):
        painter.drawLine(1,start,4,start)
        painter.drawLine(1,start,1,end)
        painter.drawLine(1,start,4,start)
        painter.drawLine(1,end,4,end)

    def __isInputPosition(self,cursor=None):
        if not cursor:
            cursor = self.textCursor()
        if cursor.block().blockFormat() == QtReduceInput().blockFormat:
            return True
        else:
            return False

    def __isOutputPosition(self,cursor=None):
        if not cursor:
            cursor = self.textCursor()
        if cursor.block().blockFormat() in \
               [QtReduceResult().blockFormat, QtReduceNoResult().blockFormat,
                QtReduceError().blockFormat]:
            return True
        return False

    def __isReadOnlyPosition(self,cursor=None):
        if self.__isOutputPosition(cursor) or self.__isRootPosition(cursor):
            return True
        return False

    def __isRootPosition(self,cursor=None):
        if not cursor:
            cursor = self.textCursor()
        if cursor.currentFrame() == self.document().rootFrame():
            return True
        return False

    def __positionPair(self,pos):
        cursor = QTextCursor(self.document())
        cursor.setPosition(pos)
        rootFrame = self.document().rootFrame()
        frames = rootFrame.childFrames()
        frame = cursor.currentFrame()
        if frame == rootFrame:
            # pos is outside any group
            return [pos,pos]
        p = frame.parentFrame()
        if p != rootFrame:
            # frame is an input or output frame containing pos
            return [frame.firstPosition(),frame.lastPosition()]
        # frame is a group frame containing pos in a comment position
        localFrames = frame.childFrames()
        inputStart = localFrames[0].firstPosition()
        if pos < inputStart:
            return [frame.firstPosition(),inputStart-1]
        inputEnd = localFrames[0].lastPosition()
        outputStart = localFrames[1].firstPosition()
        if inputEnd < pos and pos < outputStart:
            return [inputEnd+1,outputStart-1]
        outputEnd = localFrames[1].lastPosition()
        if outputEnd < pos:
            return [outputEnd+1,frame.lastPosition()]
        traceLogger.critical("bad position %d (%d %d) (%d %d)" %
                             (pos,
                              ifr.firstPosition(), ifr.lastPosition(),
                              ofr.firstPosition(), ofr.lastPosition()))
        return [-1,-1]

    def __setOutput(self,row,text,reduceBlockFormat):
        rows = self.document().rootFrame().childFrames()
        if row >= len(rows):
            traceLogger.critical("invalid row %d > %d" % (row,len(rows)-1))
            return
        rowFrames = rows[row].childFrames()
        if len(rowFrames) != 2:
            traceLogger.critical("%d subframes in row %d", len(rowFrames), row)
            return
        outputFrame = rowFrames[1]
        cursor = outputFrame.firstCursorPosition()
        cursor.setPosition(outputFrame.lastPosition(),QTextCursor.KeepAnchor)
        cursor.setBlockFormat(reduceBlockFormat.blockFormat)
        cursor.insertText(text.decode('utf-8'),reduceBlockFormat.charFormat)
