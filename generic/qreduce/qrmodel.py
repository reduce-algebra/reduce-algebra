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

from types import IntType

from PySide.QtCore import QAbstractTableModel
from PySide.QtCore import QCoreApplication
from PySide.QtCore import QFile
from PySide.QtCore import QIODevice
from PySide.QtCore import QModelIndex
from PySide.QtCore import QMutex
from PySide.QtCore import QObject
from PySide.QtCore import QSettings
from PySide.QtCore import Qt
from PySide.QtCore import QThread
from PySide.QtCore import Signal
from PySide.QtCore import QXmlStreamWriter

from PySide.QtGui import QMessageBox

from PySide.QtXml import QXmlSimpleReader
from PySide.QtXml import QXmlInputSource
from PySide.QtXml import QXmlDefaultHandler

from qrlogging import signalLogger
from qrlogging import traceLogger

from qrdefaults import QtReduceDefaults

from RedPy import procNew, procDelete, ansNew, ansDelete


class Reduce(QObject):
    def __init__(self,reduce='../../bin/redpsl'):
        super(Reduce,self).__init__()
        self.__process = procNew(sys.path[0] + "/" + reduce)
        self.__processId = self.__process['processId']
        self.__process = self.__process['handle']
        self.__mutex = QMutex()

    def __del__(self):
        traceLogger.warning("about to delete Reduce process - this is good!")
        procDelete(self.__process)

    def compute(self,c):
        self.__mutex.lock()
        a = self.__compute(c)
        self.__mutex.unlock()
        return a

    def __compute(self,c):
        a = ansNew(self.__process,c)
        ansDelete(a['handle'])
        return a['data']

    def signal(self,c):
        signalLogger.debug("c=%s" % c)
        os.system('/bin/kill -' + c + ' ' + str(self.__processId))


class QtReduce(QThread):
    # currently only works with 'object' type, not with
    # 'QtReduceComputation'
    startComputation = Signal(object)
    endComputation = Signal(object)

    def __init__(self,parent=None):
        super(QtReduce,self).__init__(parent)
        self.reduce = Reduce(self.__binary())
        self.__initialize()
        self.finishedComputations = []
        self.startedComputations = []
        self.started.connect(self.startedHandler)
        self.finished.connect(self.finishedHandler)

    def abortComputation(self):
        traceLogger.debug("entering")
        self.reduce.signal("SIGINT")

    def compute(self,c,i,silent=False):
        self.wait()
        traceLogger.debug("after wait, %s"% c)
        self.computation = QtReduceComputation()
        self.computation.command = c
        self.computation.row = i
        self.computation.evaluating = True
        self.computation.silent = silent
        self.startedComputations.append(self.computation)
        self.start()

    def finishedHandler(self):
        signalLogger.debug("emitting QtReduce.endComputation %s" %
                           self.computation)
        while self.finishedComputations:
            self.endComputation.emit(self.finishedComputations.pop(0))

    def run(self):
        c = self.computation.command
        traceLogger.debug("computing %s" % c)
        a = self.reduce.compute(c)
        self.computation.processAnswer(a)
        self.computation.evaluating = False
        self.finishedComputations.append(self.computation)
        if self.computation.error:
            a = self.reduce.compute(" 0.0.")
            traceLogger.debug("error recovery %s" % a)

    def startedHandler(self):
        signalLogger.debug("emitting QtReduce.startComputation %s" %
                           self.computation)
        while self.startedComputations:
            self.startComputation.emit(self.startedComputations.pop(0))

    def __binary(self):
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
            mbox = QMessageBox()
            mbox.setIcon(QMessageBox.Warning)
            mbox.setWindowModality(Qt.WindowModal)
            mbox.setWindowTitle(tit)
            mbox.setText(txt)
            mbox.setInformativeText(itxt)
            mbox.exec_()
            binary = QtReduceDefaults.REDUCE
        return binary

    def __initialize(self):
        self.reduce.compute("off nat$")
        self.reduce.compute("load_package utf8$")
        self.reduce.compute("on utf8,utf8exp,utf82d$")
        self.reduce.compute("on comp$")
        self.reduce.compute("lisp procedure lr_aprint(u); mathprint u$")
        self.reduce.compute("lisp procedure qr_render(u);"
                     "mathprint car u where !*nat=t$")
        self.reduce.compute("lisp put('qr_render,'psopfn,'qr_render)$")
        self.reduce.compute("off comp,msg$")
        self.reduce.compute("lisp if 'psl memq lispsystem!* then remd 'break$")


