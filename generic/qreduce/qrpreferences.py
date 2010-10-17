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

from types import StringType

from PySide.QtCore import Qt
from PySide.QtCore import Signal

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

from qrlogging import signalLogger
from qrlogging import fontLogger
from qrlogging import traceLogger

class QtReducePreferencePane(QDialog):

    def __init__(self,parent=None):
        super(QtReducePreferencePane,self).__init__(parent)
        self.parent = parent

        self.__createContents()

        self.toolBar = QtReducePreferencesToolBar(self)
        self.worksheet = QtReducePreferencesWorksheet(self)
        self.computation = QtReducePreferencesComputation(self)

        self.pagesWidget = QStackedWidget()
        self.pagesWidget.addWidget(self.toolBar)
        self.pagesWidget.addWidget(self.worksheet)
        self.pagesWidget.addWidget(self.computation)

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
        self.pagesWidget.setCurrentIndex(self.contentsWidget.row(current))

    def __createContents(self):
        self.contentsWidget = QListWidget()
        self.contentsWidget.setViewMode(QListView.ListMode)
        self.contentsWidget.setMovement(QListView.Static)

        toolBar = QListWidgetItem(self.contentsWidget)
        toolBar.setText(self.tr("Toolbar"))
        toolBar.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

        self.contentsWidget.setCurrentItem(toolBar)

        worksheet = QListWidgetItem(self.contentsWidget)
        worksheet.setText(self.tr("Worksheet"))
        worksheet.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

        computation = QListWidgetItem(self.contentsWidget)
        computation.setText(self.tr("Computation"))
        computation.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)

        self.contentsWidget.currentItemChanged.connect(self.changePage)


class QtReduceComboBox(QComboBox):
    def __init__(self):
        super(QtReduceComboBox,self).__init__()
        self.setFocusPolicy(Qt.NoFocus)
        self.setEditable(False)


class QtReducePreferencesToolBar(QWidget):
    def __init__(self,parent=None):
        super(QtReducePreferencesToolBar,self).__init__(parent)
        self.parent = parent

        toolBarGroup = QGroupBox(self.tr("Toolbar"))

        self.iconSetCombo = QtReduceComboBox()
        iDbKeys = self.parent.parent.toolBar.iDb.keys()
        iDbKeys.sort()
        self.iconSetCombo.addItems(iDbKeys)
        self.iconSetCombo.setCurrentIndex(
            self.iconSetCombo.findText(self.parent.parent.toolBar.iconSet))

        self.iconSizeCombo = QtReduceComboBox()
        self.iconSizeCombo.addItems(["16","22","32"])
        self.iconSizeCombo.setCurrentIndex(
            self.iconSizeCombo.findText(str(self.parent.parent.toolBar.iconSize)))

        self.showCombo = QtReduceComboBox()
        self.showCombo.addItems([self.tr("Symbol and Text"),self.tr("Only Symbol"),self.tr("Only Text")])
        text = self.toolButtonStyleToText(self.parent.parent.toolBar.toolButtonStyle())
        self.showCombo.setCurrentIndex(self.showCombo.findText(text))

        toolBarLayout = QFormLayout()
        toolBarLayout.addRow(self.tr("Symbol Set"),self.iconSetCombo)
        toolBarLayout.addRow(self.tr("Symbol Size"),self.iconSizeCombo)
        toolBarLayout.addRow(self.tr("Show"),self.showCombo)

        toolBarGroup.setLayout(toolBarLayout)

        mainLayout = QVBoxLayout()
        mainLayout.addWidget(toolBarGroup)

        self.setLayout(mainLayout)

    def textToToolButtonStyle(self,sh):
        if sh == self.tr("Symbol and Text"):
            return Qt.ToolButtonTextUnderIcon
        if sh == self.tr("Only Symbol"):
            return Qt.ToolButtonIconOnly
        if sh == self.tr("Only Text"):
            return Qt.ToolButtonTextOnly
        return ""

    def toolButtonStyleToText(self,bs):
        if bs == Qt.ToolButtonTextUnderIcon:
            return self.tr("Symbol and Text")
        if bs == Qt.ToolButtonIconOnly:
            return self.tr("Only Symbol")
        if bs == Qt.ToolButtonTextOnly:
            return self.tr("Only Text")
        return ""


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
                and not fdb.bold(fam,sty) and not fdb.italic(fam,sty):
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
        self.parent = parent

        fontGroup = QGroupBox(self.tr("Fonts"))

        self.fontCombo = QtReduceFontComboBox(self)
        self.setFocusPolicy(Qt.NoFocus)
        self.fontCombo.setEditable(False)
#        self.fontCombo.setFontFilters(QFontComboBox.MonospacedFonts)
        self.fontCombo.setCurrentFont(self.parent.parent.worksheet.font())

        self.sizeCombo = QtReduceComboBox()
        self.findSizes(self.fontCombo.currentFont())
        self.fontCombo.currentFontChanged.connect(self.findSizes)

#        styleCombo = QtReduceComboBox()

        fontLayout = QFormLayout()
        fontLayout.addRow(self.tr("General Worksheet Font"),self.fontCombo)
        fontLayout.addRow(self.tr("Size"),self.sizeCombo)

        fontGroup.setLayout(fontLayout)

        mainLayout = QVBoxLayout()
        mainLayout.addWidget(fontGroup)

        self.setLayout(mainLayout)

    def findSizes(self,font):
        traceLogger.debug("font.key()=%s" % font.key())
        fontDatabase = QFontDatabase()
        currentSize = unicode(self.parent.parent.worksheet.defaultFontSize)
        self.sizeCombo.blockSignals(True)
        self.sizeCombo.clear()

        styleStr = fontDatabase.styleString(font)
        if fontDatabase.isSmoothlyScalable(font.family(),styleStr):
            for size in QFontDatabase.standardSizes():
                self.sizeCombo.addItem(str(size))
        else:
            for size in fontDatabase.smoothSizes(font.family(),styleStr):
                self.sizeCombo.addItem(str(size))

        self.sizeCombo.blockSignals(False)

        sizeIndex = self.sizeCombo.findText(currentSize)
        self.sizeCombo.setCurrentIndex(sizeIndex)


class QtReducePreferencesComputation(QWidget):
    def __init__(self,parent=None):
        super(QtReducePreferencesComputation,self).__init__(parent)

        reduceGroup = QGroupBox("Reduce")

        self.reduceBinary = QLineEdit()

        reduceLayout = QFormLayout()
        reduceLayout.addRow(self.tr("Reduce Binary"),self.reduceBinary)

        reduceGroup.setLayout(reduceLayout)

        mainLayout = QVBoxLayout()
        mainLayout.addWidget(reduceGroup)

        self.setLayout(mainLayout)
