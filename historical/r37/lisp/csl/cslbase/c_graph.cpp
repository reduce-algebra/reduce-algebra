// c_graph.cpp
//     Management of the graphics window, including its menus,
//     COPY and PRINT operations and re-sizing.
//
//     Copyright (C)/©/¸ Codemist Ltd, 1995-2001


/*
 * This code may be used and modified, and redistributed in binary
 * or source form, subject to the "CCL Public License", which should
 * accompany it. This license is a variant on the BSD license, and thus
 * permits use of code derived from this in either open and commercial
 * projects: but it does require that updates to this code be made
 * available back to the originators of the package.
 * Before merging other code in with this or linking this code
 * with other packages or libraries please check that the license terms
 * of the other material are compatible with those of this.
 */


/* Signature: 54823e70 08-Apr-2002 */

#ifdef GRAPHICS_WINDOW

#include "cwin.hpp"


CGraphicsWindow::CGraphicsWindow()
{
// I want the default size for my graphics window to be something that I
// control rather than something that Windows imposes upon me. So I will
// start by measuring the screen and go on from there...
    screenWidth = ::GetSystemMetrics(SM_CXSCREEN);
    screenHeight = ::GetSystemMetrics(SM_CYSCREEN);
    graphicsWidth = (10*screenWidth)/17;
    graphicsHeight = (4*graphicsWidth)/5;
    CRect r(rectDefault);
    CSize s(graphicsWidth, graphicsHeight);
    CPoint w = r.TopLeft();
    r.BottomRight() = w + s;
    int temp = r.right - screenWidth + 16;
    if (temp > 0) r.left -= temp, r.right -= temp;
    temp = r.bottom - screenHeight + 16;
    if (temp > 0) r.bottom -= temp, r.top -= temp;
    Create(NULL, "Graphics Window",
                 WS_POPUP | WS_CAPTION | WS_OVERLAPPED | WS_MINIMIZEBOX |
                 WS_MAXIMIZEBOX | WS_TABSTOP | WS_THICKFRAME,
                 r, NULL,
                 "GraphicsMenu");
    this->GetClientRect(&r);
    graphicsHeight = r.bottom - r.top;
    graphicsWidth = r.right - r.left;
    viewpointWindow.ShowWindow(SW_HIDE);
    viewpointShown = FALSE;
    memcpy((void *)xform, (void *)stdView, sizeof(stdView));
    perspecDistance = 50000.0;
    drawWire = 1;
    drawSurface = IDM_SQUARES;
    wirePreview = 1;
    fullRender = fullyRendered = 0;
    ctrlPressed = 0;
}

virtual CGraphicsWindow::~CGraphicsWindow()
{
    DestroyWindow();
}

BEGIN_MESSAGE_MAP(CGraphicsWindow, CFrameWnd)

    ON_WM_SETFOCUS()
//  ON_WM_KILLFOCUS()
    ON_WM_SIZE()
    ON_WM_PAINT()

    ON_WM_CHAR()
//  ON_WM_SYSCHAR()
    ON_WM_KEYDOWN()
    ON_WM_KEYUP()

//  ON_WM_LBUTTONDBLCLK()
//  ON_WM_LBUTTONDOWN()
//  ON_WM_LBUTTONUP()
//  ON_WM_MBUTTONDBLCLK()
//  ON_WM_MBUTTONDOWN()
//  ON_WM_MBUTTONUP()
//  ON_WM_RBUTTONDBLCLK()
//  ON_WM_RBUTTONDOWN()
//  ON_WM_RBUTTONUP()
//  ON_WM_MOUSEMOVE()

//  ON_WM_NCLBUTTONDOWN()
//  ON_WM_NCMBUTTONDOWN()
//  ON_WM_NCRBUTTONDOWN()

