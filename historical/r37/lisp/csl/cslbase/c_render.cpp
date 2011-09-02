// c_render.cpp
//     Drawing code for the graphics window
//     Copyright (C)/©/¸ Codemist Ltd, 1995-2001


/* Signature: 66b0240a 08-Apr-2002 */


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


#ifdef GRAPHICS_WINDOW

#include "cwin.hpp"

// I have two serious concerns here. The first is the amount of space needed
// to store descriptions of objects that I might draw. The second is the
// potential performance-bottleneck of floating point arithmetic on many
// PCs.  To try to alleviate these difficulties I will do much of my work
// using fixed point arithmetic and with data packed into 16-bit fields
// in structures.

// I will store 3D points (after rotation and so on) with X and Y
// coordinates in the range 0 to 64K, and I will translate & clip this
// so that objects at (0x8000, 0x8000) appear in the middle of my screen.
// But I will leave myself a full range of integers for the Z coordinate
// so that I do not have to worry so much about fine-tuning the
// transformations I use in that respect.
// The odd-looking range for X and Y is so I can use unsigned bitfield
// components in the following structure.

// If I want to do Phong shading at some stage (that puts nice highlights
// onto rendered surfaces) I should extend the representation of an
// XYZPoint to include a surface normal. It should be enough to use 10
// bits for each of the three direction cosines, since I do not have
// that many bits of discrimination in my control over display brightness.
// I put the field in now so that using it later on will be easy, but
// will probably not fill in the values to start with. Note that the
// direction cosines need to be signed fields, so I should normalise them
// to the range -511 to +511 (nb NOT 512).  The typedef is in my main
// header file but is replicated here to make it easier to read this code.

//--   typedef struct tagXYZPoint
//--   {
//--       unsigned int x:16;
//--       unsigned int y:16;
//--       int z;
//--       signed int nx:10, ny:10, nz:10;
//--       unsigned int red:8, green:8, blue:8, spare:8;
//--   } XYZPoint;

// I will build up images out of triangles. When I need a rectangle or
// bigger polygon I will just split it into triangles. I will assume that
// all the vertices I will ever use have been stored in a linear array
// of type XYZPoint[].
// A triangle is then represented as a triple of XYZPoints each denoted
// by their index values in the array, say v1, v2, v3.
// The vertices should be listed in clockwise when viewed from the "outside"
// of the object, and if pairs of triangles are used to form rectangles
// then the diagonal of the rectangle should be given as the first pair of
// vertices.
// When a triangle is drawn some or all of its edges can be drawn in with
// a pen that will often have a contrasting colour to that used for the
// interior of the cell. The need to have only SOME edges drawn in this
// way arises when larger polygons have been split into multiple triangles
// for processing - the edges of the original polygon may need drawing but
// synthetic interior joins do not. The three flag bits edge1, edge2 and
// edge3 are used to control which (if any) edges get drawn. All edges
// in an entire figure will end up drawn in the same colour: no provision is
// made for giving all the edges their own separate colours.
//***** What follows has not been implemented yet *****
// So that axes and other line-art can be included there is special support
// for straight line "triangles". These have the flag "lineflag" set and then
// do not need to use vertex3, which should be set equal to vertex2.
// A record with lineflag set represents a straight line segment from vertex1
// to vertex2. If edge1 is set it is drawn in the outline colour (as used for
// edges of proper triangles) while otherwise it uses its own R-G-B colour.
// If vertex1 is equal to vertex2 when lineflag is set then the record would
// appear to represent a point (and vertex3 will be equal to vertex1 and
// vertex2). I am inclined to believe that I do not want to draw individual
// points.


typedef struct tagTriangle
{   // Observe that each line packs to just 16 bits.
    // At present I leave 15 bits spare! I used to keep a colour in
    // that slot but now I keep colous with vertices not faces, so do
    // not need that space.
    unsigned int lineflag:1, moved:1, spare:14;
    unsigned int edge1:1, vertex1:15;
    unsigned int edge2:1, vertex2:15;
    unsigned int edge3:1, vertex3:15;
} Triangle;

