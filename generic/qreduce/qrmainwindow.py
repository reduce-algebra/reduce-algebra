# ----------------------------------------------------------------------
# $Id$
# ----------------------------------------------------------------------
# Copyright (c) 2009 T. Sturm, 2010 T. Sturm, C.Zengler
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

from PySide.QtCore import QFileInfo
from PySide.QtCore import QSettings
from PySide.QtCore import Signal
from PySide.QtCore import QSize
from PySide.QtCore import Qt

from PySide.QtGui import QAbstractItemView
from PySide.QtGui import QApplication
from PySide.QtGui import QHeaderView
from PySide.QtGui import QMainWindow
from PySide.QtGui import QStatusBar
from PySide.QtGui import QMenu
from PySide.QtGui import QMenuBar
from PySide.QtGui import QFont
from PySide.QtGui import QLabel
from PySide.QtGui import QFontMetrics
from PySide.QtGui import QAction
from PySide.QtGui import QMessageBox
from PySide.QtGui import QKeySequence
from PySide.QtGui import QFileDialog
from PySide.QtGui import QIcon
from PySide.QtGui import QTableView
from PySide.QtGui import QToolBar
from PySide.QtGui import QStyle
from PySide.QtGui import QTextEdit

from qrcontroller import QtReduceController

from qrlogging import signalLogger
from qrlogging import traceLogger

from qrworksheet import QtReduceWorksheet

from qrpreferences import QtReducePreferencePane

from qrdefaults import QtReduceDefaults
from qrdefaults import QtReduceIconSets

from types import StringType


