/********************************************************************************
*                                                                               *
*                      R e d u c e   m e n u s   D i a l o g                    *
*                                                                               *
*********************************************************************************
* Copyright (C) 2000,2006 by Jeroen van der Zijp.   All Rights Reserved.        *
* [adapted from FXReplaceDialog.h by A C Norman, 2014-15]                       *
*********************************************************************************
* This library is free software; you can redistribute it and/or                 *
* modify it under the terms of the GNU Lesser General Public                    *
* License as published by the Free Software Foundation; under                   *
* version 2.1 of the License. Note that 2.1 compoatibility may not be removed,  *
* but as a special concession the code may be used in a GPL 3 context.          *
* This library is distributed in the hope that it will be useful,               *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU             *
* Lesser General Public License for more details.                               *
*                                                                               *
* You should have received a copy of the GNU Lesser General Public              *
* License along with this library; if not, write to the Free Software           *
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.    *
*********************************************************************************
* $Id$                    *
********************************************************************************/
#ifndef FXREDUCEDIALOG_H
#define FXREDUCEDIALOG_H

#ifndef FXDIALOGBOX_H
#include "FXDialogBox.h"
#endif

namespace FX {


class FXButton;
class FXLabel;
class FXTextField;
class FXHorizontalFrame;


/// Reduce helper dialog
class FXAPI FXReduceDialog : public FXDialogBox {
  FXDECLARE(FXReduceDialog)
protected:
  FXButton          *accept;
  FXButton          *cancel;
protected:
  FXReduceDialog(){}
private:
  FXReduceDialog(const FXReduceDialog&);
  FXReduceDialog &operator=(const FXReduceDialog&);
public:
  long onCmdAccept(FXObject*,FXSelector,void*);
  long onCmdReject(FXObject*,FXSelector,void*);
public:
  enum {
    DONE          = 0,    /// Cancel search
    };
public:

  /// Construct search and replace dialog box
  FXReduceDialog(FXWindow* owner,const FXString& caption,FXIcon* ic=NULL,FXuint opts=0,FXint x=0,FXint y=0,FXint w=0,FXint h=0);

  /// Return replace text the user has entered
  FXString getReduceText() const;

  /// Run modal invocation of the dialog
  virtual FXuint execute(FXuint placement=PLACEMENT_CURSOR);

  /// Destructor
  virtual ~FXReduceDialog();
  };

class FXAPI FXReduceInputDialog : public FXDialogBox {
  FXDECLARE(FXReduceInputDialog)
protected:
  FXTextField *input[7];    // Text field widgets
protected:
  FXReduceInputDialog(){}
private:
  FXReduceInputDialog(const FXReduceInputDialog&);
  FXReduceInputDialog &operator=(const FXReduceInputDialog&);
  void initialize(int num, const FXString labels[]);
public:
  long onCmdAccept(FXObject*,FXSelector,void*);
public:

  /// Construct input dialog box with given caption, icon, and prompt text
  FXReduceInputDialog(FXWindow* owner1,const FXString& caption,
    int num, const FXString labels[],
    FXint x=0,FXint y=0,FXint w=0,FXint h=0);

  /// Get input string
  FXString getText(int num) const;

  /// Set input string
  void setText(int num, const FXString& text);

  /// Run modal invocation of the dialog
  virtual FXuint execute(FXuint placement=PLACEMENT_CURSOR);

  };

}

#endif
