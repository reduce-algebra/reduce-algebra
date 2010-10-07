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
from PySide.QtCore import Signal

from PySide.QtGui import QMainWindow
from PySide.QtGui import QStatusBar
from PySide.QtGui import QMenuBar
from PySide.QtGui import QFont
from PySide.QtGui import QLabel
from PySide.QtGui import QFontMetrics
from PySide.QtGui import QAction
from PySide.QtGui import QMessageBox
from PySide.QtGui import QKeySequence
from PySide.QtGui import QFileDialog

from qrworksheet import QtReduceWorksheet
from reduce import Reduce

class QtReduceMainWindow(QMainWindow):
    sheets = [];

    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent)
        self.setUnifiedTitleAndToolBarOnMac(1)
        self.setStatusBar(QtReduceStatusBar(parent))
        self.setMenuBar(QtReduceMenuBar(self,parent))
        self.statusBar().reduceStatus.setText(" Initialising")
        self.__createWorksheet()
        self.statusBar().reduceStatus.setText(" Ready")
        self.__initStatusBarSignals()
        self.__setWidthByFont(83)
        self.__setHeightByFont(24)
        print "before setTitle"
        self.setTitle(self.worksheet.fileName,0)
        self.worksheet.modified = 0
        self.setCentralWidget(self.worksheet)
        self.show()
        self.raise_()
#         loadOptions();
#         setupFileMenu();
#         setupEditMenu();
#         setupToolBar();
#         setupWorksheets();

    def __initStatusBarSignals(self):
        self.worksheet.newResult.connect(
            self.statusBar().newReduceResultHandler,
            type=Qt.DirectConnection)
        self.worksheet.newComputation.connect(
            self.statusBar().newReduceComputationHandler,
            type=Qt.DirectConnection)
        print "got here"
        #self.worksheet.reduce.newReduceResult.connect(
        #    self.worksheet.newReduceResultHandler,
        #    type=Qt.DirectConnection)
        #self.worksheet.reduce.newReduceResult.connect(
        #    self.statusBar().newReduceResultHandler,
        #    type=Qt.DirectConnection)
        #self.worksheet.reduce.newReduceComputation.connect(
        #    self.statusBar().newReduceComputationHandler,
        #    type=Qt.DirectConnection)
        self.worksheet.fileNameChanged.connect(
            self.setTitle,
            type=Qt.DirectConnection)

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

    # File Actions
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
        fileName = str(fileName[0])
        if fileName == '':
            return
        if not fileName.endswith(".rws"):
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
        fileName = QFileDialog.getSaveFileName(self,title,path,filter)
        fileName = str(fileName[0])
        print "fileName=",fileName
        if fileName == '':
            return
        if not fileName.endswith(".rws"):
            fileName += ".rws"
        self.worksheet.save(fileName)
        self.activateWindow()

    # View Actions
    def zoomIn(self):
        self.worksheet.setupFont(self.worksheet.font().pixelSize()+1)
        self.__setWidthByFont(83,True)

    def zoomOut(self):
        self.worksheet.setupFont(max(self.worksheet.font().pixelSize()-1,8))
        self.__setWidthByFont(83,True)

    def zoomDef(self):
        self.worksheet.setupFont(14)
        self.__setWidthByFont(83,True)

    # Development Actions
    def test(self):
        self.worksheet.zoomIn(10)

    # Help Actions
    def about(self):
        QMessageBox.about(self, self.tr("About QReduce"),self.tr(
                '<center>'
                '<h3>QReduce 0.2</h3>'
                '<p>&copy; 2009-2010 T. Sturm, 2010 C. Zengler'
                '</center>'
                'A worksheet-based GUI for the computer algebra system Reduce.'
                '<p>'
                '<font size="-3">'
                '<hr>'
                '<strong>License: </strong>'
                'Redistribution and use in source and binary forms, with '
                'or without modification, are permitted provided that the '
                'following conditions are met: '
                '(a) Redistributions of source code must retain the relevant '
                'copyright notice, this list of conditions and the following '
                'disclaimer. '
                '(b) Redistributions in binary form must reproduce the above '
                'copyright notice, this list of conditions and the following '
                'disclaimer in the documentation and/or other materials '
                'provided with the distribution. '
                '</font>'
                '<p>'
                '<font size="-3">'
                '<strong>Disclaimer:</strong> '
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
                '</font>'))

    
    def showMessage(self,message):
	self.statusBar.showMessage(message,0)

    def __createWorksheet(self):
        self.worksheet = QtReduceWorksheet(self)

    def setTitle(self,message,modified):
        print "in setTitle", message, modified
        msg = message.split('/')[-1] or 'untitled'
        if modified:
            msg = '*' + msg + '*'
        print "msg=", msg
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
        msg += self.worksheet.fileName.split('/')[-1] or 'untitled' + '"?</b><p>'
        msg += '<font size="-1">Otherwise they will get lost.</font>'
        diag.setText(msg)
        diag.setStandardButtons(QMessageBox.StandardButton.Discard |
                                QMessageBox.StandardButton.Cancel |
                                QMessageBox.StandardButton.Save)
        diag.setWindowModality(Qt.WindowModal)
        return diag.exec_()


