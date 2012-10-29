/* #define DEBUG */
#if defined DEBUG
#include <stdio.h>
#endif

#if defined WINDOWS
#include <windows.h>
#else
#include <setjmp.h>
#include "xredtech.h"
#endif

#if defined WINDOWS
CATCHBUF errorset;
#else
#if defined SOLARIS
jmp_buf Errorset[5];
#define errorset Errorset[0]
#else
jmp_buf errorset;
#endif /* SOLARIS */
#endif /* WINDOWS */

char fancy_error_state;
char error_message[40];
char first_time;

#if defined WINDOWS
warning(LPSTR,LPSTR);
#endif


char apuffer[100];
extern int fancy_xrange, fancy_yrange, fancy_tab;

int xlo,xhi,ylo,yhi,end_code;
int global_indpos;

#ifdef WINDOWS
#define CHARS_PER_INT  2
#else
#define CHARS_PER_INT  4
#endif

#define TYPE 0
#define NEXT 1
#define X0  2
#define Y0  3

/*   empty cell type */
#define EMPTY_TYPE   -1
#define EMPTY_LTH    3

/*   compound type */
#define COMP_TYPE   0
#define COMP_LTH    4
#define COMP_CONT   4

/*   char type */
#define CHAR_TYPE   2
#define CHAR_LTH    5
#define CHAR_FONT   4
#define CHAR_CHAR   5

/*   line type */
#define LINE_TYPE   3
#define LINE_LTH    7
#define LINE_X0     4
#define LINE_Y0     5
#define LINE_X1     6
#define LINE_Y1     7

/*   bracket type */
#define BRACK_TYPE   4
#define BRACK_LTH    7
#define BRACK_CHAR   4
#define BRACK_FONT   5
#define BRACK_LO     6   
#define BRACK_HI     7   



#define RAISE       '^'
#define LOWER       '_'
#define ESCAPE      '\\'

#define FANCY_OFF   0x11

/*----------------some declarations -------------------------------*/

int make_chain();
int make_char();
int append_char();

/*-----------------------------------------------------------------*/

#define PROG_MAX 2000
int prog_last = -1;

#if defined WINDOWS
LPINT prog;
LPBYTE c_prog; 
HANDLE hprog=NULL;
#else
int *prog;
char * c_prog; 
#endif

int prog_upperbound=-1;
char * input;
#if defined WINDOWS
extern LPSTR   fancy_lines[];
#else
extern char * fancy_lines[];
#endif
int            local_lines_ptr;
char           nullum[1];


/*-----------------------------------------------------------------*/

extern int font_height[2];
extern int font_width[2];

/*-----------------------------------------------------------------*/

reset_struct()
  {
    prog_last = 0;
    if(prog_upperbound<0)
    {
#if defined WINDOWS
      prog = (int*)NULL;
      if(hprog = LocalAlloc(LMEM_MOVEABLE,PROG_MAX * CHARS_PER_INT))
      {  
         prog = (LPINT)LocalLock(hprog);
         c_prog = (LPBYTE)prog;
      }
#else
      prog = (int*)malloc(PROG_MAX * CHARS_PER_INT);
      c_prog = (char*) prog;   
#endif
      if(!prog) fancy_error("\nfancy no memory available\n");
      prog_upperbound=PROG_MAX;
    }
  }

extend_struct()
   {
     int r=0;
#if defined WINDOWS
     HANDLE memnew;
     if(0==LocalUnlock(hprog))
     memnew = LocalReAlloc(hprog,
                        (prog_upperbound+PROG_MAX)* CHARS_PER_INT,
                        LMEM_MOVEABLE);    
     if(memnew) { r=1; hprog=memnew; }
     prog=(LPINT)LocalLock(hprog);
     c_prog = (LPBYTE) prog;
#else
     int * prognew;
     prognew = (int*)realloc((char*)prog,
                       (prog_upperbound+PROG_MAX)* CHARS_PER_INT);
     if(prognew) { r=1; prog=prognew; c_prog = (char*) prog;}
#endif
     if(!r) fancy_error("\nfancy cannot extend memory\n");
             else 
            prog_upperbound=prog_upperbound+PROG_MAX;
  }
     

