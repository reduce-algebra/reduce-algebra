# ----------------------------------------------------------------------
# $Id$
# ----------------------------------------------------------------------
# Copyright (c) 2010 T. Sturm, C. Zengler
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

from types import StringType

from PySide.QtCore import Qt
from PySide.QtCore import Signal
from PySide.QtCore import QSettings

from PySide.QtGui import QDialog
from PySide.QtGui import QWidget
from PySide.QtGui import QListWidget
from PySide.QtGui import QListWidgetItem
from PySide.QtGui import QListView
from PySide.QtGui import QStackedWidget
from PySide.QtGui import QHBoxLayout
from PySide.QtGui import QFormLayout
from PySide.QtGui import QPushButton
from PySide.QtGui import QVBoxLayout
from PySide.QtGui import QFontDialog
from PySide.QtGui import QFont
from PySide.QtGui import QFontInfo
from PySide.QtGui import QGroupBox
from PySide.QtGui import QLabel
from PySide.QtGui import QCheckBox
from PySide.QtGui import QLineEdit
from PySide.QtGui import QFontComboBox
from PySide.QtGui import QComboBox
from PySide.QtGui import QFontDatabase
from PySide.QtGui import QMessageBox

from qrlogging import fontLogger
from qrlogging import signalLogger
from qrlogging import traceLogger

from qrdefaults import QtReduceDefaults
from qrdefaults import QtReduceIconSets


class QtReducePreferencePane(QDialog):

    def __init__(self,parent=None):
        super(QtReducePreferencePane,self).__init__(parent)

        self.__createContents()

        self.toolBar = QtReducePreferencesToolBar(self)
        self.worksheet = QtReducePreferencesWorksheet(self)
        self.computation = QtReducePreferencesComputation(self)

        self.pagesWidget = QStackedWidget()
        self.pagesWidget.addWidget(self.toolBar)
        self.pagesWidget.addWidget(self.worksheet)
        self.pagesWidget.addWidget(self.computation)

        self.pagesWidget.setCurrentIndex(
            self.contentsWidget.row(self.contentsWidget.currentItem()))

        closeButton = QPushButton(self.tr("Close"))
        closeButton.clicked.connect(self.close)

        horizontalLayout = QHBoxLayout()
        horizontalLayout.addWidget(self.contentsWidget)
        horizontalLayout.addWidget(self.pagesWidget)

        buttonsLayout = QHBoxLayout()
        buttonsLayout.addStretch(1)
        buttonsLayout.addWidget(closeButton)

        mainLayout = QVBoxLayout()
        mainLayout.addLayout(horizontalLayout)
        mainLayout.addLayout(buttonsLayout)

        self.setLayout(mainLayout)

        self.setWindowTitle(self.tr("QReduce Preferences"))

    def changePage(self,current,previous):
        if not current:
            current = previous
        QSettings().setValue("preferences/currentitem",current.text())
        self.pagesWidget.setCurrentIndex(self.contentsWidget.row(current))

    def __createContents(self):
        self.contentsWidget = QListWidget()
        self.contentsWidget.setViewMode(QListView.ListMode)
        self.contentsWidget.setMovement(QListView.Static)

        toolBar = QListWidgetItem(self.contentsWidget)
        toolBar.setText(self.tr("Toolbar"))
        toolBar.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

        worksheet = QListWidgetItem(self.contentsWidget)
        worksheet.setText(self.tr("Worksheet"))
        worksheet.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

        computation = QListWidgetItem(self.contentsWidget)
        computation.setText(self.tr("Computation"))
        computation.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

        currentItem = QSettings().value("preferences/currentitem",
                                        self.tr(QtReduceDefaults.CURRENTITEM))
        if currentItem == self.tr("Toolbar"):
            self.contentsWidget.setCurrentItem(toolBar)
        elif currentItem == self.tr("Worksheet"):
            self.contentsWidget.setCurrentItem(worksheet)
        elif currentItem == self.tr("Computation"):
            self.contentsWidget.setCurrentItem(computation)

        self.contentsWidget.currentItemChanged.connect(self.changePage)


class QtReduceComboBox(QComboBox):
    def __init__(self):
        super(QtReduceComboBox,self).__init__()
        self.setFocusPolicy(Qt.NoFocus)
        self.setEditable(False)