class QtReduceMainWindow(QMainWindow):
    iconSetChanged = Signal(StringType)
    iconSizeChanged = Signal(StringType)
    toolButtonStyleChanged = Signal(StringType)

    def __init__(self, parent=None):
        super(QtReduceMainWindow,self).__init__(parent)
        self.setWindowIcon(QIcon(sys.path[0] + "/" + "Bumblebee.png"))
        self.setUnifiedTitleAndToolBarOnMac(True)
        self.controller = QtReduceController(self)
        self.setCentralWidget(self.controller.view)
        self.__createPreferences()
        self.__initTitleBar()
        self.__createStatusBar()
        self.__createActions()
        self.__createMenus()
        self.__createToolBar()
        self.__resizeByFont(QtReduceDefaults.WIDTH,QtReduceDefaults.HEIGHT)
        self.raise_()
        self.show()
        self.rawModelView = QtReduceTableView(self)
        self.rawModelView.setModel(self.controller.model)

    def about(self):
        QMessageBox.about(self, self.tr("About QReduce"),self.tr(
            '<span style="font-size:x-large;font-weight:bold;color:#000000">'
            'QReduce'
            '</span>'
            '<p>'
            '<span style="font-weight:normal;">'
            'Version 0.2'
            '</span>'
            '<p>'
            '<span style="font-weight:normal;">'
            'A Worksheet-Oriented GUI '
            'for the Computer Algebra System Reduce'
            '</span>'
            '<p>'
            '<span style="font-size:small;font-weight:normal;color:#808080">'
            '&copy; 2009 T. Sturm, 2010 T. Sturm, C. Zengler'
            '</span>'
            '</span>'))

    def closeEvent(self,ev):
        while self.isWindowModified():
            button = self.__savediag()
            if button == QMessageBox.Save:
                self.save()
            elif button == QMessageBox.Discard:
                del self.controller.model.reduce.reduce
                ev.accept()
                return
            elif button == QMessageBox.Cancel:
                ev.ignore()
                return
        del self.controller.model.reduce.reduce
        ev.accept()

    def currentFontChangedHandler(self,font):
        signalLogger.debug("font=%s" % font)
        self.controller.view.currentFontChangedHandler(font)
        self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    def currentSizeChangedHandler(self,size):
        self.controller.view.currentSizeChangedHandler(size)

    def license_(self):
        lic = QTextEdit(self)
        lic.setWindowFlags(Qt.Window)
        lic.setWindowTitle("QReduce FreeBSD License")
        font = lic.font()
        font.setFamily('')
        font.setFixedPitch(True)
        font.setKerning(0)
        font.setWeight(QFont.Normal)
        font.setItalic(False)
        lic.setFont(font)
        lic.setText(
            'Copyright (c) 2009 T. Sturm, 2010 T. Sturm, C. Zengler'
            '<p>'
            'All rights reserved.'
            '<p>'
            'Redistribution and use in source and binary forms, with '
            'or without modification, are permitted provided that the '
            'following conditions are met:'
            '<ol>'
            '<li>Redistributions of source code must retain the relevant '
            'copyright notice, this list of conditions and the following '
            'disclaimer. '
            '<p>'
            '<li>Redistributions in binary form must reproduce the above '
            'copyright notice, this list of conditions and the following '
            'disclaimer in the documentation and/or other materials '
            'provided with the distribution. '
            '</ol>'
            '<p>'
            'THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND '
            'CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, '
            'INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF '
            'MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE '
            'DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR '
            'CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, '
            'SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT '
            'NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; '
            'LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) '
            'HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN '
            'CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR '
            'OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS '
            'SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.'
            '</span>')
        lic.setReadOnly(True)
        w = 66 * lic.fontMetrics().width('m')
        h = 36 * lic.fontMetrics().height()
        lic.resize(w,h)
        lic.show()
        lic.raise_()

    def open(self):
        title = self.tr("Open Reduce Worksheet")
        fn = self.controller.fileName().__str__()
        if fn == '':
            fn = '$HOME'
        path = os.path.dirname(os.path.abspath(fn))
        traceLogger.debug("path=%s" % path)
        filter = self.tr("Reduce Worksheets (*.rws);;All Files (*.*)")
        fileName = QFileDialog.getOpenFileName(self,title,path,filter)
        fileName = str(fileName[0])
        traceLogger.debug("fileName=%s" % fileName)
        if fileName is '':
            return
        if not fileName.endswith(".rws"):
            fileName += ".rws"
        return self.controller.open(fileName)

    def openRecentFile(self):
        action = self.sender()
        if action:
            self.controller.open(action.data())

    def save(self):
        if self.controller.fileName() == '':
            self.saveAs()
        else:
            self.controller.save()

    def saveAs(self):
        title = self.tr("Save Reduce Worksheet")
        path = os.path.dirname(os.path.abspath(self.controller.fileName().__str__()))
        filter = self.tr("Reduce Worksheets (*.rws)")
        fileName = QFileDialog.getSaveFileName(self,title,path,filter)
        fileName = str(fileName[0])
        traceLogger.debug("fileName=%s" % fileName)
        if fileName == '':
            return
        if not fileName.endswith(".rws"):
            fileName += ".rws"
        self.controller.saveAs(fileName)
        self.activateWindow()

    def setTitle(self,fullPath):
        traceLogger.debug("fullPath=%s" % fullPath)
        if fullPath is '':
            self.setWindowTitle("[*]" + self.tr("Untitled"))
        else:
            info = QFileInfo(fullPath)
            self.setWindowFilePath(info.absolutePath())
            self.setWindowTitle("[*]" + info.fileName())

    def showMessage(self,message):
	self.statusBar().showMessage(message,0)

    def toggleRawModel(self):
        if self.rawModelView.isVisible():
            self.rawModelView.hide()
            self.rawModelAct.setText('Show Raw Model')
        else:
            self.rawModelView.show()
            self.rawModelView.raise_()
            self.rawModelAct.setText('Hide Raw Model')

    def test(self):
        None

    def toggleFullScreen(self):
        if self.isFullScreen():
            self.showNormal()
            self.fullScreenAct.setText("Enter Full Screen")
        else:
            self.showFullScreen()
            self.fullScreenAct.setText("Exit Full Screen")

    def updateActionIcons(self):
        for act in [self.openAct,
                    self.saveAct,
                    self.saveAsAct,
                    self.quitAct,
                    self.preferencesAct,
                    self.zoomDefAct,
                    self.zoomInAct,
                    self.zoomOutAct,
                    self.fullScreenAct,
                    self.insertAboveAct,
                    self.insertBelowAct,
                    self.evalAct,
                    self.abortAct,
                    self.rawModelAct,
                    self.testAct,
                    self.aboutAct,
                    self.licenseAct]:
            act.setIcon(QtReduceIconSets().icon(act))

    def zoomDef(self):
        self.controller.view.zoomDef()
        #self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    def zoomIn(self):
        self.controller.view.zoomIn()
        #self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    def zoomOut(self):
        self.controller.view.zoomOut()
        #self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    def __createActions(self):
        self.openAct = QAction(self.tr("Open ..."), self,
                               iconText=self.tr("Open"),
                               shortcut=QKeySequence(QKeySequence.Open),
                               triggered=self.open)

        self.saveAct = QAction(self.tr("Save"), self,
                               shortcut=QKeySequence(QKeySequence.Save),
                               triggered=self.save)

        self.saveAsAct = QAction(self.tr("Save As ..."), self,
                                 iconText=self.tr("Save As"),
                                 shortcut=QKeySequence(QKeySequence.SaveAs),
                                 triggered=self.saveAs)

        self.quitAct = QAction(self.tr("Quit"), self,
                               menuRole=QAction.QuitRole,
                               shortcut=QKeySequence(QKeySequence.Quit),
                               triggered=self.close)

        self.preferencesAct = QAction(self.tr("Preferences ..."), self,
                                      menuRole=QAction.PreferencesRole,
                                      shortcut=QKeySequence(
                                          QKeySequence.Preferences),
                                      triggered=self.preferencePane.show)

        self.zoomDefAct = QAction(self.tr("Zoom Default"), self,
                                  shortcut=QKeySequence(Qt.ControlModifier|
                                                        Qt.Key_Equal),
                                  triggered=self.zoomDef)

        self.zoomInAct = QAction(self.tr("Zoom In"), self,
                                 shortcut=QKeySequence(QKeySequence.ZoomIn),
                                 triggered=self.zoomIn)

        self.zoomOutAct = QAction(self.tr("Zoom Out"), self,
                                 shortcut=QKeySequence(QKeySequence.ZoomOut),
                                 triggered=self.zoomOut)

        self.fullScreenAct = QAction(self.tr("Enter Full Screen"), self,
                                 triggered=self.toggleFullScreen)

        self.evalSelAct = QAction(self.tr("Evaluate Selection"), self,
                               enabled=False,
                               triggered=self.controller.evaluateSelection)

        self.evalAct = QAction(self.tr("Evaluate All"), self,
                               enabled=True,
                               triggered=self.controller.evaluateAll)

        self.deleteAct = QAction(self.tr("Delete Group"), self,
                                      shortcut=QKeySequence(Qt.ControlModifier|
                                                            Qt.Key_Backspace),
                                      enabled=True,
                                      triggered=self.controller.deleteRowOrPreviousRow)

        self.insertAboveAct = QAction(self.tr("Insert Group Above"), self,
                                      shortcut=QKeySequence(Qt.ShiftModifier|
                                                            Qt.ControlModifier|
                                                            Qt.Key_Return),
                                      enabled=True,
                                      triggered=self.controller.insertAbove)

        self.insertBelowAct = QAction(self.tr("Insert Group Below"), self,
                                      enabled=True,
                                      shortcut=QKeySequence(Qt.ControlModifier|
                                                            Qt.Key_Return),
                                      triggered=self.controller.insertBelow)

        self.abortAct = QAction(self.tr("Abort Evaluation"), self,
                                enabled=False,
                                iconText=self.tr("Abort"),
                                shortcut=QKeySequence(Qt.AltModifier|Qt.Key_C),
                                triggered=self.controller.abortComputation)
        self.controller.acceptAbort.connect(self.abortAct.setEnabled)

        self.rawModelAct = QAction(self.tr("Show Raw Model"), self,
                               enabled=True,
                               triggered=self.toggleRawModel)

        self.testAct = QAction(self.tr("MainWindow::test"), self,
                               enabled=True,
                               shortcut=QKeySequence(Qt.ControlModifier|
                                                     Qt.Key_T),
                               triggered=self.test)

        self.aboutAct = QAction(self.tr("About"), self,
                                menuRole=QAction.AboutRole,
                                triggered=self.about)

        self.licenseAct = QAction(self.tr("License"), self,
                                  triggered=self.license_)

        self.iconSetChanged.connect(self.updateActionIcons)
        self.iconSizeChanged.connect(self.updateActionIcons)

        self.updateActionIcons()

    def __createMenus(self):
        self.recentFileMenu = QtRecentFileMenu(self)
        self.controller.fileNameChanged.connect(self.recentFileMenu.addFile)

        self.fileMenu = self.menuBar().addMenu(self.tr("File"))
        self.fileMenu.addAction(self.openAct)
        self.fileMenu.addMenu(self.recentFileMenu)
        self.fileMenu.addSeparator()
        self.fileMenu.addAction(self.saveAct)
        self.fileMenu.addAction(self.saveAsAct)
        self.fileMenu.addSeparator()
        self.fileMenu.addAction(self.quitAct)

        self.editMenu = self.menuBar().addMenu(self.tr("Edit"))
        self.editMenu.addAction(self.preferencesAct)

        self.viewMenu = self.menuBar().addMenu(self.tr("View"))
        self.viewMenu.addAction(self.fullScreenAct)
        self.viewMenu.addSeparator()
        self.viewMenu.addAction(self.zoomDefAct)
        self.viewMenu.addAction(self.zoomInAct)
        self.viewMenu.addAction(self.zoomOutAct)

        self.worksheetMenu = self.menuBar().addMenu(self.tr("Worksheet"))
        self.worksheetMenu.addAction(self.evalSelAct)
        self.worksheetMenu.addAction(self.evalAct)
        self.worksheetMenu.addSeparator()
        self.worksheetMenu.addAction(self.deleteAct)
        self.worksheetMenu.addSeparator()
        self.worksheetMenu.addAction(self.insertAboveAct)
        self.worksheetMenu.addAction(self.insertBelowAct)
        self.worksheetMenu.addSeparator()
        self.worksheetMenu.addAction(self.abortAct)

        self.develMenu = self.menuBar().addMenu(self.tr("Develop"))
        self.develMenu.addAction(self.rawModelAct)
        self.develMenu.addSeparator()
        self.develMenu.addAction(self.testAct)

        self.helpMenu = self.menuBar().addMenu(self.tr("Help"))
        self.helpMenu.addAction(self.aboutAct)
        self.helpMenu.addAction(self.licenseAct)

    def __createPreferences(self):
        self.preferencePane = QtReducePreferencePane(self)

        self.preferencePane.toolBar.iconSetCombo.currentIndexChanged.connect(
            self.iconSetChanged)
        self.preferencePane.toolBar.iconSetCombo.currentIndexChanged.connect(
            QtReduceIconSets().iconSetChanged)
        self.preferencePane.toolBar.iconSetCombo.currentIndexChanged.connect(
            self.updateActionIcons)

        self.preferencePane.toolBar.iconSizeCombo.currentIndexChanged.connect(
            self.iconSizeChanged)
        self.preferencePane.toolBar.iconSizeCombo.currentIndexChanged.connect(
            QtReduceIconSets().iconSizeChanged)
        self.preferencePane.toolBar.iconSizeCombo.currentIndexChanged.connect(
            self.updateActionIcons)

        self.preferencePane.toolBar.showCombo.currentIndexChanged.connect(
            self.toolButtonStyleChanged)

        self.preferencePane.worksheet.fontCombo.currentFontChanged.connect(
            self.currentFontChangedHandler)

        self.preferencePane.worksheet.sizeCombo.currentIndexChanged.connect(
            self.currentSizeChangedHandler)

    def __createStatusBar(self):
        self.setStatusBar(QtReduceStatusBar(self))
        self.controller.startComputation.connect(
            self.statusBar().startComputationHandler)
        self.controller.endComputation.connect(
            self.statusBar().endComputationHandler)
        self.controller.view.cursorPositionChanged.connect(
            self.statusBar().clearMessage)

    def __createToolBar(self):
        self.toolBar = QtReduceToolBar(self)

        self.toolBar.addAction(self.openAct)
        self.toolBar.addAction(self.saveAct)
        self.toolBar.addAction(self.saveAsAct)
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.zoomOutAct)
        self.toolBar.addAction(self.zoomDefAct)
        self.toolBar.addAction(self.zoomInAct)
        self.toolBar.addSeparator()
        self.toolBar.addAction(self.abortAct)

        self.addToolBar(self.toolBar)

        self.iconSetChanged.connect(self.toolBar.refresh)
        self.iconSizeChanged.connect(self.toolBar.refresh)
        self.toolButtonStyleChanged.connect(self.toolBar.toolButtonStyleChanged)
    def __initTitleBar(self):
        self.setTitle(os.path.dirname(''))
        self.controller.fileNameChanged.connect(self.setTitle)
        self.controller.modified.connect(self.setWindowModified)

    def __savediag(self):
        diag = QMessageBox(self)
        msg = 'Do you want to save the changes in your worksheet "'
        msg += (self.controller.fileName().split('/')[-1] or 'untitled') + '"?'
        diag.setText(msg)
        diag.setInformativeText("Otherwise they will get lost")
        diag.setIcon(QMessageBox.Warning)
        diag.setStandardButtons(QMessageBox.StandardButton.Discard |
                                QMessageBox.StandardButton.Cancel |
                                QMessageBox.StandardButton.Save)
        diag.setWindowModality(Qt.WindowModal)
        return diag.exec_()

    def __resizeByFont(self,columns,lines):
        mwidth = 72 * self.controller.view.fontMetrics().width('m')
        mheight = 9 * self.controller.view.fontMetrics().lineSpacing()
        self.setMinimumSize(mwidth,mheight)
        width = columns * self.controller.view.fontMetrics().width('m')
        height = lines * self.controller.view.fontMetrics().lineSpacing()
        self.resize(width,height)

    def __setWidthByFont(self,n,adaptHeight=False):
        oldWidth = self.width()
        width = n * self.controller.view.fontMetrics().width('m')
        traceLogger.debug("width=%s, n=%s, family=%s, size=%s" %
                          (width,n,self.controller.view.font().family(),
                           self.controller.view.font().pointSize()))
        self.setFixedWidth(width)
        if adaptHeight:
            factor = float(self.width())/float(oldWidth)
            self.resize(1,int(self.height()*factor))

    def __setHeightByFont(self,n):
        height = n * QFontMetrics(self.controller.view.font()).height()
        self.resize(1,height)


