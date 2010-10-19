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

from PySide.QtGui import QApplication
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
from PySide.QtGui import QToolBar
from PySide.QtGui import QStyle
from PySide.QtGui import QTextEdit

from qrlogging import signalLogger
from qrlogging import traceLogger

from qrworksheet import QtReduceWorksheet
from reduce import Reduce
from qrpreferences import QtReducePreferencePane
from qrdefaults import QtReduceDefaults


class QtReduceMainWindow(QMainWindow):

    def __init__(self, parent=None):
        QMainWindow.__init__(self, parent)
        self.setWindowIcon(QIcon(sys.path[0] + "/" + "Bumblebee.png"))
        self.setUnifiedTitleAndToolBarOnMac(True)
        self.setTitle(os.path.dirname(''))
        self.setMenuBar(QtReduceMenuBar(self,parent))
        self.toolBar = QtReduceToolBar(self)
        self.addToolBar(self.toolBar)
        self.setStatusBar(QtReduceStatusBar(parent))
        self.worksheet = QtReduceWorksheet(self)
        self.setCentralWidget(self.worksheet)
        self.__setWidthByFont(QtReduceDefaults.WIDTH)
        self.__setHeightByFont(QtReduceDefaults.HEIGHT)
        self.raise_()
        self.show()
        # QApplication.setOverrideCursor(Qt.WaitCursor)
        self.preferencePane = QtReducePreferencePane(self)
        self.__initPreferencePaneSignals()
        self.__initStatusBarSignals()
        self.__initMenuBarSignals()
        self.__initTitleBarSignals()
        self.worksheet.initialize()
        # QApplication.restoreOverrideCursor()

    def __initStatusBarSignals(self):
        self.worksheet.endComputation.connect(
            self.statusBar().endComputationHandler,
            type=Qt.DirectConnection)
        self.worksheet.startComputation.connect(
            self.statusBar().startComputationHandler,
            type=Qt.DirectConnection)

    def __initMenuBarSignals(self):
        self.worksheet.endComputation.connect(
            self.menuBar().endComputationHandler,
            type=Qt.DirectConnection)
        self.worksheet.startComputation.connect(
            self.menuBar().startComputationHandler,
            type=Qt.DirectConnection)

    def __initPreferencePaneSignals(self):
        self.preferencePane.toolBar.iconSetCombo.currentIndexChanged.connect(
            self.toolBar.iconSetChanged)
        self.preferencePane.toolBar.iconSizeCombo.currentIndexChanged.connect(
            self.toolBar.iconSizeChanged)
        self.preferencePane.toolBar.showCombo.currentIndexChanged.connect(
            self.toolBar.toolButtonStyleChanged)
        self.preferencePane.worksheet.fontCombo.currentFontChanged.connect(
            self.currentFontChangedHandler)
        self.preferencePane.worksheet.sizeCombo.currentIndexChanged.connect(
            self.currentSizeChangedHandler)

    def __initTitleBarSignals(self):
        self.worksheet.fileNameChanged.connect(self.setTitle,
                                               type=Qt.DirectConnection)
        self.worksheet.fileNameChanged.connect(
            self.menuBar().recentFileMenu.addFile,
            type=Qt.DirectConnection)
        self.worksheet.modified.connect(self.setWindowModified,
                                        type=Qt.DirectConnection)

    def __setWidthByFont(self,n,adaptHeight=False):
        oldWidth = self.width()
        width = n * self.worksheet.fontMetrics().width('m')
        traceLogger.debug("width=%s, n=%s, family=%s, size=%s" %
                          (width,n,self.worksheet.font().family(),
                           self.worksheet.font().pixelSize()))
        self.setFixedWidth(width)
        if adaptHeight:
            factor = float(self.width())/float(oldWidth)
            self.resize(1,int(self.height()*factor))

    def __setHeightByFont(self,n):
        height = n * QFontMetrics(self.worksheet.font()).height()
        self.resize(1,height)

    def currentFontChangedHandler(self,font):
        signalLogger.debug("font=%s" % font)
        self.worksheet.currentFontChangedHandler(font)
        self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    def currentSizeChangedHandler(self,size):
        self.worksheet.currentSizeChangedHandler(size)
        self.zoomDef()

    # File Actions
    def open(self):
        title = self.tr("Open Reduce Worksheet")
        fn = self.worksheet.fileName.__str__()
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
        return self.worksheet.open(fileName)

    def openRecentFile(self):
        action = self.sender()
        if action:
            self.worksheet.open(action.data())

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
        traceLogger.debug("fileName=%s" % fileName)
        if fileName == '':
            return
        if not fileName.endswith(".rws"):
            fileName += ".rws"
        self.worksheet.save(fileName)
        self.activateWindow()

    # Edit Actions
    def preferences(self):
        self.preferencePane.show()

    # View Actions
    def zoomIn(self):
        self.worksheet.setupFont(self.worksheet.font().pixelSize()+1)
        self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    def zoomOut(self):
        self.worksheet.setupFont(self.worksheet.font().pixelSize()-1,-1)
        self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    def zoomDef(self):
        self.worksheet.zoomDef()
        self.__setWidthByFont(QtReduceDefaults.WIDTH,True)

    # Development Actions
    def test(self):
        self.worksheet.zoomIn(10)

    # Help Actions
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

    def showMessage(self,message):
	self.statusBar().showMessage(message,0)

    def setTitle(self,fullPath):
        traceLogger.debug("fullPath=%s" % fullPath)
        if fullPath is '':
            self.setWindowTitle("[*]" + self.tr("Untitled"))
        else:
            info = QFileInfo(fullPath)
            self.setWindowFilePath(info.absolutePath())
            self.setWindowTitle("[*]" + info.fileName())

    def closeEvent(self,ev):
        while self.isWindowModified():
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
        msg = 'Do you want to save the changes in your worksheet "'
        msg += (self.worksheet.fileName.split('/')[-1] or 'untitled') + '"?'
        diag.setText(msg)
        diag.setInformativeText("Otherwise they will get lost")
        diag.setIcon(QMessageBox.Warning)
        diag.setStandardButtons(QMessageBox.StandardButton.Discard |
                                QMessageBox.StandardButton.Cancel |
                                QMessageBox.StandardButton.Save)
        diag.setWindowModality(Qt.WindowModal)
        return diag.exec_()

    def abortEvaluation(self):
        signalLogger.debug("entering")
        self.worksheet.abortEvaluation()


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

    # def showMessage(self,message):
    #     if os.uname()[0] == "Darwin":
    #         message = '<font size="-2">' + message + '</font>'
    #     super(QtReduceStatusBar,self).showMessage(message)

    def startComputationHandler(self,computation):
        #print computation.currentCommand
        # QApplication.setOverrideCursor(Qt.BusyCursor)
        self.__updateStatus(computation.evaluating)

    def endComputationHandler(self,computation):
        self.__updateStatus(computation.evaluating)
        self.__updateTime(computation.accTime,computation.accGcTime)
        self.__updateMode(computation.symbolic)
        # QApplication.restoreOverrideCursor()

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