char nchar()
  { 
     char c;
     c = *input;
     if (c==FANCY_OFF) {c=0; *nullum=0; input = nullum;}
     if(c)
     { input++;
       if (*input == 0 || *input == '\n')
          { local_lines_ptr++;
           if(fancy_lines[local_lines_ptr]) 
                   input = fancy_lines[local_lines_ptr];
              else {*nullum=0; input = nullum;}
          }
     }
     return(c);
  }

get_struct(type,lth)
  int type,lth;

  {
    int i,cell;
    lth ++;
    cell = prog_last;
    prog_last = prog_last + lth;
    if(prog_last > prog_upperbound) extend_struct(); 
/*    
    { 
      fancy_error("\nfancy output too long\n");
      prog_last=0;  cell=0;
    } 
*/
    prog[cell+TYPE] = type;
    for(i=TYPE+1;i<lth;i++) prog[cell+i]=0;
    return(cell);
  }

#define ARRAYMAX 401

make_array(font)
  int font;

  {
     int canchor, lanchor, array, line, elt;
     int basx,basy,cols=0;
     int lxlo=0, lxhi=0, lylo=0,lyhi=0;
     int yindhi,yindlo;
     int exhi[ARRAYMAX], eyhi[ARRAYMAX];
     int line_cnt,col_cnt,line_lth;
     int ymid;

     array = get_struct(COMP_TYPE,COMP_LTH);
     canchor = array + COMP_CONT;
     while(*input == ' ') nchar();  nchar();
     while('c' == nchar()) cols++; 

  /* loop1: create boxes for all elements */

     line_cnt = 0;
     col_cnt = 0;
     line_lth = 0;
   next_line:
     line = get_struct(COMP_TYPE,COMP_LTH);
     lanchor = line + COMP_CONT;
     if((line_cnt+1)*line_lth > ARRAYMAX)
         fancy_error("\nfancy overflow array table\n");

   next_col:  
     if (col_cnt>=line_lth) line_lth=col_cnt+1;
     elt = make_chain(font,'&');
     if(prog[elt+COMP_CONT] == 0) goto loop2; 
     if(ylo) prog[elt+Y0] = -ylo;
       yhi = yhi-ylo; ylo = 0;
     if(xhi>lxhi) lxhi = xhi;
     if(yhi>lyhi) lyhi = yhi;
     exhi[line_cnt*line_lth + col_cnt] = xhi;
     eyhi[line_cnt*line_lth + col_cnt] = yhi;

     col_cnt++;
     prog[lanchor] = elt;
     lanchor = elt + NEXT;
     if(col_cnt < cols) goto next_col;

     prog[canchor] = line;
     canchor = line+NEXT;
     line_cnt++;
     col_cnt = 0;
     if (end_code != -4) goto next_line;

   loop2:  /* second loop: put elements in places */
     if(lxhi > 2*font_width[font]  || lyhi > 2*font_height[font])
        { lxhi = lxhi+font_width[font]; lyhi = lyhi+font_height[font]/2;}
         else
        { lxhi = lxhi+font_width[font]/2; 
          /* lyhi = lyhi+font_height[font]/4; */};
     line_cnt = 0;
     col_cnt = 0;
     basx = 0; basy = 0;
     line = prog[array + COMP_CONT];      
  next_line2:
     lanchor = line + COMP_CONT;
  next_col2:
     elt = prog[lanchor];
     prog[elt + X0] = 
       basx + (lxhi - exhi[line_cnt*line_lth + col_cnt])/2;
     prog[elt + Y0] = prog[elt + Y0] + 
       basy + (lyhi - eyhi[line_cnt*line_lth + col_cnt])/2;    


     col_cnt++;
     basx = basx + lxhi;
     lanchor = elt + NEXT;
     if(col_cnt < cols) goto next_col2;
    
     basy = basy + lyhi; line_cnt++;
     line = prog[line + NEXT];
     
     if(line == 0) goto ready;
     
     basx = 0; col_cnt = 0; 
     goto next_line2;

  ready:
     /*  center matrix in y around mid of character */
     ymid = font_height[font]/2;
     xlo = 0; xhi = basx;
     yhi = basy/2;
     prog[array+Y0] = ymid-yhi;
     ylo = ymid-yhi; yhi = ymid+yhi; 
     elt =  get_struct(COMP_TYPE,COMP_LTH);
     prog[elt+COMP_CONT] = array;
     return(elt);
  }


