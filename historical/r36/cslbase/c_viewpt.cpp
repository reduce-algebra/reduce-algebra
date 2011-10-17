// c_viewpt.cpp
//     A dialog box to allow adjustment of the viewpoint for
//     graphics objects. Implemented as a regular window rather
//     than as a special dialog box since I want almost all of my
//     "controls" to be custom-drawn, and the usual dialog box stuff
//     does not seem to help very much.
//
//     Copyright (C)/©/¸ Codemist Ltd, 1995-96

/* Signature: 61b86258 08-Jan-1996 */


#ifdef GRAPHICS_WINDOW

#include "cwin.hpp"

// What follows is my default transformation matrix. It is pretty
// arbitrarily chosen & I may want to change it later. I collected the numbers
// by viewing a simple object, selecting a pretty view & dumping the
// transformation matrix I had built.

fourByFour stdView =
{
    {0.906307792530088, -0.109381667816302,  0.408217878032017, 0.0},
    {0.422618249959983,  0.234569751569506, -0.875426094224625, 0.0},
    {0.0,                0.965925816196225,  0.258819082769520, 0.0},
    {0.0,                0.0,                0.0,               1.0/700.0}
};


CViewpointWindow::CViewpointWindow()
{
   activeButton = NULL;
   mouseDrag = 0;
   moveObject = 1;
   for (int i=0; i<60; i++) buttonPressed[i] = 0;
// I will create my dialog window at a size that increases somewhat as the
// selected screen resolution does, on the hypothesis that people who use high
// resolutions will have physically large monitors and that this will then
// keep the displayed size of the box very roughly constant across systems.
// It will also mean that at higher resolutions the controls have more pixels
// in them so should be clearer and the box as a whole remains big enough
// to see, while with low resolution displays it doe snot take over quite
// all of the screen.
    int screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
    dlgWidth = 280;
    if (screenWidth > 640) dlgWidth = 320;
    if (screenWidth > 800) dlgWidth = 360;
    if (screenWidth > 1024) dlgWidth = 400;
    dlgHeight = (3*dlgWidth)/4;
    click = dlgWidth/40;
    setArcPoints();
// I will always start with the control box in the top right hand of the
// screen.
    CreateEx(0, "AfxWnd", "Graphics Viewpoint",
             WS_POPUP | WS_DLGFRAME | WS_OVERLAPPED,
             screenWidth-dlgWidth-10, 10, dlgWidth, dlgHeight,
             NULL, NULL);
    int fontSize = -((dlgWidth+15)/30);
    labelFont.CreateFont(fontSize, 0,
                         0, 0,
                         FW_NORMAL, 0, 0, 0, ANSI_CHARSET,
                         OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                         DEFAULT_QUALITY, DEFAULT_PITCH+FF_DONTCARE,
                         "Arial");
    fontSize = -((dlgWidth+10)/20);
    titleFont.CreateFont(fontSize, 0,
                         0, 0,
                         FW_BOLD, 0, 0, 0, ANSI_CHARSET,
                         OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                         DEFAULT_QUALITY, DEFAULT_PITCH+FF_DONTCARE,
                         "Arial");
    memcpy((void *)view1, (void *)stdView, sizeof(stdView));
    memcpy((void *)view2, (void *)stdView, sizeof(stdView));
    undoCount = undoPoint = 0;
}

virtual CViewpointWindow::~CViewpointWindow()
{
}

BEGIN_MESSAGE_MAP(CViewpointWindow, CWnd)

    ON_WM_SETFOCUS()
//  ON_WM_KILLFOCUS()
    ON_WM_ERASEBKGND()
    ON_WM_PAINT()

//  ON_WM_CHAR()
//  ON_WM_KEYDOWN()

    ON_WM_LBUTTONDOWN()
    ON_WM_LBUTTONUP()
    ON_WM_MOUSEMOVE()
    ON_WM_LBUTTONDBLCLK()

END_MESSAGE_MAP()


// Now message handlers


BOOL CViewpointWindow::OnEraseBkgnd(CDC *dc)
{
    CBrush backgroundBrush(RGB(255,255,128));
    CBrush *oldBrush = dc->SelectObject(&backgroundBrush);
    dc->Rectangle(0, 0, dlgWidth, dlgHeight);
    dc->SelectObject(oldBrush);
    return TRUE;
}

