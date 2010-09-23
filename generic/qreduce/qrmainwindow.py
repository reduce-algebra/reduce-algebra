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

import sys
import os

from PySide.QtCore import Qt
from PySide.QtCore import SIGNAL
from PySide.QtCore import SLOT

from PySide.QtGui import QMainWindow
from PySide.QtGui import QFont
from PySide.QtGui import QLabel
from PySide.QtGui import QFontMetrics
from PySide.QtGui import QAction
from PySide.QtGui import QMessageBox
from PySide.QtGui import QKeySequence
from PySide.QtGui import QFileDialog

from qrworksheet import QtReduceWorksheet

class QtReduceMainWindow(QMainWindow):
    sheets = [];

    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent)
        self.setUnifiedTitleAndToolBarOnMac(1)
        self.__initStatusBar()
        self.__createMenus()
        self.__createActions()
        self.__createWorksheet()
        self.__setWidthByFont(82)
        self.__setHeightByFont(24)
        self.setTitle(self.worksheet.fileName,0)
        self.setCentralWidget(self.worksheet)
        self.show()
        self.raise_()
#         loadOptions();
#         setupFileMenu();
#         setupEditMenu();
#         setupToolBar();
#         setupWorksheets();

    def __setWidthByFont(self,n,adaptHeight=False):
        oldWidth = self.width()
        width = n * QFontMetrics(self.worksheet.font()).width('m')
        self.setFixedWidth(width)
        if adaptHeight:
            factor = float(self.width())/float(oldWidth)
            self.resize(1,int(self.height()*factor))

    def __setHeightByFont(self,n):
        height = n * QFontMetrics(self.worksheet.font()).height()
        self.resize(1,height)

    def __initStatusBar(self):
        self.statusBar = self.statusBar()
        font = QFont()
        font.setPixelSize(10)
        self.statusBar.setFont(font)
        self.reduceMode = QLabel()
        self.reduceMode.setFixedWidth(QFontMetrics(font).width('Mode: Algebraic'))
        self.reduceMode.setFont(font)
        self.statusBar.addPermanentWidget(self.reduceMode)
        self.reduceTime = QLabel()
        self.reduceTime.setFont(font)
        self.statusBar.addPermanentWidget(self.reduceTime)
        self.reduceStatus = QLabel()
        self.reduceStatus.setFont(font)
        self.reduceStatus.setText(" Initialising")
        self.statusBar.addWidget(self.reduceStatus)

    def __createMenus(self):
        self.fileMenu = self.menuBar().addMenu(self.tr("&File"))
        self.viewMenu = self.menuBar().addMenu(self.tr("&View"))
        self.develMenu = self.menuBar().addMenu(self.tr("Develop"))
        self.helpMenu = self.menuBar().addMenu(self.tr("&Help"))

    def __createActions(self):
        self.__createFileActions()
        self.__createViewActions()
        self.__createDevelActions()
        self.__createHelpActions()

    def __createHelpActions(self):
        self.aboutAct = QAction(self.tr("&About"), self)
        self.helpMenu.addAction(self.aboutAct)
        self.connect(self.aboutAct, SIGNAL("triggered()"), self.about)

    def about(self):
        QMessageBox.about(self, self.tr("About QReduce"),self.tr(
                '<center><h3>QReduce 0.2</h3>'
                '<p>&copy; 2009-2010 Thomas Sturm</center>'
                '<p>Redistribution and use in source and binary forms, with '
                'or without modification, are permitted provided that the '
                'following conditions are met:'
                '<ul>'
                '<li>Redistributions of source code must retain the relevant '
                'copyright notice, this list of conditions and the following '
                'disclaimer.'
                '<li>Redistributions in binary form must reproduce the above '
                'copyright notice, this list of conditions and the following '
                'disclaimer in the documentation and/or other materials '
                'provided with the distribution. '
                '</ul>'
                '<hr><small><strong>Disclaimer:</strong> '
                'This software is provided by the copyright holders and '
                'contributors "as is" and any express or implied warranties, '
                'including, but not limited to, the implied warranties of '
                'merchantability and fitness for a particular purpose are '
                'disclaimed. In no event shall the copyright owners or '
                'contributors be liable for any direct, indirect, incidental, '
                'special, exemplary, or consequential damages (including, but '
                'not limited to, procurement of substitute goods or services; '
                'loss of use, data, or profits; or business interruption) '
                'however caused and on any theory of liability, whether in '
                'contract, strict liability, or tort (including negligence or '
                'otherwise) arising in any way out of the use of this '
                'software, even if advised of the possibility of such damage.'
                '</small><hr>'))

    def __createFileActions(self):
        self.openAct = QAction(self.tr("&Open..."), self)
        self.openAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_O))
        self.fileMenu.addAction(self.openAct)
        self.connect(self.openAct, SIGNAL("triggered()"), self.open)

        self.saveAct = QAction(self.tr("&Save"), self)
        self.saveAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_S))
        self.fileMenu.addAction(self.saveAct)
        self.connect(self.saveAct, SIGNAL("triggered()"), self.save)

        self.saveAsAct = QAction(self.tr("Save As..."), self)
        self.saveAsAct.setShortcut(
            QKeySequence(Qt.ShiftModifier|Qt.ControlModifier|Qt.Key_S))
        self.fileMenu.addAction(self.saveAsAct)
        self.connect(self.saveAsAct, SIGNAL("triggered()"), self.saveAs)

    def open(self):
        title = self.tr("Open Reduce Worksheet")
        fn = self.worksheet.fileName.__str__()
        print fn
        if fn == '':
            fn = '$HOME'
        print fn
        path = os.path.dirname(os.path.abspath(fn))
        print path
        filter = self.tr("Reduce Worksheets (*.rws)")
        fileName = QFileDialog.getOpenFileName(None,title,path,filter)
        if fileName == '':
            return
        if not fileName.endsWith(".rws"):
            fileName += ".rws"
        self.worksheet.open(fileName)

    def save(self):
        if self.worksheet.fileName == '':
            self.saveAs()
        else:
            self.worksheet.save('')

    def saveAs(self):
        title = self.tr("Save Reduce Worksheet")
        path = os.path.dirname(os.path.abspath(self.worksheet.fileName.__str__()))
        filter = self.tr("Reduce Worksheets (*.rws)")
        diag = QFileDialog()