int make_chain(font,term)
  int font; 
  char term;

  {
     int anchor, new ,cell, indpos=-1;
     unsigned char c,cc;
     int string=0;
     int xact=0,yact=0,d,fh;
     int lxlo=0, lxhi=0, lylo=0,lyhi=0;
     int yindhi,yindlo,ymid;

     end_code = 0;
     cell = get_struct(COMP_TYPE,COMP_LTH);
     anchor = cell + COMP_CONT;
     xact = 0; yact = 0;
     xhi = 0; xlo = 0; ylo = 0; yhi = 0;
     fh = font_height[font]; lyhi = fh;
     ymid = fh/2;

  loop:
     c = nchar(); cc=*input;
     if(c == '{' && term == 0)
         { term = '}'; goto loop;};

     if(c == ' ') goto loop;
     if(c == term) goto finish;
     if(c == 0 || c == '\n')  goto finish;

          /* handle escaped single characters */
     if(c == ESCAPE &&
        (cc == ' ' || c == '_' || c == '^' || c == '{' || c == '}'))
          c = nchar();

     if(c == ESCAPE) 
       { 
         indpos = -1; string = 0; 
         global_indpos = 0;
         new = make_escape(font);
         if(new == -999) goto loop; /* ignore? */
         if (global_indpos)
         { 
           indpos = xact; 
           yindhi = yhi + font_height[1]; /* here use smaller font */
           yindlo = ylo - font_height[1];
         }
       } 
       else
                       /* upper or lower index */
     if(c == LOWER || c == RAISE)
       { 
         string = 0;
         if(indpos>-1) 
         { xact=indpos; yhi = yindhi; ylo = yindlo;}
           else 
         { indpos=xact; yindhi = yhi; yindlo = ylo;}
         
         new = make_chain(1,0);
         d = fh/2;
         if(c == RAISE) 
            d = yindlo + d - 1 - yhi; 
            else
            d = yindhi - d + 1 - ylo;           /* d+(yhi-fh); }; */
         
         prog[new+Y0] = d;
         ylo = ylo+d; yhi = yhi+d;
       }
      else
                        /* start of a new goup */
    if(c == '{') 
       {
         new = make_chain(font,'}'); 
         indpos=-1;
       }
      else
       { indpos=-1; 
         if(string)
         { append_char(string,c,font);
           xact = xact+xhi;
           if(xact>lxhi) lxhi = xact;
           goto loop;
         }
           else
         {
           new = make_char(font,0,c);
           string = new;
         }
       }

     if(new < 0 ) { end_code = new; goto finish; }

     prog[anchor] = new;
     anchor = new + NEXT;
     prog[new+X0] = xact;
        /* center in y direction */
        /*  prog[new+Y0] = ymid - (ylo + yhi)/2;   this was wrong */
     xact = xact + xhi;
     if(xact>lxhi) lxhi = xact; else xact=lxhi;
     if(ylo<lylo) lylo=ylo;
     if(yhi>lyhi) lyhi=yhi;
     
     if(term > 0) goto loop;
     
 finish:
     ylo = lylo; yhi = lyhi;
     xlo = lxlo; xhi = lxhi;
     return(cell);

   }

