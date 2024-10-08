## Process this file with automake to produce Makefile.in

## MODIFIED BY A C NORMAN, 2008, 2009, 2014
## The changes add some new source files and to avoid use of
## libtool. This comment is here because LGPL obliges me to mark any
## file that is altered with a prominent notice.


## I have had LOTS of pain with libtool when I try to build on Windows,
## various versions of Linux (with various generations of libtool installed),
## BSD and Solaris etc. So I am changing the build here so that it only
## creates simple libraries and thus is able to avoid all use of libtool.

# If is very probable that the passage of time has let to libtool becoming
# stable, but the scheme used here is also stable so I will not move back.

CXXFLAGS = @CXXFLAGS@ @X_CFLAGS@ -fmax-errors=7
AM_CPPFLAGS = -I$(top_srcdir)/include -I$(top_builddir)/include
# ACN change to use abs_top_builddir - an absolute pathname...
RESWRAP  = $(abs_top_builddir)/utils/reswrap$(EXEEXT)
$(RESWRAP):
	$(MAKE) -C $(abs_top_builddir)/utils reswrap$(EXEEXT)
SUFFIXES = .gif .bmp

noinst_DATA =
lib_LIBRARIES = libFOX-1.6.a

CURSORS = \
crosshair.xbm \
crosshair_mask.xbm \
dndcopy.xbm \
dndcopy_mask.xbm \
dndlink.xbm \
dndlink_mask.xbm \
dndmove.xbm \
dndmove_mask.xbm \
dontdrop.xbm \
dontdrop_mask.xbm \
drag.xbm \
drag_mask.xbm \
gray.xbm \
hand.xbm \
hand_mask.xbm \
helparrow.xbm \
helparrow_mask.xbm \
hsplit.xbm \
hsplit_mask.xbm \
move.xbm \
move_mask.xbm \
ne.xbm \
ne_mask.xbm \
se.xbm \
se_mask.xbm \
sw.xbm \
sw_mask.xbm \
nw.xbm \
nw_mask.xbm \
resizeleft.xbm \
resizeleft_mask.xbm \
resizetop.xbm \
resizetop_mask.xbm \
resizetopleft.xbm \
resizetopleft_mask.xbm \
resizetopright.xbm \
resizetopright_mask.xbm \
rotate.xbm \
rotate_mask.xbm \
swatch.xbm \
swatch_mask.xbm \
vsplit.xbm \
vsplit_mask.xbm \
xsplit.xbm \
xsplit_mask.xbm

ICONS = \
arrownext.gif \
arrowprev.gif \
bigapp.gif \
bigcdrom.gif \
bigcomputer.gif \
bigdesktop.gif \
bigdoc.gif \
bigfloppy.gif \
bigfolder.gif \
bigfolderopen.gif \
bignetdrive.gif \
bignethood.gif \
bookset.gif \
bookclr.gif \
cmymode.gif \
dialmode.gif \
dirupicon.gif \
deleteicon.gif \
docktop.gif \
dockbottom.gif \
dockleft.gif \
dockright.gif \
dockfree.gif \
dockflip.gif \
entericon.gif \
erroricon.gif \
eyedrop.gif \
filecopy.gif \
filemove.gif \
filehidden.gif \
filelink.gif \
filerename.gif \
filedelete.gif \
fileshown.gif \
foldernew.gif \
gotohome.gif \
gotoicon.gif \
gotowork.gif \
hsvmode.gif \
infoicon.gif \
landscape.gif \
listmode.gif \
miniapp.gif \
minicdrom.gif \
minicomputer.gif \
minidesktop.gif \
minidoc.gif \
minifloppy.gif \
minifolder.gif \
minifolderopen.gif \
miniharddisk.gif \
mininetdrive.gif \
mininethood.gif \
minizipdrive.gif \
portrait.gif \
questionicon.gif \
rgbmode.gif \
searchicon.gif \
showbigicons.gif \
showdetails.gif \
showsmallicons.gif \
warningicon.gif \
winclose.gif \
winmaximize.gif \
winminimize.gif \
winrestore.gif


CODECS = \
FX88591Codec.cpp \
FX88592Codec.cpp \
FX88593Codec.cpp \
FX88594Codec.cpp \
FX88595Codec.cpp \
FX88596Codec.cpp \
FX88597Codec.cpp \
FX88598Codec.cpp \
FX88599Codec.cpp \
FX885910Codec.cpp \
FX885911Codec.cpp \
FX885913Codec.cpp \
FX885914Codec.cpp \
FX885915Codec.cpp \
FX885916Codec.cpp \
FXCP437Codec.cpp \
FXCP850Codec.cpp \
FXCP852Codec.cpp \
FXCP855Codec.cpp \
FXCP856Codec.cpp \
FXCP857Codec.cpp \
FXCP860Codec.cpp \
FXCP861Codec.cpp \
FXCP862Codec.cpp \
FXCP863Codec.cpp \
FXCP864Codec.cpp \
FXCP865Codec.cpp \
FXCP866Codec.cpp \
FXCP869Codec.cpp \
FXCP874Codec.cpp \
FXCP1250Codec.cpp \
FXCP1251Codec.cpp \
FXCP1252Codec.cpp \
FXCP1253Codec.cpp \
FXCP1254Codec.cpp \
FXCP1255Codec.cpp \
FXCP1256Codec.cpp \
FXCP1257Codec.cpp \
FXCP1258Codec.cpp \
FXKOI8RCodec.cpp \
FXUTF8Codec.cpp \
FXUTF16Codec.cpp \
FXUTF32Codec.cpp

