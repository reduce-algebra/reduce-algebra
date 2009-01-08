// Sample code to demonstrate use of the Native Printer Code
//
// This pops up an MDI window, but the important part is not at all
// anything displayed - it is that there is a FILE/PRINT menu item
// and when activated it prints a sample page with lines and text.
//

// This code came with FXDCNativePrinter.cpp. There have been
// slight adjustments to allow it to run with either FOX 1.0 or FOX 1.1

// As originally supplied this files did not contain any copyright or
// author information. Its author (Manuel <address@te...> expained
// in an e-mail:
//
//"c) Including it in FOX: I havent put any copyright notice on the code so it
//  could be used for any purpose. If Jeroen wants to incorporate it or a
//  derivative work, it is fine with me."
//
// and on that basis it seems reasonable to re-circulate this slightly
// updated version as usable subject to anything Manuel wants to say but
// at least in line with the license terms of the main FOX toolkit.
 


/* Signature: 3cb080b2 01-May-2008 */


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>

#include <fx.h>

#include "FXDCNativePrinter.h"

FXPrinter printer;

#define CLOCKTIMER 500

const unsigned char penguin[]={
0x47,0x49,0x46,0x38,0x37,0x61,0x10,0x00,0x12,0x00,0xf2,0x00,0x00,0xb2,0xc0,0xdc,
0x80,0x80,0x80,0x00,0x00,0x00,0xc0,0xc0,0xc0,0x10,0x10,0x10,0xff,0xff,0xff,0xe0,
0xa0,0x08,0x00,0x00,0x00,0x2c,0x00,0x00,0x00,0x00,0x10,0x00,0x12,0x00,0x00,0x03,
0x53,0x08,0xba,0x21,0x12,0x2b,0xc6,0xe6,0x9e,0x94,0x62,0x64,0x77,0xa3,0x20,0x4e,
0x21,0x74,0x8b,0x60,0x9c,0x1a,0xa9,0x98,0xa8,0x45,0xb2,0x85,0x38,0x76,0x4f,0x6c,
0xbb,0x93,0x60,0xdb,0x0d,0xe4,0xd9,0x83,0x1d,0xe7,0x57,0x18,0x04,0x6f,0xb8,0x4c,
0xec,0x88,0x9c,0x01,0x0c,0x47,0x66,0xac,0xa2,0x38,0x19,0x76,0x36,0x83,0xc3,0xf0,
0xb4,0x5e,0x77,0x03,0xaf,0xf8,0x7b,0x13,0x77,0xad,0xd3,0xad,0x75,0x61,0xa5,0x54,
0x02,0x27,0x45,0x02,0x00,0x3b
};



//////////////////////////////////////////////////////////////////////////////////////////////

// Mini application object
class FXAPI MainWindow : public FXMainWindow {
  FXDECLARE(MainWindow)
    
protected:
  FXMenuBar         *menubar;
  FXMDIClient       *mdiclient;               // MDI Client area
  FXMDIMenu         *mdimenu;                 // MDI Window Menu
  FXGIFIcon         *mdiicon;                 // MDI Icon
  FXMenuPane        *filemenu;
  FXMenuPane        *windowmenu;
  FXMenuPane        *editmenu;
  FXMenuPane        *popupmenu;               // Context menu

  FXToolBarShell    *dragshell1,*dragshell2;
  FXToolBar         *toolbar;
  FXStatusBar       *statusbar;

  FXMenuPane        *helpmenu;
  FXFont            *font;

protected:
  MainWindow(){}
  
public:
  
  // We define ID's, starting from the last one used by the base class+1.
  // This way, we know the ID's are all unique for this particular target.
  enum {
    ID_ABOUT=FXMainWindow::ID_LAST,
    ID_NEW,
    ID_SAVE,
    ID_OPEN,
    ID_CLOSE,
    ID_QUIT,
    ID_PRINTSETUP,
    ID_PRINT,
    ID_LAST
    };
    
  // message handlers
  long onCmdAbout(FXObject*,FXSelector,void*);
  long onCmdNew(FXObject*,FXSelector,void*);
  long onCmdSave(FXObject*,FXSelector,void*);
  long onCmdOpen(FXObject*,FXSelector,void*);
  long onCmdClose(FXObject*,FXSelector,void*);
  long onCmdQuit(FXObject*,FXSelector,void*);
  long onCmdPrintSetup(FXObject*,FXSelector,void*);          
  long onCmdPrint(FXObject*,FXSelector,void*);  
public:
  MainWindow(FXApp* a);
  virtual void create();
  virtual ~MainWindow();
  };
  

