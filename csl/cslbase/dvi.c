#include <stdio.h>
#include <stdint.h>

// I have a generated file that contains the widths of all the fonts
// I am willing to use here.

#include "cmfont-widths.c"


/*
 * This is the ".dvi" file created by running LaTeX on the following
 * small input file. It is provided as a sequence of hex bytes so that
 * I have something to test and demonstrate even if there is no file
 * containig any .dvi stuff readily available.
 *
 *  \documentclass{article}
 *  \begin{document}
 *  This is some text
 *  \[ \frac{- b \pm \sqrt{b^2 - 4ac}}{2a}\]
 *  end text
 *  \end{document}
 */

unsigned char math_dvi[] =
{
    0xf7,  0x02,  0x01,  0x83,  0x92,  0xc0,  0x1c,  0x3b,  
    0x00,  0x00,  0x00,  0x00,  0x03,  0xe8,  0x1b,  0x20,  
    0x54,  0x65,  0x58,  0x20,  0x6f,  0x75,  0x74,  0x70,  
    0x75,  0x74,  0x20,  0x32,  0x30,  0x31,  0x30,  0x2e,  
    0x31,  0x31,  0x2e,  0x30,  0x35,  0x3a,  0x32,  0x30,  
    0x33,  0x33,  0x8b,  0x00,  0x00,  0x00,  0x01,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  0x00,  
    0x00,  0x00,  0x00,  0xff,  0xff,  0xff,  0xff,  0xa0,  
    0x02,  0x79,  0x00,  0x00,  0x8d,  0xa0,  0xfd,  0xa3,  
    0x00,  0x00,  0xa0,  0x02,  0x3f,  0x00,  0x00,  0x8d,  
    0xa0,  0xfd,  0xe4,  0x00,  0x00,  0x8d,  0x91,  0x4d,  
    0x00,  0x00,  0xf3,  0x07,  0x4b,  0xf1,  0x60,  0x79,  
    0x00,  0x0a,  0x00,  0x00,  0x00,  0x0a,  0x00,  0x00,  
    0x00,  0x05,  0x63,  0x6d,  0x72,  0x31,  0x30,  0xb2,  
    0x54,  0x68,  0x69,  0x73,  0x96,  0x03,  0x55,  0x55,  
    0x69,  0x73,  0x93,  0x73,  0x6f,  0x6d,  0x65,  0x93,  
    0x74,  0x65,  0x78,  0x74,  0x8e,  0x9f,  0x10,  0xe5,  
    0xfb,  0x8d,  0x8d,  0x8d,  0x8d,  0x9f,  0xf9,  0x3c,  
    0x24,  0x8d,  0x92,  0x00,  0xc8,  0x61,  0x7e,  0xf3,  
    0x0d,  0x21,  0x22,  0x2c,  0x9a,  0x00,  0x0a,  0x00,  
    0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  
    0x6d,  0x73,  0x79,  0x31,  0x30,  0xb8,  0x00,  0xf3,  
    0x0a,  0x0b,  0xa0,  0x62,  0x3e,  0x00,  0x0a,  0x00,  
    0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  
    0x6d,  0x6d,  0x69,  0x31,  0x30,  0xb5,  0x62,  0x96,  
    0x02,  0x38,  0xe0,  0xb8,  0x06,  0x8d,  0x8d,  0x93,  
    0x9f,  0xf7,  0xaa,  0xab,  0x70,  0x8e,  0x8d,  0x91,  
    0x0a,  0x8e,  0x37,  0x9f,  0xf7,  0xaa,  0xab,  0x89,  
    0x00,  0x00,  0x66,  0x65,  0x00,  0x23,  0x9d,  0x07,  
    0x9f,  0x08,  0x55,  0x55,  0x8d,  0xb5,  0x62,  0x8d,  
    0x9f,  0xfd,  0x1c,  0x72,  0xf3,  0x06,  0xd9,  0x93,  
    0xa0,  0x52,  0x00,  0x07,  0x00,  0x00,  0x00,  0x07,  
    0x00,  0x00,  0x00,  0x04,  0x63,  0x6d,  0x72,  0x37,  
    0xb1,  0x32,  0x8e,  0x91,  0x06,  0xb5,  0x53,  0xb8,  
    0x00,  0x93,  0xb2,  0x34,  0xb5,  0x61,  0x63,  0x8e,  
    0x8e,  0x8e,  0x8e,  0x92,  0x00,  0xc8,  0x61,  0x7e,  
    0x9f,  0x04,  0x77,  0x0e,  0x89,  0x00,  0x00,  0x66,  
    0x65,  0x00,  0x44,  0x3d,  0x04,  0x9f,  0x09,  0x28,  
    0xd6,  0x8d,  0x91,  0x1c,  0xf9,  0xea,  0xb2,  0x32,  
    0xb5,  0x61,  0x8e,  0x8e,  0x8e,  0x8e,  0x8e,  0x9f,  
    0x14,  0xcd,  0xd0,  0x8d,  0x91,  0x3e,  0x00,  0x00,  
    0xb2,  0x65,  0x6e,  0x64,  0x91,  0x03,  0x55,  0x55,  
    0x74,  0x65,  0x78,  0x74,  0x8e,  0x8e,  0x9f,  0x1e,  
    0x00,  0x00,  0x8d,  0x92,  0x00,  0xe8,  0x00,  0x00,  
    0x31,  0x8e,  0x8e,  0x8c,  0xf8,  0x00,  0x00,  0x00,  
    0x2a,  0x01,  0x83,  0x92,  0xc0,  0x1c,  0x3b,  0x00,  
    0x00,  0x00,  0x00,  0x03,  0xe8,  0x02,  0x79,  0x00,  
    0x00,  0x01,  0x97,  0x00,  0x00,  0x00,  0x0b,  0x00,  
    0x01,  0xf3,  0x0d,  0x21,  0x22,  0x2c,  0x9a,  0x00,  
    0x0a,  0x00,  0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  
    0x06,  0x63,  0x6d,  0x73,  0x79,  0x31,  0x30,  0xf3,  
    0x0a,  0x0b,  0xa0,  0x62,  0x3e,  0x00,  0x0a,  0x00,  
    0x00,  0x00,  0x0a,  0x00,  0x00,  0x00,  0x06,  0x63,  
    0x6d,  0x6d,  0x69,  0x31,  0x30,  0xf3,  0x07,  0x4b,  
    0xf1,  0x60,  0x79,  0x00,  0x0a,  0x00,  0x00,  0x00,  
    0x0a,  0x00,  0x00,  0x00,  0x05,  0x63,  0x6d,  0x72,  
    0x31,  0x30,  0xf3,  0x06,  0xd9,  0x93,  0xa0,  0x52,  
    0x00,  0x07,  0x00,  0x00,  0x00,  0x07,  0x00,  0x00,  
    0x00,  0x04,  0x63,  0x6d,  0x72,  0x37,  0xf9,  0x00,  
    0x00,  0x01,  0x7c,  0x02,  0xdf,  0xdf,  0xdf,  0xdf
};



