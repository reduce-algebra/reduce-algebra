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

from PySide.QtCore import Qt

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
from PySide.QtGui import QGroupBox
from PySide.QtGui import QLabel
from PySide.QtGui import QCheckBox
from PySide.QtGui import QLineEdit
from PySide.QtGui import QFontComboBox
from PySide.QtGui import QComboBox
from PySide.QtGui import QFontDatabase

from qrlogging import signalLogger
from qrlogging import traceLogger

class QtReducePreferencePane(QDialog):

    def __init__(self,parent=None):
        super(QtReducePreferencePane,self).__init__(parent)
        self.parent = parent
        self.setModal(False)

        self.__createContents()

        self.appearance = QtReducePreferencesAppearance(self)
        self.computation = QtReducePreferencesComputation(self)

        self.pagesWidget = QStackedWidget()
        self.pagesWidget.addWidget(self.appearance)
        self.pagesWidget.addWidget(self.computation)

        closeButton = QPushButton("Close")
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

        self.setWindowTitle("QReduce Preferences")

    def changePage(self,current,previous):
        if not current:
            current = previous
        self.pagesWidget.setCurrentIndex(self.contentsWidget.row(current))

    def __createContents(self):
        self.contentsWidget = QListWidget()
        self.contentsWidget.setViewMode(QListView.ListMode)
        self.contentsWidget.setMovement(QListView.Static)
        appearance = QListWidgetItem(self.contentsWidget)
        appearance.setText("Appearance")
        appearance.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
        self.contentsWidget.setCurrentItem(appearance)
        computation = QListWidgetItem(self.contentsWidget)
        computation.setText("Computation")
        computation.setFlags(Qt.ItemIsSelectable | Qt.ItemIsEnabled)
        self.contentsWidget.currentItemChanged.connect(self.changePage)


class QtReducePreferencesAppearance(QWidget):
    def __init__(self,parent=None):
        super(QtReducePreferencesAppearance,self).__init__(parent)
        self.parent = parent

        fontGroup = QGroupBox("Fonts")

        self.fontCombo = QFontComboBox()
        self.fontCombo.setEditable(False)
        self.fontCombo.setFontFilters(QFontComboBox.MonospacedFonts)
        self.fontCombo.setCurrentFont(self.parent.parent.worksheet.font())
#        self.fontCombo.setWritingSystem(QFontDatabase.Latin)

        self.sizeCombo = QComboBox()
        self.sizeCombo.setEditable(False)
        self.findSizes(self.fontCombo.currentFont())
        self.fontCombo.currentFontChanged.connect(self.findSizes)

#        styleCombo = QComboBox()

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
