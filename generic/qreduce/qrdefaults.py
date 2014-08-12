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
from PySide.QtCore import QObject
from PySide.QtCore import QSettings
from PySide.QtCore import Qt

from PySide.QtGui import QIcon

from qrlogging import traceLogger

import sys


class QtReduceDefaults(object):

    # Mainwindow:
    WIDTH = 90
    HEIGHT = 36

    # Menu
    MAXRECENT = 5

    # Toolbar:
    ICONSET = "Oxygen"
    ICONSIZE = 16
    BUTTONSTYLE = "Symbol and Text"

    # Worksheet
    FONTFAMILY = "DejaVu Sans Mono"
    FONTSIZE = 12
    FONTSIZEFS = 14

    # Reduce
    REDUCE = "../../bin/redcsl"

    # Preferences
    CURRENTITEM = "Toolbar"


class QtReduceIconSets(QObject):

    def __new__(type, *args):
        if not '_the_instance' in type.__dict__:
            type._the_instance = QObject.__new__(type)
        return type._the_instance

    def __init__(self):
        if not '_ready' in dir(self):
            super(QtReduceIconSets,self).__init__()
            self.db = {"Bluesphere":
                       {"sized":False,
                        self.tr("Open ..."):"fileopen.svg",
                        self.tr("Save"):"filesave-2.1.svg",
                        self.tr("Save As"):"filesaveas.svg",
                        self.tr("Quit"):"",
                        self.tr("Preferences"):"",
                        self.tr("Enter Full Screen"):"",
                        self.tr("Exit Full Screen"):"",
                        self.tr("Insert Group Above"):"",
                        self.tr("Insert Group Below"):"",
                        self.tr("Evaluate All"):"",
                        self.tr("Evaluate Selection"):"",
                        self.tr("Delete All Output"):"",
                        self.tr("Abort"):"button_cancel.svg",
                        self.tr("Show Raw Model"):"",
                        self.tr("Hide Raw Model"):"",
                        self.tr("MainWindow::test"):"",
                        self.tr("About"):"",
                        self.tr("License"):"",
                        self.tr("Zoom In"):"edit_add.svg",
                        self.tr("Zoom Out"):"edit_remove.svg",
                        self.tr("Zoom Default"):"bookmark.svg"},
                       "Crystal":
                       {"sized":False,
                        self.tr( "Open ..."):"fileopen-256.png",
                        self.tr("Save"):"filesave-256.png",
                        self.tr("Save As"):"filesaveas-256.png",
                        self.tr("Quit"):"",
                        self.tr("Preferences"):"",
                        self.tr("Enter Full Screen"):"",
                        self.tr("Exit Full Screen"):"",
                        self.tr("Insert Group Above"):"",
                        self.tr("Insert Group Below"):"",
                        self.tr("Evaluate All"):"",
                        self.tr("Evaluate Selection"):"",
                        self.tr("Delete All Output"):"",
                        self.tr("Abort"):"agt_stop-256.png",
                        self.tr("Show Raw Model"):"",
                        self.tr("Hide Raw Model"):"",
                        self.tr("MainWindow::test"):"",
                        self.tr("About"):"",
                        self.tr("License"):"",
                        self.tr("Zoom In"):"viewmag+-256.png",
                        self.tr("Zoom Out"):"viewmag--256.png",
                        self.tr("Zoom Default"):"viewmag1-256.png"},
                       "Nuvola":
                       {"sized":True,
                       self.tr( "Open ..."):"fileopen.png",
                        self.tr("Save"):"filesave.png",
                        self.tr("Save As"):"filesaveas.png",
                        self.tr("Quit"):"",
                        self.tr("Preferences"):"",
                        self.tr("Enter Full Screen"):"view_fullscreen.png",
                        self.tr("Exit Full Screen"):"view_fullscreen.png",
                        self.tr("Insert Group Above"):"",
                        self.tr("Insert Group Below"):"",
                        self.tr("Evaluate All"):"misc.png",
                        self.tr("Evaluate Selection"):"",
                        self.tr("Delete All Output"):"editdelete.png",
                        self.tr("Abort"):"stop.png",
                        self.tr("Show Raw Model"):"",
                        self.tr("Hide Raw Model"):"",
                        self.tr("MainWindow::test"):"",
                        self.tr("About"):"",
                        self.tr("License"):"",
                        self.tr("Zoom In"):"viewmag+.png",
                        self.tr("Zoom Out"):"viewmag-.png",
                        self.tr("Zoom Default"):"viewmag1.png"},
                       "Oxygen":
                       {"sized":True,
                        self.tr("Open ..."):"document_open.png",
                        self.tr("Save"):"document_save.png",
                        self.tr("Save As"):"document_save_as.png",
                        self.tr("Quit"):"",
                        self.tr("Preferences"):"",
                        self.tr("Enter Full Screen"):"view_fullscreen.png",
                        self.tr("Exit Full Screen"):"view_fullscreen.png",
                        self.tr("Insert Group Above"):"",
                        self.tr("Insert Group Below"):"",
                        self.tr("Evaluate All"):"exec.png",
                        self.tr("Evaluate Selection"):"",
                        self.tr("Delete All Output"):"eraser.png",
                        self.tr("Abort"):"stop.png",
                        self.tr("Show Raw Model"):"",
                        self.tr("Hide Raw Model"):"",
                        self.tr("MainWindow::test"):"",
                        self.tr("About"):"",
                        self.tr("License"):"",
                        self.tr("Zoom In"):"zoom_in.png",
                        self.tr("Zoom Out"):"zoom_out.png",
                        self.tr("Zoom Default"):"zoom_original.png"},
                       "Tango":
                       {"sized":True,
                        self.tr("Open ..."):"document-open.png",
                        self.tr("Save"):"document-save.png",
                        self.tr("Save As"):"document-save-as.png",
                        self.tr("Quit"):"",
                        self.tr("Preferences"):"",
                        self.tr("Enter Full Screen"):"view-fullscreen.png",
                        self.tr("Exit Full Screen"):"view-fullscreen.png",
                        self.tr("Insert Group Above"):"",
                        self.tr("Insert Group Below"):"",
                        self.tr("Evaluate All"):"emblem-system.png",
                        self.tr("Evaluate Selection"):"",
                        self.tr("Delete All Output"):"edit-clear.png",
                        self.tr("Abort"):"process-stop.png",
                        self.tr("Show Raw Model"):"",
                        self.tr("Hide Raw Model"):"",
                        self.tr("MainWindow::test"):"",
                        self.tr("About"):"",
                        self.tr("License"):"",
                        self.tr("Zoom In"):"list-add.png",
                        self.tr("Zoom Out"):"list-remove.png",
                        self.tr("Zoom Default"):"view-refresh.png"}}
            self._ready = True

    def icon(self, act):
        settings = QSettings()
        iconSet = settings.value("toolbar/iconset",QtReduceDefaults.ICONSET)
        iconSize = settings.value("toolbar/iconsize",
                                     QtReduceDefaults.ICONSIZE)
        if iconSet:
            iEntry = self.db[iconSet]
            text = act.iconText()
            entry = None
            if text in iEntry.keys():
                entry = iEntry[text]
            path = ''
            if entry:
                path = sys.path[0] + "/icons/" + iconSet + "/"
                if iEntry["sized"]:
                    path += str(iconSize) + "/"
                path += entry
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
                return QIcon('')

    def iconSetChanged(self,iconSet):
        QSettings().setValue("toolbar/iconset",iconSet)

    def iconSizeChanged(self,iconSize):
        iconSize = int(iconSize)
        QSettings().setValue("toolbar/iconsize",iconSize)
