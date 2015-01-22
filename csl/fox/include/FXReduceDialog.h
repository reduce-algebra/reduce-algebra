/********************************************************************************
*                                                                               *
*                      R e d u c e   m e n u s   D i a l o g                    *
*                                                                               *
*********************************************************************************
* Copyright (C) 2000,2006 by Jeroen van der Zijp.   All Rights Reserved.        *
* [adapted from FXReplaceDealog.h by A C Norman, 2014]                          *
*********************************************************************************
* This library is free software; you can redistribute it and/or                 *
* modify it under the terms of the GNU Lesser General Public                    *
* License as published by the Free Software Foundation; either                  *
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
* $Id: FXReduceDialog.h,v 1.22 2006/01/22 17:58:08 fox Exp $                   *
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

}

#endif