// The above layout has several uncomfortable limitations. Perhaps the
// most obvious is that it can only handle 32K points. This represents
// a grid 180 by 180. A brief experiment with "gnuplot" suggests that it
// runs out of space well before that, and many plots I have seen demonstrated
// use a grid that is more like 20 by 20,  The examples in the Jenks and
// Sutor book on Axiom have their most impressive pictures using under
// 25K vertices (a bit tight....) and I think that only their fractal
// images (eg Antoine's Necklace) would defeat the structure I have here.
// I could keep my triangle records the same size but allow for up to
// about 1000000 vertices by packing vertex numbers in a way that would
// cross word boundaries. I will consider that possibility later on.



// I will do a somewhat crude job clipping triangles that do not intersect
// the part of the screen that is being re-drawn.
// I will also assume that triangles never intersect, so a version
// of the painter's algorithm will do for rendering.


XYZPoint *points;
Triangle *triangles;
int triangleCount = 0;

#define x_steps 27
#define y_steps 29

XYZPoint vertices[(x_steps+1)*(y_steps+1)];

Triangle faces[x_steps*y_steps*2];

// I will want to colour faces based on their Z coordinate or some other
// parameter. The following function maps an integer into a colour in
// such a way that increasing the integer leads to a sequence of colours
// that cycles through the rainbow and then back from blue to red via
// magenta.

void selectColour(int z, int &red, int &green, int &blue)
{
    while (z < 0) z += (6*255)*0x00100000;
    z = z % (6*255);
    switch (z / 255)
    {
case 0: red = 255;
        green = z % 255;
        blue = 0;
        return;
case 1: red = 255 - z % 255;
        green = 255;
        blue = 0;
        return;
case 2: red = 0;
        green = 255;
        blue = z % 255;
        return;
case 3: red = 0;
        green = 255 - z % 255;
        blue = 255;
        return;
case 4: red = z % 255;
        green = 0;
        blue = 255;
        return;
case 5: red = 255;
        green = 0;
        blue = 255 - z % 255;
        return;
    }
}

// The "raw data" section of this code is really for debugging purposes only
// and will need to be replaced by something that can accept surface
// specifications from some external source.

typedef struct tagRealPoint
{
    double x, y, z;
} RealPoint;

RealPoint rawData[x_steps+1][y_steps+1];

CBrush thirtyTwoBrushes[32];

void initRawData()
{
    int x, y;
    for (x=0; x<=x_steps; x++)
    {   double rx = (6.0*(double)x)/(double)x_steps - 3.0;
        for (y=0; y<=y_steps; y++)
        {   int n = x+(x_steps+1)*y;
            double ry = (6.0*(double)y)/(double)y_steps - 3.0;
            double rz = 3.0*cos(3.0*sqrt(rx*rx+ry*ry));
            rawData[x][y].x = rx;
            rawData[x][y].y = ry;
            rawData[x][y].z = rz;
        }
    }
    for (int i=0; i<32; i++)
    {   int red, green, blue;
        selectColour((255*6*i)/32, red, green, blue);
        thirtyTwoBrushes[i].CreateSolidBrush(RGB(red, green, blue));
    }
}

static doneInit = 0;

// I truncate at 2^30 because that is slightly easier than using the
// whole of the integer range, and the cases where it makes a difference
// will not arise very often.

#define IntegerRange 1073741824.0  // 2^30