// Read 1, 2 3 or 4 byte integers from the input file, with the shorter
// variants being either signed or unsigned. All are arranged in big-endian
// style, as defined by the DVI format.

unsigned char *string_input = NULL;

int mygetc(FILE *f)
{
   if (string_input != NULL) return *string_input++;
   else return getc(f);
}

int32_t u1(FILE *f)
{
    return mygetc(f) & 0xff;
}

int32_t u2(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    return ((c1 & 0xff) << 8) | (c2 & 0xff);
}

int32_t u3(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    int32_t c3 = mygetc(f);
    return ((c1 & 0xff) << 16) | ((c2 & 0xff) << 8) | (c3 & 0xff);
}

int32_t s1(FILE *f)
{
    return (int32_t)(int8_t)(mygetc(f));
}

int32_t s2(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    return (int32_t)(int16_t)(((c1 & 0xff) << 8) | (c2 & 0xff));
}

int32_t s3(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    int32_t c3 = mygetc(f);
    int32_t r = ((c1 & 0xff) << 16) | ((c2 & 0xff) << 8) | (c3 & 0xff);
    if ((r & 0x00800000) != 0) r |= 0xff000000;
    return (int32_t)r;
}

int32_t s4(FILE *f)
{
    int32_t c1 = mygetc(f);
    int32_t c2 = mygetc(f);
    int32_t c3 = mygetc(f);
    int32_t c4 = mygetc(f);
    return ((c1 & 0xff) << 24) | ((c2 & 0xff) << 16) |
           ((c3 & 0xff) << 8) | (c4 & 0xff);
}