void CViewpointWindow::LText(CDC *dc, int x1, int y, char *s)
{
    int n = strlen(s);
    dc->TextOut(x1, y, s, n);
}

void CViewpointWindow::CText(CDC *dc, int x1, int x2, int y, char *s)
{
    int n = strlen(s);
    CSize w = dc->GetTextExtent(s, n);
    int slack = (x2 - x1) - w.cx;
    dc->TextOut(x1+slack/2, y, s, n);
}

void CViewpointWindow::RText(CDC *dc, int x2, int y, char *s)
{
    int n = strlen(s);
    CSize w = dc->GetTextExtent(s, n);
    dc->TextOut(x2-w.cx, y, s, n);
}

#define B_MID    0
#define B_UP     1
#define B_DOWN   2
#define B_LEFT   3
#define B_RIGHT  4
#define B_RADIO  5
#define B_CLOSE  6
#define B_TEXT   7
#define B_TWIST  8

const ButtonPlace buttonLocations[] =
{
#define mobjC   0
    { mobjC,    14, 8,   2,  B_RADIO,  NULL},     // What moves - eye or object?
#define meyeC   1
    { meyeC,    14, 6,   2,  B_RADIO,  NULL},     // (Radio buttons come first in this list)
#define far3C   2
    { far3C,    2,  28,  2,  B_LEFT,   NULL},     // The perspective FAR/NEAR arrows
#define far2C   3
    { far2C,    4,  28,  2,  B_LEFT,   NULL},
#define far1C   4
    { far1C,    6,  28,  2,  B_LEFT,   NULL},
#define far0C   5
    { far0C,    8,  28,  2,  B_MID,    NULL},
#define near1C  6
    { near1C,   10, 28,  2,  B_RIGHT,  NULL},
#define near2C  7
    { near2C,   12, 28,  2,  B_RIGHT,  NULL},
#define near3C  8
    { near3C,   14, 28,  2,  B_RIGHT,  NULL},
#define smal3C  9
    { smal3C,   2,  22,  2,  B_LEFT,   NULL},     // The image size SMALL/LARGE arrows
#define smal2C  10
    {smal2C,    4,  22,  2,  B_LEFT,   NULL},
#define smal1C  11
    {smal1C,    6,  22,  2,  B_LEFT,   NULL},
#define big0C   12
    {big0C,     8,  22,  2,  B_MID,    NULL},
#define big1C   13
    {big1C,     10, 22,  2,  B_RIGHT,  NULL},
#define big2C   14
    {big2C,     12, 22,  2,  B_RIGHT,  NULL},
#define big3C   15
    {big3C,     14, 22,  2,  B_RIGHT,  NULL},
#define left3C  16
    {left3C,    2,  12,  2,  B_LEFT,   NULL},     // The image position LEFT/RIGHT arrows
#define left2C  17
    {left2C,    4,  12,  2,  B_LEFT,   NULL},
#define left1C  18
    {left1C,    6,  12,  2,  B_LEFT,   NULL},
#define midC    19
    {midC,      8,  12,  2,  B_MID,    NULL},
#define right1C 20
    {right1C,   10, 12,  2,  B_RIGHT,  NULL},
#define right2C 21
    {right2C,   12, 12,  2,  B_RIGHT,  NULL},
#define right3C 22
    {right3C,   14, 12,  2,  B_RIGHT,  NULL},
#define down3C  23
    {down3C,    8,  18,  2,  B_DOWN,   NULL},     // The image position UP/DOWN arrows
#define down2C  24
    {down2C,    8,  16,  2,  B_DOWN,   NULL},
#define down1C  25
    {down1C,    8,  14,  2,  B_DOWN,   NULL},
#define up1C    26
    {up1C,      8,  10,  2,  B_UP,     NULL},
#define up2C    27
    {up2C,      8,  8,   2,  B_UP,     NULL},
#define up3C    28
    {up3C,      8,  6,   2,  B_UP,     NULL},
#define rleft3C 29
    {rleft3C,   24, 12,  2,  B_LEFT,   NULL},     // The rotation turntable-rotate arrows
#define rleft2C 30
    {rleft2C,   26, 12,  2,  B_LEFT,   NULL},
#define rleft1C 31
    {rleft1C,   28, 12,  2,  B_LEFT,   NULL},
#define backC   32
    {backC,     30, 12,  2,  B_MID,    NULL},
#define rrt1C   33
    {rrt1C,     32, 12,  2,  B_RIGHT,  NULL},
#define rrt2C   34
    {rrt2C,     34, 12,  2,  B_RIGHT,  NULL},
#define rrt3C   35
    {rrt3C,     36, 12,  2,  B_RIGHT,  NULL},
#define rdown3C 36
    {rdown3C,   30, 18,  2,  B_DOWN,   NULL},     // Rotation roll forwards/backwards arrows
#define rdown2C 37
    {rdown2C,   30, 16,  2,  B_DOWN,   NULL},
#define rdown1C 38
    {rdown1C,   30, 14,  2,  B_DOWN,   NULL},
#define rup1C   39
    {rup1C,     30, 10,  2,  B_UP,     NULL},
#define rup2C   40
    {rup2C,     30, 8,   2,  B_UP,     NULL},
#define rup3C   41
    {rup3C,     30, 6,   2,  B_UP,     NULL},
#define closeC  42
    {closeC,    38, 1,   1,  B_CLOSE,  NULL},
#define showC  43
    {showC,     18, 14,  4,  B_TEXT,   "show"},
#define undoC   44
    {undoC,     18, 18,  4,  B_TEXT,   "undo"},
#define stdC    45
    {stdC,      19, 25,  3,  B_TEXT,   "Std"},
#define XC      46
    {XC,        19, 28,  3,  B_TEXT,   "X"},
#define YC      47
    {YC,        24, 25,  3,  B_TEXT,   "Y"},
#define ZC      48
    {ZC,        24, 28,  3,  B_TEXT,   "Z"},
#define V1C     49
    {V1C,       29, 25,  3,  B_TEXT,   "V1"},
#define V2C     50
    {V2C,       29, 28,  3,  B_TEXT,   "V2"},
#define SV1C    51
    {SV1C,      34, 25,  4,  B_TEXT,   "set V1"},
#define SV2C    52
    {SV2C,      34, 28,  4,  B_TEXT,   "set V2"},
#define twl3C   53
    {twl3C,     1,  0,   0,  B_TWIST,   NULL},
#define twl2C   54
    {twl2C,     1,  1,   0,  B_TWIST,   NULL},
#define twl1C   55
    {twl1C,     1,  2,   0,  B_TWIST,   NULL},
#define twl0C   56
    {twl0C,     1,  3,   0,  B_TWIST,   NULL},
#define twr1C   57
    {twr1C,     1,  4,   0,  B_TWIST,   NULL},
#define twr2C   58
    {twr2C,     1,  5,   0,  B_TWIST,   NULL},
#define twr3C   59
    {twr3C,     1,  6,   0,  B_TWIST,   NULL},
    { 0,        0,  0,   0,  0,         NULL}
};