void CGraphicsWindow::initSurface()
{
    if (doneInit == 0)
    {   initRawData();
        doneInit = 1;
    }
    int x, y, sx, sy;
    points = vertices;
    for (x=0; x<=x_steps; x++)
    {   for (y=0; y<=y_steps; y++)
        {   int n = x+(x_steps+1)*y;
            double rx = rawData[x][y].x;
            double ry = rawData[x][y].y;
            double rz = rawData[x][y].z;
            double aw = xform[3][3];
            double ax = (xform[0][0]*rx+xform[1][0]*ry+xform[2][0]*rz+xform[3][0])/aw;
            double ay = (xform[0][1]*rx+xform[1][1]*ry+xform[2][1]*rz+xform[3][1])/aw;
            double az = (xform[0][2]*rx+xform[1][2]*ry+xform[2][2]*rz+xform[3][2])/aw;
            double rw = perspecDistance/(perspecDistance - az);
            ax *= rw;
            ay *= rw;

            if (ax < -IntegerRange) sx = 0;
            else if (ax > IntegerRange) sx = 0xffff;
            else sx = 0x8000+(int)ax;
            if (sx < 0) sx = 0; else if (sx > 0xffff) sx = 0xffff;
            points[n].x = sx;

            if (ay < -IntegerRange) sy = 0;
            else if (ay > IntegerRange) sy = 0xffff;
            else sy = 0x8000+(int)ay;
            if (sy < 0) sy = 0; else if (sy > 0xffff) sy = 0xffff;
            points[n].y = sy;

            if (az < -IntegerRange) az = -IntegerRange;
            else if (az > IntegerRange) az = IntegerRange;
            points[n].z = (int)az;

            int red, green, blue;
            selectColour((int)(400.0*rz), red, green, blue);
            points[n].red = red;
            points[n].green = green;
            points[n].blue = blue;
            points[n].spare = 0xff & (int)(100*rz);
        }
    }
    triangles = faces;
    triangleCount = 0;
    for (x=0; x<x_steps; x++)
    {   for (y=0; y<y_steps; y++)
        {   int n = x+(x_steps+1)*y;
// I set things up here so that edges 1 and 2 of each triangle are the
// ones that form the diagonal of the rectangle that is being divided. I
// do this so that it is at least partially reasonable to select a colour
// for the whole of a triangle by averaging these...
            triangles[triangleCount].lineflag = 0;
            triangles[triangleCount].edge1 = 0;
            triangles[triangleCount].edge2 = 1;
            triangles[triangleCount].edge3 = 1;
            triangles[triangleCount+1].lineflag = 0;
            triangles[triangleCount+1].edge1 = 0;
            triangles[triangleCount+1].edge2 = 1;
            triangles[triangleCount+1].edge3 = 1;
// Note I make the triangles clockwise here
            int x1 = points[n].x, y1 = points[n].y, z1 = points[n].z;
            int x2 = points[n+1].x, y2 = points[n+1].y, z2 = points[n+1].z;
            int x3 = points[n+x_steps+1].x, y3 = points[n+x_steps+1].y, z3 = points[n+x_steps+1].z;
            int x4 = points[n+x_steps+2].x, y4 = points[n+x_steps+2].y, z4 = points[n+x_steps+2].z;
            int d1 = x4-x1, d2 = y4-y1, d3 = z4-z1;
            int d4 = x3-x2, d5 = y3-y2, d6 = z3-z2;
            if (d1*d1+d2*d2+d3*d3 >= d4*d4+d5*d5+d6*d6)
            {   triangles[triangleCount].vertex1 = n + x_steps + 1;
                triangles[triangleCount].vertex2 = n + 1;
                triangles[triangleCount].vertex3 = n;
                triangles[triangleCount+1].vertex1 = n + 1;
                triangles[triangleCount+1].vertex2 = n + x_steps + 1;
                triangles[triangleCount+1].vertex3 = n + x_steps + 2;
            }
            else
            {   triangles[triangleCount].vertex1 = n + x_steps + 2;
                triangles[triangleCount].vertex2 = n;
                triangles[triangleCount].vertex3 = n + x_steps + 1;
                triangles[triangleCount+1].vertex1 = n;
                triangles[triangleCount+1].vertex2 = n + x_steps + 2;
                triangles[triangleCount+1].vertex3 = n + 1;
            }
            triangleCount += 2;
        }
    }
    sortTriangles();
}

int triangleLeft(const Triangle *a)
{
    int w, r;
    r = points[a->vertex1].x;
    if ((w = points[a->vertex2].x) < r) r = w;
    if ((w = points[a->vertex3].x) < r) r = w;
    return r;
}

int triangleRight(const Triangle *a)
{
    int w, r;
    r = points[a->vertex1].x;
    if ((w = points[a->vertex2].x) > r) r = w;
    if ((w = points[a->vertex3].x) > r) r = w;
    return r;
}

