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
FXReduceDialog::FXReduceDialog(FXWindow* owner1,const FXString& caption,FXIcon* ic,FXuint opts,FXint x,FXint y,FXint w,FXint h):
  FXDialogBox(owner1,caption,opts|DECOR_TITLE|DECOR_BORDER|DECOR_RESIZE,x,y,w,h,10,10,10,10, 10,10)
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

//@@ class FXAPI FXReduceInputDialog : public FXDialogBox {
//@@   FXDECLARE(FXReduceInputDialog)
//@@ protected:
//@@   FXTextField *input[7];    // Text field widgets
//@@ protected:
//@@   FXReduceInputDialog(){}
//@@ private:
//@@   FXReduceInputDialog(const FXReduceInputDialog&);
//@@   FXReduceInputDialog &operator=(const FXReduceInputDialog&);
//@@   void initialize(int num, const FXString labels[]);
//@@ public:
//@@   long onCmdAccept(FXObject*,FXSelector,void*);
//@@ public:
//@@
//@@   /// Construct input dialog box with given caption, icon, and prompt text
//@@   FXReduceInputDialog(FXWindow* owner1,const FXString& caption,
//@@     int num, const FXString labels[];
//@@     FXint x=0,FXint y=0,FXint w=0,FXint h=0);
//@@
//@@   /// Get input string
//@@   FXString getText(int num) const;
//@@
//@@   /// Set input string
//@@   void setText(int num, const FXString& text);
//@@
//@@   /// Run modal invocation of the dialog
//@@   virtual FXuint execute(FXuint placement=PLACEMENT_CURSOR);
//@@
//@@ };

// Padding for buttons
#define HORZ_PAD 20
#define VERT_PAD 2

/*******************************************************************************/

// Map
FXDEFMAP(FXReduceInputDialog) FXReduceInputDialogMap[]={
  FXMAPFUNC(SEL_COMMAND,FXReduceInputDialog::ID_ACCEPT,FXReduceInputDialog::onCmdAccept),
  };


// Object implementation
FXIMPLEMENT(FXReduceInputDialog,FXDialogBox,FXReduceInputDialogMap,ARRAYNUMBER(FXReduceInputDialogMap))




// Create input dialog box
FXReduceInputDialog::FXReduceInputDialog(FXWindow* owner1,
    const FXString& caption,
    int num, const FXString labels[], FXint x,FXint y,FXint w,FXint h):
  FXDialogBox(owner1,caption,DECOR_TITLE|DECOR_BORDER,
              x,y,w,h,10,10,10,10, 10,10){
  initialize(num, labels);
  }


// Build contents
void FXReduceInputDialog::initialize(int num, const FXString labels[]){
  FXuint textopts=
    TEXTFIELD_ENTER_ONLY|FRAME_SUNKEN|FRAME_THICK|LAYOUT_FILL_X;
  FXHorizontalFrame* buttons=
    new FXHorizontalFrame(this,
      LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH,0,0,0,0,0,0,0,0);
  new FXButton(buttons,tr("&OK"),NULL,this,ID_ACCEPT,
    BUTTON_INITIAL|BUTTON_DEFAULT|FRAME_RAISED|
                   FRAME_THICK|LAYOUT_CENTER_Y|LAYOUT_RIGHT,
    0,0,0,0,HORZ_PAD,HORZ_PAD,VERT_PAD,VERT_PAD);
  new FXButton(buttons,tr("&Cancel"),NULL,this,ID_CANCEL,
    BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|LAYOUT_CENTER_Y|LAYOUT_RIGHT,
    0,0,0,0,HORZ_PAD,HORZ_PAD,VERT_PAD,VERT_PAD);
  new FXHorizontalSeparator(this,
    SEPARATOR_GROOVE|LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X);
  FXHorizontalFrame* toppart=
    new FXHorizontalFrame(this,
      LAYOUT_SIDE_TOP|LAYOUT_FILL_X|LAYOUT_CENTER_Y,0,0,0,0, 0,0,0,0, 10,10);
//:  new FXLabel(toppart,FXString::null,icon1,
//:    ICON_BEFORE_TEXT|JUSTIFY_CENTER_X|JUSTIFY_CENTER_Y|
//:                     LAYOUT_FILL_Y|LAYOUT_FILL_X);
  FXVerticalFrame* entry=
    new FXVerticalFrame(toppart,
      LAYOUT_FILL_X|LAYOUT_CENTER_Y,0,0,0,0, 0,0,0,0);
  int i;
  for (i=0; i<num; i++) {
    new FXLabel(entry,labels[i],NULL,
      JUSTIFY_LEFT|ICON_BEFORE_TEXT|LAYOUT_TOP|LAYOUT_LEFT|LAYOUT_FILL_X);
    input[i]=new FXTextField(entry,20,this,ID_ACCEPT,
                             textopts, 0,0,0,0, 8,8,4,4);
    }
  while (i < 7) input[i++] = NULL;
  }


// Get input string
FXString FXReduceInputDialog::getText(int num) const {
  if (input[num] == NULL) return "";
  else return input[num]->getText();
  }


// Set input string
void FXReduceInputDialog::setText(int num, const FXString& text){
  if (input[num] != NULL) input[num]->setText(text);
  }


// We have to do this so as to force the initial text to be seleced
FXuint FXReduceInputDialog::execute(FXuint placement){
  create();
  input[0]->setFocus();
  input[0]->selectAll();
  show(placement);
  return getApp()->runModalFor(this);
  }


// Close dialog with an accept.
long FXReduceInputDialog::onCmdAccept(FXObject* sender,FXSelector sel,void* ptr){
  FXDialogBox::onCmdAccept(sender,sel,ptr);
  return 1;
  }

}

/*******************************************************************************/

// end of FXReduceDialog.cpp