// Now things on the menus...

    ON_COMMAND(IDM_SAVEAS,         OnSaveAs)
    ON_COMMAND(IDM_PRINT,          OnPrint)
    ON_COMMAND(IDM_CLOSE,          OnCloseButton)

    ON_COMMAND(IDM_COPY,           OnCopy)
    ON_COMMAND(IDM_CLEAR,          OnClear)
    ON_COMMAND(IDM_REDRAW,         OnRedraw)
    ON_COMMAND(IDM_VIEWPOINT,      OnViewpoint)
    ON_MESSAGE(WM_USER+2,          OnViewpoint1)
    ON_COMMAND(IDM_WIREFRAME,      OnWireframe)
    ON_COMMAND(IDM_NOSURFACE,      OnNoSurface)
    ON_COMMAND(IDM_SURFACE,        OnSurface)
    ON_COMMAND(IDM_SQUARES,        OnSquares)
    ON_COMMAND(IDM_TRIANGLES,      OnTriangles)
    ON_COMMAND(IDM_SMOOTH,         OnSmooth)
    ON_COMMAND(IDM_HISMOOTH,       OnHiSmooth)
    ON_COMMAND(IDM_WIREPREVIEW,    OnWirePreview)
    ON_COMMAND(IDM_ROTLEFT,        OnRotLeft)
    ON_COMMAND(IDM_ROTRIGHT,       OnRotRight)
    ON_COMMAND(IDM_ROTUP,          OnRotUp)
    ON_COMMAND(IDM_ROTDOWN,        OnRotDown)
    ON_COMMAND(IDM_CLOCKWISE,      OnClockwise)
    ON_COMMAND(IDM_ANTICLOCK,      OnAntiClockwise)
    ON_COMMAND(IDM_ENLARGE,        OnEnlarge)
    ON_COMMAND(IDM_SHRINK,         OnShrink)

END_MESSAGE_MAP()


// Now message handlers


void CGraphicsWindow::OnCloseButton()
{
    theApp.mainWindow->PostMessage(WM_USER, 0, 0);
}

void CGraphicsWindow::OnSize(UINT nType, int cx, int cy)
{
    graphicsWidth = cx;
    graphicsHeight = cy;
    Invalidate();
}

void CGraphicsWindow::OnPaint()
{
    CClientDC dc(this);
    CRect rect;
    this->GetClientRect(&rect);
    RECT r;
    GetUpdateRect(&r, TRUE);
// In some cases I will redraw the screen in bands, in an attempt to get
// better response to further events... if I draw the whole object all at once
// the re-draw can take a painfully long time during which my application is
// unable to respond to anything else.
    if (drawSurface == IDM_SMOOTH || drawSurface == IDM_HISMOOTH)
    {   int clientWidth = rect.right - rect.left;
        int left = r.left, right = r.right;
        int updateWidth = right - left;
        if (4*updateWidth > 3*clientWidth+10) r.right = (3*left + right)/4;
        else if (2*updateWidth > clientWidth+10) r.right = (2*left + right)/3;
        else if (4*updateWidth > clientWidth+10) r.right = (left + right)/2;
    }
    ValidateRect(&r);
    dc.IntersectClipRect(&r);
    PaintOrPrint(&dc, &r, graphicsWidth, graphicsHeight, NULL, NULL);
    dc.SelectStockObject(SYSTEM_FONT);
}

void CGraphicsWindow::SubTriangle(CDC *dc,
                     int x1, int y1, int red1, int green1, int blue1,
                     int x2, int y2, int red2, int green2, int blue2,
                     int x3, int y3, int red3, int green3, int blue3, int n)
{
    if (n == 0)
    {   POINT p[3];
        p[0].x = x1; p[0].y = y1;
        p[1].x = x2; p[1].y = y2;
        p[2].x = x3; p[2].y = y3;
        CBrush b(RGB((red1+red2+red3)/3,
                     (green1+green2+green3)/3,
                     (blue1+blue2+blue3)/3));
        CBrush *oldBrush = dc->SelectObject(&b);
        dc->Polygon(p, 3);
        dc->SelectObject(oldBrush);
        return;
    }
    SubTriangle(dc, x1, y1, red1, green1, blue1,
                    (x1+x2)/2, (y1+y2)/2, (red1+red2)/2, (green1+green2)/2, (blue1+blue2)/2,
                    (x1+x3)/2, (y1+y3)/2, (red1+red3)/2, (green1+green3)/2, (blue1+blue3)/2, n-1);
    SubTriangle(dc, x2, y2, red2, green2, blue2,
                    (x2+x3)/2, (y2+y3)/2, (red2+red3)/2, (green2+green3)/2, (blue2+blue3)/2,
                    (x2+x1)/2, (y2+y1)/2, (red2+red1)/2, (green2+green1)/2, (blue2+blue1)/2, n-1);
    SubTriangle(dc, x3, y3, red3, green3, blue3,
                    (x3+x1)/2, (y3+y1)/2, (red3+red1)/2, (green3+green1)/2, (blue3+blue1)/2,
                    (x3+x2)/2, (y3+y2)/2, (red3+red2)/2, (green3+green2)/2, (blue3+blue2)/2, n-1);
    SubTriangle(dc, (x2+x3)/2, (y2+y3)/2, (red2+red3)/2, (green2+green3)/2, (blue2+blue3)/2,
                    (x1+x2)/2, (y1+y2)/2, (red1+red2)/2, (green1+green2)/2, (blue1+blue2)/2,
                    (x1+x3)/2, (y1+y3)/2, (red1+red3)/2, (green1+green3)/2, (blue1+blue3)/2, n-1);
}


