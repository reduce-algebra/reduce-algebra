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

from PySide.QtCore import QObject
from PySide.QtCore import Signal

from qrlogging import fontLogger
from qrlogging import signalLogger
from qrlogging import traceLogger

from qrmodel import QtReduceModel

from qrview import QtReduceFrameView

from types import BooleanType
from types import StringType

class QtReduceController(QObject):

    endComputation = Signal(object)
    acceptAbort = Signal(BooleanType)
    fileNameChanged = Signal(StringType)
    modified = Signal(BooleanType)
    startComputation = Signal(object)

    def __init__(self,parent=None):
        super(QtReduceController,self).__init__(parent)

        self.setFileName('')

        self.__requestPending = False

        self.model = QtReduceModel()
        self.view = QtReduceFrameView(parent)

        self.view.computationRequest.connect(self.computationRequestV)
        self.view.modified.connect(self.modified)

        self.model.dataChanged.connect(self.dataChangedM)
        self.model.endComputation.connect(self.endComputationM)
        self.model.rowsInserted.connect(self.rowsInsertedM)
        self.model.rowsRemoved.connect(self.rowsRemovedM)
        self.model.startComputation.connect(self.startComputationM)

        self.model.insertRow(0)

    def abortComputation(self):
        self.model.abortComputation()

    def computationRequestV(self,row):
        signalLogger.debug("catching row = %d" % row)
        if not self.view.input(row):
            return
        index = self.model.index(row,0)
        computation = self.model.data(index,QtReduceModel.RawDataRole).copy()
        computation.command = self.view.input(row)
        self.model.computeAndSetData(index,computation,
                                     QtReduceModel.RawDataRole)
        self.__requestPending = True

    def evaluateAll(self):
        for row in range(self.view.rowCount()):
            self.computationRequestV(row)

    def evaluateSelection(self):
        None

    def dataChangedM(self,topLeft,bottomRight):
        start = topLeft.row()
        end = bottomRight.row()
        signalLogger.debug("start = %d, end = %d" % (start,end))
        for row in range(start,end+1):
            index = self.model.index(row,0)
            computation = self.model.data(index,QtReduceModel.RawDataRole)
            self.view.setInput(row,computation.command)
            traceLogger.debug(computation)
            if computation.error:
                self.view.setError(row,computation.errorText)
                return
            elif computation.result:
                result = computation.result
                if not computation.symbolic:
                    result = self.renderResult(result)
                self.view.setResult(row,result)
            elif computation.evaluated:
                self.view.setNoResult(row)
            else:
                self.view.setNotEvaluated(row)
        if self.__requestPending:
            self.__requestPending = False
            if row == self.model.rowCount() - 1:
                self.model.insertRow(row + 1)
        if row < self.model.rowCount() - 1:
            self.view.gotoRow(row + 1)

    def deleteOutput(self):
        self.model.deleteOutput()

    def deleteRowOrPreviousRow(self):
        row = self.view.rowOrPreviousRow()
        if row >= 0:
            self.model.removeRow(row)
        if self.model.rowCount() == 0:
            self.model.insertRow(0)

    def endComputationM(self,computation):
        signalLogger.debug("catching computation.statCounter = %s,"
                           "evaluating=%s" %
                           (computation.statCounter,computation.evaluating))
        self.view.setReadOnly(False)
        self.acceptAbort.emit(False)
        self.endComputation.emit(computation)

    def fileName(self):
        return self.__fileName

    def insertAbove(self):
        if self.view.atEnd():
            self.model.insertRow(self.model.rowCount())
            return
        row = self.view.rowOrNextRow()
        if row < 0:
            traceLogger.critical("unxepected row %s" % row)
        self.model.insertRow(row)
        self.view.gotoRow(row)

    def insertBelow(self):
        if self.view.atStart():
            self.model.insertRow(0)
            return
        row = self.view.rowOrPreviousRow()
        if row < 0:
            traceLogger.critical("unxepected row %s" % row)
        self.model.insertRow(row + 1)
        self.view.gotoRow(row + 1)

    def open(self,fileName):
        success = self.model.open(fileName)
        if success:
            self.view.gotoRow(self.model.rowCount() - 1)
            self.modified.emit(False)
            self.setFileName(fileName)
            self.parent().showMessage(self.tr("Read ") + fileName)
        return

    def renderResult(self,result):
        command = "qr_render(" + result + ");"
        answer = self.model.reduce.reduce.compute(command)
        return answer['pretext'].strip()

    def rowsInsertedM(self,parent,start,end):
        traceLogger.debug("start=%d, end=%d" % (start, end))
        self.view.insertRows(start,end)

    def rowsRemovedM(self,parent,start,end):
        traceLogger.debug("start=%d, end=%d" % (start, end))
        self.view.removeRows(start,end)

    def save(self):
        if not self.__fileName:
            traceLogger.critical('empty file name')
        self.__saveAs(self.__fileName)

    def saveAs(self,fileName):
        self.__saveAs(fileName)
        self.setFileName(fileName)

    def setFileName(self,name):
        self.__fileName = name
        self.fileNameChanged.emit(name)

    def startComputationM(self,computation):
        signalLogger.debug("catching computation.command =  %s" %
                           computation.command)
        self.view.setReadOnly(True)
        self.acceptAbort.emit(True)
        self.startComputation.emit(computation)

    def __saveAs(self,fileName):
        self.model.save(fileName)
        self.modified.emit(False)