class QtReducePreferencesToolBar(QWidget):
    def __init__(self,parent=None):
        super(QtReducePreferencesToolBar,self).__init__(parent)

        settings = QSettings()

        toolBarGroup = QGroupBox(self.tr("Toolbar"))

        self.iconSetCombo = QtReduceComboBox()
        iDbKeys = QtReduceIconSets().db.keys()
        iDbKeys.sort()
        self.iconSetCombo.addItems(iDbKeys)
        self.iconSetCombo.setCurrentIndex(
            self.iconSetCombo.findText(
                settings.value("toolbar/iconset",QtReduceDefaults.ICONSET)))

        self.iconSizeCombo = QtReduceComboBox()
        self.iconSizeCombo.addItems(["16","22","32"])
        self.iconSizeCombo.setCurrentIndex(
            self.iconSizeCombo.findText(
                str(settings.value("toolbar/iconsize",
                                   QtReduceDefaults.ICONSIZE))))

        self.showCombo = QtReduceComboBox()
        self.showCombo.addItems([self.tr("Symbol and Text"),
                                 self.tr("Only Symbol"),
                                 self.tr("Only Text")])
        self.showCombo.setCurrentIndex(self.showCombo.findText(
            settings.value("toolbar/buttonstyle",
                           self.tr(QtReduceDefaults.BUTTONSTYLE))))

        toolBarLayout = QFormLayout()
        toolBarLayout.addRow(self.tr("Symbol Set"),self.iconSetCombo)
        toolBarLayout.addRow(self.tr("Symbol Size"),self.iconSizeCombo)
        toolBarLayout.addRow(self.tr("Show"),self.showCombo)

        toolBarGroup.setLayout(toolBarLayout)

        mainLayout = QVBoxLayout()
        mainLayout.addWidget(toolBarGroup)

        self.setLayout(mainLayout)


class QtReduceFontComboBox(QtReduceComboBox):
    currentFontChanged = Signal(QFont)

    def __init__(self,parent=None):
        super(QtReduceFontComboBox,self).__init__()
        fdb = QFontDatabase()
        l = []
        self.fontDict = {}
        for fam in fdb.families(QFontDatabase.Latin):
            for sty in fdb.styles(fam):
                if not fam in l and fdb.isFixedPitch(fam,sty) \
                and not fdb.bold(fam,sty) and not fdb.italic(fam,sty) \
                and self.__osxHack(fam):
                    fontLogger.debug("family=%s, style=%s, isFixedPitch=%s" %
                                     (fam, sty, fdb.isFixedPitch(fam,sty)))
                    sizes = fdb.smoothSizes(fam,sty)
                    if sizes:
                        font = fdb.font(fam,sty,sizes[0])
                        if not font.exactMatch():
                            fontLogger.debug("no exactMatch for  %s %s %s" %
                                             (fam,sty,sizes[0]))

                        l += [fam]
                        self.fontDict.update({str(fam):font})
        l.sort
        self.addItems(l)
        self.currentIndexChanged.connect(self.currentIndexChangedHandler)

    def __osxHack(self,fam):
        if os.uname()[0] != "Darwin":
            return True
        if fam.find("Andale") != -1 \
        or fam.find("Bitstream") != -1 \
        or fam.find("Consolas") != -1 \
        or fam.find("Courier") != -1 \
        or fam.find("DejaVu") != -1 \
        or fam.find("Lucida") != -1 \
        or fam.find("Monaco") != -1:
            return True
        return False

    def setCurrentFont(self,font):
        info = QFontInfo(font)
        self.setCurrentIndex(self.findText(info.family()))

    def currentFont(self):
        return self.fontDict[self.currentText()]

    def currentIndexChangedHandler(self,index):
        return self.currentFontChanged.emit(self.currentFont())