int make_char(font,cs,c)
  int font;
  int cs;
  unsigned char c;
  {
     int cell,h,fh;
     int box[4];
     cell = get_struct(CHAR_TYPE,CHAR_LTH);
     c_prog[(cell+CHAR_CHAR)*CHARS_PER_INT] = c;
     prog[cell+CHAR_FONT] = (font & 255) + (cs<<8);
     inquire_char_box(box,c,cs,font);
     h = box[3] - box[1];
     fh = font_height[font];
     xlo = box[0]; ylo = box[1];
     xhi = box[2]; yhi = box[3];
    if(h>fh)
     { h = (h-fh)/2;
       prog[cell+Y0] = -h;
       ylo = ylo - h; yhi = yhi - h;
     }
     return(cell);
  }

int append_char(string,c,font)
  int string;
  unsigned char c;
  int font;
  {
    int pos,cpos;
    int box[4]; 
    pos = (prog[string]>>8)&255; pos++;
    cpos = (string+CHAR_CHAR) * CHARS_PER_INT;
    c_prog[cpos + pos] = c;
    prog[string] = (prog[string]&255) + (pos<<8);
    prog_last = prog_last + (pos/CHARS_PER_INT - (pos-1)/CHARS_PER_INT);
    inquire_char_box(box,c,0,font);
    xhi = box[2]; yhi = box[3];
  }

int make_string(font,cs,s)
  int font;
  int cs;
  char*s;
  {
     int cell,h,fh,x;
     cell = make_char(font,cs,*s++);
     x = xhi;
     while(*s){ append_char(cell,*s++,font); x=x+xhi; }
     xhi = x;
     return cell;
  }

make_bracket(font,c,y0,y1)
  int font;
  char c;
  int y0;
  int y1;
  {
     int cell;

     cell = get_struct(BRACK_TYPE,BRACK_LTH);
     prog[cell+BRACK_CHAR] = c;
     prog[cell+BRACK_FONT] = font;
     prog[cell+BRACK_LO]   = y0;
     prog[cell+BRACK_HI]   = y1; 
     if(y0 == y1) y1 = font_height[font];
     xlo = 0; ylo = y0; yhi = y1;
     xhi = font_width[font]; 
     return(cell);
  }

make_dist(font,c,mal,durch)
  int font,mal,durch;
  char c;
  {
     int cell; int box[4];
     cell=get_struct(EMPTY_TYPE,EMPTY_LTH);
     /* xhi = font_width[font]/2; */
     inquire_char_box(box,' ',0,font);
     xhi = (box[2]*mal)/durch;
     xlo = 0; yhi=0; ylo=0;
     return(cell);
  }


make_line(x0,y0,x1,y1)
  int x0;
  int y0;
  int x1;
  int y1;
  {
     int cell;
     cell = get_struct(LINE_TYPE,LINE_LTH);
     prog[cell+LINE_X0] = x0;
     prog[cell+LINE_Y0] = y0;
     prog[cell+LINE_X1] = x1;
     prog[cell+LINE_Y1] = y1;
     return(cell);
  }

make_frac(font)
  {
     int anchor,cell;
     int numr,denr,line;
     int lxlo=0, lxhi=0, lylo=0,lyhi=0;
     int nxhi,dxhi,nyhi,dyhi,nylo,dylo;
     int ydist=2;
     int yline;

     
     cell = get_struct(COMP_TYPE,COMP_LTH);
     anchor = cell + COMP_CONT;
     
      /* position for the line */
     yline = font_height[font] / 2;

     xhi = 0; xlo = 0; yhi = 0; ylo = 0;
     numr = make_chain(font,0); 
     nxhi = xhi; nyhi = yhi; nylo = ylo;
     
     xhi = 0; xlo = 0; yhi = 0; ylo = 0;
     denr = make_chain(font,0); 
     dxhi = xhi; dyhi = yhi; dylo = ylo;

       /* move the shorter one to the middle */
     if(dxhi > nxhi)
     {  
        lxhi = dxhi;
        prog[numr+X0] = (dxhi - nxhi)/2;
     }
       else 
     {  
        lxhi = nxhi;
        prog[denr+X0] = (nxhi - dxhi)/2;
     }
       
     /* make line */
     line = make_line(0,yline,lxhi,yline);

     /* put num on top */
     prog[numr+Y0] = yline - ydist - nyhi;  
     
     /* put denr below */
     prog[denr+Y0] = yline + ydist - dylo;

     /* total frame */
     xlo = 0; xhi = lxhi;
     ylo = yline - ydist -(nyhi-nylo);
     yhi = yline + ydist +(dyhi-dylo);

     /* make chain */
     prog[anchor] = line;
     anchor = line+NEXT;
     prog[anchor] = numr;
     anchor = numr+NEXT;
     prog[anchor] = denr;

     return(cell);
  }