int triangleBottom(const Triangle *a)
{
    int w, r;
    r = points[a->vertex1].y;
    if ((w = points[a->vertex2].y) < r) r = w;
    if ((w = points[a->vertex3].y) < r) r = w;
    return r;
}

int triangleTop(const Triangle *a)
{
    int w, r;
    r = points[a->vertex1].y;
    if ((w = points[a->vertex2].y) > r) r = w;
    if ((w = points[a->vertex3].y) > r) r = w;
    return r;
}

int triangleFar(const Triangle *a)
{
    int w, r;
    r = points[a->vertex1].z;
    if ((w = points[a->vertex2].z) < r) r = w;
    if ((w = points[a->vertex3].z) < r) r = w;
    return r;
}

int triangleNear(const Triangle *a)
{
    int w, r;
    r = points[a->vertex1].z;
    if ((w = points[a->vertex2].z) > r) r = w;
    if ((w = points[a->vertex3].z) > r) r = w;
    return r;
}

int orderTriangles(const void *va, const void *vb)
{
    int za = triangleFar((const Triangle *)va);
    int zb = triangleFar((const Triangle *)vb);
    if (za < zb) return -1;
    else if (za > zb) return 1;
    else return 0;
}

// The next function returns 1 is the line (a1-a2) lies above (and thus
// obscures) the line (b1-b2), or -1 if there is an obscuring that goes
// the other way.

int linesCross(XYZPoint *a1, XYZPoint *a2, XYZPoint *b1, XYZPoint *b2)
{
// Firstly I will discard all cases where the line segments are not incident.
    int l1 = a1->y-a2->y, m1 = a2->x-a1->x, n1 = a1->x*a2->y-a2->x*a1->y;
    int u1 = l1*b1->x+m1*b1->y+n1, u2 = l1*b2->x+m1*b2->y+n1;
    if (u1 >= 0 && u2 >= 0) return 0;
    if (u1 <= 0 && u2 <= 0) return 0;
    int l2 = b1->y-b2->y, m2 = b2->x-b1->x, n2 = b1->x*b2->y-b2->x*b1->y;
    int v1 = l2*a1->x+m2*a1->y+n2, v2 = l2*a2->x+m2*a2->y+n2;
    if (v1 >= 0 && v2 >= 0) return 0;
    if (v1 <= 0 && v2 <= 0) return 0;
// Now I know that the line segments cross in their XY projections, so I
// compute the Z coordinates of the intersection.
    double z1 = ((double)v1*(double)a2->z-(double)v2*(double)a1->z)/
                (double)(v1-v2);
    double z2 = ((double)u1*(double)b2->z-(double)u2*(double)b1->z)/
                (double)(u1-u2);
    if (z1 > z2) return 1;
    if (z1 < z2) return -1;
// The position here is possibly nasty - the two triangles DO overlap, but
// at the point where the edges cross they have the same distance. I should
// do something more here, but that can come later on.
    return 0;
}

int insideTriangle(XYZPoint *a, XYZPoint *b1, XYZPoint *b2, XYZPoint *b3)
{
// place-holder
    return 0;
}

int triangleObscures(Triangle *a, Triangle *b)
{
    XYZPoint *a1 = &points[a->vertex1],
             *a2 = &points[a->vertex2],
             *a3 = &points[a->vertex3];
    XYZPoint *b1 = &points[b->vertex1],
             *b2 = &points[b->vertex2],
             *b3 = &points[b->vertex3];
    int v;
    if ((v = linesCross(a1, a2, b1, b2)) != 0) return (v > 0);
    if ((v = linesCross(a1, a2, b2, b3)) != 0) return (v > 0);
    if ((v = linesCross(a1, a2, b3, b1)) != 0) return (v > 0);
    if ((v = linesCross(a2, a3, b1, b2)) != 0) return (v > 0);
    if ((v = linesCross(a2, a3, b2, b3)) != 0) return (v > 0);
    if ((v = linesCross(a2, a3, b3, b1)) != 0) return (v > 0);
    if ((v = linesCross(a3, a1, b1, b2)) != 0) return (v > 0);
    if ((v = linesCross(a3, a1, b2, b3)) != 0) return (v > 0);
    if ((v = linesCross(a3, a1, b3, b1)) != 0) return (v > 0);
    if ((v = insideTriangle(a1, b1, b2, b3)) != 0) return v;
    if ((v = insideTriangle(a2, b1, b2, b3)) != 0) return v;
    if ((v = insideTriangle(a3, b1, b2, b3)) != 0) return v;
    if ((v = insideTriangle(b1, a1, a2, a3)) != 0) return v;
    if ((v = insideTriangle(b2, a1, a2, a3)) != 0) return v;
    if ((v = insideTriangle(b3, a1, a2, a3)) != 0) return v;
    return 0;
}

