/*
 * "showmem.c"        A C Norman,               1996-2007
 *
 * This program processes a "memory.use" log file created by CSL
 * in a variant compiled with MEMORY_TRACE defined. It displays the
 * memory use map and allows the user to zoom in using I and out using
 * O, move left, right, up or down.  V redraws viewing just the box.
 * A "." input resets the image.  The numbers displayed at the top left
 * are as for use with "-m" in a CSL command line to provoke an exception
 * when a memory reference in the box is first seen.
 *
 * This code uses the Watcom graphics library, so is DOS specific. Furthermore
 * it is coded assuming you have a monitor suitable for 1024*768 in
 * 256 colours.
 */

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


/* Signature: 7e3ca32b 18-Jan-2007 */

#include <conio.h>
#include <graph.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *f = fopen("memory.use", "rb");
    int c, c1, c2, len, col, nrecords;
    int x, y, done;
    double x1, y1, x2, y2, w;
    double ox1, oy1, ox2, oy2;
    int sx, sy;
    unsigned i;
    int zeros = 0, ones=0, onebyte = 0, twobyte = 0, threebyte = 0;
    char buffer[100];
    double a00, a01, a02, a10, a11, a12;
    long int filepos;

    if (f == NULL) return 1;
    
    nrecords = getc(f) & 0xff;
    nrecords = nrecords + ((getc(f) & 0xff) << 8);
    nrecords = nrecords + ((getc(f) & 0xff) << 16);

    len = getc(f) & 0xff;
    len = len + ((getc(f) & 0xff) << 8);
    len = len + ((getc(f) & 0xff) << 16);

    a00 = 1020.0/(double)nrecords;     a01 = 0.0;  a02 = 2.0;
    a10 = 0.0;     a11 = -760.0/(2.0*(double)len);  a12 = 768.0-4.0;
    x1 = 0.0; y1 = 0.0; x2 = (double)nrecords; y2 = 2.0*(double)len;
    
#define X(x,y) ((int)(a00*x+a01*y+a02))
#define Y(x,y) ((int)(a10*x+a11*y+a12))

    filepos = ftell(f);
    _setvideomode(_XRES256COLOR);  /* 1024 * 768 */

repaint:
    _clearscreen(_GCLEARSCREEN);
    _setcolor(15);
    _settextposition(2, 2);
    sprintf(buffer, "%d:%d:%d              ", 0x400*(int)x1, (int)y1, (int)y2);
    _outtext(buffer);
    _rectangle(_GBORDER, X(x1,y1), Y(x1,y1), X(x2,y2), Y(x2,y2));

    fseek(f, filepos, SEEK_SET);

    for (x=0; ; x++)
    {   col = 0;
        c = kbhit();
        if (c != 0) break;
        for (;;)
        {   c = getc(f);
            if (c == EOF) break;
            if ((c & 0x80) == 0)
            {   if (c == 0) zeros++;
                else if (c == 1) ones++;
                onebyte++;
                col += c;
            }
            else if ((c & 0x40) == 0)
            {   c1 = getc(f) & 0xff;
                if (c1 == 0)
                {   if (c == 0x80) break;  /* end of line code */
                    col += 0x400000*(c & 0x3f);
                    continue;
                }
                col += (c & 0x3f) + (c1 << 6);
                twobyte++;
            }
            else
            {   c1 = getc(f) & 0xff;
                c2 = getc(f) & 0xff;
                c = (c & 0x3f) + (c1 << 6) + (c2 << 14);
                if (c < 0x40)
                {   if (c == 0) c = 30;
                    else if (c == 16) c = 31;
                    _setcolor(c);
                    continue;
                }
                col += c;
                threebyte++;
            }
            sx = X(x, col);
            if (sx >= 0 && sx < 1024)
            {   sy = Y(x, col);
                if (sy >= 0 && sy < 768) _setpixel(X(x,col), Y(x,col));
            }
        }
        if (c == EOF) break;
    }
    
    done = 0;
    while (!done)
    {   ox1 = x1, oy1 = y1;
        ox2 = x2, oy2 = y2;
        switch (tolower(getch()))
        {
    case 'q':
            done = 1;
            continue;
    case '.':
            x1 = 0.0; y1 = 0.0; x2 = (double)nrecords; y2 = 2.0*(double)len;
            if (a00 != 1020.0/(double)nrecords ||
                a01 != 0.0 ||
                a02 != 2.0 ||
                a10 != 0.0 ||
                a11 != -760.0/(2.0*(double)len) ||
                a12 != 768.0-4.0)
            {   a00 = 1020.0/(double)nrecords;     a01 = 0.0;  a02 = 2.0;
                a10 = 0.0;     a11 = -760.0/(2.0*(double)len);  a12 = 768.0-4.0;
                goto repaint;
            }
            break;
    case 'u':
            w = (y2 - y1)/2.0;
            y1 += w;
            y2 += w;
            break;
    case 'd':
            w = (y2 - y1)/2.0;
            y1 -= w;
            y2 -= w;
            break;
    case 'l':
            w = (x2 - x1)/2.0;
            x1 -= w;
            x2 -= w;
            break;
    case 'r':
            w = (x2 - x1)/2.0;
            x1 += w;
            x2 += w;
            break;
    case 'i':
            w = (y2 - y1)/10.0;
            y1 += w;
            y2 -= w;
            w = (x2 - x1)/10.0;
            x1 += w;
            x2 -= w;
            break;
    case 'o':
            w = (y2 - y1)/10.0;
            y1 -= w;
            y2 += w;
            w = (x2 - x1)/10.0;
            x1 -= w;
            x2 += w;
            break;
    case 'n':
            w = (x2 - x1)/10.0;
            x1 += w;
            x2 -= w;
            break;
    case 'w':
            w = (x2 - x1)/10.0;
            x1 -= w;
            x2 += w;
            break;
    case 'v':
            a00 = -1018.0/(x1-x2);
            a10 = 0.0;
            a02 = 2.0*(510.0*x1 - x2)/(x1-x2);
            a10 = 0.0;
            a11 = 760.0/(y1-y2);
            a12 = 4.0*(y1 - 191.0*y2)/(y1-y2);
            goto repaint;
        }
        _setplotaction(_GXOR);
        _setcolor(15);
        _rectangle(_GBORDER, X(ox1,oy1), Y(ox1,oy1), X(ox2,oy2), Y(ox2,oy2));
        _settextposition(2, 2);
        sprintf(buffer, "%d:%d:%d              ", 0x400*(int)x1, (int)y1, (int)y2);
        _outtext(buffer);
        _rectangle(_GBORDER, X(x1,y1), Y(x1,y1), X(x2,y2), Y(x2,y2));
        _setplotaction(_GPSET);
    }

    _setvideomode(_DEFAULTMODE);
    printf("len = %d bits, Max x was %d, nrecords = %d = %x\n",
           2*len, x, nrecords, nrecords);
    printf("zeros=%d ones=%d onebyte=%d twobyte=%d threebyte=%d\n",
           zeros, ones, onebyte, twobyte, threebyte);
    return 0;
}

/* end of showmem.c */