#define X  255

typedef unsigned char two_bytes[2];
typedef two_bytes seven_points[7];

const seven_points buttonShapes[] =
{
    {{2,2}, {2,4}, {4,4}, {4,2}, {X,0}, {0,0}, {0,0}},  // mid
    {{0,3}, {3,6}, {6,3}, {3,0}, {X,0}, {0,0}, {0,0}},  // mid selected
    {{1,1}, {5,1}, {3,5}, {X,0}, {0,0}, {0,0}, {0,0}},  // up
    {{2,1}, {2,3}, {1,3}, {3,5}, {5,3}, {4,3}, {4,1}},  // up selected
    {{3,1}, {1,5}, {5,5}, {X,0}, {0,0}, {0,0}, {0,0}},  // down
    {{3,0}, {5,3}, {4,3}, {4,5}, {2,5}, {2,3}, {1,3}},  // down selected
    {{1,3}, {5,1}, {5,5}, {X,0}, {0,0}, {0,0}, {0,0}},  // left
    {{0,3}, {3,5}, {3,4}, {5,4}, {5,2}, {3,2}, {3,1}},  // left selected
    {{1,1}, {1,5}, {5,3}, {X,0}, {0,0}, {0,0}, {0,0}},  // right
    {{1,2}, {1,4}, {3,4}, {3,5}, {5,3}, {3,1}, {3,2}}   // right selected
};

