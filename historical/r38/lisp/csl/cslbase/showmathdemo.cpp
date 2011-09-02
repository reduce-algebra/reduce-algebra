/*
 * Demonstrate display of mathematical formulae...
 * If FOX is not installed then this code will not build at all. Furthermore
 * you MUST have the Computer Moden fonts that I use here installed, and
 * on some X systems you may need special versions of them that I have
 * produced!
 */


/* Signature: 131f206d 18-Mar-2008 */


#include "config.h"

#ifndef HAVE_LIBFOX

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("FOX library not detected and so this demo is unavailable\n");
    return 0;
}

#else

#include"fx.h"	

#include "FXShowMath.h"

#include <ctype.h>
#include <string.h>
#include <stdio.h>

#ifdef HAVE_XFT
#include <X11/Xft/Xft.h>

extern Display      *dpy;
extern int          screen;
extern XftDraw      *ftDraw;
extern Visual       *ftVisual;
extern Colormap     ftColormap;
extern XftColor     ftBlack;
extern FcConfig     *config;
extern XftFont      *ftFont;

#endif


#define MINIMAL_SUPPORT 1

#include "fwin.c"

FXCanvas *text;
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

class FontWindow : public FXMainWindow
{

    FXDECLARE(FontWindow)

private:
    FXApp *app;
    FXCanvas *canvas;

protected:
    FontWindow() {}
    ~FontWindow();

public:
    long onPaint(FXObject *, FXSelector, void *);
    FontWindow(FXApp* a);
    virtual void create();
    enum
    {   ID_CANVAS = FXMainWindow::ID_LAST,
        ID_LAST
    };
};



FXDEFMAP(FontWindow) FontWindowMap[] =
{
    FXMAPFUNC(SEL_PAINT, FontWindow::ID_CANVAS, FontWindow::onPaint),
};

FXIMPLEMENT(FontWindow,FXMainWindow,FontWindowMap,ARRAYNUMBER(FontWindowMap))


FontWindow::FontWindow(FXApp *a)
          :FXMainWindow(a,"Font Application",NULL,NULL,DECOR_ALL,0,0,550,600)
{
    canvas=new FXCanvas(this,this,ID_CANVAS,
        FRAME_SUNKEN|FRAME_THICK|LAYOUT_FILL_X|LAYOUT_FILL_Y|
        LAYOUT_FILL_ROW|LAYOUT_FILL_COLUMN);
    text = canvas;
    app = a;
}

FontWindow::~FontWindow()
{
    closeShowMath(app);
}

void FontWindow::create()
{
    FXMainWindow::create();
    show(PLACEMENT_SCREEN);
}

static Box *topBox = NULL;

static int fontFace = 2;

long FontWindow::onPaint(FXObject *, FXSelector, void *ptr)
{
    FXEvent *ev = (FXEvent*)ptr;
    FXDCWindow dc(canvas, ev);
    dc.setForeground(canvas->getBackColor());
    dc.fillRectangle(ev->rect.x, ev->rect.y, ev->rect.w, ev->rect.h);
    dc.setForeground(FXRGB(80, 20, 0));

#ifdef HAVE_XFT
    if (fwin_use_xft) ftFont = (XftFont *)mathFont[fontFace];
    else
#endif
        dc.setFont((FXFont *)mathFont[fontFace]);
    int i, j;
    for (i=0; i<256; i+=16)
    {   char bb[4];
        for (j=0; j<16; j++)
        {   bb[0] = i+j;
#ifdef HAVE_XFT
            FT_UInt bbb[1];
            bbb[0] = i+j+1;
            if (fwin_use_xft)
            {   if ((i+j) <= 0x7f)
                    XftDrawGlyphs(ftDraw, &ftBlack, ftFont,
                       32*j+25, (71*i)/50+220, bbb, 1);
            }
            else 
#endif
                dc.drawText(32*j+25, (71*i)/50+220, bb, 1);
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

    FXApp application("Font", "FoxTest");
    application.init(argc, argv);

    find_program_directory(argv[0]);

    int whichArg = 0;
    argv++;

    while (argc-- > 1)
    {   const char *a = *argv++;
        if (*a == '-') fwin_use_xft = 0;
        else
        {   unsigned int n = atoi(a);
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
    }

    int mainSize = fontSize;
    new FontWindow(&application);

    application.create();

    setupShowMath(&application, mainSize);

    TeXInput = testData[example];

    topBox = parseTeX(nextChar, 0);

    if (topBox == NULL)
    {   printf("Failed to parse this example\n");
        exit(1);
    }

    measureBox(topBox);

    return application.run();
}


void reportDestroy(int n)
{   // callback from math display code. Not activated by this demo.
}

#endif /* HAVE_LIBFOX */

// end of showmathdemo.cpp