void CGraphicsWindow::PaintOrPrint(CDC *dc, RECT *clip, int width, int height,
                                   CFont *mainFont, CFont *smallFont)
{
    paintTriangles(dc, clip, width, height);
}

void CGraphicsWindow::OnSetFocus(CWnd *pOldWnd)
{
    SetWindowPos(&wndTop, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE|SWP_SHOWWINDOW);
}


void CGraphicsWindow::OnKillFocus(CWnd *pNewWnd)
{
}


void CGraphicsWindow::OnChar(UINT ch, UINT nRepCnt, UINT nFlags)
{
    switch (ch)
    {
case ('O' & 0x1f):
        OnCopy();
        return;
case ('L' & 0x1f):
        OnRedraw();
        return;
default:
//      DisplayMsg("Char %d %x", ch, ch);
        return;
    }
}


//-  void CGraphicsWindow::OnSysChar(UINT ch, UINT nRepCnt, UINT nFlags)
//-  {
//-      switch (ch)
//-      {
//-  default:
//-          DisplayMsg("SysChar %d %x", ch, ch);
//-          return;
//-      }
//-  }


void CGraphicsWindow::OnKeyDown(UINT ch, UINT nRepCnt, UINT nFlags)
{
    switch (ch)
    {
case VK_SHIFT:
        ctrlPressed |= 1;
        break;
case VK_CONTROL:
        ctrlPressed |= 2;
        break;
// Here the direction arrows can be used to shift the object (in this case
// I will always make them move the object, never the viewpoint). Just
// pressed directly they give rotations. SHIFT increases the amount of
// rotation applied.  CONTROL and CONTROL+SHIFT give translations rather than
// rotations.  I do not give as fine control here as I do via the viewpoint
// dialog-box, and will always fully repaint the screen after every keystroke,
// which may sometimes feel clumsy.
case VK_LEFT:
case VK_NUMPAD4:
        switch (ctrlPressed & 3)
        {
    case 0:  viewpointWindow.rotateXform(Yaxis, 5.625);     break;
    case 1:  viewpointWindow.rotateXform(Yaxis, 22.5);      break;
    case 2:  viewpointWindow.translateXform(500.0, 0.0);    break;
    case 3:  viewpointWindow.translateXform(2500.0, 0.0);   break;
        }
        break;

case VK_RIGHT:
case VK_NUMPAD6:
        switch (ctrlPressed & 3)
        {
    case 0:  viewpointWindow.rotateXform(Yaxis, -5.625);    break;
    case 1:  viewpointWindow.rotateXform(Yaxis, -22.5);     break;
    case 2:  viewpointWindow.translateXform(-500.0, 0.0);   break;
    case 3:  viewpointWindow.translateXform(-2500.0, 0.0);  break;
        }
        break;

case VK_UP:
case VK_NUMPAD8:
        switch (ctrlPressed & 3)
        {
    case 0:  viewpointWindow.rotateXform(Xaxis, -5.625);    break;
    case 1:  viewpointWindow.rotateXform(Xaxis, -22.5);     break;
    case 2:  viewpointWindow.translateXform(0.0, -500.0);   break;
    case 3:  viewpointWindow.translateXform(0.0, -2500.0);  break;
        }
        break;

case VK_DOWN:
case VK_NUMPAD2:
        switch (ctrlPressed & 3)
        {
    case 0:  viewpointWindow.rotateXform(Xaxis, 5.625);     break;
    case 1:  viewpointWindow.rotateXform(Xaxis, 22.5);      break;
    case 2:  viewpointWindow.translateXform(0.0, 500.0);    break;
    case 3:  viewpointWindow.translateXform(0.0, 2500.0);   break;
        }
        break;

case VK_X:
        viewpointWindow.resetXform(Xaxis);
        break;
case VK_Y:
        viewpointWindow.resetXform(Yaxis);
        break;
case VK_Z:
        viewpointWindow.resetXform(Zaxis);
        break;

    }
}


