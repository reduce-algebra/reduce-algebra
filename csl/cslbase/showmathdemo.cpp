/*
 * showmathdemo.cpp                          Copyright (C) Codemist Ltd 2008
 *
 * Demonstrate display of mathematical formulae...
 */

/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/


/* Signature: 025f6bb0 31-May-2008 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#define HAVE_LIBFOX 1
#endif

#ifndef HAVE_LIBFOX

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("FOX library not detected and so this demo is unavailable\n");
    return 0;
}

#else

#include "fx.h"	
#include "fwin.h"

#include "FXShowMath.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>

#ifndef WIN32
#ifdef HAVE_LIBXFT
#include <X11/Xft/Xft.h>
#else
#error The code needs Xft on non-Windows platforms
#endif
#endif

namespace FX {

extern "C" {

extern int main(int argc,char *argv[]);

#ifdef HAVE_LIBXFT

extern Display      *dpy;
extern int          screen;
extern XftDraw      *ftDraw;
extern Visual       *ftVisual;
extern Colormap     ftColormap;
extern XftColor     ftBlack;
extern FcConfig     *config;
extern XftFont      *ftFont;

#endif
}


// At least for testing purposes I will extract the LaTeX-like stuff
// from a string...

static const char *TeXInput;

static int nextChar()
{
    return *TeXInput++;
}


///////////////////////////////////////////////////////////////////////////

// Now a small framework that displays a window and paints a box structure
// in it.

class MathWindow : public FXMainWindow
{

    FXDECLARE(MathWindow)

private:
    FXApp *app;

protected:
    MathWindow() {}
    ~MathWindow();

public:
    FXCanvas *canvas;
    long onPaint(FXObject *, FXSelector, void *);
    MathWindow(FXApp* a);
    virtual void create();
    enum
    {   ID_CANVAS = FXMainWindow::ID_LAST,
        ID_LAST
    };
};



FXDEFMAP(MathWindow) MathWindowMap[] =
{
    FXMAPFUNC(SEL_PAINT, MathWindow::ID_CANVAS, MathWindow::onPaint),
};

FXIMPLEMENT(MathWindow,FXMainWindow,MathWindowMap,ARRAYNUMBER(MathWindowMap))


MathWindow::MathWindow(FXApp *a)
          :FXMainWindow(a,"Font Application",NULL,NULL,DECOR_ALL,0,0,550,600)
{
    canvas=new FXCanvas(this,this,ID_CANVAS,
        FRAME_SUNKEN|FRAME_THICK|LAYOUT_FILL_X|LAYOUT_FILL_Y|
        LAYOUT_FILL_ROW|LAYOUT_FILL_COLUMN);
    app = a;
}

MathWindow::~MathWindow()
{
    closeShowMath(app);
}

void MathWindow::create()
{
    FXMainWindow::create();
    show(PLACEMENT_SCREEN);
}

static Box *topBox = NULL;

static int fontFace = 2;

long MathWindow::onPaint(FXObject *, FXSelector, void *ptr)
{
    FXEvent *ev = (FXEvent*)ptr;
    FXDCWindow dc(canvas, ev);
    dc.setForeground(canvas->getBackColor());
    dc.fillRectangle(ev->rect.x, ev->rect.y, ev->rect.w, ev->rect.h);
    dc.setForeground(FXRGB(80, 20, 0));

#ifndef WIN32
    ftFont = (XftFont *)mathFont[fontFace];
#endif
        dc.setFont((FXFont *)mathFont[fontFace]);
    int i, j;
    for (i=0; i<256; i+=16)
    {   for (j=0; j<16; j++)
        {
#ifdef WIN32
            char bb[4];
            bb[0] = i+j;
            dc.drawText(32*j+25, (71*i)/50+220, bb, 1);
#else
            FT_UInt bbb[1];
            bbb[0] = i+j+1;
            XftDrawGlyphs(ftDraw, &ftBlack, ftFont,
                          32*j+25, (71*i)/50+220, bbb, 1);
#endif
        }
    }
    paintBox(&dc, topBox,
             (550 - topBox->text.width)/2,
             topBox->text.height + 10);
    return 1;
}


///////////////////////////////////////////////////////////////////////////


// The main program just sets things up and runs the demo.

// Some test data.

static const char *testData[] =
{
"\\begin{center}$\\displaystyle x$\\end{center}",

"\\begin{center}$\\displaystyle x_2$\\end{center}",

"\\begin{center}$\\displaystyle x+\\mathrm{100}$\\end{center}",

"\\begin{center}$\\displaystyle x^4-\\mathrm{12}\\*x^3+\\mathrm{54}\\*x^2"
"-\\mathrm{108}\\*x+\\mathrm{81}$\\end{center}",

"\\begin{center}$\\displaystyle x^{\\mathrm{30}}+\\mathrm{30}\\*x^{"
"\\mathrm{29}}+\\mathrm{435}\\*x^{\\mathrm{28}}+\\mathrm{4060}\\*x^{\\mathrm{27}}+"
"\\mathrm{27405}\\*x^{\\mathrm{26}}+\\mathrm{142506}\\*x^{\\mathrm{25}}+\\mathrm{593775}"
"\\*x^{\\mathrm{24}}+\\mathrm{2035800}\\*x^{\\mathrm{23}}+\\mathrm{5852925}\\*x^{"
"\\mathrm{22}}+$\\end{center}",

"\\begin{center}$\\displaystyle \\mathrm{14307150}\\*x^{\\mathrm{21}}+"
"\\mathrm{30045015}\\*x^{\\mathrm{20}}+\\mathrm{54627300}\\*x^{\\mathrm{19}}+\\mathrm{86"
"493225}\\*x^{\\mathrm{18}}+\\mathrm{119759850}\\*x^{\\mathrm{17}}+\\mathrm{145422675}"
"\\*x^{\\mathrm{16}}+$\\end{center}",

"\\begin{center}$\\displaystyle \\sin\\left(y\\right)$\\end{center}",

"\\begin{center}$\\displaystyle \\sqrt{-x+1}$\\end{center}",

"\\begin{center}$\\displaystyle \\left(\\frac{x+1}{x-1}\\right)$\\end{center}",

"\\begin{center}$\\displaystyle \\pi$\\end{center}",

"\\begin{center}$\\displaystyle e^z$\\end{center}",

"\\begin{center}$\\displaystyle e^{i\\*\\theta}$\\end{center}",

"\\begin{center}$\\displaystyle \\left(\\begin{matrix} \\sin \\left(1\\right) & x_2+\\Theta^2 \\\\"
"\\frac{\\exists x : x < 2}{3-z_2} & \\gamma"
"\\end{matrix}\\right\\}$\\end{center}",

"\\begin{center}$\\displaystyle \\int 2^{e^{e^x}}\\,d\\,x$\\end{center}",

"\\begin{center}$\\displaystyle b!$\\end{center}",

NULL
};


int main(int argc,char *argv[])
{
    int example = 0;
    int fontSize = 160;
    fontFace = 2;

    FXApp application("ShowMath", "Test");
    application.init(argc, argv);

    find_program_directory(argv[0]);

    int whichArg = 0;
    argv++;

    while (argc-- > 1)
    {   const char *a = *argv++;
        unsigned int n = atoi(a);
        switch (whichArg++)
        {
    case 0:
            if (n >= 0 && n < sizeof(testData)/sizeof(testData[0]))
            example = n;
            break;
    case 1:
            if (n < 0) n = -n;
            if (n == 0) n = 280;
            while (n < 50) n = n*10;
            while (n >= 500) n = n/10;
            fontSize = n;
            break;
    case 2:
            if (n >= 0 && n<12) fontFace = n;
            else fontFace = 2;
            break;
    default:
            break;
        }
    }

    int mainSize = fontSize;
    MathWindow *w = new MathWindow(&application);

    application.create();

    setupShowMath(&application, mainSize, w->canvas);

    TeXInput = testData[example];

    topBox = parseTeX(nextChar, 0);

    if (topBox == NULL)
    {   printf("Failed to parse this example\n");
        exit(1);
    }

    measureBox(topBox);

    return application.run();
}


}

#endif /* HAVE_LIBFOX */

// end of showmathdemo.cpp