// Map
FXDEFMAP(MainWindow) MainWindowMap[]={
  //________Message_Type____________ID___________________Message_Handler________
  FXMAPFUNC(SEL_COMMAND,  MainWindow::ID_ABOUT,     MainWindow::onCmdAbout),
  FXMAPFUNC(SEL_COMMAND,  MainWindow::ID_NEW,       MainWindow::onCmdNew),
  FXMAPFUNC(SEL_COMMAND,  MainWindow::ID_SAVE,      MainWindow::onCmdSave),
  FXMAPFUNC(SEL_COMMAND,  MainWindow::ID_OPEN,      MainWindow::onCmdOpen),
  FXMAPFUNC(SEL_COMMAND,  MainWindow::ID_PRINTSETUP,MainWindow::onCmdPrintSetup),
  FXMAPFUNC(SEL_COMMAND,  MainWindow::ID_PRINT,     MainWindow::onCmdPrint),    
  FXMAPFUNC(SEL_SIGNAL,   MainWindow::ID_QUIT,      MainWindow::onCmdQuit),
  FXMAPFUNC(SEL_CLOSE,    0,                        MainWindow::onCmdQuit),
  FXMAPFUNC(SEL_COMMAND,  MainWindow::ID_QUIT,      MainWindow::onCmdQuit),
  };


// Object implementation
FXIMPLEMENT(MainWindow,FXMainWindow,MainWindowMap,ARRAYNUMBER(MainWindowMap))


/*******************************************************************************/

// Start the whole thing
int main(int argc,char *argv[]){

  // Make application
  FXApp application("MDI skeleton","MDI skeleton");

  // Open display
  application.init(argc,argv);

  // Make window
  MainWindow *w=new MainWindow(&application);

  // Create app
  application.create();
  w->setFocus();
  
  // Run
  return application.run();
  }