CPoint innerArc[8], outerArc[8];
CRect  innerRect,   outerRect;
CRgn   arcRegions[7];

void CViewpointWindow::DrawButton(CDC *dc, const ButtonPlace *pb)
{
    const two_bytes *p;
    int i;
    POINT pp[8];
    CRect r;
    CPen darkGrayPen(PS_SOLID, 0, RGB(128, 128, 128));
    int xx = click*pb->x, yy = click*pb->y;
    int width = click*pb->width;
    int flavour = 2*pb->flavour + buttonPressed[pb->id];
    switch (flavour)
    {
default:
        p = buttonShapes[flavour];
        dc->SelectStockObject(BLACK_PEN);
        dc->MoveTo(xx, yy);
        dc->LineTo(xx+2*click, yy);
        dc->LineTo(xx+2*click, yy-2*click);
        dc->MoveTo(xx, yy);
        dc->LineTo(xx, yy-2*click);
        dc->LineTo(xx+2*click, yy-2*click);
        dc->SelectStockObject(NULL_PEN);
        for (i=0; i<7 && p[i][0] != X; i++)
        {   int dx = p[i][0], dy = p[i][1];
            if (dx < 3) dx = dx*3;
            else if (dx > 3) dx = 2*click-(6-dx)*3;
            else dx = click;
            if (dy < 3) dy = dy*3;
            else if (dy > 3) dy = 2*click-(6-dy)*3;
            else dy = click;
            pp[i].x = xx + dx;
            pp[i].y = yy - dy;
        }
        dc->SelectStockObject(BLACK_BRUSH);
        dc->Polygon(pp, i);
        return;

case 2*B_CLOSE+1:
        dc->SelectStockObject(GRAY_BRUSH);
        dc->Rectangle(xx, yy-click, xx+click+2, yy+2);
case 2*B_CLOSE:
        dc->SelectStockObject(BLACK_PEN);
        dc->MoveTo(xx, yy);
        dc->LineTo(xx+click, yy);
        dc->LineTo(xx, yy-click);
        dc->LineTo(xx, yy);
        dc->LineTo(xx+click, yy-click);
        dc->MoveTo(xx, yy-click);
        dc->LineTo(xx+click, yy-click);
        dc->LineTo(xx+click, yy);
        return;

case 2*B_TWIST+1:
        dc->SelectStockObject(GRAY_BRUSH);
case 2*B_TWIST:
        i = pb->y;
        pp[0] = innerArc[i];
        pp[1] = innerArc[i+1];
        pp[2] = outerArc[i];
        dc->Polygon(pp, 3);
        pp[0] = innerArc[i+1];
        pp[1] = outerArc[i];
        pp[2] = outerArc[i+1];
        dc->Polygon(pp, 3);
        dc->SelectStockObject(BLACK_PEN);
        dc->MoveTo(innerArc[i]);
        dc->LineTo(outerArc[i]);
        dc->MoveTo(innerArc[i+1]);
        dc->LineTo(outerArc[i+1]);
        dc->Arc(&innerRect, innerArc[i], innerArc[i+1]);
        dc->Arc(&outerRect, outerArc[i], outerArc[i+1]);
        return;

case 2*B_RADIO+1:
        dc->SelectStockObject(GRAY_BRUSH);
        dc->Ellipse(xx+click-2*3, yy-click-2*3,
                    xx+click+2*3, yy-click+2*3);
case 2*B_RADIO:
        dc->SelectStockObject(BLACK_BRUSH);
        if (pb->id != moveObject)
            dc->Ellipse(xx+click-3, yy-click-3,
                        xx+click+3, yy-click+3);
        dc->SelectStockObject(NULL_BRUSH);
        dc->SelectStockObject(BLACK_PEN);
        dc->Ellipse(xx+click-2*3, yy-click-2*3,
                    xx+click+2*3, yy-click+2*3);
        return;

case 2*B_TEXT+1:
        dc->SelectStockObject(BLACK_PEN);
        dc->SelectStockObject(NULL_BRUSH);
        r.SetRect(xx, yy-2*click, xx+width, yy);
        pp[0].x = 3;
        pp[0].y = 3;
        dc->RoundRect(&r, pp[0]);
        dc->SelectObject(&darkGrayPen);
        dc->MoveTo(xx+width-2, yy-2*click+1);
        dc->LineTo(xx+1, yy-2*click+1);
        dc->LineTo(xx+1, yy-2);
        CText(dc, xx, xx+width+2, yy-2*click+2, pb->text);
        dc->SelectStockObject(BLACK_PEN);
        return;
case 2*B_TEXT:
        dc->SelectStockObject(BLACK_PEN);
        dc->SelectStockObject(NULL_BRUSH);
        r.SetRect(xx, yy-2*click, xx+width, yy);
        pp[0].x = 3;
        pp[0].y = 3;
        dc->RoundRect(&r, pp[0]);
        dc->SelectStockObject(WHITE_PEN);
        dc->MoveTo(xx+width-2, yy-2*click+1);
        dc->LineTo(xx+1, yy-2*click+1);
        dc->LineTo(xx+1, yy-2);
        dc->SelectObject(&darkGrayPen);
        dc->LineTo(xx+width-2, yy-2);
        dc->LineTo(xx+width-2, yy-2*click+1);
        CText(dc, xx, xx+width, yy-2*click, pb->text);
        dc->SelectStockObject(BLACK_PEN);
        return;
    }
}

