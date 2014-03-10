## Process this file with automake to produce Makefile.in

# Altered by ACN to list the extra header files he introduced.

# This segment added by Arthur Norman in a messy attempt to reduce
# trouble with autoconf and friend.

# The standard arrangment used by automake arranges to re-run aclocal,
# autoconf and automake if any of the files they generate are out of date.
# However proper behaviour there not only relies on autoconf being installed
# but sometimes on the correct version being installed. The replacement
# logic here deals with that by running my own script "autogen.sh"
# when anything needs updating. That will reconfigure using whatever
# version of autoconf is available locally, and if none is it will
# just use "touch" to reset time-stamps on files so that the ordering
# appears reasonable.

# The rules here are arranged to chain so that configure is only
# considered after aclocal.m4 has been dealt with and Makefile.in only after
# that. This is trying to follow the guidance given re "Multiple Outputs"
# in the automake manual so that even when a parallel make is used
# autogen.sh will only end up called once. However I found that (for
# reasons I do not understand so far) there was a tendancy for autogen.sh
# to get called twice. I have put what I think ought to be redundant extra
# code that  means that whena recipe is called it does a further check
# to see if it is actually needed, and that sorts things out. It may be that
# the issues I observed are to do with the very special treatment that
# make gives to the re-creation of Makefile and the files that it is
# derived from.

$(ACLOCAL_M4):  $(am__aclocal_m4_deps)
	@if test $(ACLOCAL_M4) -ot $(top_srcdir)/configure.ac; \
	then \
	  $(top_srcdir)/../../autogen.sh csl/fox ; \
	else echo Redundant attempt to remake $(ACLOCAL_M4) ; \
	fi

$(top_srcdir)/configure:  $(am__configure_deps) $(ACLOCAL_M4)
	@if test $(top_srcdir)/configure -ot $(top_srcdir)/configure.ac || \
	   test $(top_srcdir)/configure -ot $(ACLOCAL_M4) ; \
	then \
	  $(top_srcdir)/../../autogen.sh csl/fox ; \
	else echo Redundant attempt to remake configure ; \
        fi

$(srcdir)/Makefile.in:  $(srcdir)/Makefile.am  $(am__configure_deps) \
		$(top_srcdir)/configure
	@if test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure.ac || \
	   test $(srcdir)/Makefile.in -ot $(ACLOCAL_M4) || \
	   test $(srcdir)/Makefile.in -ot $(top_srcdir)/configure || \
	   test $(srcdir)/Makefile.in -ot $(srcdir)/Makefile.am ; \
	then \
	  $(top_srcdir)/../../autogen.sh csl/fox ; \
	else echo Redundant attempt to remake Makefile.in ; \
	fi




foxincludedir=$(includedir)/fox-1.6

CODECS = \
FX88591Codec.h \
FX88592Codec.h \
FX88593Codec.h \
FX88594Codec.h \
FX88595Codec.h \
FX88596Codec.h \
FX88597Codec.h \
FX88598Codec.h \
FX88599Codec.h \
FX885910Codec.h \
FX885911Codec.h \
FX885913Codec.h \
FX885914Codec.h \
FX885915Codec.h \
FX885916Codec.h \
FXCP437Codec.h \
FXCP850Codec.h \
FXCP852Codec.h \
FXCP855Codec.h \
FXCP856Codec.h \
FXCP857Codec.h \
FXCP860Codec.h \
FXCP861Codec.h \
FXCP862Codec.h \
FXCP863Codec.h \
FXCP864Codec.h \
FXCP865Codec.h \
FXCP866Codec.h \
FXCP869Codec.h \
FXCP874Codec.h \
FXCP1250Codec.h \
FXCP1251Codec.h \
FXCP1252Codec.h \
FXCP1253Codec.h \
FXCP1254Codec.h \
FXCP1255Codec.h \
FXCP1256Codec.h \
FXCP1257Codec.h \
FXCP1258Codec.h \
FXKOI8RCodec.h \
FXUTF8Codec.h \
FXUTF16Codec.h \
FXUTF32Codec.h

# The new files included here...
ACN_EXTRAS = \
FXDCNativePrinter.h \
FXPostscriptFont.h \
FXShowMath.h \
FXTerminal.h \
fwin.h \
termed.h

