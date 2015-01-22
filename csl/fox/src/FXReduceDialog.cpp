/********************************************************************************
*                                                                               *
*                      R e d u c e   M e n u s   D i a l o g                    *
*                                                                               *
*********************************************************************************
* Copyright (C) 2000,2006 by Jeroen van der Zijp.   All Rights Reserved.        *
* (built by A C Norman based in FXReplaceDialog.cpp, 2014                       *
*********************************************************************************
* This library is free software; you can redistribute it and/or                 *
* modify it under the terms of the GNU Lesser General Public                    *
* License as published by the Free Software Foundation; either                  *
* version 2.1 of the License. The A C Norman extensions here must not have      *
* GPL 2.1 compatibility removed, but as a special concession may be used with   *
* GPL 3 code.                                                                   *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU             *
* Lesser General Public License for more details.                               *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public              *
* License along with this library; if not, write to the Free Software           *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.    *
*********************************************************************************
* $Id: FXReduceDialog.cpp,v 1.49 2006/03/01 02:13:21 fox Exp $                 *
********************************************************************************/
#include "xincs.h"
#include "fxver.h"
#include "fxdefs.h"
#include "fxkeys.h"
#include "FXHash.h"
#include "FXThread.h"
#include "FXStream.h"
#include "FXString.h"
#include "FXSize.h"
#include "FXPoint.h"
#include "FXRectangle.h"
#include "FXRegistry.h"
#include "FXAccelTable.h"
#include "FXApp.h"
#include "FXFont.h"
#include "FXImage.h"
#include "FXIcon.h"
#include "FXGIFIcon.h"
#include "FXWindow.h"
#include "FXFrame.h"
#include "FXArrowButton.h"
#include "FXSeparator.h"
#include "FXLabel.h"
#include "FXButton.h"
#include "FXCheckButton.h"
#include "FXRadioButton.h"
#include "FXPacker.h"
#include "FXScrollBar.h"
#include "FXTextField.h"
#include "FXVerticalFrame.h"
#include "FXHorizontalFrame.h"
#include "FXReduceDialog.h"



// Padding for buttons
#define HORZ_PAD      12
#define VERT_PAD      2

using namespace FX;

/*******************************************************************************/

namespace FX {


// Map
FXDEFMAP(FXReduceDialog) FXReduceDialogMap[]={
  FXMAPFUNC(SEL_COMMAND,FXReduceDialog::ID_ACCEPT,FXReduceDialog::onCmdAccept),
  };


// Object implementation
FXIMPLEMENT(FXReduceDialog,FXDialogBox,FXReduceDialogMap,ARRAYNUMBER(FXReduceDialogMap))


// Generic Reduce Dialog
FXReduceDialog::FXReduceDialog(FXWindow* owner,const FXString& caption,FXIcon* ic,FXuint opts,FXint x,FXint y,FXint w,FXint h):
  FXDialogBox(owner,caption,opts|DECOR_TITLE|DECOR_BORDER|DECOR_RESIZE,x,y,w,h,10,10,10,10, 10,10)
{
#if 0
  FXHorizontalFrame* buttons=new FXHorizontalFrame(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT,0,0,0,0,0,0,0,0);
  accept=new FXButton(buttons,tr("&Reduce"),NULL,this,ID_ACCEPT,BUTTON_INITIAL|BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|LAYOUT_FILL_Y|LAYOUT_RIGHT,0,0,0,0,HORZ_PAD,HORZ_PAD,VERT_PAD,VERT_PAD);
  cancel=new FXButton(buttons,tr("&Cancel"),NULL,this,ID_CANCEL,BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|LAYOUT_FILL_Y|LAYOUT_RIGHT,0,0,0,0,HORZ_PAD,HORZ_PAD,VERT_PAD,VERT_PAD);
  FXHorizontalFrame* pair=new FXHorizontalFrame(buttons,LAYOUT_FILL_Y|LAYOUT_RIGHT,0,0,0,0, 0,0,0,0);
  FXHorizontalFrame* toppart=new FXHorizontalFrame(this,LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|LAYOUT_CENTER_Y,0,0,0,0, 0,0,0,0, 10,10);
  new FXLabel(toppart,FXString::null,ic,ICON_BEFORE_TEXT|JUSTIFY_CENTER_X|JUSTIFY_CENTER_Y|LAYOUT_FILL_Y|LAYOUT_FILL_X);
  FXVerticalFrame* entry=new FXVerticalFrame(toppart,LAYOUT_FILL_X|LAYOUT_CENTER_Y,0,0,0,0, 0,0,0,0);
  searchlabel=new FXLabel(entry,tr("S&earch for:"),NULL,JUSTIFY_LEFT|ICON_BEFORE_TEXT|LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X);
  searchbox=new FXHorizontalFrame(entry,FRAME_SUNKEN|FRAME_THICK|LAYOUT_FILL_X|LAYOUT_CENTER_Y,0,0,0,0, 0,0,0,0, 0,0);
  searchtext=new FXTextField(searchbox,26,this,ID_SEARCH_TEXT,TEXTFIELD_ENTER_ONLY|LAYOUT_FILL_X|LAYOUT_FILL_Y,0,0,0,0, 4,4,4,4);
  FXVerticalFrame* searcharrows=new FXVerticalFrame(searchbox,LAYOUT_RIGHT|LAYOUT_FILL_Y,0,0,0,0, 0,0,0,0, 0,0);
  current=0;
#endif
 }


// Return text or pattern the user has entered
FXString FXReduceDialog::getReduceText() const {
//  return resulttext->getText();
    return FXString("Boo!;");
  }


// Return from the dialog
long FXReduceDialog::onCmdAccept(FXObject*,FXSelector,void*){
#if 0
  getApp()->stopModal(this,REPLACE);
#else
  getApp()->stopModal(this,0);
#endif
  hide();
  return 1;
  }



// Force the initial text to be selected
FXuint FXReduceDialog::execute(FXuint placement){
  create();
//  searchtext->setFocus();
  show(placement);
  return getApp()->runModalFor(this);
  }


// Cleanup
FXReduceDialog::~FXReduceDialog(){
#if 0
  searchlabel=(FXLabel*)-1L;
  searchtext=(FXTextField*)-1L;
  searchbox=(FXHorizontalFrame*)-1L;
  replacelabel=(FXLabel*)-1L;
  replacetext=(FXTextField*)-1L;
  replacebox=(FXHorizontalFrame*)-1L;
#endif
  accept=(FXButton*)-1L;
  cancel=(FXButton*)-1L;
  }

}

// end of FXReduceDialog.cpp