#undef X

void copyView(fourByFour *dest, fourByFour *src)
{
   for (int i=0; i<3; i++)
       for (int j=0; j<3; j++) (*dest)[i][j] = (*src)[i][j];
}

void CViewpointWindow::resetXform(int whence)
{
    fourByFour *m = &theApp.mainWindow->graphicsWindow->xform;
    int i, j;
    if (whence != Undo)
    {   copyView(&undoStack[undoPoint++ & undoMask], m);
        if (undoCount != undoMask) undoCount++;
    }
    switch (whence)
    {
case Xaxis:   for (i=0; i<3; i++)
                  for (j=0; j<3; j++) (*m)[i][j] = 0.0;
              (*m)[0][1] = (*m)[1][2] = (*m)[2][0] = 1.0;
              break;
case Yaxis:   for (i=0; i<3; i++)
                  for (j=0; j<3; j++) (*m)[i][j] = 0.0;
              (*m)[0][2] = (*m)[1][0] = (*m)[2][1] = 1.0;
              break;
case Zaxis:   for (i=0; i<3; i++)
                  for (j=0; j<3; j++) (*m)[i][j] = 0.0;
              (*m)[0][0] = (*m)[1][1] = (*m)[2][2] = 1.0;
              break;
case StdView: copyView(m, &stdView);
              break;
case View1:   copyView(m, &view1);
              break;
case View2:   copyView(m, &view2);
              break;
case Undo:    if (undoCount == 0) break;
              copyView(m, &undoStack[--undoPoint & undoMask]);
              undoCount--;
              break;
    }
    theApp.mainWindow->graphicsWindow->Invalidate();
}


void CViewpointWindow::changeXform(double delta[4][4])
{
    double xform1[4][4];
    int i, j, k;
    copyView(&undoStack[undoPoint++ & undoMask],
             &theApp.mainWindow->graphicsWindow->xform);
    if (undoCount != undoMask) undoCount++;
    for (i=0; i<4; i++)
        for (k=0; k<4; k++)
        {   double w = 0.0;
            for (j=0; j<4; j++)
                w += theApp.mainWindow->graphicsWindow->xform[i][j]*delta[j][k];
            xform1[i][k] = w;
        }
    for (i=0; i<4; i++)
        for (j=0; j<4; j++)
            theApp.mainWindow->graphicsWindow->xform[i][j] = xform1[i][j];
    theApp.mainWindow->graphicsWindow->Invalidate();
}

const double toRadians = 0.017453292;   // pi/180

void CViewpointWindow::rotateXform(int axis, double angle)
{
    if (moveObject) angle = -angle;
    angle *= toRadians;
    double rot[4][4];
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            rot[i][j] = (i == j) ? 1.0 : 0.0;
    double c = cos(angle), s = sin(angle);
    switch (axis)
    {
case Xaxis:
        rot[1][1] = rot[2][2] = c;
        rot[1][2] = -s; rot[2][1] = s;
        break;
case Yaxis:
        rot[0][0] = rot[2][2] = c;
        rot[0][2] = -s; rot[2][0] = s;
        break;
case Zaxis:
        rot[1][1] = rot[0][0] = c;
        rot[1][0] = -s; rot[0][1] = s;
        break;
    }
    changeXform(rot);
}