class QtReduceComputation(QObject):

    def __init__(self,d={}):
        self.statCounter = int(d.get('statCounter',0))
        self.command = d.get('command','')
        self.symbolic = self.__bool(d.get('symbolic',False))
        self.result = d.get('result','')
        self.nextPrompt = d.get('nextPrompt','')
        self.time = int(d.get('time',0))
        self.gcTime = int(d.get('gcTime',0))
        self.accTime = int(d.get('accTime',0))
        self.accGcTime = int(d.get('accGcTime',0))
        self.error = self.__bool(d.get('error',False))
        self.errorText = d.get('errorText','')
        self.evaluating = self.__bool(d.get('evaluating',False))
        self.evaluated = self.__bool(d.get('evaluated',False))
        self.silent = self.__bool(d.get('silent',False))
        self.row = int(d.get('row',-1))

    def __repr__(self):
        l = self.toDict().items()
        l.sort()
        string = "[%-11s = %s\n" % (l[0][0], l[0][1])
        for x in l[1:-1]:
            string += " %-11s = %s\n" % (x[0], x[1])
        string += " %-11s = %s]" % (l[-1][0], l[-1][1])
        return string

    def copy(self):
        copy = QtReduceComputation(self.toDict())
        return copy

    def processAnswer(self,a):
        self.statCounter = a['statcounter']
        self.symbolic = a['symbolic']
        self.result = a['result'] or ''
        if self.result:
            self.result = self.result.replace('\n',' ')
        self.nextPrompt = a['nextpompt'] or ''
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
            self.errorText = s or 'INCOMPLETE INPUT'
        if a['time'] != -1:
            self.time = a['time']
            self.accTime += self.time
        if a['gctime'] != -1:
            self.gcTime = a['gctime']
            self.accGcTime += self.gcTime
        self.error = a['error']
        self.evaluated = True

    def toDict(self):
        return {'statCounter':str(self.statCounter),
                'command':str(self.command),
                'symbolic':str(self.symbolic),
                'result':str(self.result),
                'nextPrompt':str(self.nextPrompt),
                'time':str(self.time),
                'gcTime':str(self.gcTime),
                'accTime':str(self.accTime),
                'accGcTime':str(self.accGcTime),
                'error':str(self.error),
                'errorText':str(self.errorText),
                'silent':str(self.silent),
                'evaluating':str(self.evaluating),
                'evaluated':str(self.evaluated),
                'row':str(self.row)}

    def __bool(self,s):
        if s in [0, '0', False, 'False']:
            return False
        return bool(s)

    def __str(self,s):
        if s == 'None':
            return None
        return str(s)


class QtReduceModel(QAbstractTableModel):

    RawDataRole = Qt.UserRole

    endComputation = Signal(object)
    startComputation = Signal(object)

    def __init__(self,parent=None):
        super(QtReduceModel,self).__init__(parent)
        self.model = []
        self.reduce = QtReduce(self)
        self.reduce.startComputation.connect(self.startComputation)
        self.reduce.endComputation.connect(self.endComputationHandler)
        self.reduce.compute("$ % For initializing the status bar",-1,silent=True)

    def abortComputation(self):
        self.reduce.abortComputation()

    def columnCount(self,index):
        if index == QModelIndex():
            return 1
        traceLogger.warning("called with valid parent %s" % index)
        return 0

    def compute(self,index):
        traceLogger.debug(index.row())
        computation = self.data(index,QtReduceModel.RawDataRole)
        self.reduce.compute(computation.command,index.row())

    def computeAndSetData(self,index,value,role=Qt.EditRole):
        if role != QtReduceModel.RawDataRole:
            traceLogger.warning("role %s not supported" % role)
        self.model[index.row()] = value
        self.compute(index)

    def data(self,index,role):
        computation = self.model[index.row()]
        if role == QtReduceModel.RawDataRole:
            return computation
        if role == Qt.DisplayRole:
            return computation.__repr__()