// After setting up the list of triangles (which must be re-done each time
// I rotate or re-scale) I must call the following to Z-sort the data

void CGraphicsWindow::sortTriangles()
{
// First I do a simple and direct sort based on the lowest point in each
// triangle.
    qsort(triangles, triangleCount, sizeof(Triangle), orderTriangles);
// Now the ordering I am left with is NOT guaranteed adequate, since I might
// have a tall triangle whose lowest point is very low but where some
// other triangle that starts higher up is in fact underneath it where they
// happen to cross. I will do something more like an insertion sort
// now to try to fix up such cases.
    int i;
    for (i=0; i<triangleCount; i++) triangles[i].moved = 0;
    i = 0;
    while (i<triangleCount-1)
    {   int l = triangleLeft(&triangles[i]),
            r = triangleRight(&triangles[i]),
            t = triangleTop(&triangles[i]),
            b = triangleBottom(&triangles[i]),
            n = triangleNear(&triangles[i]);
        for (int j=i+1;j<triangleCount;j++)
        {   if (triangleFar(&triangles[j]) >= n) break;
            if (triangleLeft(&triangles[j]) >= r) continue;
            if (triangleRight(&triangles[j]) <= l) continue;
            if (triangleBottom(&triangles[j]) >= t) continue;
            if (triangleTop(&triangles[j]) <= b) continue;
            if (triangleObscures(&triangles[i], &triangles[j]))
            {   if (triangles[j].moved) continue;
                triangles[i].moved = 1;
                Triangle w = triangles[j];
                for (int k=j-1; k>=i; k--)
                    triangles[k+1] = triangles[k];
                triangles[i] = w;
                i--;
                break;
            }
        }
        i++;
    }
}


// Supposing that the triangles have been sorted so that the bottom-most
// one is at the front of the vector, I can just paint all the data...