class QtReducePreferencesWorksheet(QWidget):
    def __init__(self,parent=None):
        super(QtReducePreferencesWorksheet,self).__init__(parent)

        fontGroup = QGroupBox(self.tr("Fonts"))

        self.fontCombo = QtReduceFontComboBox(self)
        self.setFocusPolicy(Qt.NoFocus)
        self.fontCombo.setEditable(False)
        self.fontCombo.setCurrentFont(self.parent().parent().controller.view.font())

        self.sizeCombo = QtReduceComboBox()
        self.sizeComboFs = QtReduceComboBox()
        self.findSizes(self.fontCombo.currentFont())
        self.fontCombo.currentFontChanged.connect(self.findSizes)

        fontLayout = QFormLayout()
        fontLayout.addRow(self.tr("General Worksheet Font"),self.fontCombo)
        fontLayout.addRow(self.tr("Font Size"),self.sizeCombo)
        fontLayout.addRow(self.tr("Full Screen Font Size"),self.sizeComboFs)

        fontGroup.setLayout(fontLayout)

        mainLayout = QVBoxLayout()
        mainLayout.addWidget(fontGroup)

        self.setLayout(mainLayout)

    def findSizes(self,font):
        fontLogger.debug("font.key()=%s" % font.key())
        fontDatabase = QFontDatabase()

        self.sizeCombo.blockSignals(True)
        self.sizeCombo.clear()

        self.sizeComboFs.blockSignals(True)
        self.sizeComboFs.clear()

        styleStr = fontDatabase.styleString(font)
        if fontDatabase.isSmoothlyScalable(font.family(),styleStr):
            for size in QFontDatabase.standardSizes():
                self.sizeCombo.addItem(str(size))
                self.sizeComboFs.addItem(str(size))
        else:
            for size in fontDatabase.smoothSizes(font.family(),styleStr):
                self.sizeCombo.addItem(str(size))
                self.sizeComboFs.addItem(str(size))

        self.sizeCombo.blockSignals(False)
        self.sizeComboFs.blockSignals(False)

        currentSize = unicode(QSettings().value("worksheet/fontsize",
                                                QtReduceDefaults.FONTSIZE))
        sizeIndex = self.sizeCombo.findText(currentSize)
        self.sizeCombo.setCurrentIndex(sizeIndex)

        currentSize = unicode(QSettings().value("worksheet/fontsizefs",
                                                QtReduceDefaults.FONTSIZEFS))
        sizeIndex = self.sizeCombo.findText(currentSize)
        self.sizeComboFs.setCurrentIndex(sizeIndex)


class QtReducePreferencesComputation(QWidget):
    def __init__(self,parent=None):
        super(QtReducePreferencesComputation,self).__init__(parent)

        reduceGroup = QGroupBox("Reduce")

        self.reduceBinary = QLineEdit()

        # font = self.reduceBinary.font()
        # font.setFamily(QSettings().value("worksheet/fontfamily",
        #                                QtReduceDefaults.FONTFAMILY))
        # self.reduceBinary.setFont(font)

        self.reduceBinary.setText(QSettings().value("computation/reduce",
                                                    QtReduceDefaults.REDUCE))

        self.reduceBinary.editingFinished.connect(self.editingFinishedHandler)

        reduceLayout = QFormLayout()
        reduceLayout.addRow(self.tr("Reduce Binary"),self.reduceBinary)

        reduceGroup.setLayout(reduceLayout)

        mainLayout = QVBoxLayout()
        mainLayout.addWidget(reduceGroup)

        self.setLayout(mainLayout)

    def editingFinishedHandler(self):
        settings = QSettings()
        old = settings.value("computation/reduce",QtReduceDefaults.REDUCE)
        new = self.reduceBinary.text()
        if old == new:
            return
        self.reduceBinary.blockSignals(True)
        tit = "Change Binary?"
        txt = self.tr("Do you really want to change this setting?")
        itxt = self.tr("If yes, then the binary ")
        itxt += '"' + new + '" '
        itxt += self.tr("will be used at the next restart.")
        mbox = QMessageBox(self)
        mbox.setIcon(QMessageBox.Question)
        mbox.setWindowModality(Qt.WindowModal)
        mbox.setWindowTitle(tit)
        mbox.setText(txt)
        mbox.setInformativeText(itxt)
        mbox.setStandardButtons(QMessageBox.Yes|QMessageBox.No)
        button = mbox.exec_()
        if button == QMessageBox.Yes:
            settings.setValue("computation/reduce",new)
        else:
            self.reduceBinary.setText(old)
        self.reduceBinary.blockSignals(False)
