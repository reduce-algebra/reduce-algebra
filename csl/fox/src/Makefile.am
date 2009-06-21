## Process this file with automake to produce Makefile.in

## MODIFIED BY A C NORMAN, 2008, 2009
## The changes add some new sources and support an experimental
## build for windows-64 using the Microsoft command-line tools. This
## comment is only here because LGPL obliges me to mark any file that is
## altered with a prominent notice. Somehow the GPL/LGPL people could be
## amazingly uptight at the stage that the original BSD license has an
## "obnoxious advertising clause" while not minding that they oblige me
## to incorporate something rather similar here!

## I have had LOTS of pain with libtool when I try to build on Windows,
## various versions of Linux (with various generations of libtool installed),
## BSD and Solaris etc. So I am changing the build here so that it only
## creates simple libraries and thus is able to avoid all use of libtool.


AM_CXXFLAGS = @CXXFLAGS@ @X_CFLAGS@
INCLUDES = -I$(top_srcdir)/include -I$(top_builddir)/include
RESWRAP  = $(top_builddir)/utils/reswrap$(EXEEXT)
SUFFIXES = .gif .bmp

# For a (cross-) build for Windows-64 (and possibly at some stage to build
# using the command line Microsoft compilers for 32-bit windows using the
# cygwin version of bash as a shell) I want to create libFOX-1.6.lib rather
# then libFOX-1.6.la. The automake/autoconf seems not to really understand
# the ".lib" suffix, and so in that case I will do the build and the
# install essentially manually.

if msvcxp64

noinst_DATA = libFOX-1.6.lib
lib_LIBRARIES =

else

noinst_DATA =
lib_LIBRARIES = libFOX-1.6.a
# The next line may have been useful when this was an LTLIBRARY but hurts
# when it is a regular library!
# libFOX_1_6_a_LIBADD = $(X_LIBS) $(X_BASE_LIBS) $(X_EXTRA_LIBS) $(GL_LIBS)
endif

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


if msvcxp64

.cpp.obj:
	$(CXXCOMPILE) -c `cygpath -w $<`

CODECS64 = \
FX88591Codec.obj \
FX88592Codec.obj \
FX88593Codec.obj \
FX88594Codec.obj \
FX88595Codec.obj \
FX88596Codec.obj \
FX88597Codec.obj \
FX88598Codec.obj \
FX88599Codec.obj \
FX885910Codec.obj \
FX885911Codec.obj \
FX885913Codec.obj \
FX885914Codec.obj \
FX885915Codec.obj \
FX885916Codec.obj \
FXCP437Codec.obj \
FXCP850Codec.obj \
FXCP852Codec.obj \
FXCP855Codec.obj \
FXCP856Codec.obj \
FXCP857Codec.obj \
FXCP860Codec.obj \
FXCP861Codec.obj \
FXCP862Codec.obj \
FXCP863Codec.obj \
FXCP864Codec.obj \
FXCP865Codec.obj \
FXCP866Codec.obj \
FXCP869Codec.obj \
FXCP874Codec.obj \
FXCP1250Codec.obj \
FXCP1251Codec.obj \
FXCP1252Codec.obj \
FXCP1253Codec.obj \
FXCP1254Codec.obj \
FXCP1255Codec.obj \
FXCP1256Codec.obj \
FXCP1257Codec.obj \
FXCP1258Codec.obj \
FXKOI8RCodec.obj \
FXUTF8Codec.obj \
FXUTF16Codec.obj \
FXUTF32Codec.obj