#        fileName = diag.getSaveFileName(self,self.tr("Save File"),
#                                        "", self.tr("Reduce Worksheets (*.rws)"),
#                                        None,QFileDialog.DontUseNativeDialog)
        fileName = diag.getSaveFileName(None,title,path,filter)
        if fileName == '':
            return
        if not fileName.endsWith(".rws"):
            fileName += ".rws"
        self.worksheet.open(fileName)
        self.activateWindow()
        if fileName == '':
            return
        if not fileName.endsWith(".rws"):
            fileName += ".rws"
        self.worksheet.save(fileName)

    def __createViewActions(self):
        self.zoomInAct = QAction(self.tr("&Zoom In"), self)
        self.zoomInAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Plus))
        self.viewMenu.addAction(self.zoomInAct)
        self.connect(self.zoomInAct, SIGNAL("triggered()"), self.zoomIn)

        self.zoomOutAct = QAction(self.tr("&Zoom Out"), self)
        self.zoomOutAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Minus))
        self.viewMenu.addAction(self.zoomOutAct)
        self.connect(self.zoomOutAct, SIGNAL("triggered()"), self.zoomOut)

        self.zoomDefAct = QAction(self.tr("&Zoom Default"), self)
        self.zoomDefAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Equal))
        self.viewMenu.addAction(self.zoomDefAct)
        self.connect(self.zoomDefAct, SIGNAL("triggered()"), self.zoomDef)

    def zoomIn(self):
        self.worksheet.setupFont(self.worksheet.font().pixelSize()+1)
        self.__setWidthByFont(82,True)

    def zoomOut(self):
        self.worksheet.setupFont(max(self.worksheet.font().pixelSize()-1,8))
        self.__setWidthByFont(82,True)

    def zoomDef(self):
        self.worksheet.setupFont(14)
        self.__setWidthByFont(82,True)

    def __createDevelActions(self):
        self.testAct = QAction(self.tr("Test"), self)
        self.testAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_T))
        self.develMenu.addAction(self.testAct)
        self.connect(self.testAct, SIGNAL("triggered()"), self.test)

    def test(self):
        self.worksheet.zoomIn(10)

    def showMessage(self,message):
	self.statusBar.showMessage(message,0)

    def __createWorksheet(self):
        self.worksheet = QtReduceWorksheet(self)
	self.connect(self.worksheet,SIGNAL("fileNameChanged()"),self.setTitle)
	self.connect(self.worksheet,SIGNAL("textChanged()"),
                     self.worksheet.textChangedHandler)
	self.connect(self.worksheet,SIGNAL("cursorPositionChanged()"),
                     self.worksheet.cursorPositionChangedHandler)
	self.connect(self.worksheet.reduce,SIGNAL("newReduceResult()"),
                     self.worksheet.newReduceResultHandler)
        self.worksheet.compute('$',True)

    def setTitle(self,message,modified):
        msg = message.split('/')[-1] or 'untitled'
        if modified:
            msg = '*' + msg + '*'
        self.setWindowTitle(msg)

    def closeEvent(self,ev):
        while self.worksheet.modified:
            button = self.__savediag()
            if button == QMessageBox.Save:
                self.save()
            elif button == QMessageBox.Discard:
                del self.worksheet.reduce
                ev.accept()
                return
            elif button == QMessageBox.Cancel:
                ev.ignore()
                return
        del self.worksheet.reduce
        ev.accept()

    def __savediag(self):
        diag = QMessageBox(self)
        msg = '<b>Do you want to save the changes in your worksheet "'
        msg += self.worksheet.fileName.split('/')[-1] or 'untitled'
        msg += '"?</b><p><small>Otherwise they will get lost.</small>'
        diag.setInformativeText(msg)
        diag.setStandardButtons(QMessageBox.StandardButton.Discard |
                                QMessageBox.StandardButton.Cancel |
                                QMessageBox.StandardButton.Save)
        diag.setWindowModality(Qt.WindowModal)
        return diag.exec_()