void CGraphicsWindow::paintTriangles(CDC *dc, RECT *clip, int width, int height)
{
// TESTING CODE HERE
    initSurface();
 // END OF TESTING CODE
    Triangle *p = triangles;
    int i;
    for (i=0; i<triangleCount; i++, p++)
    {   BOOL lineflag = p->lineflag;
        XYZPoint *v1 = &points[p->vertex1],
                 *v2 = &points[p->vertex2],
                 *v3 = &points[p->vertex3];
        int xscale = (65536*width)/10000,
            yscale = (65536*height)/10000;
        int xoff = width/2, yoff = height/2;
        int x1 = xoff + ((((int)v1->x-32768)*xscale)>>16),
            y1 = yoff - ((((int)v1->y-32768)*yscale)>>16);
        int x2 = xoff + ((((int)v2->x-32768)*xscale)>>16),
            y2 = yoff - ((((int)v2->y-32768)*yscale)>>16);
        int x3 = xoff + ((((int)v3->x-32768)*xscale)>>16),
            y3 = yoff - ((((int)v3->y-32768)*yscale)>>16);
        if (clip != NULL)
        {   int left   = clip->left,
                top    = clip->top,
                right  = clip->right,
                bottom = clip->bottom;
            if (x1 < left && x2 < left && x3 < left) continue;
            if (x1 > right && x2 > right && x3 > right) continue;
            if (y1 < top && y2 < top && y3 < top) continue;
            if (y1 > bottom && y2 > bottom && y3 > bottom) continue;
        }
        int red1 = v1->red, green1 = v1->green, blue1 = v1->blue;
        int red2 = v2->red, green2 = v2->green, blue2 = v2->blue;
        int red3 = v3->red, green3 = v3->green, blue3 = v3->blue;
        BOOL e1 = p->edge1, e2 = p->edge2, e3 = p->edge3;
        if (fullRender || !wirePreview || !viewpointShown)
        {   if (!drawWire && drawSurface != IDM_NOSURFACE) e1 = e2 = e3 = 0;
            switch (drawSurface)
            {
        case IDM_NOSURFACE:
                break;
        case IDM_SURFACE:
                {   CBrush *b = &thirtyTwoBrushes[v1->spare & 0x1f];
                    POINT tri[3];
                    tri[0].x = x1; tri[0].y = y1;
                    tri[1].x = x2; tri[1].y = y2;
                    tri[2].x = x3; tri[2].y = y3;
                    dc->SelectObject(b);
                    dc->SelectStockObject(NULL_PEN);
                    dc->Polygon(tri, 3);
                    dc->SelectStockObject(BLACK_BRUSH);
                    break;
                }
        case IDM_SQUARES:
                {   CBrush b(RGB((red1+red2)/2, (green1+green2)/2, (blue1+blue2)/2));
                    POINT tri[3];
                    tri[0].x = x1; tri[0].y = y1;
                    tri[1].x = x2; tri[1].y = y2;
                    tri[2].x = x3; tri[2].y = y3;
                    dc->SelectObject(&b);
                    dc->SelectStockObject(NULL_PEN);
                    dc->Polygon(tri, 3);
                    dc->SelectStockObject(BLACK_BRUSH);
                    break;
                }
        case IDM_TRIANGLES:
                {   CBrush b(RGB((red1+red2+red3)/3,
                                 (green1+green2+green3)/3,
                                 (blue1+blue2+blue3)/3));
                    POINT tri[3];
                    tri[0].x = x1; tri[0].y = y1;
                    tri[1].x = x2; tri[1].y = y2;
                    tri[2].x = x3; tri[2].y = y3;
                    dc->SelectObject(&b);
                    dc->SelectStockObject(NULL_PEN);
                    dc->Polygon(tri, 3);
                    dc->SelectStockObject(BLACK_BRUSH);
                    break;
                }
        case IDM_SMOOTH:
                dc->SelectStockObject(NULL_PEN);
                SubTriangle(dc, x1, y1, red1, green1, blue1,
                                x2, y2, red2, green2, blue2,
                                x3, y3, red3, green3, blue3, 2);
                break;
        case IDM_HISMOOTH:
                dc->SelectStockObject(NULL_PEN);
                SubTriangle(dc, x1, y1, red1, green1, blue1,
                                x2, y2, red2, green2, blue2,
                                x3, y3, red3, green3, blue3, 4);
                break;
            }
        }
        if (e1 && e3)
        {   dc->SelectStockObject(BLACK_PEN);
            dc->MoveTo(x3, y3);
            dc->LineTo(x1, y1);
            dc->LineTo(x2, y2);
            if (e2) dc->LineTo(x3, y3);
        }
        else if (e1)
        {   dc->SelectStockObject(BLACK_PEN);
            dc->MoveTo(x1, y1);
            dc->LineTo(x2, y2);
            if (e2) dc->LineTo(x3, y3);
        }
        else if (e2)
        {   dc->SelectStockObject(BLACK_PEN);
            dc->MoveTo(x2, y2);
            dc->LineTo(x3, y3);
            if (e3) dc->LineTo(x1, y1);
        }
        else if (e3)
        {   dc->SelectStockObject(BLACK_PEN);
            dc->MoveTo(x3, y3);
            dc->LineTo(x1, y1);
        }
    }
    if (!GetUpdateRect(NULL, FALSE))
    {   fullyRendered = fullRender;
        fullRender = 0;
    }
}

#endif

// end of c_render.cpp