make_sqrt(font)
  {
     int anchor,cell;
     int expt,rad,line;
     int lxlo=0, lxhi=0, lylo=0,lyhi=0;
     int ydist=2; int xdist; int d,z;
     int yline;

     xdist = font_width[font]/2;

     cell = get_struct(COMP_TYPE,COMP_LTH);
     anchor = cell + COMP_CONT;
     d =(font_height[font] /2);                        /*  * 2) / 3;  */

     while(*input == ' ') nchar();
     if(*input == '[')
     { nchar();
       expt = make_chain(1,']'); 
       prog[anchor] = expt;
       anchor = expt+NEXT;
       prog[expt+Y0] = -d;
       lxhi = xhi;
       lylo = ylo-d; lyhi=yhi-d;
     }
  
     rad = make_chain(font,0); 
     yline = ylo - ydist;

      /* draw the surd symbol */
     line = make_line(lxhi,font_height[font]-d,lxhi,yhi);  
     prog[anchor] = line;
     anchor = line+NEXT;
     
     z = lxhi + xdist; 
     line = make_line(lxhi,yhi,z,yline);  
     prog[anchor] = line;
     anchor = line+NEXT;
     
     lxhi = z + xdist;
     prog[rad+X0] = lxhi;
     xhi = lxhi + xhi;
     line = make_line(z,yline,xhi,yline);  
     prog[anchor] = line;
     anchor = line+NEXT;
     prog[anchor] = rad;

     if(lylo < yline) ylo=lylo; else ylo=yline;
     if(lyhi > yhi) yhi=lyhi;
     return(cell);
  }

make_big_brack(font,siz)
  int font;
  int siz;
  {
     int fw,fh,b;
     unsigned char c;
     nchar();  /* skip character r resp. l */
     fw = font_width[font]; fh = font_height[font];
     ylo = - (fh/2) * siz;  yhi = fh -ylo;
     c = nchar(); if (c=='\\') c = nchar();
     b = make_bracket(font,(int)c,ylo,yhi);
     xlo = 0; xhi = fw;
     return (b);
  }

make_left(font)
  int font;
  {
     int anchor,cell;
     int rad,b;
     int lxlo=0, lxhi=0, lylo=0,lyhi=0;
     int yline;
     char cleft,cright;

     cell = get_struct(COMP_TYPE,COMP_LTH);
     anchor = cell + COMP_CONT;

     while(*input == ' ') nchar();
     cleft = nchar(); 
     if (cleft != '(' && cleft != '{')  
         fancy_error ("illegal symbol to \\left: ");
     rad = make_chain(font,1); 
     cright = nchar();
     if (  (cleft == '(' && cright == ')')  
         ||(cleft == '{' && cright == '}')); 
       else  fancy_error ("brackets dont match: ");   
     
     lylo = ylo; lyhi = yhi; lxhi = xhi;
     b = make_bracket(font,cleft,lylo,lyhi);
     prog[anchor] = b;
     anchor = b + NEXT;
     prog[anchor] = rad;
     anchor = rad + NEXT; 
     prog[rad+X0] = xhi;
     lxhi = xhi + lxhi;
     b = make_bracket(font,cright,lylo,lyhi); 
     prog[anchor] = b;
     prog[b+X0] = lxhi;
     xhi = xhi + lxhi;
     return(cell);
  }