class QtReduceStatusBar(QStatusBar):

    def __init__(self,parent=None):
        QStatusBar.__init__(self,parent)
        self.symbolic = None
        font = self.font()
        traceLogger.debug(font.pointSize())
        if os.uname()[0] == "Darwin":
            font.setPointSize(font.pointSize() - 2)
        self.setFont(font)
        self.reduceMode = QLabel()
        self.reduceMode.setFixedWidth(
            QFontMetrics(font).width(self.tr("Mode: Algebraic")))
        self.reduceMode.setFont(font)
        self.reduceTime = QLabel()
        self.reduceTime.setFont(font)
        self.reduceStatus = QLabel()
        self.reduceStatus.setFont(font)
        self.addPermanentWidget(self.reduceMode)
        self.addPermanentWidget(self.reduceTime)
        self.addWidget(self.reduceStatus)
        self.reduceStatus.setText(self.tr("Initializing ..."))

    def startComputationHandler(self,computation):
        signalLogger.debug(computation.command)
        signalLogger.debug(computation.evaluating)
        self.__updateStatus(computation.evaluating)

    def endComputationHandler(self,computation):
        signalLogger.debug(computation.evaluating)
        self.__updateStatus(computation.evaluating)
        self.__updateTime(computation.accTime,computation.accGcTime)
        self.__updateMode(computation.symbolic)

    def __updateMode(self,symbolic):
        if symbolic != self.symbolic:
            self.symbolic = symbolic
            if self.symbolic:
                self.reduceMode.setText(self.tr("Mode: Symbolic"))
            else:
                self.reduceMode.setText(self.tr("Mode: Algebraic"))

    def __updateTime(self,time,gcTime):
        timeStr = "%.2f s" % (float(time + gcTime)/1000)
        self.reduceTime.setText(self.tr("Time: ") + timeStr)

    def __updateStatus(self,evaluating):
        if evaluating:
            self.reduceStatus.setText(self.tr(" Evaluating"))
        else:
            self.reduceStatus.setText(self.tr(" Ready"))