srcs1 = \
$(CODECS64) \
FXDCNativePrinter.obj \
FXMathText.obj \
FXPostscriptFont.obj \
FXShowMath.obj \
FXTerminal.obj \
fwin.obj \
termed.obj \
FXWorker.obj \
FX4Splitter.obj \
FX7Segment.obj \
FXAccelTable.obj \
FXApp.obj \
FXArrowButton.obj \
FXBMPIcon.obj \
FXBMPImage.obj \
FXBitmap.obj \
FXBitmapFrame.obj \
FXBitmapView.obj \
FXButton.obj \
FXBZFileStream.obj \
FXCURCursor.obj \
FXCanvas.obj \
FXCheckButton.obj \
FXChoiceBox.obj \
FXColorBar.obj \
FXColorDialog.obj \
FXColorList.obj \
FXColorNames.obj \
FXColorRing.obj \
FXColorSelector.obj \
FXColorWell.obj \
FXColorWheel.obj \
FXComboBox.obj \
FXComposeContext.obj \
FXComposite.obj \
FXCursor.obj \
FXDataTarget.obj \
FXDate.obj \
FXDC.obj \
FXDCPrint.obj \
FXDCWindow.obj \
FXDLL.obj \
FXDebugTarget.obj \
FXDelegator.obj \
FXDial.obj \
FXDialogBox.obj \
FXDict.obj \
FXDir.obj \
FXDirBox.obj \
FXDirDialog.obj \
FXDirList.obj \
FXDirSelector.obj \
FXDockBar.obj \
FXDockSite.obj \
FXDockHandler.obj \
FXDockTitle.obj \
FXDocument.obj \
FXDragCorner.obj \
FXDrawable.obj \
FXDriveBox.obj \
FXException.obj \
FXExpression.obj \
FXExtentd.obj \
FXExtentf.obj \
FXFile.obj \
FXFileDialog.obj \
FXFileDict.obj \
FXFileList.obj \
FXFileSelector.obj \
FXFileStream.obj \
FXFoldingList.obj \
FXFont.obj \
FXFontDialog.obj \
FXFontSelector.obj \
FXFrame.obj \
FXGIFCursor.obj \
FXGIFIcon.obj \
FXGIFImage.obj \
FXGLCanvas.obj \
FXGLCone.obj \
FXGLContext.obj \
FXGLCube.obj \
FXGLCylinder.obj \
FXGLObject.obj \
FXGLShape.obj \
FXGLSphere.obj \
FXGLTriangleMesh.obj \
FXGLViewer.obj \
FXGLVisual.obj \
FXGradientBar.obj \
FXGroupBox.obj \
FXGUISignal.obj \
FXGZFileStream.obj \
FXHash.obj \
FXHeader.obj \
FXHorizontalFrame.obj \
FXICOIcon.obj \
FXICOImage.obj \
FXIFFIcon.obj \
FXIFFImage.obj \
FXIO.obj \
FXIcon.obj \
FXIconDict.obj \
FXIconList.obj \
FXIconSource.obj \
FXId.obj \
FXImage.obj \
FXImageFrame.obj \
FXImageView.obj \
FXInputDialog.obj \
FXJPGIcon.obj \
FXJPGImage.obj \
FXKnob.obj \
FXLabel.obj \
FXList.obj \
FXListBox.obj \
FXMDIButton.obj \
FXMDIChild.obj \
FXMDIClient.obj \
FXMainWindow.obj \
FXMat3d.obj \
FXMat4d.obj \
FXMat3f.obj \
FXMat4f.obj \
FXMatrix.obj \
FXMemMap.obj \
FXMemoryStream.obj \
FXMenuBar.obj \
FXMenuButton.obj \
FXMenuCaption.obj \
FXMenuCascade.obj \
FXMenuCheck.obj \
FXMenuRadio.obj \
FXMenuCommand.obj \
FXMenuPane.obj \
FXMenuSeparator.obj \
FXMenuTitle.obj \
FXMessageBox.obj \
FXObject.obj \
FXObjectList.obj \
FXOptionMenu.obj \
FXPCXIcon.obj \
FXPCXImage.obj \
FXPNGIcon.obj \
FXPNGImage.obj \
FXPPMIcon.obj \
FXPPMImage.obj \
FXPacker.obj \
FXPath.obj \
FXPicker.obj \
FXPipe.obj  \
FXPopup.obj \
FXPoint.obj \
FXPrintDialog.obj \
FXProgressBar.obj \
FXProgressDialog.obj \
FXQuatd.obj \
FXQuatf.obj \
FXRASIcon.obj \
FXRASImage.obj \
FXRGBIcon.obj \
FXRGBImage.obj \
FXRadioButton.obj \
FXRangef.obj \
FXRanged.obj \
FXRealSlider.obj \
FXRealSpinner.obj \
FXRecentFiles.obj \
FXRectangle.obj \
FXRegion.obj \
FXRegistry.obj \
FXReplaceDialog.obj \
FXRex.obj \
FXRootWindow.obj \
FXRuler.obj \
FXRulerView.obj \
FXScrollArea.obj \
FXScrollBar.obj \
FXScrollPane.obj \
FXScrollWindow.obj \
FXSearchDialog.obj \
FXSeparator.obj \
FXSettings.obj \
FXShell.obj \
FXShutter.obj \
FXSize.obj \
FXSlider.obj \
FXSocket.obj \
FXSpinner.obj \
FXSpheref.obj \
FXSphered.obj \
FXSplashWindow.obj \
FXSplitter.obj \
FXSpring.obj \
FXStat.obj \
FXStatusBar.obj \
FXStatusLine.obj \
FXStream.obj \
FXString.obj \
FXStringDict.obj \
FXSwitcher.obj \
FXSystem.obj \
FXTGAIcon.obj \
FXTGAImage.obj \
FXTIFIcon.obj \
FXTIFImage.obj \
FXTabBar.obj \
FXTabBook.obj \
FXTabItem.obj \
FXTable.obj \
FXText.obj \
FXTextCodec.obj \
FXTextField.obj \
FXThread.obj \
FXToggleButton.obj \
FXToolBar.obj \
FXToolBarGrip.obj \
FXToolBarShell.obj \
FXToolBarTab.obj \
FXToolTip.obj \
FXTopWindow.obj \
FXTranslator.obj \
FXTreeList.obj \
FXTreeListBox.obj \
FXTriStateButton.obj \
FXUndoList.obj \
FXURL.obj \
FXVec2d.obj \
FXVec2f.obj \
FXVec3d.obj \
FXVec3f.obj \
FXVec4d.obj \
FXVec4f.obj \
FXVerticalFrame.obj \
FXVisual.obj \
FXWindow.obj \
FXWizard.obj \
FXXBMIcon.obj \
FXXBMImage.obj \
FXXPMIcon.obj \
FXXPMImage.obj \
fxascii.obj \
fxbmpio.obj \
fxfilematch.obj \
fxgifio.obj \
fxicoio.obj \
fxiffio.obj \
fxjpegio.obj \
fxkeyboard.obj \
fxkeysym.obj \
fxparsegeometry.obj \
fxpcxio.obj \
fxpngio.obj \
fxppmio.obj \
fxpriv.obj \
fxpsio.obj \
fxfsquantize.obj \
fxezquantize.obj \
fxwuquantize.obj \
fxrasio.obj \
fxrgbio.obj \
fxtargaio.obj \
fxtifio.obj \
fxunicode.obj \
fxutils.obj \
fxxbmio.obj \
fxxpmio.obj \
icons.obj \
strtoll.obj \
vsscanf.obj

