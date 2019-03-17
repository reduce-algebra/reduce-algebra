/********************************************************************************
*                                                                               *
*                   M a i n   F O X   I n c l u d e   F i l e                   *
*                                                                               *
*********************************************************************************
* Copyright (C) 1997,2006 by Jeroen van der Zijp.   All Rights Reserved.        *
*********************************************************************************
* This library is free software; you can redistribute it and/or                 *
* modify it under the terms of the GNU Lesser General Public                    *
* License as published by the Free Software Foundation; either                  *
* version 2.1 of the License, or (at your option) any later version.            *
*                                                                               *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU             *
* Lesser General Public License for more details.                               *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public              *
* License along with this library; if not, write to the Free Software           *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.    *
*********************************************************************************
* $Id$                               *
********************************************************************************/
#ifndef FX_H
#define FX_H

// Basic includes
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

// FOX defines
#include "fxver.h"
#include "fxdefs.h"
#include "fxascii.h"
#include "fxunicode.h"

// FOX classes
#include "FXHash.h"
#include "FXException.h"
#include "FXThread.h"
#include "FXStream.h"
#include "FXIO.h"
#include "FXFile.h"
#include "FXPipe.h"
#include "FXSocket.h"
#include "FXFileStream.h"
#include "FXMemoryStream.h"
#include "FXString.h"
#include "FXSize.h"
#include "FXPoint.h"
#include "FXRectangle.h"
#include "FXObject.h"
#include "FXDelegator.h"
#include "FXDict.h"
#include "FXPath.h"
#include "FXSystem.h"
#include "FXStat.h"
#include "FXDir.h"
#include "FXDate.h"
#include "FXURL.h"
#include "FXStringDict.h"
#include "FXSettings.h"
#include "FXRegistry.h"
#include "FXObjectList.h"
#include "FXAccelTable.h"
#include "FXRecentFiles.h"
#include "FXApp.h"
#include "FXId.h"
#include "FXVisual.h"
#include "FXFont.h"
#include "FXCursor.h"
#include "FXGUISignal.h"
#include "FXCURCursor.h"
#include "FXGIFCursor.h"
#include "FXDrawable.h"
#include "FXBitmap.h"
#include "FXImage.h"
#include "FXIcon.h"
#include "FXGIFImage.h"
#include "FXIFFImage.h"
#include "FXBMPImage.h"
#include "FXICOImage.h"
#include "FXXBMImage.h"
#include "FXXPMImage.h"
#include "FXPCXImage.h"
#include "FXTGAImage.h"
#include "FXRGBImage.h"
#include "FXPPMImage.h"
#include "FXRASImage.h"
#include "FXGIFIcon.h"
#include "FXIFFIcon.h"
#include "FXBMPIcon.h"
#include "FXICOIcon.h"
#include "FXXBMIcon.h"
#include "FXXPMIcon.h"
#include "FXPCXIcon.h"
#include "FXTGAIcon.h"
#include "FXRGBIcon.h"
#include "FXPPMIcon.h"
#include "FXRASIcon.h"
#include "FXRegion.h"
#include "FXDC.h"
#include "FXDCWindow.h"
#include "FXDCPrint.h"
#include "FXIconSource.h"
#include "FXIconDict.h"
#include "FXFileDict.h"
#include "FXWindow.h"
#include "FXFrame.h"
#include "FXSeparator.h"
#include "FXLabel.h"
#include "FX7Segment.h"
#include "FXDial.h"
#include "FXKnob.h"
#include "FXColorBar.h"
#include "FXColorRing.h"
#include "FXColorWell.h"
#include "FXColorWheel.h"
#include "FXTextField.h"
#include "FXButton.h"
#include "FXPicker.h"
#include "FXToggleButton.h"
#include "FXTriStateButton.h"
#include "FXCheckButton.h"
#include "FXRadioButton.h"
#include "FXArrowButton.h"
#include "FXMenuButton.h"
#include "FXComposite.h"
#include "FXPacker.h"
#include "FXHorizontalFrame.h"
#include "FXVerticalFrame.h"
#include "FXSpring.h"
#include "FXMatrix.h"
#include "FXSpinner.h"
#include "FXRealSpinner.h"
#include "FXRootWindow.h"
#include "FXCanvas.h"
#include "FXGroupBox.h"
#include "FXShell.h"
#include "FXToolTip.h"
#include "FXPopup.h"
#include "FXTopWindow.h"
#include "FXDialogBox.h"
#include "FXMainWindow.h"
#include "FXMenuPane.h"
#include "FXScrollPane.h"
#include "FXMenuCaption.h"
#include "FXMenuSeparator.h"
#include "FXMenuTitle.h"
#include "FXMenuCascade.h"
#include "FXMenuCommand.h"
#include "FXMenuCheck.h"
#include "FXMenuRadio.h"
#include "FXMenuBar.h"
#include "FXOptionMenu.h"
#include "FXSwitcher.h"
#include "FXTabBar.h"
#include "FXTabBook.h"
#include "FXTabItem.h"
#include "FXScrollBar.h"
#include "FXScrollArea.h"
#include "FXScrollWindow.h"
#include "FXList.h"
#include "FXComboBox.h"
#include "FXListBox.h"
#include "FXTreeList.h"
#include "FXTreeListBox.h"
#include "FXFoldingList.h"
#include "FXBitmapView.h"
#include "FXBitmapFrame.h"
#include "FXImageView.h"
#include "FXImageFrame.h"
#include "FXTable.h"
#include "FXDragCorner.h"
#include "FXStatusBar.h"
#include "FXStatusLine.h"
#include "FXChoiceBox.h"
#include "FXMessageBox.h"
#include "FXDirList.h"
#include "FXSlider.h"
#include "FXRealSlider.h"
#include "FXSplitter.h"
#include "FX4Splitter.h"
#include "FXHeader.h"
#include "FXShutter.h"
#include "FXIconList.h"
#include "FXFileList.h"
#include "FXDirBox.h"
#include "FXDriveBox.h"
#include "FXDirSelector.h"
#include "FXDirDialog.h"
#include "FXFileSelector.h"
#include "FXFileDialog.h"
#include "FXColorSelector.h"
#include "FXColorDialog.h"
#include "FXFontSelector.h"
#include "FXFontDialog.h"
#include "FXUndoList.h"
#include "FXRex.h"
#include "FXText.h"
#include "FXDataTarget.h"
#include "FXProgressBar.h"
#include "FXReplaceDialog.h"
#include "FXRuler.h"
#include "FXRulerView.h"
#include "FXSearchDialog.h"
#include "FXInputDialog.h"
#include "FXProgressDialog.h"
#include "FXWizard.h"
#include "FXMDIButton.h"
#include "FXMDIClient.h"
#include "FXMDIChild.h"
#include "FXDocument.h"
#include "FXDockSite.h"
#include "FXDockBar.h"
#include "FXToolBar.h"
#include "FXDockHandler.h"
#include "FXDockTitle.h"
#include "FXToolBarGrip.h"
#include "FXToolBarShell.h"
#include "FXToolBarTab.h"
#include "FXPrintDialog.h"
#include "FXDebugTarget.h"
#include "FXSplashWindow.h"


