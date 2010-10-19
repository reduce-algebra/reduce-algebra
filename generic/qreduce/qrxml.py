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
from PySide.QtCore import QFile
from PySide.QtCore import QIODevice
from PySide.QtCore import QXmlStreamWriter

from PySide.QtGui import QTextCursor

from PySide.QtXml import QXmlSimpleReader
from PySide.QtXml import QXmlInputSource
from PySide.QtXml import QXmlDefaultHandler

from qrlogging import signalLogger
from qrlogging import traceLogger

from qrformats import ReduceInputBlockFormat
from qrformats import ReduceResultBlockFormat
from qrformats import ReduceNoResultBlockFormat
from qrformats import ReduceErrorBlockFormat

class ReduceXmlReader(QXmlDefaultHandler):
    def __init__(self,document):
        QXmlDefaultHandler.__init__(self)
        self.document = document
        self.mode = None

    def startElement(self,namespaceURI,localName,qName,atts):
	if localName == "rws":
            self.mode = None
            return True
        elif localName == "reduceInput":
            self.mode = 0
	elif localName == "reduceOutput":
            self.mode = 1
	elif localName == "reduceNoOutput":
            self.mode = 2
	elif localName == "reduceError":
            self.mode = 3
        else:
            throw('Unknown tag ' + localName)
        if not self.cursor.atStart():
            self.cursor.insertBlock()
        cur = self.cursor
        self.labelBlock(cur,self.mode)
	return True

    def endElement(self,namespaceURI,localName,qName):
	self.mode = None
	return True

    def characters(self,ch):
        if self.mode == 0:
            self.cursor.insertText(ch)
        if self.mode == 1:
            self.cursor.insertText(ch)
        if self.mode == 2:
            self.cursor.insertText(ch)
        if self.mode == 3:
            self.cursor.insertText(ch)
        return True

    def open(self,fileName):
	file = QFile(fileName)
	if (file.open(QIODevice.ReadOnly | QIODevice.Text)):
            self.mode = None
            self.document.clear()
            self.cursor = QTextCursor(self.document)
            self.cursor.movePosition(QTextCursor.Start)
            xmlReader = QXmlSimpleReader()
            xmlReader.setContentHandler(self)
            xmlReader.setErrorHandler(self)
            xmlSource = QXmlInputSource(file)
            xmlReader.parse(xmlSource)
            return True
        else:
            return False

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

class ReduceXmlWriter:
    def __init__(self,document):
        self.document = document

    def save(self,fileName):
	file = QFile(fileName)
	if file.open(QIODevice.WriteOnly | QIODevice.Text):
            xmlWriter = QXmlStreamWriter(file)
            xmlWriter.setAutoFormatting(1)
            xmlWriter.writeStartDocument()
            xmlWriter.writeStartElement("rws")
            self.__saveWorksheet(xmlWriter)
            xmlWriter.writeEndElement()
            xmlWriter.writeEndDocument()

    def __saveWorksheet(self,xmlWriter):
        block = self.document.firstBlock()
        while block.length() != 0:
            if block.userState() == 0:
                xmlWriter.writeStartElement("reduceInput")
            elif block.userState() == 1:
                xmlWriter.writeStartElement("reduceOutput")
            elif block.userState() == 2:
                xmlWriter.writeStartElement("reduceNoOutput")
            elif block.userState() == 3:
                xmlWriter.writeStartElement("reduceError")
            xmlWriter.writeCharacters(block.text())
            xmlWriter.writeEndElement()
            block = block.next()