class QtReduceMenuBar(QMenuBar):

    def __init__(self,mainWindow,parent=None):
        QMenuBar.__init__(self,parent)
        self.main = mainWindow
        self.__createMenus()
        self.__createActions()

    def startComputationHandler(self,rc):
        self.abortAct.setEnabled(True)

    def endComputationHandler(self,rc):
        self.abortAct.setEnabled(False)

    def __createMenus(self):
        self.fileMenu = self.addMenu(self.tr("File"))
        self.editMenu = self.addMenu(self.tr("Edit"))
        self.viewMenu = self.addMenu(self.tr("View"))
        self.worksheetMenu = self.addMenu(self.tr("Worksheet"))
#        self.develMenu = self.ddMenu(self.tr("Develop"))
        self.helpMenu = self.addMenu(self.tr("Help"))

    def __createActions(self):
        self.__createFileActions()
        self.__createEditActions()
        self.__createViewActions()
        self.__createWorksheetActions()
#        self.__createDevelActions()
        self.__createHelpActions()

    def __createFileActions(self):
        self.openAct = QAction(self.tr("Open ..."), self)
        self.openAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_O))
        self.openAct.setIconText(self.tr("Open"))
        self.fileMenu.addAction(self.openAct)
        self.openAct.triggered.connect(self.main.open,type=Qt.DirectConnection)

        self.fileMenu.main = self.main
        self.recentFileMenu = QtRecentFileMenu(self.fileMenu)
        self.fileMenu.addMenu(self.recentFileMenu)

        self.fileMenu.addSeparator()

        self.saveAct = QAction(self.tr("Save"), self)
        self.saveAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_S))
        self.saveAct.setIconText(self.tr("Save"))

        self.fileMenu.addAction(self.saveAct)
        self.saveAct.triggered.connect(self.main.save,type=Qt.DirectConnection)

        self.saveAsAct = QAction(self.tr("Save As ..."), self)
        self.saveAsAct.setShortcut(
            QKeySequence(Qt.ShiftModifier|Qt.ControlModifier|Qt.Key_S))
        self.saveAsAct.setIconText(self.tr("Save As"))

        self.fileMenu.addAction(self.saveAsAct)
        self.saveAsAct.triggered.connect(self.main.saveAs,type=Qt.DirectConnection)

        self.fileMenu.addSeparator()

        self.quitAct = QAction(self.tr("Quit"), self)
        self.quitAct.setShortcut(
            QKeySequence(Qt.ControlModifier|Qt.Key_Q))

        self.fileMenu.addAction(self.quitAct)
        self.quitAct.triggered.connect(self.main.close,type=Qt.DirectConnection)
    def __createEditActions(self):
        self.preferencesAct = QAction(self.tr("Preferences ..."), self)
        self.preferencesAct.setShortcut(QKeySequence(Qt.AltModifier|Qt.Key_Comma))
        self.editMenu.addAction(self.preferencesAct)
        self.preferencesAct.triggered.connect(self.main.preferences,type=Qt.DirectConnection)

    def __createViewActions(self):
        self.zoomDefAct = QAction(self.tr("Zoom Default"), self)
        self.zoomDefAct.setIconText(self.tr("Zoom Default"))
        self.zoomDefAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Equal))

        self.viewMenu.addAction(self.zoomDefAct)
        self.zoomDefAct.triggered.connect(self.main.zoomDef,type=Qt.DirectConnection)

        self.zoomInAct = QAction(self.tr("Zoom In"), self)
        self.zoomInAct.setIconText(self.tr("Zoom In"))
        self.zoomInAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Plus))

        self.viewMenu.addAction(self.zoomInAct)
        self.zoomInAct.triggered.connect(self.main.zoomIn,type=Qt.DirectConnection)

        self.zoomOutAct = QAction(self.tr("Zoom Out"), self)
        self.zoomOutAct.setIconText(self.tr("Zoom Out"))
        self.zoomOutAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_Minus))

        self.viewMenu.addAction(self.zoomOutAct)
        self.zoomOutAct.triggered.connect(self.main.zoomOut,type=Qt.DirectConnection)

    def __createWorksheetActions(self):
        self.insertAboveAct = QAction(self.tr("Insert Group Above"), self)
        self.insertAboveAct.setEnabled(False)
        self.worksheetMenu.addAction(self.insertAboveAct)

        self.insertBelowAct = QAction(self.tr("Insert Group Below"), self)
        self.insertBelowAct.setEnabled(False)
        self.worksheetMenu.addAction(self.insertBelowAct)

        self.worksheetMenu.addSeparator()

        self.evalAct = QAction(self.tr("Evaluate Worksheet"), self)
        self.evalAct.setEnabled(False)
        self.worksheetMenu.addAction(self.evalAct)

        self.worksheetMenu.addSeparator()

        self.abortAct = QAction(self.tr("Abort Evaluation"), self)
        self.abortAct.setShortcut(QKeySequence(Qt.AltModifier|Qt.Key_C))
        self.abortAct.setIconText(self.tr("Abort"))
        self.abortAct.setEnabled(False)

        self.worksheetMenu.addAction(self.abortAct)
        self.abortAct.triggered.connect(self.main.abortEvaluation)

    def __createDevelActions(self):
        self.testAct = QAction(self.tr("Test"), self)
        self.testAct.setShortcut(QKeySequence(Qt.ControlModifier|Qt.Key_T))
        self.develMenu.addAction(self.testAct)
        self.testAct.triggered.connect(self.main.test,type=Qt.DirectConnection)

    def __createHelpActions(self):
        self.aboutAct = QAction(self.tr("About"), self)
        self.helpMenu.addAction(self.aboutAct)
        self.aboutAct.triggered.connect(self.main.about,type=Qt.DirectConnection)
        self.licenseAct = QAction(self.tr("License"), self)
        self.helpMenu.addAction(self.licenseAct)
        self.licenseAct.triggered.connect(self.main.license_,type=Qt.DirectConnection)