void CViewpointWindow::scaleXform(double factor)
{
    double xform1[4][4];
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            xform1[i][j] = (i == j) ? 1.0 : 0.0;
    xform1[3][3] = 1/factor;
    changeXform(xform1);
}

void CViewpointWindow::translateXform(double x, double y)
{
    double xform1[4][4];
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            xform1[i][j] = (i == j) ? 1.0 : 0.0;
    if (moveObject) x = -x, y = -y;
    xform1[3][0] = x;
    xform1[3][1] = y;
    changeXform(xform1);
}


void CViewpointWindow::ButtonAction(int n)
{
    switch (n)
    {
case mobjC:
        moveObject = 1;
        SetControl(&buttonLocations[0], 0);
        SetControl(&buttonLocations[1], 0);
        return;
case meyeC:
        moveObject = 0;
        SetControl(&buttonLocations[0], 0);
        SetControl(&buttonLocations[1], 0);
        return;
case far3C:
        theApp.mainWindow->graphicsWindow->perspecDistance *= 1.2*1.2*1.2;
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case far2C:
        theApp.mainWindow->graphicsWindow->perspecDistance *= 1.2*1.2;
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case far1C:
        theApp.mainWindow->graphicsWindow->perspecDistance *= 1.1;
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case far0C:
        theApp.mainWindow->graphicsWindow->perspecDistance = 50000.0;
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case near1C:
        theApp.mainWindow->graphicsWindow->perspecDistance /= 1.1;
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case near2C:
        theApp.mainWindow->graphicsWindow->perspecDistance /= (1.2*1.2);
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case near3C:
        theApp.mainWindow->graphicsWindow->perspecDistance /= (1.2*1.2*1.2);
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case smal3C:
        scaleXform(1.0/(1.2*1.2*1.2));
        return;
case smal2C:
        scaleXform(1.0/(1.2*1.2));
        return;
case smal1C:
        scaleXform(1.0/1.1);
        return;
case big0C:
        scaleXform(theApp.mainWindow->graphicsWindow->xform[3][3]*700.0);
        return;
case big1C:
        scaleXform(1.1);
        return;
case big2C:
        scaleXform(1.2*1.2);
        return;
case big3C:
        scaleXform(1.2*1.2*1.2);
        return;
case left3C:
        translateXform(2500.0, 0.0);
        return;
case left2C:
        translateXform(500.0, 0.0);
        return;
case left1C:
        translateXform(100.0, 0.0);
        return;
case midC:
        translateXform(-theApp.mainWindow->graphicsWindow->xform[0][3],
                       -theApp.mainWindow->graphicsWindow->xform[1][3]);
        return;
case right1C:
        translateXform(-100.0, 0.0);
        return;
case right2C:
        translateXform(-500.0, 0.0);
        return;
case right3C:
        translateXform(-2500.0, 0.0);
        return;
case down3C:
        translateXform(0.0, 2500.0);
        return;
case down2C:
        translateXform(0.0, 500.0);
        return;
case down1C:
        translateXform(0.0, 100.0);
        return;
case up1C:
        translateXform(0.0, -100.0);
        return;
case up2C:
        translateXform(0.0, -500.0);
        return;
case up3C:
        translateXform(0.0, -2500.0);
        return;
case rleft3C:
        rotateXform(Yaxis, 22.5);
        return;
case rleft2C:
        rotateXform(Yaxis, 5.625);
        return;
case rleft1C:
        rotateXform(Yaxis, 1.125);
        return;
case backC:
        rotateXform(Yaxis, 180.0);
        return;
case rrt1C:
        rotateXform(Yaxis, -1.125);
        return;
case rrt2C:
        rotateXform(Yaxis, -5.625);
        return;
case rrt3C:
        rotateXform(Yaxis, -22.5);
        return;
case rdown3C:
        rotateXform(Xaxis, 22.5);
        return;
case rdown2C:
        rotateXform(Xaxis, 5.625);
        return;
case rdown1C:
        rotateXform(Xaxis, 1.125);
        return;
case rup1C:
        rotateXform(Xaxis, -1.125);
        return;
case rup2C:
        rotateXform(Xaxis, -5.625);
        return;
case rup3C:
        rotateXform(Xaxis, -22.5);
        return;
case closeC:
        theApp.mainWindow->graphicsWindow->PostMessage(WM_USER+2, 0, 0);
        return;
case showC:
        theApp.mainWindow->graphicsWindow->fullRender = 1;
        theApp.mainWindow->graphicsWindow->Invalidate();
        return;
case undoC:
        resetXform(Undo);
        return;
case stdC:
        resetXform(StdView);
        return;
case XC:
        resetXform(Xaxis);
        return;
case YC:
        resetXform(Yaxis);
        return;
case ZC:
        resetXform(Zaxis);
        return;
case V1C:
        resetXform(View1);
        return;
case V2C:
        resetXform(View2);
        return;
case SV1C:
        memcpy((void *)view1, (void *)theApp.mainWindow->graphicsWindow->xform, sizeof(stdView));
        return;
case SV2C:
        memcpy((void *)view2, (void *)theApp.mainWindow->graphicsWindow->xform, sizeof(stdView));
        return;
case twl3C:
        rotateXform(Zaxis, 22.5);
        return;
case twl2C:
        rotateXform(Zaxis, 5.625);
        return;
case twl1C:
        rotateXform(Zaxis, 1.125);
        return;
case twl0C:
        rotateXform(Zaxis, 180.0);
        return;
case twr1C:
        rotateXform(Zaxis, -1.125);
        return;
case twr2C:
        rotateXform(Zaxis, -5.625);
        return;
case twr3C:
        rotateXform(Zaxis, -22.5);
        return;
    }
}