int make_tab()
  {
     fancy_tab = fancy_tab + 5;
     return(-999);
  }

int make_symb(font)
    int font;
   {
      int c,r=0;
      while ((c=nchar()) != '}') r=r*10 + c-'0';
      return(make_char(font,1,r));
   }

int make_escape(font)
    int font;

    {
      char g; int r;

      
      /* if(test("pi"))               return(make_char(font,1,'p')); else */ 
      if(g = test_greek())         return(make_char(font,1,g)); else
                                    /* infty symbol always big font */
      if(test("infty"))            return(make_char(0,1,0xa5)); else
      if(test("to"))               return(make_char(font,1,174)); else
      if(test("int"))              return(make_char(font,2,'i')); else
      if(test("Int"))              return(make_char(font,2,'I')); else
      if(test("sum"))              {global_indpos = 1;
                                    return(make_char(font,2,'S'));} else
      if(test("prod"))             {global_indpos = 1;
                                    /* big PI */
                                    return(make_char(font,1,80));} else
      if(test("lim"))              {global_indpos = 1;
                                    return(make_string(font,0,"lim"));} else
      if(test("symb{"))            return(make_symb(font)); else
      if(test(","))                return(make_dist(font,' ',3,4)); else
      if(test(" "))                return(make_dist(font,' ',1,1)); else
      if(test("_"))                return(make_char(font,0,'_')); else
      if(test(">"))                return(make_tab()); else
      if(test("\\"))               return(-1); else
      if(test("&"))                return(-2); else  
      if(test("{"))                return(make_char(font,0,'{')); else
      if(test("}"))                return(make_char(font,0,'}')); else
      if(test("frac"))             return(make_frac(font)); else
      if(test("sqrt"))             return(make_sqrt(font)); else
      if(test("left"))             return(make_left(font)); else
      if(test("right"))            return(-3); else
      if(test("bigg"))             return(make_big_brack(font,3)); else
      if(test("Bigg"))             return(make_big_brack(font,4)); else
      if(test("big"))              return(make_big_brack(font,1)); else
      if(test("Big"))              return(make_big_brack(font,2)); else
      if(test("backslash"))        return(make_char(font,0,'\\')); else
      if(test("begin{array}"))     return(make_array(font)); else
      if(test("end{array}"))       return(-4); else
      {    
          fancy_error("unknown control sequence: \\");
      }
    }

char * greek[] = {"alpha","beta","gamma","delta","epsilon","zeta",
                  "eta","theta","iota","kappa","lambda","mu","nu",
                  "xi","pi","rho","sigma","tau","upsilon","phi",
                  "chi","psi","omega",""};

char agreek[] = {'a','b','g','d','e','z',
                 'h','q','i','k','l','m','n',
                 'x','p','r','s','t','u','f',
                 'c','y','w','\0'};

int test_greek()
  { int i=0,r=0; char * name;
    while (!r && *greek[i]) 
         if(test(greek[i])) r=agreek[i]; else i++;
    return(r);
  }

int test(u)
   char * u;

  { char * s; char c; int r=1,lp;
    s = input; lp = local_lines_ptr; 
    while (r && *u && (c=nchar())) r = (*u++ == c);
    if (r) return(1);
      /* reset input pointers to previous values */
    input = s; local_lines_ptr = lp;
    return(0);
  }


/*--------------------------- interpreter -------------------------*/

int fout_loop(cell,x,y)
  int cell,x,y;
  {
    int type;
 
    type = prog[cell+TYPE] & 255;
    if(type == CHAR_TYPE) fout_char(cell,x,y); else
    if(type == COMP_TYPE) fout_comp(cell,x,y); else
    if(type == LINE_TYPE) fout_line(cell,x,y); else
    if(type == BRACK_TYPE)fout_brack(cell,x,y);
    return(0);
  }