class QtRecentFileMenu(QMenu):

    def __init__(self,parent=None):
        super(QtRecentFileMenu,self).__init__(parent)

        self.main = parent.main

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
    iDb = {"Aqua":
           {"sized":True,
            "Open":"fileopen.png",
            "Save":"filesave.png",
            "Save As":"filesaveas.png",
            "Zoom In":"tab_new.png",
            "Zoom Out":"tab_remove.png",
            "Zoom Default":"player_stop.png",
            "Abort":"stop.png"},
           "Bluesphere":
           {"sized":False,
            "Open":"fileopen.svg",
            "Save":"filesave-2.1.svg",
            "Save As":"filesaveas.svg",
            "Zoom In":"edit_add.svg",
            "Zoom Out":"edit_remove.svg",
            "Zoom Default":"bookmark.svg",
            "Abort":"button_cancel.svg"},
           "Crystal":
           {"sized":False,
            "Open":"fileopen-256.png",
            "Save":"filesave-256.png",
            "Save As":"filesaveas-256.png",
            "Zoom In":"viewmag+-256.png",
            "Zoom Out":"viewmag--256.png",
            "Zoom Default":"viewmag1-256.png",
            "Abort":"agt_stop-256.png"},
           "Nuvola":
           {"sized":True,
            "Open":"fileopen.png",
            "Save":"filesave.png",
            "Save As":"filesaveas.png",
            "Zoom In":"viewmag+.png",
            "Zoom Out":"viewmag-.png",
            "Zoom Default":"viewmag1.png",
            "Abort":"stop.png"},
           "Oxygen":
           {"sized":True,
            "Open":"document_open.png",
            "Save":"document_save.png",
            "Save As":"document_save_as.png",
            "Zoom In":"zoom_in.png",
            "Zoom Out":"zoom_out.png",
            "Zoom Default":"zoom_original.png",
            "Abort":"stop.png"},
           "Tango":
           {"sized":True,
            "Open":"document-open.png",
            "Save":"document-save.png",
            "Save As":"document-save-as.png",
            "Zoom In":"list-add.png",
            "Zoom Out":"list-remove.png",
            "Zoom Default":"view-refresh.png",
            "Abort":"process-stop.png"}}

    def __init__(self,parent=None):

        super(QtReduceToolBar,self).__init__(parent)

        self.setVisible(True)

        settings = QSettings()

        iconSize = settings.value("toolbar/iconsize",
                                     QtReduceDefaults.ICONSIZE)
        self.setIconSize(QSize(iconSize,iconSize))

        self.__setIcons()

        buttonStyle = settings.value("toolbar/buttonstyle",
                                        self.tr(QtReduceDefaults.BUTTONSTYLE))
        self.setToolButtonStyleByText(buttonStyle)

        self.setContextMenuPolicy(Qt.CustomContextMenu)
        self.customContextMenuRequested.connect(self.contextMenu)

        self.addAction(self.parent().menuBar().openAct)
        self.addAction(self.parent().menuBar().saveAct)
        self.addAction(self.parent().menuBar().saveAsAct)

        self.addSeparator()

        self.addAction(self.parent().menuBar().zoomOutAct)
        self.addAction(self.parent().menuBar().zoomDefAct)
        self.addAction(self.parent().menuBar().zoomInAct)

        self.addSeparator()

        self.addAction(self.parent().menuBar().abortAct)

        self.setVisible(True)

    def contextMenu(self,position):
        None

    def iconSetChanged(self,iconSet):
        QSettings().setValue("toolbar/iconset",iconSet)
        self.__setIcons()

    def iconSizeChanged(self,iconSize):
        iconSize = int(iconSize)
        QSettings().setValue("toolbar/iconsize",iconSize)
        self.setIconSize(QSize(iconSize,iconSize))
        self.__setIcons()

    def toolButtonStyleChanged(self,text):
        QSettings().setValue("toolbar/buttonstyle",text)
        self.setToolButtonStyleByText(text)
        visibility = self.isVisible()
        self.setVisible(not visibility)
        self.setVisible(visibility)

    def setToolButtonStyleByText(self,text):
        style = self.__textToToolButtonStyle(text)
        self.setToolButtonStyle(style)

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

    def __setIcons(self):
        self.parent().menuBar().openAct.setIcon(self.__icon("Open"))
        self.parent().menuBar().saveAct.setIcon(self.__icon("Save"))
        self.parent().menuBar().saveAsAct.setIcon(self.__icon("Save As"))
        self.parent().menuBar().zoomOutAct.setIcon(self.__icon("Zoom Out"))
        self.parent().menuBar().zoomDefAct.setIcon(self.__icon("Zoom Default"))
        self.parent().menuBar().zoomInAct.setIcon(self.__icon("Zoom In"))
        self.parent().menuBar().abortAct.setIcon(self.__icon("Abort"))
        visibility = self.isVisible()
        self.setVisible(not visibility)
        self.setVisible(visibility)

    def __icon(self,mEntry):
        settings = QSettings()
        iconSet = settings.value("toolbar/iconset",QtReduceDefaults.ICONSET)
        iconSize = settings.value("toolbar/iconsize",
                                     QtReduceDefaults.ICONSIZE)
        if iconSet:
            iEntry = self.iDb[iconSet]
            path = sys.path[0] + "/icons/" + iconSet + "/"
            if iEntry["sized"]:
                path += str(iconSize) + "/"
            path += iEntry[mEntry]
            traceLogger.debug("iconPath=%s" % path)
            return QIcon(path)
        else:
            if mEntry == "open":
                return self.style().standardIcon(QStyle.SP_DialogOpenButton)
            elif mEntry == "save":
                return self.style().standardIcon(QStyle.SP_DialogSaveButton)
            elif mEntry == "abort":
                return self.style().standardIcon(QStyle.SP_BrowserStop)
            else:
                return QIcon("")
