#!/usr/bin/env python
# ----------------------------------------------------------------------
# $Id$
# ----------------------------------------------------------------------
# (c) 2009 T. Sturm, 2010 T. Sturm, C. Zengler, 2011-2014 T. Sturm
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

import locale
import os
import sys

from PySide.QtGui import QApplication
from PySide.QtGui import QIcon

from PySide.QtCore import QTranslator
from PySide.QtCore import QLocale
from PySide.QtCore import QLibraryInfo
from PySide.QtCore import Qt

from qrmainwindow import QtReduceMainWindow

app = QApplication(sys.argv)

app.setOrganizationName("The Reduce Project")
app.setOrganizationDomain("reduce-algebra.sourceforge.net")
app.setApplicationName("QReduce")

qtTranslator = QTranslator(app)
qtTranslator.load("qt_" + QLocale.system().name(),
                  QLibraryInfo.location(QLibraryInfo.TranslationsPath))
app.installTranslator(qtTranslator)

qreduceTranslator = QTranslator(app)
qreduceTranslator.load(sys.path[0] + "/" + "qreducetr." +
                       str(locale.getdefaultlocale()[0]))
#app.installTranslator(qreduceTranslator)

# app.setStyleSheet("QStatusBar::item { border: 0px solid black }");

app.setWindowIcon(QIcon(sys.path[0] + "/" + "Bumblebee.png"))

if os.uname()[0] == "Darwin":
    app.setAttribute(Qt.AA_DontShowIconsInMenus)

mainwindow = QtReduceMainWindow()

sys.exit(app.exec_())