int32_t h, v, w, x, y, z;

int32_t C[10], p;

int32_t checksum, size, designsize;
int arealen, namelen;
char fontname[256];

int font[256];

int32_t num, den, mag;

#define MAX_STACK 100

int32_t stack[6*MAX_STACK];
int stackp;

// The following two macros are syntactically delicate - so BEWARE.

#define push()         \
  stack[stackp++] = h; \
  stack[stackp++] = v; \
  stack[stackp++] = w; \
  stack[stackp++] = x; \
  stack[stackp++] = y; \
  stack[stackp++] = z

#define pop()          \
  z = stack[--stackp]; \
  y = stack[--stackp]; \
  x = stack[--stackp]; \
  w = stack[--stackp]; \
  v = stack[--stackp]; \
  h = stack[--stackp]

int findfont()
{
    printf("Define Font\n");
    printf("checksum = %.8x\n", checksum);
    printf("size = %d designsize = %d\n", size, designsize);
    printf("%d %d: %s\n", arealen, namelen, fontname);
    return 0;
}

void set_char(int32_t c)
{
    printf("Set (%f,%f) char %.2x (%c)\n",
        (double)h/(double)(1<<20), (double)v/(double)(1<<20), (int)c, (int)c);
}

void put_char(int32_t c)
{
    printf("Set (%f,%f) char %.2x (%c)\n",
        (double)h/(double)(1<<20), (double)v/(double)(1<<20), (int)c, (int)c);
}

void set_font(int n)
{
    printf("set font number %d\n");
}

