/********************************************************************************
*                                                                               *
*                       F o u r - W a y   S p l i t t e r                       *
*                                                                               *
*********************************************************************************
* Copyright (C) 1999,2006 by Jeroen van der Zijp.   All Rights Reserved.        *
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
* $Id$                       *
********************************************************************************/
#ifndef FX4SPLITTER_H
#define FX4SPLITTER_H

#ifndef FXCOMPOSITE_H
#include "FXComposite.h"
#endif

namespace FX {

// Splitter options
enum {
  FOURSPLITTER_TRACKING = 0x00008000,	// Track continuously during split
  FOURSPLITTER_NORMAL   = 0
  };



/**
* The four-way splitter is a layout manager which manages
* four children like four panes in a window.
* You can use a four-way splitter for example in a CAD program
* where you may want to maintain three orthographic views, and
* one oblique view of a model.
* The four-way splitter allows interactive repartitioning of the
* panes by means of moving the central splitter bars.
* When the four-way splitter is itself resized, each child is
* proportionally resized, maintaining the same split-percentage.
* The four-way splitter widget sends a SEL_CHANGED to its target
* during the resizing of the panes; at the end of the resize interaction,
* it sends a SEL_COMMAND to signify that the resize operation is complete.
*/
class FXAPI FX4Splitter : public FXComposite {
  FXDECLARE(FX4Splitter)
private:
  FXint     splitx;         // Current x split
  FXint     splity;         // Current y split
  FXint     barsize;        // Size of the splitter bar
  FXint     fhor;           // Horizontal split fraction
  FXint     fver;           // Vertical split fraction
  FXint     offx;
  FXint     offy;
  FXuchar   mode;
protected:
  FX4Splitter();
  FXuchar getMode(FXint x,FXint y);
  void moveSplit(FXint x,FXint y);
  void drawSplit(FXint x,FXint y,FXuint m);
  void adjustLayout();
private:
  FX4Splitter(const FX4Splitter&);
  FX4Splitter &operator=(const FX4Splitter&);
public:
  long onLeftBtnPress(FXObject*,FXSelector,void*);
  long onLeftBtnRelease(FXObject*,FXSelector,void*);
  long onMotion(FXObject*,FXSelector,void*);
  long onFocusUp(FXObject*,FXSelector,void*);
  long onFocusDown(FXObject*,FXSelector,void*);
  long onFocusLeft(FXObject*,FXSelector,void*);
  long onFocusRight(FXObject*,FXSelector,void*);
  long onCmdExpand(FXObject*,FXSelector,void*);
  long onUpdExpand(FXObject*,FXSelector,void*);
public:
  enum {
    ExpandNone        = 0,                                  /// None expanded
    ExpandTopLeft     = 1,                                  /// Expand top left child
    ExpandTopRight    = 2,                                  /// Expand top right child
    ExpandBottomLeft  = 4,                                  /// Expand bottom left child
    ExpandBottomRight = 8,                                  /// Expand bottom right child
    ExpandTop         = ExpandTopLeft|ExpandTopRight,       /// Expand top children
    ExpandBottom      = ExpandBottomLeft|ExpandBottomRight, /// Expand bottom children
    ExpandLeft        = ExpandTopLeft|ExpandBottomLeft,     /// Expand left children
    ExpandRight       = ExpandTopRight|ExpandBottomRight,   /// Expand right children
    ExpandAll         = ExpandLeft|ExpandRight              /// Expand all children
    };
public:
  enum {
    ID_EXPAND_NONE=(FXuint)FXComposite::ID_LAST+(FXuint)ExpandNone,
    ID_EXPAND_TOP=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandTop,
    ID_EXPAND_BOTTOM=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandBottom,
    ID_EXPAND_LEFT=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandLeft,
    ID_EXPAND_RIGHT=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandRight,
    ID_EXPAND_TOPLEFT=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandTopLeft,
    ID_EXPAND_TOPRIGHT=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandTopRight,
    ID_EXPAND_BOTTOMLEFT=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandBottomLeft,
    ID_EXPAND_BOTTOMRIGHT=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandBottomRight,
    ID_EXPAND_ALL=(FXuint)ID_EXPAND_NONE+(FXuint)ExpandAll,
    ID_LAST
    };
public:

  /// Create 4-way splitter, initially shown as four unexpanded panes
  FX4Splitter(FXComposite* p,FXuint opts=FOURSPLITTER_NORMAL,FXint x=0,FXint y=0,FXint w=0,FXint h=0);

  /// Create 4-way splitter, initially shown as four unexpanded panes; notifies target about size changes
  FX4Splitter(FXComposite* p,FXObject* tgt,FXSelector sel,FXuint opts=FOURSPLITTER_NORMAL,FXint x=0,FXint y=0,FXint w=0,FXint h=0);

  /// Get top left child, if any
  FXWindow *getTopLeft() const;

  /// Get top right child, if any
  FXWindow *getTopRight() const;

  /// Get bottom left child, if any
  FXWindow *getBottomLeft() const;

  /// Get bottom right child, if any
  FXWindow *getBottomRight() const;

  /// Get horizontal split fraction
  FXint getHSplit() const { return fhor; }

  /// Get vertical split fraction
  FXint getVSplit() const { return fver; }

  /// Change horizontal split fraction
  void setHSplit(FXint s);

  /// Change vertical split fraction
  void setVSplit(FXint s);

  /// Perform layout
  virtual void layout();

  /// Get default width
  virtual FXint getDefaultWidth();

  /// Get default height
  virtual FXint getDefaultHeight();

  /// Return current splitter style
  FXuint getSplitterStyle() const;

  /// Change splitter style
  void setSplitterStyle(FXuint style);

  /// Change splitter bar width
  void setBarSize(FXint bs);

  /// Get splitter bar width
  FXint getBarSize() const { return barsize; }

  /// Change set of expanded children
  void setExpanded(FXuint set=FX4Splitter::ExpandAll);

  /// Get set of expanded children
  FXuint getExpanded() const;

  /// Save to stream
  virtual void save(FXStream& store) const;

  /// Load from stream
  virtual void load(FXStream& store);
  };

}

#endif