void CViewpointWindow::setArcPoints()
{
    innerRect.SetRect(22*click, 2*click, 40*click, 20*click);
    outerRect.SetRect(20*click, 0, 42*click, 22*click);
    double a = atan(1/10.0), b, sb, cb, k = (double)click;;
    for (int i=0; i<8; i++)
    {   b = a*(double)(2*i-7);
        sb = sin(b);
        cb = cos(b);
        innerArc[i].x = 31*click + (int)(9.0*k*sb);
        innerArc[i].y = 11*click + (int)(9.0*k*cb);
        outerArc[i].x = 31*click + (int)(11.0*k*sb);
        outerArc[i].y = 11*click + (int)(11.0*k*cb);
    }
    for (i=0; i<7; i++)
    {   CPoint pp[4];
        pp[0] = innerArc[i];   pp[1] = outerArc[i];
        pp[2] = outerArc[i+1]; pp[3] = innerArc[i+1];
        arcRegions[i].CreatePolygonRgn(pp, 4, ALTERNATE);
    }
}

void CViewpointWindow::OnPaint()
{
    CPaintDC dc(this);
    dc.SelectStockObject(NULL_BRUSH);
    dc.SetBkMode(TRANSPARENT);
    dc.SelectObject(&titleFont);
    CText(&dc, 2*click,  16*click, click, "Position");
    CText(&dc, 24*click, 38*click, click, "Rotation");

    dc.SelectObject(&labelFont);
    LText(&dc, 2*click,   24*click, "far");
    RText(&dc, 16*click,  24*click, "near");
    LText(&dc, 2*click,   18*click, "small");
    RText(&dc, 16*click,  18*click, "large");
    LText(&dc, 2*click,   12*click, "left");
    RText(&dc, 16*click,  12*click, "right");
    LText(&dc, 10*click+3, 16*click, "down");
    LText(&dc, 10*click+3, 4*click,"up");
    LText(&dc, 32*click+3, 4*click,"roll");
    RText(&dc, 38*click,  12*click, "rotate");
    RText(&dc, 38*click,  16*click, "twist");
    LText(&dc, 16*click,  6*click,  "move object");
    LText(&dc, 16*click,  4*click,  "move viewpoint");

    CBrush backgroundBrush(RGB(255,255,128));

    const ButtonPlace *pb = buttonLocations;
    while (pb->x != 0)
    {   dc.SelectObject(&backgroundBrush);
        dc.SelectStockObject(NULL_PEN);
        switch (pb->flavour)
        {
    case B_TWIST:
            break;      // fills in its own background
    case B_CLOSE:
            dc.Rectangle(click*pb->x, click*(pb->y-1),
                         click*(pb->x+1), click*pb->y);
            break;
    default:
            dc.Rectangle(click*pb->x, click*(pb->y-2),
                         click*(pb->x+pb->width), click*pb->y);
            break;
        }
        DrawButton(&dc, pb);
        pb++;
    }

    dc.SelectStockObject(SYSTEM_FONT);
}