// Make some windows
MainWindow::MainWindow(FXApp* a):
    FXMainWindow(a,"MDI Widget Test",NULL,NULL,DECOR_ALL,0,0,800,600){
  FXMDIChild *mdichild;
  FXScrollWindow *scrollwindow;
  FXButton *btn;
    
  // Initialize printer selection with default values
  {
  FXPrintDialog dlg(this,"");
    // Do NOT show dialog. Just get its default printer 
    dlg.getPrinter( printer );   
  }

  // Make menu bar
  FXToolBarShell* dragshell1=new FXToolBarShell(this,FRAME_RAISED|FRAME_THICK);
  menubar=new FXMenuBar(this,dragshell1,LAYOUT_SIDE_TOP|LAYOUT_FILL_X);
  new FXToolBarGrip(menubar,menubar,FXMenuBar::ID_TOOLBARGRIP,
                    TOOLBARGRIP_DOUBLE);

  // Tool bar
  FXToolBarShell* dragshell2=new FXToolBarShell(this,FRAME_RAISED|FRAME_THICK);
  toolbar=new FXToolBar(this,dragshell2,
      LAYOUT_SIDE_TOP|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH|PACK_UNIFORM_HEIGHT);
  new FXToolBarGrip(toolbar,toolbar,
                    FXToolBar::ID_TOOLBARGRIP,TOOLBARGRIP_DOUBLE);


  // Status bar
  statusbar=new FXStatusBar(this,
      LAYOUT_SIDE_BOTTOM|LAYOUT_FILL_X|STATUSBAR_WITH_DRAGCORNER);

  // MDI Client
  mdiclient=new FXMDIClient(this,LAYOUT_FILL_X|LAYOUT_FILL_Y);
    
  // Icon for MDI Child
  mdiicon=new FXGIFIcon(getApp(),penguin);
  

  // Make MDI Menu
  mdimenu=new FXMDIMenu(this,mdiclient);
  
  // MDI buttons in menu:- note the message ID's!!!!!
  // Normally, MDI commands are simply sensitized or desensitized;
  // Under the menubar, however, they're hidden if the MDI Client is
  // not maximized.  To do this, they must have different ID's.
  new FXMDIWindowButton(menubar,NULL,mdiclient,
         FXMDIClient::ID_MDI_MENUWINDOW,LAYOUT_LEFT);
  new FXMDIDeleteButton(menubar,mdiclient,
         FXMDIClient::ID_MDI_MENUCLOSE,FRAME_RAISED|LAYOUT_RIGHT);
  new FXMDIRestoreButton(menubar,mdiclient,
         FXMDIClient::ID_MDI_MENURESTORE,FRAME_RAISED|LAYOUT_RIGHT);
  new FXMDIMinimizeButton(menubar,mdiclient,
         FXMDIClient::ID_MDI_MENUMINIMIZE,FRAME_RAISED|LAYOUT_RIGHT);
 
  // File menu
  filemenu=new FXMenuPane(this);
  new FXMenuCommand(filemenu,"&New\tCtl-N\tNew document",NULL,this,ID_NEW);
  new FXMenuCommand(filemenu,"&Open\tCtl-O\tOpen document",NULL,this,ID_OPEN);
  new FXMenuCommand(filemenu,"&Close\t\tClose document",NULL,
                    mdiclient,FXMDIClient::ID_MDI_CLOSE);
  new FXMenuSeparator(filemenu);
  new FXMenuCommand(filemenu,"&Print setup\t\tSelect printer and paper",NULL,
                    this,ID_PRINTSETUP); 
  new FXMenuCommand(filemenu,"&Print\t\tPrint document",NULL,this,ID_PRINT); 
  new FXMenuSeparator(filemenu);

  new FXMenuCommand(filemenu,"&Exit\tAlt-F4\tGo pickup some girls",NULL,
                    this,ID_QUIT,0);
  new FXMenuTitle(menubar,"&Files",NULL,filemenu);
  
  // Window menu
  windowmenu=new FXMenuPane(this);
  new FXMenuCommand(windowmenu,"Tile &Horizontally",NULL,
      mdiclient,FXMDIClient::ID_MDI_TILEHORIZONTAL);
  new FXMenuCommand(windowmenu,"Tile &Vertically",NULL,
      mdiclient,FXMDIClient::ID_MDI_TILEVERTICAL);
  new FXMenuCommand(windowmenu,"C&ascade",NULL,
      mdiclient,FXMDIClient::ID_MDI_CASCADE);
  new FXMenuCommand(windowmenu,"&Close",NULL,
      mdiclient,FXMDIClient::ID_MDI_CLOSE);
//
// The next lines were in the sample app but I can not find
// ID_CLOSE_ALL_DOCUMENTS anywhere in the FOX header files...
//

//new FXMenuCommand(windowmenu,"Clo&se All",NULL,
//    mdiclient,FXMDIClient::ID_CLOSE_ALL_DOCUMENTS);
  FXMenuSeparator* sep1=new FXMenuSeparator(windowmenu);
  sep1->setTarget(mdiclient);
  sep1->setSelector(FXMDIClient::ID_MDI_ANY);
  new FXMenuCommand(windowmenu,NULL,NULL,mdiclient,FXMDIClient::ID_MDI_1);
  new FXMenuCommand(windowmenu,NULL,NULL,mdiclient,FXMDIClient::ID_MDI_2);
  new FXMenuCommand(windowmenu,NULL,NULL,mdiclient,FXMDIClient::ID_MDI_3);
  new FXMenuCommand(windowmenu,NULL,NULL,mdiclient,FXMDIClient::ID_MDI_4);
  new FXMenuTitle(menubar,"&Windows",NULL,windowmenu);
  
  // Help menu
  helpmenu=new FXMenuPane(this);
  new FXMenuCommand(helpmenu,"&About...",NULL,this,ID_ABOUT,0);
  new FXMenuTitle(menubar,"&Help",NULL,helpmenu,LAYOUT_RIGHT);
  getApp()->addSignal(SIGINT,mdiclient,MainWindow::ID_QUIT);
  
  
  // Font 
#if (FOX_MINOR<=4)
  font = new FXFont(getApp(), "", 10,  FONTWEIGHT_NORMAL, FONTSLANT_REGULAR,
      FONTENCODING_DEFAULT, FONTSETWIDTH_DONTCARE, FONTPITCH_FIXED);
#else
  font = new FXFont(getApp(), "", 10,  FXFont::Normal, FXFont::Straight,
      FONTENCODING_DEFAULT, 0, FXFont::Fixed);
#endif

  // Right-click popup menu
  popupmenu=new FXMenuPane(this);
  new FXMenuCommand(popupmenu,"Test",NULL,this,ID_QUIT);
  
  //Fill toolbar
   new FXButton(toolbar,"Open\t\tOpen new document",mdiicon,
      this,ID_NEW,
      ICON_ABOVE_TEXT|BUTTON_TOOLBAR|FRAME_RAISED|LAYOUT_TOP|LAYOUT_LEFT);
  }