void CGraphicsWindow::OnKeyUp(UINT ch, UINT nRepCnt, UINT nFlags)
{
    switch (ch)
    {
case VK_SHIFT:
        ctrlPressed &= ~1;
        break;
case VK_CONTROL:
        ctrlPressed &= ~2;
        break;
    }
}


void CGraphicsWindow::OnLButtonDblClk(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnLButtonUp(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnMButtonDblClk(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnMButtonDown(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnMButtonUp(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnRButtonDblClk(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnRButtonDown(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnRButtonUp(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnMouseMove(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnNcLButtonDown(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnNcMButtonDown(UINT nFlags, CPoint point)
{
}


void CGraphicsWindow::OnNcRButtonDown(UINT nFlags, CPoint point)
{
}



//
// Now the things provoked from the menus...
//

HGLOBAL CGraphicsWindow::PaintBitmap(int *size, int *ppsize)
{
    CPaintDC dc(this);
    CRect rect;
    this->GetClientRect(&rect);
// I will create a bitmap device and render the image into that...
    CDC memDC;
    memDC.CreateCompatibleDC(&dc);
    CBitmap memBitmap;
    memBitmap.CreateCompatibleBitmap(&dc, graphicsWidth, graphicsHeight);
    CBitmap *pBmp = memDC.SelectObject(&memBitmap);
// I seem to need to clear the bitmap before I draw anything else
// on it. I will do that by drawing an oversized rectangle so that the
// interior of the rectangle covers the entire bitmap.
    memDC.SelectStockObject(WHITE_BRUSH);
    memDC.SelectStockObject(WHITE_PEN);
    memDC.Rectangle(-100, graphicsHeight+100, graphicsWidth+100, -100);
    PaintOrPrint(&memDC, NULL, graphicsWidth, graphicsHeight, NULL, NULL);
    memDC.SelectStockObject(SYSTEM_FONT);
    memDC.SelectObject(pBmp);
// Now I want to form the bitmap into a Device Independent Bitmap (DIB).
// This mainly involves creating a header to stick on the front.
    BITMAP bmp;
    memBitmap.GetObject(sizeof(BITMAP), &bmp);
    WORD cClrBits = (WORD)(bmp.bmPlanes * bmp.bmBitsPixel);
    if (cClrBits > 24) cClrBits = 32;
    else if (cClrBits > 16) cClrBits = 24;
    else if (cClrBits > 4) cClrBits = 8;
    else if (cClrBits > 1) cClrBits = 4;
    else cClrBits = 1;
    int psize = (cClrBits >= 24) ? 0 : (1 << cClrBits);
    int imageSize = (bmp.bmWidth + 7)/8 * bmp.bmHeight * cClrBits;
    int totalSize = sizeof(BITMAPINFOHEADER)+psize*sizeof(RGBQUAD)+imageSize;
    HGLOBAL hpbmi = ::GlobalAlloc(GMEM_MOVEABLE, totalSize);
    BITMAPINFOHEADER *pbmi = (BITMAPINFOHEADER *)::GlobalLock(hpbmi);
    pbmi->biSize = sizeof(BITMAPINFOHEADER);
    pbmi->biWidth = bmp.bmWidth;
    pbmi->biHeight = bmp.bmHeight;
    pbmi->biPlanes = 1;
    pbmi->biBitCount = cClrBits;
    pbmi->biCompression = BI_RGB;   // No compression here
    pbmi->biXPelsPerMeter = 0;
    pbmi->biYPelsPerMeter = 0;
    pbmi->biSizeImage = imageSize;
    pbmi->biClrUsed = 0;
    pbmi->biClrImportant = 0;
// The bitmap itself needs to be copied out into PBM format, so I have
// to allocate yet another buffer for the information to go into. This may be
// up to another 2.5 Mbytes...
    LPBYTE lpBits = (LPBYTE)pbmi + sizeof(BITMAPINFOHEADER) +
                            psize*sizeof(RGBQUAD);
    ::GetDIBits(memDC.m_hDC, (HBITMAP)memBitmap.m_hObject,
                0, (WORD)bmp.bmHeight,
                lpBits, (PBITMAPINFO)pbmi, DIB_RGB_COLORS);
    ::GlobalUnlock(hpbmi);
    *size = totalSize;
    *ppsize = psize*sizeof(RGBQUAD);
    return hpbmi;
}

void CGraphicsWindow::OnSaveAs()
{
    int totalSize;
    int psize;
    HGLOBAL hpbmi = PaintBitmap(&totalSize, &psize);
    void *pbmi = (void *)::GlobalLock(hpbmi);
// With a PMB header created I now get the structure ready to go in a file.
    BITMAPFILEHEADER hdr;
    hdr.bfType = 0x4d42;  // Type = "BM"
    hdr.bfSize = (DWORD)(sizeof(BITMAPFILEHEADER)+totalSize);
    hdr.bfReserved1 = 0;
    hdr.bfReserved2 = 0;
    hdr.bfOffBits = (DWORD)(sizeof(BITMAPFILEHEADER) +
                            sizeof(BITMAPINFOHEADER) +
                            psize);
    CFileDialog fd(FALSE, "dib", "*.dib",
                   OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
                   "Bitmaps (*.dib)|*.dib|All Files (*.*)|*.*||", NULL);
    if (fd.DoModal() == IDOK)
    {   FILE *out = fopen(fd.GetPathName(), "wb");
        if (out != NULL)
        {   fwrite((void *)&hdr, sizeof(BITMAPFILEHEADER), 1, out);
            fwrite(pbmi, totalSize, 1, out);
            fclose(out);
        }
    }
    ::GlobalUnlock(hpbmi);
    ::GlobalFree(hpbmi);
}

void CGraphicsWindow::OnPrint()
{
    CPrintDialog pd(FALSE);
    if (pd.DoModal() != IDOK) return;
    CDC PrintDC;
    if (PrintDC.CreateDC(pd.GetDriverName(), pd.GetDeviceName(),
                         pd.GetPortName(), NULL))
    {   int printWidth = PrintDC.GetDeviceCaps(HORZRES),
            printHeight = PrintDC.GetDeviceCaps(VERTRES);
// Also get the size of the print area in mm.
        int sizeX = PrintDC.GetDeviceCaps(HORZSIZE),
            sizeY = PrintDC.GetDeviceCaps(VERTSIZE);
// I will ensure that the height-to-width ratio of the printed image matches
// that of the screen image. In doing that I am going to ASSUME that screen
// pixels are square, but I will allow for printers that have different
// resolutions in the two directions, eg 600x300 dpi ones. This involves a
// curious mixture of calculations in millimetres and in pixels.
        int w = (graphicsHeight*sizeX)/graphicsWidth;
        if (w <= sizeY) printHeight = (w*printHeight)/sizeY;
        else
        {   w = (graphicsWidth*sizeY)/graphicsHeight;
            printWidth = (w*printWidth)/sizeX;
        }
        DOCINFO DocInfo;
        DocInfo.cbSize = sizeof(DOCINFO);
        DocInfo.lpszDocName = "Reduce 3.6 Graphics";
        DocInfo.lpszOutput = NULL;
        if (PrintDC.StartDoc(&DocInfo) != -1)
        {
            PrintDC.StartPage();
// This will paint the image in the top left-hand corner of the page. It
// should either be full width across the page or full height down the page,
// depending on the shape on the screen version.
            PaintOrPrint(&PrintDC, NULL, printWidth, printHeight, NULL, NULL);
            PrintDC.SelectStockObject(BLACK_PEN);
            PrintDC.EndPage();
            PrintDC.EndDoc();
        }
    }
    GlobalFree(pd.m_pd.hDevMode);
    GlobalFree(pd.m_pd.hDevNames);
}

void CGraphicsWindow::OnCopy()
{
    int totalSize, psize;
    HGLOBAL hpbmi = PaintBitmap(&totalSize, &psize);
    if (this->OpenClipboard())
    {   ::EmptyClipboard();
        ::SetClipboardData(CF_DIB, hpbmi);
        ::CloseClipboard();
    }
}

void CGraphicsWindow::OnClear()
{
    DisplayMsg("Graphics Window OnClear");
    Invalidate();
}

void CGraphicsWindow::OnRedraw()
{
    Invalidate();
}

void CGraphicsWindow::OnViewpoint()
{
    viewpointWindow.ShowWindow(viewpointShown ? SW_HIDE : SW_SHOW);
    viewpointShown = !viewpointShown;
    if (viewpointShown)
    {   viewpointWindow.Invalidate();
        fullyRendered = 1;
    }
    else if (wirePreview && !fullyRendered) Invalidate();
    GetMenu()->CheckMenuItem(IDM_VIEWPOINT,
            MF_BYCOMMAND | (viewpointShown ? MF_CHECKED : MF_UNCHECKED));
}

void CGraphicsWindow::OnViewpoint1(UINT a, LONG b)
{
    OnViewpoint();
}

void CGraphicsWindow::OnWireframe()
{
    drawWire = !drawWire;
    GetMenu()->CheckMenuItem(IDM_WIREFRAME,
        (drawWire ? MF_CHECKED : MF_UNCHECKED) | MF_BYCOMMAND);
    Invalidate();
}


void CGraphicsWindow::OnNoSurface()
{
    drawSurface = IDM_NOSURFACE;
    GetMenu()->CheckMenuItem(IDM_NOSURFACE, MF_CHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SURFACE,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SQUARES,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_TRIANGLES, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SMOOTH,    MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_HISMOOTH,  MF_UNCHECKED | MF_BYCOMMAND);
    if (!drawWire) OnWireframe();
    else Invalidate();
}


void CGraphicsWindow::OnSurface()
{
    drawSurface = IDM_SURFACE;
    GetMenu()->CheckMenuItem(IDM_NOSURFACE, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SURFACE,   MF_CHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SQUARES,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_TRIANGLES, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SMOOTH,    MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_HISMOOTH,  MF_UNCHECKED | MF_BYCOMMAND);
    if (!drawWire) OnWireframe();
    else Invalidate();
}


void CGraphicsWindow::OnSquares()
{
    drawSurface = IDM_SQUARES;
    GetMenu()->CheckMenuItem(IDM_NOSURFACE, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SURFACE,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SQUARES,   MF_CHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_TRIANGLES, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SMOOTH,    MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_HISMOOTH,  MF_UNCHECKED | MF_BYCOMMAND);
    Invalidate();
}


void CGraphicsWindow::OnTriangles()
{
    drawSurface = IDM_TRIANGLES;
    GetMenu()->CheckMenuItem(IDM_NOSURFACE, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SURFACE,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SQUARES,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_TRIANGLES, MF_CHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SMOOTH,    MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_HISMOOTH,  MF_UNCHECKED | MF_BYCOMMAND);
    Invalidate();
}


void CGraphicsWindow::OnSmooth()
{
    drawSurface = IDM_SMOOTH;
    GetMenu()->CheckMenuItem(IDM_NOSURFACE, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SURFACE,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SQUARES,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_TRIANGLES, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SMOOTH,    MF_CHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_HISMOOTH,  MF_UNCHECKED | MF_BYCOMMAND);
    Invalidate();
}


void CGraphicsWindow::OnHiSmooth()
{
    drawSurface = IDM_HISMOOTH;
    GetMenu()->CheckMenuItem(IDM_NOSURFACE, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SURFACE,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SQUARES,   MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_TRIANGLES, MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_SMOOTH,    MF_UNCHECKED | MF_BYCOMMAND);
    GetMenu()->CheckMenuItem(IDM_HISMOOTH,  MF_CHECKED | MF_BYCOMMAND);
    Invalidate();
}


void CGraphicsWindow::OnWirePreview()
{
    wirePreview = !wirePreview;
    GetMenu()->CheckMenuItem(IDM_WIREPREVIEW,
        (wirePreview ? MF_CHECKED : MF_UNCHECKED) | MF_BYCOMMAND);
    if (!wirePreview && !fullyRendered) Invalidate();
}


void CGraphicsWindow::OnRotLeft()
{
}


void CGraphicsWindow::OnRotRight()
{
}


void CGraphicsWindow::OnRotUp()
{
}


void CGraphicsWindow::OnRotDown()
{
}


void CGraphicsWindow::OnClockwise()
{
}


void CGraphicsWindow::OnAntiClockwise()
{
}


void CGraphicsWindow::OnEnlarge()
{
}


void CGraphicsWindow::OnShrink()
{
}

#endif

// end of c_graph.cpp