fout_char(cell,x,y)
  int cell,x,y;
  { 
    int xx,yy,f,n,d; char * c; int cs;
    n = (prog[cell] >> 8)&255;
    xx= x + prog[cell+X0];
    yy= y + prog[cell+Y0];
    f = prog[cell+CHAR_FONT];
    c = c_prog + ((cell+CHAR_CHAR)*CHARS_PER_INT);
    cs = (f>>8) & 255;
#ifdef DEBUG
    fprintf(stderr,"chars(%d,%d,%d)",cell,x,y);
    fprintf(stderr,"X0,Y0=(%d,%d)",prog[cell+X0],prog[cell+Y0]);
    { int i;
      /* for(i=0;i<n+1;i++) fprintf(stderr,"%c",
               c_prog[(cell+CHAR_CHAR)*CHARS_PER_INT+i]);
      */
      fprintf(stderr,"\n");
    }
#endif
    draw_string(xx,yy,c,n+1,cs,f & 255);
  }

fout_line(cell,x,y)
  int cell,x,y;
  { 
    int xx,yy;
    xx= x + prog[cell+X0];
    yy= y + prog[cell+Y0];
    draw_line(xx+prog[cell+LINE_X0],yy+prog[cell+LINE_Y0],
              xx+prog[cell+LINE_X1],yy+prog[cell+LINE_Y1]);
  }

fout_brack(cell,x,y)
  int cell,x,y;
  { 
    int xx,yy;
    xx= x + prog[cell+X0];
    yy= y + prog[cell+Y0];
    draw_brack  (xx,
                 yy+prog[cell+BRACK_LO],yy+prog[cell+BRACK_HI],
                 prog[cell+BRACK_CHAR],prog[cell+BRACK_FONT] );
  }



fout_comp(cell,x,y)
  int cell,x,y;
  { 
    int xx,yy,f,c;
    xx= x + prog[cell+X0];
    yy= y + prog[cell+Y0];
    c = prog[cell+COMP_CONT];
#ifdef DEBUG
    fprintf(stderr,"comp (%d,%d,%d)",cell,x,y);
    fprintf(stderr,"X0,Y0=(%d,%d)",prog[cell+X0],prog[cell+Y0]);
    fprintf(stderr,"\n");
#endif

    while(c)
    { fout_loop(c,xx,yy); c = prog[c+NEXT];}
  }

/*--------------------------- interface -------------------------*/

fancy_decode(first)
   int first;

   {
     int i; char * s;
     
     fancy_tab = 0;
     first_time = first;
     input=fancy_lines[0];         
     
     fancy_error_state = 0;
#if defined WINDOWS     
     if(Catch(errorset)) goto err;
#else
     if(setjmp(errorset)) goto err;
#endif

     reset_struct();
     
     local_lines_ptr = 0;
     
     make_chain(0,1);
#if   defined TRACE
     wsprintf(apuffer,"structure done, x= (%d:%d),y=(%d:%d)\n",xlo,xhi,ylo,yhi);
     my_puts(apuffer);
     for(i=0;i<prog_last;i++) 
       { wsprintf(apuffer, "%d ",prog[i]); my_puts(apuffer);}
     my_puts("\n ----- start interpreter\n");
#endif    
     fancy_xrange = xhi-xlo;
     fancy_yrange = yhi-ylo;
     return(1);
err: fancy_xrange = 0;
     fancy_yrange = 0;
     fancy_error_state = 1;
     return(1);
   }


fancy_draw()
   {   
     if(fancy_error_state || prog_last <0) return(0);
     fout_loop(0,-xlo,-ylo); 
   }

fancy_error(text)
   char * text;

   { 
     int i=0; char c;
     while(*text) error_message[i++]=*text++;
     for(i=i; i<38 &&(c=nchar()); i++) error_message[i]=c;
     error_message[i]=0;
     if(first_time) warning("fancy output error",error_message);
#if defined WINDOWS     
     Throw(errorset,99);
#else
     longjmp(errorset,99);
#endif   
   }