class QtRecentFileMenu(QMenu):

    def __init__(self,parent=None):
        super(QtRecentFileMenu,self).__init__(parent)

        self.main = parent

        self.setTitle(self.tr("Open Recent"))

        self.acts = []
        maxRecent = QSettings().value("menubar/maxrecent",
                                      QtReduceDefaults.MAXRECENT)
        for i in range(maxRecent):
            act = QAction(self)
            act.triggered.connect(self.main.openRecentFile)
            self.acts.append(act)

        self.clearAct = QAction(self.tr("Clear Menu"),self)
        self.clearAct.triggered.connect(self.clearRecentFiles)

        self.aboutToShow.connect(self.updateEntries)

    def updateEntries(self):
        settings = QSettings()
        settings.sync()

        maxRecent = settings.value("menubar/maxrecent",
                                      QtReduceDefaults.MAXRECENT)

        files = settings.value("menubar/recentfiles",[])
        for f in files:
            if not os.path.exists(f):
                files.remove(f)
        settings.setValue("menubar/recentfiles",files)

        numShow = min(len(files),maxRecent)

        for i in range(numShow):
            text = QFileInfo(files[i]).fileName()
            self.acts[i].setText(text)
            self.acts[i].setData(files[i])
            self.acts[i].setVisible(True)

        for j in range(numShow,maxRecent):
            self.acts[j].setVisible(False)

        for i in range(maxRecent):
            self.addAction(self.acts[i])

        self.addSeparator()

        self.addAction(self.clearAct)

    def addFile(self,fullPath):
        fileName = fullPath
        settings = QSettings()
        files = settings.value("menubar/recentfiles",[])

        try:
            files.remove(fileName)
        except ValueError:
            pass

        files.insert(0,fileName)

        maxRecent = settings.value("menubar/maxrecent",
                                   QtReduceDefaults.MAXRECENT)
        del files[maxRecent:]

        settings.setValue("menubar/recentfiles",files)

    def clearRecentFiles(self):
        QSettings().setValue("menubar/recentfiles",[])