foxinclude_HEADERS =   \
$(CODECS) \
$(ACN_EXTRAS) \
FX4Splitter.h \
FX7Segment.h \
FXAccelTable.h \
FXApp.h \
FXArray.h \
FXArrowButton.h \
FXBMPIcon.h \
FXBMPImage.h \
FXBitmap.h \
FXBitmapFrame.h \
FXBitmapView.h \
FXButton.h \
FXBZFileStream.h \
FXCURCursor.h \
FXCanvas.h \
FXCheckButton.h \
FXChoiceBox.h \
FXColorBar.h \
FXColorDialog.h \
FXColorList.h \
FXColorRing.h \
FXColorSelector.h \
FXColorWell.h \
FXColorWheel.h \
FXComboBox.h \
FXComposeContext.h \
FXComposite.h \
FXCursor.h \
FXDate.h \
FXDC.h \
FXDCPrint.h \
FXDCWindow.h \
FXDLL.h \
FXDataTarget.h \
FXDebugTarget.h \
FXDelegator.h \
FXDial.h \
FXDialogBox.h \
FXDict.h \
FXDir.h \
FXDirBox.h \
FXDirDialog.h \
FXDirList.h \
FXDirSelector.h \
FXDockBar.h \
FXDockHandler.h \
FXDockSite.h \
FXDockTitle.h \
FXDocument.h \
FXDragCorner.h \
FXDrawable.h \
FXDriveBox.h \
FXElement.h \
FXException.h \
FXExpression.h \
FXExtentd.h \
FXExtentf.h \
FXFile.h \
FXFileDialog.h \
FXFileDict.h \
FXFileList.h \
FXFileSelector.h \
FXFileStream.h \
FXFoldingList.h \
FXFont.h \
FXFontDialog.h \
FXFontSelector.h \
FXFrame.h \
FXGIFCursor.h \
FXGIFIcon.h \
FXGIFImage.h \
FXGLCanvas.h \
FXGLCone.h \
FXGLContext.h \
FXGLCube.h \
FXGLCylinder.h \
FXGLObject.h \
FXGLShape.h \
FXGLSphere.h \
FXGLTriangleMesh.h \
FXGLViewer.h \
FXGLVisual.h \
FXGroupBox.h \
FXGradientBar.h \
FXGUISignal.h \
FXGZFileStream.h \
FXHash.h \
FXHeader.h \
FXHorizontalFrame.h \
FXICOIcon.h \
FXICOImage.h \
FXIFFImage.h \
FXIFFIcon.h \
FXIO.h \
FXIcon.h \
FXIconDict.h \
FXIconList.h \
FXIconSource.h \
FXId.h \
FXImage.h \
FXImageFrame.h \
FXImageView.h \
FXInputDialog.h \
FXJPGIcon.h \
FXJPGImage.h \
FXKnob.h \
FXLabel.h \
FXList.h \
FXListBox.h \
FXMDIButton.h \
FXMDIChild.h \
FXMDIClient.h \
FXMainWindow.h \
FXMat3d.h \
FXMat4d.h \
FXMat3f.h \
FXMat4f.h \
FXMatrix.h \
FXMemoryStream.h \
FXMemMap.h \
FXMenuBar.h \
FXMenuButton.h \
FXMenuCaption.h \
FXMenuCascade.h \
FXMenuCheck.h \
FXMenuRadio.h \
FXMenuCommand.h \
FXMenuPane.h \
FXMenuSeparator.h \
FXMenuTitle.h \
FXMessageBox.h \
FXObject.h \
FXObjectList.h \
FXOptionMenu.h \
FXPCXIcon.h \
FXPCXImage.h \
FXPNGIcon.h \
FXPNGImage.h \
FXPPMIcon.h \
FXPPMImage.h \
FXPacker.h \
FXPath.h \
FXPicker.h \
FXPipe.h \
FXPoint.h \
FXPopup.h \
FXPrintDialog.h \
FXProgressBar.h \
FXProgressDialog.h \
FXQuatd.h \
FXQuatf.h \
FXRASIcon.h \
FXRASImage.h \
FXRGBIcon.h \
FXRGBImage.h \
FXRadioButton.h \
FXRangef.h \
FXRanged.h \
FXRealSlider.h \
FXRealSpinner.h \
FXRecentFiles.h \
FXRectangle.h \
FXRegion.h \
FXRegistry.h \
FXReplaceDialog.h \
FXRex.h \
FXRootWindow.h \
FXRuler.h \
FXRulerView.h \
FXScrollArea.h \
FXScrollBar.h \
FXScrollPane.h \
FXScrollWindow.h \
FXSearchDialog.h \
FXSeparator.h \
FXSettings.h \
FXShell.h \
FXShutter.h \
FXSize.h \
FXSlider.h \
FXSocket.h \
FXSpinner.h \
FXSpheref.h \
FXSphered.h \
FXSplashWindow.h \
FXSplitter.h \
FXSpring.h \
FXStat.h \
FXStatusBar.h \
FXStatusLine.h \
FXStream.h \
FXString.h \
FXStringDict.h \
FXSwitcher.h \
FXSystem.h \
FXTGAIcon.h \
FXTGAImage.h \
FXTIFIcon.h \
FXTIFImage.h \
FXTabBar.h \
FXTabBook.h \
FXTabItem.h \
FXTable.h \
FXText.h \
FXTextCodec.h \
FXTextField.h \
FXThread.h \
FXToggleButton.h \
FXToolBar.h \
FXToolBarGrip.h \
FXToolBarShell.h \
FXToolBarTab.h \
FXToolTip.h \
FXTopWindow.h \
FXTranslator.h \
FXTreeList.h \
FXTreeListBox.h \
FXTriStateButton.h \
FXUndoList.h \
FXURL.h \
FXVec2d.h \
FXVec2f.h \
FXVec3d.h \
FXVec3f.h \
FXVec4d.h \
FXVec4f.h \
FXVerticalFrame.h \
FXVisual.h \
FXWindow.h \
FXWizard.h \
FXXBMIcon.h \
FXXBMImage.h \
FXXPMIcon.h \
FXXPMImage.h \
fx.h \
fx3d.h \
fxascii.h \
fxdefs.h \
fxkeys.h \
fxunicode.h \
fxver.h \
xincs.h