ACN_FILES = \
FXDCNativePrinter.cpp \
FXPostscriptFont.cpp \
FXTerminal.cpp \
fwin.cpp \
termed.cpp \
FXWorker.cpp \
FXShowMath.cpp

libFOX_1_6_a_SOURCES = \
$(CODECS) \
$(ACN_FILES) \
FX4Splitter.cpp \
FX7Segment.cpp \
FXAccelTable.cpp \
FXApp.cpp \
FXArrowButton.cpp \
FXBMPIcon.cpp \
FXBMPImage.cpp \
FXBitmap.cpp \
FXBitmapFrame.cpp \
FXBitmapView.cpp \
FXButton.cpp \
FXBZFileStream.cpp \
FXCURCursor.cpp \
FXCanvas.cpp \
FXCheckButton.cpp \
FXChoiceBox.cpp \
FXColorBar.cpp \
FXColorDialog.cpp \
FXColorList.cpp \
FXColorNames.cpp \
FXColorRing.cpp \
FXColorSelector.cpp \
FXColorWell.cpp \
FXColorWheel.cpp \
FXComboBox.cpp \
FXComposeContext.cpp \
FXComposite.cpp \
FXCursor.cpp \
FXDataTarget.cpp \
FXDate.cpp \
FXDC.cpp \
FXDCPrint.cpp \
FXDCWindow.cpp \
FXDLL.cpp \
FXDebugTarget.cpp \
FXDelegator.cpp \
FXDial.cpp \
FXDialogBox.cpp \
FXDict.cpp \
FXDir.cpp \
FXDirBox.cpp \
FXDirDialog.cpp \
FXDirList.cpp \
FXDirSelector.cpp \
FXDockBar.cpp \
FXDockSite.cpp \
FXDockHandler.cpp \
FXDockTitle.cpp \
FXDocument.cpp \
FXDragCorner.cpp \
FXDrawable.cpp \
FXDriveBox.cpp \
FXException.cpp \
FXExpression.cpp \
FXExtentd.cpp \
FXExtentf.cpp \
FXFile.cpp \
FXFileDialog.cpp \
FXFileDict.cpp \
FXFileList.cpp \
FXFileSelector.cpp \
FXFileStream.cpp \
FXFoldingList.cpp \
FXFont.cpp \
FXFontDialog.cpp \
FXFontSelector.cpp \
FXFrame.cpp \
FXGIFCursor.cpp \
FXGIFIcon.cpp \
FXGIFImage.cpp \
FXGLCanvas.cpp \
FXGLCone.cpp \
FXGLContext.cpp \
FXGLCube.cpp \
FXGLCylinder.cpp \
FXGLObject.cpp \
FXGLShape.cpp \
FXGLSphere.cpp \
FXGLTriangleMesh.cpp \
FXGLViewer.cpp \
FXGLVisual.cpp \
FXGradientBar.cpp \
FXGroupBox.cpp \
FXGUISignal.cpp \
FXGZFileStream.cpp \
FXHash.cpp \
FXHeader.cpp \
FXHorizontalFrame.cpp \
FXICOIcon.cpp \
FXICOImage.cpp \
FXIFFIcon.cpp \
FXIFFImage.cpp \
FXIcon.cpp \
FXIconDict.cpp \
FXIconList.cpp \
FXIconSource.cpp \
FXId.cpp \
FXImage.cpp \
FXImageFrame.cpp \
FXImageView.cpp \
FXInputDialog.cpp \
FXIO.cpp \
FXJPGIcon.cpp \
FXJPGImage.cpp \
FXKnob.cpp \
FXLabel.cpp \
FXList.cpp \
FXListBox.cpp \
FXMDIButton.cpp \
FXMDIChild.cpp \
FXMDIClient.cpp \
FXMainWindow.cpp \
FXMat3d.cpp \
FXMat4d.cpp \
FXMat3f.cpp \
FXMat4f.cpp \
FXMatrix.cpp \
FXMemMap.cpp \
FXMemoryStream.cpp \
FXMenuBar.cpp \
FXMenuButton.cpp \
FXMenuCaption.cpp \
FXMenuCascade.cpp \
FXMenuCheck.cpp \
FXMenuRadio.cpp \
FXMenuCommand.cpp \
FXMenuPane.cpp \
FXMenuSeparator.cpp \
FXMenuTitle.cpp \
FXMessageBox.cpp \
FXObject.cpp \
FXObjectList.cpp \
FXOptionMenu.cpp \
FXPCXIcon.cpp \
FXPCXImage.cpp \
FXPNGIcon.cpp \
FXPNGImage.cpp \
FXPPMIcon.cpp \
FXPPMImage.cpp \
FXPacker.cpp \
FXPath.cpp \
FXPicker.cpp \
FXPipe.cpp  \
FXPopup.cpp \
FXPoint.cpp \
FXPrintDialog.cpp \
FXProgressBar.cpp \
FXProgressDialog.cpp \
FXQuatd.cpp \
FXQuatf.cpp \
FXRASIcon.cpp \
FXRASImage.cpp \
FXRGBIcon.cpp \
FXRGBImage.cpp \
FXRadioButton.cpp \
FXRangef.cpp \
FXRanged.cpp \
FXRealSlider.cpp \
FXRealSpinner.cpp \
FXRecentFiles.cpp \
FXRectangle.cpp \
FXRegion.cpp \
FXRegistry.cpp \
FXReplaceDialog.cpp \
FXReduceDialog.cpp \
FXReduceMenus.cpp \
FXRex.cpp \
FXRootWindow.cpp \
FXRuler.cpp \
FXRulerView.cpp \
FXScrollArea.cpp \
FXScrollBar.cpp \
FXScrollPane.cpp \
FXScrollWindow.cpp \
FXSearchDialog.cpp \
FXSeparator.cpp \
FXSettings.cpp \
FXShell.cpp \
FXShutter.cpp \
FXSize.cpp \
FXSlider.cpp \
FXSocket.cpp \
FXSpinner.cpp \
FXSpheref.cpp \
FXSphered.cpp \
FXSplashWindow.cpp \
FXSplitter.cpp \
FXSpring.cpp \
FXStat.cpp \
FXStatusBar.cpp \
FXStatusLine.cpp \
FXStream.cpp \
FXString.cpp \
FXStringDict.cpp \
FXSwitcher.cpp \
FXSystem.cpp \
FXTGAIcon.cpp \
FXTGAImage.cpp \
FXTIFIcon.cpp \
FXTIFImage.cpp \
FXTabBar.cpp \
FXTabBook.cpp \
FXTabItem.cpp \
FXTable.cpp \
FXText.cpp \
FXTextCodec.cpp \
FXTextField.cpp \
FXThread.cpp \
FXToggleButton.cpp \
FXToolBar.cpp \
FXToolBarGrip.cpp \
FXToolBarShell.cpp \
FXToolBarTab.cpp \
FXToolTip.cpp \
FXTopWindow.cpp \
FXTranslator.cpp \
FXTreeList.cpp \
FXTreeListBox.cpp \
FXTriStateButton.cpp \
FXUndoList.cpp \
FXURL.cpp \
FXVec2d.cpp \
FXVec2f.cpp \
FXVec3d.cpp \
FXVec3f.cpp \
FXVec4d.cpp \
FXVec4f.cpp \
FXVerticalFrame.cpp \
FXVisual.cpp \
FXWindow.cpp \
FXWizard.cpp \
FXXBMIcon.cpp \
FXXBMImage.cpp \
FXXPMIcon.cpp \
FXXPMImage.cpp \
fxascii.cpp \
fxbmpio.cpp \
fxfilematch.cpp \
fxgifio.cpp \
fxicoio.cpp \
fxiffio.cpp \
fxjpegio.cpp \
fxkeyboard.cpp \
fxkeysym.cpp \
fxparsegeometry.cpp \
fxpcxio.cpp \
fxpngio.cpp \
fxppmio.cpp \
fxpriv.cpp \
fxpsio.cpp \
fxfsquantize.cpp \
fxezquantize.cpp \
fxwuquantize.cpp \
fxrasio.cpp \
fxrgbio.cpp \
fxtargaio.cpp \
fxtifio.cpp \
fxunicode.cpp \
fxutils.cpp \
fxxbmio.cpp \
fxxpmio.cpp \
icons.cpp \
strtoll.cpp \
vsscanf.cpp \
icons.h \
jitter.h \
version.rc \
version.rc.in \
fxpriv.h \
$(CURSORS) \
$(ICONS)

# ACN changes: the original version here seemed to assume that FOX had
# been configured in-place and so it expected that reswrap would find all
# the $(ICONS) in the currect directory. I have changed it so I move to the
# source directory for that - and then I needed to make the $(RESWRAP)
# definition use an absolute path. So I believe it is now safe to build outside
# the source tree even if for any reason datestamps start off in a less
# than helpful order.

$(srcdir)/FXApp.cpp: $(srcdir)/icons.h

$(srcdir)/icons.h: $(ICONS) $(RESWRAP)
	cd $(srcdir) && $(RESWRAP) -i -n FX -o icons.h $(ICONS)


$(srcdir)/icons.cpp: $(ICONS) $(RESWRAP)
	cd $(srcdir) && $(RESWRAP) -e -n FX -o icons.cpp $(ICONS)


EXTRA_DIST = Makefile.bc \
             Makefile.bc.resp \
             Makefile.dmc \
             Makefile.wc \
             Makefile.dmc.resp