int main(int argc, char *argv[])
{
    FILE *f = NULL;
    string_input = NULL;
    if (argc > 1)
    {   f = fopen(argv[1], "rb");
        printf("Using data from file %s\n", argv[1]);
    }
    else
    {   string_input = &math_dvi[0];
        printf("Using built-in data\n");
    }
    int32_t a, b, c, i, k;
    for (;;)
    {   c = mygetc(f);
        if (c == EOF) break;
        c &= 0xff;
        if (c <= 127)
        {   set_char(c);
            continue;
        }
        else
        {   switch (c)
            {
        case 128:
                set_char(u1(f));
                continue;
        case 129:
                set_char(u2(f));
                continue;
        case 130:
                set_char(u3(f));
                continue;
        case 131:
                set_char(s4(f));
                continue;
        case 132:                           // set rule
                a = s4(f);
                b = s4(f);
                if (a > 0 && b >0)
                {   printf("set rule %d %d\n", (int)a, (int)b);
                    h += b;
                }
                continue;
        case 133:
                put_char(u1(f));
                continue;
        case 134:
                put_char(u2(f));
                continue;
        case 135:
                put_char(u3(f));
                continue;
        case 136:
                put_char(s4(f));
                continue;
        case 137:
                a = s4(f);
                b = s4(f);
                if (a > 0 && b >0)
                {   printf("put rule %d %d\n", (int)a, (int)b);
                }
                continue;
        case 138:
                continue;                      // no operation
        case 139:                           // beginning of page
                h = v = w = x = y = z = stackp = 0;
                for (i=0; i<10; i++)
                    C[i] = s4(f);
                p = s4(f);
                continue;
        case 140:                           // end of page
                continue;
        case 141:
                push();
                continue;
        case 142:
                pop();
                continue;
        case 143:
                h += s1(f);
                continue;
        case 144:
                h += s2(f);
                continue;
        case 145:
                h += s3(f);
                continue;
        case 146:
                h += s4(f);
                continue;
        case 147:
                h += w;
                continue;
        case 148:
                h += (w = s1(f));
                continue;
        case 149:
                h += (w = s2(f));
                continue;
        case 150:
                h += (w = s3(f));
                continue;
        case 151:
                h += (w = s4(f));
                continue;
        case 152:
                h += x;
                continue;
        case 153:
                h += (x = s1(f));
                continue;
        case 154:
                h += (x = s2(f));
                continue;
        case 155:
                h += (x = s3(f));
                continue;
        case 156:
                h += (x = s4(f));
                continue;
        case 157:
                v += s1(f);
                continue;
        case 158:
                v += s2(f);
                continue;
        case 159:
                v += s3(f);
                continue;
        case 160:
                v += s4(f);
                continue;
        case 161:
                v += y;
                continue;
        case 162:
                v += (y = s1(f));
                continue;
        case 163:
                v += (y = s2(f));
                continue;
        case 164:
                v += (y = s4(f));
                continue;
        case 165:
                v += (y = s4(f));
                continue;
        case 166:
                v += z;
                continue;
        case 167:
                v += (z = s1(f));
                continue;
        case 168:
                v += (z = s2(f));
                continue;
        case 169:
                v += (z = s3(f));
                continue;
        case 170:
                v += (z = s4(f));
                continue;
        case 171:  case 172:  case 173:  case 174:
        case 175:  case 176:  case 177:  case 178:
        case 179:  case 180:  case 181:  case 182:
        case 183:  case 184:  case 185:  case 186:
        case 187:  case 188:  case 189:  case 190:
        case 191:  case 192:  case 193:  case 194:
        case 195:  case 196:  case 197:  case 198:
        case 199:  case 200:  case 201:  case 202:
        case 203:  case 204:  case 205:  case 206:
        case 207:  case 208:  case 209:  case 210:
        case 211:  case 212:  case 213:  case 214:
        case 215:  case 216:  case 217:  case 218:
        case 219:  case 220:  case 221:  case 222:
        case 223:  case 224:  case 225:  case 226:
        case 227:  case 228:  case 229:  case 230:
        case 231:  case 232:  case 233:  case 234:
                set_font(c - 171);
                continue;
        case 235:
                set_font(u1(f));
                continue;
        case 236:
                set_font(u2(f));
                continue;
        case 237:
                set_font(u3(f));
                continue;
        case 238:
                set_font(s4(f));
                continue;
        case 239:
                k = u1(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 240:
                k = u2(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 241:
                k = u3(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 242:
                k = s4(f);
                for (i=0; i<k; i++) u1(f);
                continue;
        case 243:                         // fnt_def1
                k = u1(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 244:
                k = u2(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 245:
                k = u3(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 246:
                k = s4(f);
                checksum = s4(f);
                size = s4(f);
                designsize = s4(f);
                arealen = u1(f);
                namelen = u1(f);
                for (i=0; i<arealen+namelen; i++) fontname[i] = u1(f);
                fontname[arealen+namelen] = 0;
                font[k] = findfont();
                continue;
        case 247:                          // pre
                i = u1(f);
                if (i != 2)
                {   printf("illegal DVI version %d\n", i);
                    break;
                }
                num = s4(f);
                den = s4(f);
                mag = s4(f);
                k = u1(f);
                for (i=0; i<k; i++) u1(f);
                printf("PRE: num=%d, den=%d, (%f) mag=%d\n",
                       num, den, (double)num/(double)den, mag);
                continue;
        case 248:                          // post
                s4(f); // ignore p;
                s4(f); // ignure num
                s4(f); // ignore den
                s4(f); // ignore mag
                s4(f); // height+depth of largest page
                s4(f); // width of largest page
                printf("Greatest stack depth = %d\n", u2(f));
                printf("Page count = %d\n", u2(f));
    // The postamble will have font definitions here as well.
                continue;
        case 249:                          // post_post
                s4(f);
                u1(f);
                if (u1(f) != 223) printf("Malformed DVI file\n");
                break;

        // 250-255 undefined
        default:
                printf("Unknown/undefined opcode %.2x\n", c);
                break;
            }
            break;
        }
    }
    printf("end of file\n");
}