void CViewpointWindow::OnSetFocus(CWnd *pOldWnd)
{
    SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);
}


void CViewpointWindow::OnKillFocus(CWnd *pNewWnd)
{
}


void CViewpointWindow::OnChar(UINT ch, UINT nRepCnt, UINT nFlags)
{
    DisplayMsg("Viewpoint Window OnChar");
}


void CViewpointWindow::OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags)
{
    DisplayMsg("Viewpoint Window OnKeyDown");
}


int CViewpointWindow::inButton(const ButtonPlace *b, int x, int y)
{
    if (b->flavour == B_TWIST) return arcRegions[b->y].PtInRegion(x, y);
    else return (click*b->x <= x && x < click*(b->x+b->width) &&
                 click*((int)b->y-2) <= y && y < click*b->y);
}

const ButtonPlace *CViewpointWindow::FindControl(int x, int y)
{
    const ButtonPlace *b = buttonLocations;
    while (b->x != 0)
    {   if (inButton(b, x, y)) return b;
        b++;
    }
    return NULL;
}

void CViewpointWindow::SetControl(const ButtonPlace *b, int state)
{
    buttonPressed[b->id] = state;
    CRect r(click*b->x, click*((int)b->y-2),
            click*(b->x+b->width), click*b->y);
    if (b->flavour == B_TWIST) InvalidateRgn(&arcRegions[b->y], FALSE);
    else InvalidateRect(&r, FALSE);
}

void CViewpointWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
    SetCapture();
    const ButtonPlace *b = FindControl(point.x, point.y);
    if (b == NULL)
    {   mouseDrag = 1;
        mouseX = point.x;
        mouseY = point.y;
    }
    else
    {   activeButton = b;
        SetControl(b, 1);
    }
}

// If the user double-clicks on the dialog box it will go away. Well, at least
// if the double-click is not on a button.

void CViewpointWindow::OnLButtonDblClk(UINT nFlags, CPoint point)
{
    if (FindControl(point.x, point.y) == NULL)
        theApp.mainWindow->graphicsWindow->PostMessage(WM_USER+2, 0, 0);
}

void CViewpointWindow::OnLButtonUp(UINT nFlags, CPoint point)
{
    ReleaseCapture();
    if (mouseDrag)
    {   mouseDrag = 0;
        activeButton = NULL;
        return;
    }
    if (activeButton == NULL) return;
    const ButtonPlace *b = activeButton;
    activeButton = NULL;
    if (inButton(b, point.x, point.y))
    {   buttonPressed[b->id] = 0;
        SetControl(b, 0);
        ButtonAction(b->id);      // Dispatch to some activity
    }
}

void CViewpointWindow::OnMouseMove(UINT nFlags, CPoint point)
{
    if (mouseDrag)
    {   WINDOWPLACEMENT w;
        GetWindowPlacement(&w);
        w.rcNormalPosition.left   += point.x - mouseX;
        w.rcNormalPosition.right  += point.x - mouseX;
        w.rcNormalPosition.top    += point.y - mouseY;
        w.rcNormalPosition.bottom += point.y - mouseY;
        SetWindowPlacement(&w);
        return;
    }
    if (activeButton == NULL) return;
    const ButtonPlace *b = activeButton;
    if (inButton(b, point.x, point.y))
    {   if (buttonPressed[b->id] == 0)
        {   buttonPressed[b->id] = 1;
            SetControl(b, 1);
        }
    }
    else if (buttonPressed[b->id])
    {   buttonPressed[b->id] = 0;
        SetControl(b, 0);
    }
}

#endif

// end of c_viewpt.cpp