#ifndef FX_NO_GLOBAL_NAMESPACE
using namespace FX;
#endif


// An "my_assert" scheme that lets me write in my own code to print the
// diagnostics.

[[noreturn]] static void my_abort()
{   std::abort();
}

template <typename F>
inline void my_assert(bool ok, F&& action)
{
#ifndef NDEBUG
// Use this as in
//     my_assert(predicate, [&]{...});
// where the "..." is an arbitrary sequence of actions to be taken
// if the assertion fails.
    if (!ok) { action(); my_abort(); }
#endif //NDEBUG
}

//
// I have a bunch of macros that I use for desparation-mode debugging,
// and in particular when I have bugs that wriggle back into their lairs
// when I try running under "gdb" or whatever. These print dull messages
// to stderr. The "do..while" idiom is to keep C syntax safe with regard to
// semicolons.
//

#define D do { \
          const char *_f_ = strrchr(__FILE__, '/'); \
          if (_f_ == NULL) _f_ = strrchr(__FILE__, '\\'); \
          if (_f_ == NULL) _f_ = __FILE__; else _f_++; \
          fprintf(stderr, "Line %d File %s\n", __LINE__, _f_); \
          fflush(stderr); \
          } while (0)

#define DS(s) do { \
          const char *_f_ = strrchr(__FILE__, '/'); \
          if (_f_ == NULL) _f_ = strrchr(__FILE__, '\\'); \
          if (_f_ == NULL) _f_ = __FILE__; else _f_++; \
          fprintf(stderr, "Line %d File %s: %s\n", __LINE__, _f_, (s)); \
          fflush(stderr); \
          } while (0)

#define DX(s) do { \
          const char *_f_ = strrchr(__FILE__, '/'); \
          if (_f_ == NULL) _f_ = strrchr(__FILE__, '\\'); \
          if (_f_ == NULL) _f_ = __FILE__; else _f_++; \
          fprintf(stderr, "Line %d File %s: %llx\n", __LINE__, _f_, \
                          (long long unsigned)(s)); \
          fflush(stderr); \
          } while (0)

#define DF(f,...) do { \
          const char *_f_ = strrchr(__FILE__, '/'); \
          if (_f_ == NULL) _f_ = strrchr(__FILE__, '\\'); \
          if (_f_ == NULL) _f_ = __FILE__; else _f_++; \
          fprintf(stderr, "Line %d File %s: ", __LINE__, _f_); \
          fprintf(stderr, f, __VA_ARGS__); \
          fprintf(stderr, "\n"); \
          fflush(stderr); \
          } while (0)


#endif // !FX_H