class QtReduceToolBar(QToolBar):

    def __init__(self,parent=None):
        super(QtReduceToolBar,self).__init__(parent)

        buttonStyle = QSettings().value("toolbar/buttonstyle",
                                        self.tr(QtReduceDefaults.BUTTONSTYLE))
        self.setToolButtonStyleByText(buttonStyle)

        self.setContextMenuPolicy(Qt.CustomContextMenu)
        self.customContextMenuRequested.connect(self.contextMenu)

        self.setVisible(True)

    def contextMenu(self):
        None

    def toolButtonStyleChanged(self,text):
        QSettings().setValue("toolbar/buttonstyle",text)
        self.setToolButtonStyleByText(text)

    def setToolButtonStyleByText(self,text):
        style = self.__textToToolButtonStyle(text)
        self.setToolButtonStyle(style)
        self.refresh()

    def __textToToolButtonStyle(self,show):
        traceLogger.debug("show=%s,('%s', '%s', '%s')" %
                          (show,
                           self.tr("Symbol and Text"),
                           self.tr("Only Symbol"),
                           self.tr("Only Text")))
        if show == self.tr("Symbol and Text"):
            return Qt.ToolButtonTextUnderIcon
        if show == self.tr("Only Symbol"):
            return Qt.ToolButtonIconOnly
        if show == self.tr("Only Text"):
            return Qt.ToolButtonTextOnly
        traceLogger.warning("unknown tool button style '%s'" % show)
        return Qt.ToolButtonTextUnderIcon

    def refresh(self):
        visibility = self.isVisible()
        self.setVisible(not visibility)
        self.setVisible(visibility)


class QtReduceTableView(QTableView):

    def __init__(self,parent=None):
        super(QtReduceTableView,self).__init__(parent)
        font = self.font()
        font.setFamily(QSettings().value("worksheet/fontfamily",
                                         QtReduceDefaults.FONTFAMILY))
        font.setFixedPitch(True)
        font.setKerning(0)
        font.setWeight(QFont.Normal)
        font.setItalic(False)
        font.setPointSize(9)
        self.setFont(font)
        self.setWindowFlags(Qt.Drawer)
        self.horizontalHeader().setStretchLastSection(True)
        self.horizontalHeader().hide()
        self.verticalHeader().setResizeMode(QHeaderView.ResizeToContents)
        self.setVerticalScrollMode(QAbstractItemView.ScrollPerPixel)
        self.setShowGrid(True)
        self.setSelectionMode(QAbstractItemView.NoSelection)
        self.setEditTriggers(QAbstractItemView.NoEditTriggers)

    def closeEvent(self,e):
        self.parent().toggleRawModel()
        e.accept()