// Clean up  
MainWindow::~MainWindow(){
  delete helpmenu;
  delete windowmenu;
  delete filemenu;
  delete font;
  delete popupmenu;
  }

// Start
void MainWindow::create(){
  FXMainWindow::create();
  show(PLACEMENT_SCREEN);
  }

  
// About
long MainWindow::onCmdAbout(FXObject*,FXSelector,void*){
  FXMessageBox::information(this,MBOX_OK,"About", "Sample App");
  return 1;
  }

long MainWindow::onCmdNew(FXObject*,FXSelector,void*)
{
  return 1;
}
  
long MainWindow::onCmdSave(FXObject*,FXSelector,void*)
{
  return 1;
}

long MainWindow::onCmdOpen(FXObject*,FXSelector,void*)
{
  return 1;
}

long MainWindow::onCmdClose(FXObject*,FXSelector,void*)
{
  return 1;
}

long MainWindow::onCmdQuit(FXObject*o,FXSelector sel,void*ptr)
{
  mdiclient->forallWindows(this,MKUINT(0,SEL_CLOSE),0);
  if  ( ((sel>>16)&0xFFFF)==SEL_CLOSE  ) 
  {
    FXTopWindow::handle(o,sel,ptr); 
  }
  getApp()->handle(this, MKUINT(FXApp::ID_QUIT,SEL_COMMAND),ptr);

  return 1;
}

long MainWindow::onCmdPrintSetup(FXObject*,FXSelector,void*)
{
    FXPrintDialog dlg(this,"");
    dlg.setPrinter( printer );  // Use last printer selection
    dlg.execute();
    dlg.getPrinter( printer );   

    return 1;
}

long MainWindow::onCmdPrint(FXObject*,FXSelector,void*)
{
FXDCNativePrinter prt(getApp());
FXFont *font10, *font16;
FXint w,h;
char string[]="Hello world!";

    prt.beginPrint(printer);
    font10 = prt.fntGenerateFont("helvetica", 10);
    font10->create();
    font16 = prt.fntGenerateFont("helvetica", 16);
    font16->create();
    prt.beginPage(1);
    
    /* I want to use tenths of millimeter (2.54 cm per inch) */
    prt.setHorzUnitsInch( 254 );
    prt.setVertUnitsInch( 254 );
    
    prt.setForeground( FXRGB(0,0,0) );
    
    /* WARNING: The concept of border is subject to change. Right now, it is
    ** not clear if the border is the physical paper border, or the printable
    ** area.
    ** The later is printer-dependant .
    ** Paper size (width x height) is the physical paper size
    */
    
    
    
    /* Draw a frame around the page, 2 cm from each border of the paper.
    ** This only takes into account your selected paper size, regardles of
    **  the actual physical size of the paper you feed to the printer.
    */
    prt.drawRectangle(200,200,prt.getPageWidth()-400,prt.getPageHeight()-400);
    
    /* Draw a frame exactly at page boundaries */
    prt.drawRectangle( 0,0, prt.getPageWidth()-1, prt.getPageHeight()-1 );
    
    /* draw a 10cm horizontal line 3cm from the top-left border */ 
    prt.drawLine(300,300, 1300,300 );
    /* Put some text over the line */
    prt.setTextFont( font10 );
    prt.drawText(300,300, string, strlen(string) );
    
    /* draw another line 2cm below the other */
    prt.drawLine(300,500, 1300,500 );
    /* Put some text over the line */
    prt.setTextFont( font16 );
    prt.drawText(300,500, string, strlen(string) );  

    /* Draw some aligned text */
    prt.drawLine(1000, 150, 1000, 1700 );
    w=prt.fntGetTextWidth( string, strlen(string) );
    prt.drawText( 1000, 1200, string, strlen(string) );  /* Right */
    prt.drawText( 1000-w, 1300, string, strlen(string) );  /* Left */    
    prt.drawText( 1000-(w/2), 1400, string, strlen(string) );  /* Centre */
    
    /* Now, I want to draw using 100th of inch as drawing unit */
    prt.setHorzUnitsInch( 100 );
    prt.setVertUnitsInch( 100 );
    
    /* Draw a box with sides 1 inch long */
    prt.setForeground( FXRGB(255,0,0) ); /* Red box */
    prt.drawRectangle( 300, 300, 100, 100 );  /* 3 inches from the margin */
    
    prt.endPage();
    prt.endPrint();
    return 1;
}

// end of printing sample code.