class QtReduceStatusBar(QStatusBar):

    def __init__(self,parent=None):
        QStatusBar.__init__(self,parent)
        self.symbolic = None
        font = QFont()
        font.setPixelSize(10)
        self.setFont(font)
        self.reduceMode = QLabel()
        self.reduceMode.setFixedWidth(QFontMetrics(font).width('Mode: Algebraic'))
        self.reduceMode.setFont(font)
        self.reduceTime = QLabel()
        self.reduceTime.setFont(font)
        self.reduceStatus = QLabel()
        self.reduceStatus.setFont(font)
        self.addPermanentWidget(self.reduceMode)
        self.addPermanentWidget(self.reduceTime)
        self.addWidget(self.reduceStatus)

    def newReduceResultHandler(self,computation):
        self.__updateStatus(computation.evaluating)
        self.__updateTime(computation.accTime,computation.accGcTime)
        self.__updateMode(computation.symbolic)

    def newReduceComputationHandler(self,computation):
        self.__updateStatus(computation.evaluating)

    def __updateMode(self,symbolic):
        if symbolic != self.symbolic:
            self.symbolic = symbolic
            if self.symbolic:
                self.reduceMode.setText('Mode: Symbolic')
            else:
                self.reduceMode.setText('Mode: Algebraic')

    def __updateTime(self,time,gcTime):
        timeStr = "%.2f s" % (float(time + gcTime)/1000)
        self.reduceTime.setText("Time: " + timeStr)

    def __updateStatus(self,evaluating):
        if evaluating:
            self.reduceStatus.setText(" Evaluating")
        else:
            self.reduceStatus.setText(" Ready")


class QtReduceMenuBar(QMenuBar):

    def __init__(self,mainWindow,parent=None):
        QMenuBar.__init__(self,parent)
        self.main = mainWindow
        self.__createMenus()
        self.__createActions()

    def __createMenus(self):
        self.fileMenu = self.addMenu(self.tr("&File"))
        self.viewMenu = self.addMenu(self.tr("&View"))
        self.develMenu = self.addMenu(self.tr("Develop"))
        self.helpMenu = self.addMenu(self.tr("&Help"))

    def __createActions(self):
        self.__createFileActions()
        self.__createViewActions()
        self.__createDevelActions()
        self.__createHelpActions()

    def __createFileActions(self):
        self.openAct = QAction(self.tr("&Open..."), self)
        self.openAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_O))
        self.fileMenu.addAction(self.openAct)
        self.openAct.triggered.connect(self.main.open,type=Qt.DirectConnection)

        self.saveAct = QAction(self.tr("&Save"), self)
        self.saveAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_S))
        self.fileMenu.addAction(self.saveAct)
        self.saveAct.triggered.connect(self.main.save,type=Qt.DirectConnection)

        self.saveAsAct = QAction(self.tr("Save As..."), self)
        self.saveAsAct.setShortcut(
            QKeySequence(Qt.ShiftModifier|Qt.ControlModifier|Qt.Key_S))
        self.fileMenu.addAction(self.saveAsAct)
        self.saveAsAct.triggered.connect(self.main.saveAs,type=Qt.DirectConnection)

    def __createViewActions(self):
        self.zoomInAct = QAction(self.tr("&Zoom In"), self)
        self.zoomInAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Plus))
        self.viewMenu.addAction(self.zoomInAct)
        self.zoomInAct.triggered.connect(self.main.zoomIn,type=Qt.DirectConnection)

        self.zoomOutAct = QAction(self.tr("&Zoom Out"), self)
        self.zoomOutAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Minus))
        self.viewMenu.addAction(self.zoomOutAct)
        self.zoomOutAct.triggered.connect(self.main.zoomOut,type=Qt.DirectConnection)

        self.zoomDefAct = QAction(self.tr("&Zoom Default"), self)
        self.zoomDefAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Equal))
        self.viewMenu.addAction(self.zoomDefAct)
        self.zoomDefAct.triggered.connect(self.main.zoomDef,type=Qt.DirectConnection)

    def __createDevelActions(self):
        self.testAct = QAction(self.tr("Test"), self)
        self.testAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_T))
        self.develMenu.addAction(self.testAct)
        self.testAct.triggered.connect(self.main.test,type=Qt.DirectConnection)

    def __createHelpActions(self):
        self.aboutAct = QAction(self.tr("&About"), self)
        self.helpMenu.addAction(self.aboutAct)
        self.aboutAct.triggered.connect(self.main.about,type=Qt.DirectConnection)