hdrrc = icons.h \
jitter.h \
version.rc \
version.rc.in \
fxpriv.h 

srcs = $(srcs1) $(hdrrc) $(CURSORS) $(ICONS)

libFOX-1.6.lib:	$(srcs)
	lib /out:libFOX-1.6.lib $(srcs1)

install-data-local:	libFOX-1.6.lib
	cp libFOX-1.6.lib $(DESTDIR)$(libdir)/libFOX-1.6.lib"

else

libFOX_1_6_a_SOURCES = \
$(CODECS) \
FXDCNativePrinter.cpp \
FXPostscriptFont.cpp \
FXTerminal.cpp \
fwin.c \
termed.c \
FXWorker.cpp \
FXShowMath.cpp \
FXMathText.cpp \
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
FXIO.cpp \
FXIcon.cpp \
FXIconDict.cpp \
FXIconList.cpp \
FXIconSource.cpp \
FXId.cpp \
FXImage.cpp \
FXImageFrame.cpp \
FXImageView.cpp \
FXInputDialog.cpp \
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
fxpriv.h 

endif

FXApp.$(OBJEXT):	icons.h

icons.h: $(ICONS)
	$(RESWRAP) -i -n FX -o icons.h $(ICONS)


icons.cpp: $(ICONS)
	$(RESWRAP) -e -n FX -o icons.cpp $(ICONS)


EXTRA_DIST = Makefile.bc \
             Makefile.bc.resp \
             Makefile.dmc \
             Makefile.wc \
             Makefile.dmc.resp