#        traceLogger.debug("called with unhandled role %s" % role)
        return None

    def deleteOutput(self):
        for computation in self.model:
            computation.result = ''
            computation.evaluated = False
        self.dataChanged.emit(self.index(0,0),self.index(len(self.model)-1,0))

    def endComputationHandler(self,computation):
        if not computation.silent:
            row = computation.row
            if row == -1:
                traceLogger.critical("invalid row -1")
            self.setData(self.index(row,0),computation,QtReduceModel.RawDataRole)
        self.endComputation.emit(computation)

    def flags(self,index):
        return(Qt.ItemIsSelectable|Qt.ItemIsEditable|Qt.ItemIsEnabled)

    def headerData(self,section,orientation,role=Qt.DisplayRole):
        if orientation == Qt.Horizontal:
            return super(QtReduceModel,self).headerData(section,orientation,role)
        if orientation == Qt.Vertical:
            return super(QtReduceModel,self).headerData(section,orientation,role)
        traceLogger.warning(orientation)
        return None

    def insertRows(self,row,count,index=QModelIndex()):
        self.beginInsertRows(index,row,row+count-1)
        self.model[row:row] = [QtReduceComputation()] * count
        self.endInsertRows()
        return True

    def removeRows(self,row,count,index=QModelIndex()):
        self.beginRemoveRows(index,row,row+count-1)
        self.model[row:row+count] = []
        self.endRemoveRows()
        return True

    def rowCount(self,index=QModelIndex()):
        if index == QModelIndex():
            return len(self.model)
        traceLogger.warning("called with valid parent %s" % index)
        return 0

    def save(self,fileName):
	file = QFile(fileName)
	file.open(QIODevice.WriteOnly | QIODevice.Text)
        xmlWriter = QXmlStreamWriter(file)
        xmlWriter.setAutoFormatting(1)
        xmlWriter.writeStartDocument()
        xmlWriter.writeStartElement("rws")
        for i in range(self.rowCount()):
            c = self.data(self.index(i,0),QtReduceModel.RawDataRole)
            xmlWriter.writeStartElement("group")
            l = c.toDict().items()
            l.sort()
            for x in l:
                xmlWriter.writeStartElement(x[0])
                xmlWriter.writeCharacters(x[1])
                xmlWriter.writeEndElement()
            xmlWriter.writeEndElement()
        xmlWriter.writeEndElement()
        xmlWriter.writeEndDocument()

    def open(self,fileName):
        tempFileName = fileName
        if tempFileName == '':
            tempFileName = self.fileName
        xmlReader = QtReduceXmlReader(self)
        newModel = xmlReader.readModel(tempFileName)
        if not newModel:
            tit = self.tr("Unable to Open File")
            txt = self.tr("The file ")
            txt += '"' + fileName + '" '
            txt += self.tr("cannot be opened.")
            mbox = QMessageBox(self)
            mbox.setIcon(QMessageBox.Information)
            mbox.setWindowModality(Qt.WindowModal)
            mbox.setWindowTitle(tit)
            mbox.setText(txt)
            mbox.exec_()
            return False
        self.removeRows(0,self.rowCount())
        self.insertRows(0,len(newModel))
        for row in range(len(newModel)):
            self.setData(self.index(row,0),newModel[row],self.RawDataRole)
        return True

    def setData(self,index,value,role=Qt.EditRole):
        if role != QtReduceModel.RawDataRole:
            traceLogger.warning("role %s not supported" % role)
        self.model[index.row()] = value
        self.dataChanged.emit(index,index)

    def addComputation(self,computation):
        traceLogger.debug("%s" % computation)
        self.insertRow(self.rowCount(QModelIndex()),QModelIndex())
        self.model[-1] = computation


class QtReduceXmlReader(QXmlDefaultHandler):

    def __init__(self,model):
        super(QtReduceXmlReader,self).__init__()
        self.model = model
        self.modelData = []
        self.key = None
        self.value = ''

    def startElement(self,namespaceURI,localName,qName,atts):
	if localName == "rws":
            return True
        if localName == 'group':
            self.key = None
            self.value = ''
            self.computationDict = {}
            return True
        self.key = localName
        self.value = ''
	return True

    def endElement(self,namespaceURI,localName,qName):
	if localName == "rws":
            return True
        if localName == 'group':
            computation = QtReduceComputation(self.computationDict)
            self.modelData.append(computation)
        self.computationDict[self.key] = self.value
	return True

    def characters(self,ch):
        if self.key:
            self.value += ch
        return True

    def readModel(self,fileName):
	file = QFile(fileName)
	if (file.open(QIODevice.ReadOnly | QIODevice.Text)):
            xmlReader = QXmlSimpleReader()
            xmlReader.setContentHandler(self)
            xmlReader.setErrorHandler(self)
            xmlSource = QXmlInputSource(file)
            xmlReader.parse(xmlSource)
            return self.modelData
        else:
            return  None
