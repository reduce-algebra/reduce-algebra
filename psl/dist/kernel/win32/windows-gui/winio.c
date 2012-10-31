#include "psllw.h"
#include "winext.h"

#define        FANCY_ON 0x10
#define        FANCY_OFF 0x11
#define        SCROLLUP 10
#define        INSERT insert==0

extern int input_mark;
extern int input_marklength;
void char_delete(int mode);

my_prepare()
  {int i,j;
    for(i=0;i<255;i++) ipuffer[i]='\0';
      /* create output buffer */
    lpuffer_handle = LocalAlloc(LMEM_FIXED,(LINELENGTH+1)*(MAXLOPUFFER+1));
    if(!lpuffer_handle) warning("cannot allocate output buffer","");
    lpuffer_mem=LocalLock(lpuffer_handle);

    for(i=0;i<MAXLOPUFFER+1;i++)
     {lpuffer[i] = lpuffer_mem+(i*(LINELENGTH+1));
      for(j=0;j<LINELENGTH;j++) lpuffer_mem[i*(LINELENGTH+1)+j] = ' ';
      lpuffer_mem[i*(LINELENGTH+1)+LINELENGTH] = 0;
     }
   }

cursorKey(WORD key)
    {int i,loc;

      mySetBkMode(hDC,OPAQUE); /* we need overwriting here */

      switch(key)
       {
	 case 0x8:     /* backspace */
	
	    if (i_ptr==0) break;
	bottom_page();
	    i_ptr--;
	    for(i=i_ptr;i<LINELENGTH;i++) 
		ipuffer[i] = ipuffer[i+1];
	    ipuffer[LINELENGTH] = '\0';
	    caret_x = caret_x - cWidth;
	  break;
	 
	 case 0x2e:    /* del */
	bottom_page();
	char_delete(1);
	  break;  
	 
	 case 0x2d:    /* ins  (toggle) */
	bottom_page();
	    insert = !insert;
	 break;

	 case 0x25:     /* <- */
	bottom_page();
	    if(i_ptr == 0) break;
	    i_ptr--;
	    caret_x = caret_x - cWidth;
	 break;
	 
	 case 0x24:     /* home */
	bottom_page();
	    while(i_ptr > 0) 
	    { i_ptr--; caret_x = caret_x - cWidth;}
	 break;

	 case 0x27:     /* -> */
	bottom_page();
	    if(i_ptr >= wColumns || ipuffer[i_ptr] == '\0') break;
	    i_ptr++;
	    caret_x = caret_x + cWidth;
	 break;

	 case 0x23:     /* end */
	bottom_page();
	cursor_to_end();
	 break;

	 case 0x1b:     /* esc */
	bottom_page();
	ipuffer[i_ptr] = '\0';               // 19.1.94
	    while(i_ptr > 0) 
	    { i_ptr--; 
	      ipuffer[i_ptr] = '\0';
	      caret_x = caret_x - cWidth;}       
	 break;
	    

	 case 0x26:     /* up */
	    bottom_page();
	if(liptr > licount)
	    { liptr--;
	      for(i=0;i<LINELENGTH;i++)
		  ipuffer[i] = lipuffer[liptr][i];
	      caret_x = caret_x - cWidth * i_ptr;
	      i_ptr = 0;
	  cursor_to_end();
	    };
	 break;

	 case 0x28:     /* down */
	bottom_page();
	    if(liptr < MAXLIPUFFER)
	    { liptr++;
		for(i=0;i<LINELENGTH;i++)
		if(liptr < MAXLIPUFFER)
		  ipuffer[i] = lipuffer[liptr][i];
		    else
		  ipuffer[i] = '\0';
	      caret_x = caret_x - cWidth * i_ptr;
	      i_ptr = 0;
	cursor_to_end();
	    }
	 break;

		    /* 21.7.93  Ctrl + PgUp/Down */
	 case 0x21:     /* Pgup */
	    if (act_show <= wLines || act_line <= wLines) return(0);
	if(ctrl) my_showpage(wLines);
		else my_showpage(act_show - wLines);
	    return(0);
	 
	 case 0x22:     /* Pgdown */
	if(ctrl) my_showpage(act_line);
		else my_showpage(act_show + wLines);
	    return(0);


	 default:
	   return(0);
       }
       input_mark = -1;
       show_inputline(1);
    }

void char_delete(int mode)
      { int i,j=1;
	 if(mode ==0 && input_mark<0) return;
	 if (input_mark>=0) j=input_marklength;
	 ipuffer[LINELENGTH] = '\0';
	 for(i=i_ptr;i+j<=LINELENGTH;i++) ipuffer[i] = ipuffer[i+j]; 
	 input_mark = -1;
	 show_inputline(1);
       }

cursor_to_end()
   /* move cursor to end of line */
   {
      while(i_ptr < wColumns && ipuffer[i_ptr] != '\0')
	    { i_ptr++; caret_x = caret_x + cWidth;}
   }

#ifdef OS2     

show_inputline(int mode)
    {
	int i,j;

    de_select();             /* 23.7.93 */

	my_flush();
	for(i=0; i<LINELENGTH && ipuffer[i] && ipuffer[i]!='\n'; i++); 
	dcon(); 
	     
	mySetBkMode(hDC,OPAQUE);
	if(mode && lpuffer[act_line][0])
	     TextOutFix(hDC,0,act_y,lpuffer[act_line],o_ptr);
	  TextOutFix(hDC,o_ptr*cWidth,act_y,ipuffer,i);
	  for(j=o_ptr+i;j<wColumns;j=j+10)
	     TextOutFix(hDC,j * cWidth,act_y, "          ",10);
	dcoff();
	caret_y=act_y; 
		       /* hier falsch, weil cursor mitten im Text stehen kann
		       /*     caret_x=(o_ptr+i)*cWidth; /*hierrr*/
	return(i);
     }

#else

show_inputline(int mode)
    {
	int i,j,k; 

    de_select();             /* 23.7.93 */

	my_flush();
	for(i=0; i<LINELENGTH && ipuffer[i] && ipuffer[i]!='\n'; i++); 
	dcon(); 
	     
    if(mode || INSERT)  /* overwriting line */
    {
      if(INSERT) mySetBkMode(hDC,OPAQUE);
      if(lpuffer[act_line][0])
	     TextOutFix(hDC,0,act_y,lpuffer[act_line],o_ptr);
	  TextOutFix(hDC,o_ptr*cWidth,act_y,ipuffer,i);
	  for(j=o_ptr+i;j<wColumns;j=j+10)
	     TextOutFix(hDC,j * cWidth,act_y, "          ",10);
    }
      else
    {
      /* TextOutFix(hDC,(o_ptr+i-1)*cWidth,act_y,ipuffer+(i-1),1); */
      TextOutFix(hDC,o_ptr*cWidth,act_y,ipuffer,i);   /* 27.9.93 */
    }
    
     // bracket matching
    j=1;
    for(k=i_ptr; k>=0 && j; k--) j=iline_match_bkt(k);
    dcoff();
    caret_y=act_y; 
		    
    return(i);
  }

iline_match_bkt(int act)
  { char c; int r=1;
    c=ipuffer[act];
    if(c==')' || c=='}' || c==']') r=iline_match_bkt1(act,-1); else
    if(c=='(' || c=='{' || c=='[') r=iline_match_bkt1(act,+1); 
    return(r);
  }
    
#define RED   0x0000ffL
#define GREEN 0x00ff00L
#define BLUE  0xff0000L

buntchar(int a,DWORD col)
    { DWORD old;
      old = SetTextColor(hDC,col);
      TextOutFix(hDC,(o_ptr+a)*cWidth,act_y,ipuffer+a,1);
      SetTextColor(hDC,old);
      return(0);
    }

iline_match_bkt1(int act,int dir)
  {
    int a;
    a = iline_match_bkt_find(act,dir);
    if (a<-1) return(0); // error has been marked
    if (a<0) return(1);  // continue 
    buntchar(act,RED);
    buntchar(a,RED);
    return(0);
   }    

iline_match_bkt_find(int act,int dir)
  {
    int p,a=act; char c,c1,c2;
    c1 = ipuffer[a];
   
  loop:
    a=a+dir;
    if (a<0 || !(c=ipuffer[a])) return(-1);
    p = a;
    if(c == '(' || c == '{' || c == '[')
     { if(dir == 1) p = iline_match_bkt_find(a,dir);
	else
       if( iline_match_bkt_incompat(c,c1))
	{ buntchar(act,RED); buntchar(a,RED); return(-2);}
       else return(a);
     }
    else
    if(c == ')' || c == '}' || c == ']')
     { if(dir == -1) p = iline_match_bkt_find(a,dir);
	else
       if( iline_match_bkt_incompat(c1,c))
	{ buntchar(act,RED); buntchar(a,RED); return(-2);}
       else return(a);
     }   
    if(p<0) return(p);
    a = p;
    goto loop;
  }
    
iline_match_bkt_incompat(char a,char b)
  {
    return(a == '(' && b != ')' ||
	   a == '[' && b != ']' ||
	   a == '{' && b != '}');
  }
 
#endif

bottom_page()
      // jump to bottom page if that is not the actual one
   {
      if(act_line != act_show) my_showpage(act_line);
   }

//*******************************************************************
//       character from keyboard (or paste)
//*******************************************************************/
      
do_char(char c)
     {long i;
      int j,k,l;
   
      if(c == 9) c=' ';    // 29.5.94:tab
      if(c<' ' && c!= '\n' && c != 0x1b) return(1); 
 
      liptr = MAXLIPUFFER;
      bottom_page();

     if(c != '\n')
     { 
       char_delete(0); 
       if (INSERT)
	{   for(i=254;i>i_ptr;i--)
		ipuffer[i]=ipuffer[i-1];
	    ipuffer[i_ptr] = ' ';
	 }
       
       if (o_ptr + i_ptr < wColumns) 
	  { ipuffer[i_ptr] = c; 
	    i_ptr++;
	  } 
	  
       if (o_ptr + i_ptr < wColumns)   
	  {
	    caret_x = caret_x + cWidth;
           /* WN 1.1.98 if(!hdef_input) */
            l = show_inputline(0); // blocked during paste for faster output
	    return(1);
	  }
     };
      
      l = show_inputline(1);
      if(c == '\n') ipuffer[l]  = '\n';  else ipuffer[l] = '\0';
      ipuffer[l+1] = '\0';
      insert = 1;  /* insert off */

       /* save input line */
       licount=max(licount-1,0);
       for(j=licount;j<MAXLIPUFFER-1; j++)
	    for(k=0;k<LINELENGTH;k++) lipuffer[j][k] = lipuffer[j+1][k];
       for(k=0;k<l;k++) 
	      lpuffer[act_line][o_ptr+k] = lipuffer[MAXLIPUFFER-1][k] 
					 = ipuffer[k];
					 
       for(k=l;k<LINELENGTH;k++) lipuffer[MAXLIPUFFER-1][k] = '\0';
       o_ptr = o_ptr+l;
       overwrite_caret = 1;
       my_putc('\n');
       overwrite_caret = 0;
	 
	 /* process the line, surrounded by the hourglass symbol */
       i_ptr = 0;
  
       hSaveCursor = SetCursor(hHourGlass);

       dri_cls = 0;
       state = CALL;
       i = my_input(ipuffer);
       state = LOOP;
       dri_cls = 1;
       hActCursor=SetCursor(hSaveCursor);
       if(hActCursor!=hHourGlass) SetCursor(hActCursor);
  
       for (j=0; j<LINELENGTH; j++) ipuffer[j] = '\0';
       insert = 0;   /* reactivate insert mode for next input */
       if (i==0) { destroy=1; return(0);} else return(1);
     }

/*******************************************************************
	 graphical display services
/*******************************************************************/

int draw_x,draw_y,fancy_line=-1;

fancy_display(int line,int mode,int yy)
   {
     int i,b,initial,free_y;

     initial = (mode == 1);

     /* decode and compute ranges */
     fancy_line = -1; /* lock refresher */
     fancy_start = line;
     /* find the line buffer */ 
     fancy_lines[0] = &lpuffer[line][2]; 
     fancy_lines[1] = 0;
     for(i=1; i<15 && line+i<=act_line && lpuffer[line+i][0]==0;i++)
	 {
	    fancy_lines[i] = & lpuffer[line+i][1];
	    fancy_lines[i+1] = 0;
	  };
     
	  /* close current line and set terminators */
     if(initial)
     { 
       fancy_on=1; my_putc('\n'); my_putc(0); my_putc(0); fancy_on=0;
       if(act_line >= wLines) yy = yy - cHeight; 
     }
     
     fancy_decode(initial);
   
     draw_y = yy; 
     free_y = (act_line-line+1) * cHeight;  //+1 reingesetzt
 y_range:    
     if(initial && free_y < fancy_yrange)
	{  
	   fancy_on = 1; my_putc('\n'); my_putc(0); my_putc(0); fancy_on =0;
	   if(act_line >= wLines) draw_y = draw_y - cHeight; 
	   free_y = free_y + cHeight;
	   goto y_range;
	}

     /* x range: use tab or center expression */
     if(!fancy_tab ||( (draw_x = fancy_tab*cWidth) + fancy_xrange > wpColumns))
	    draw_x = (wpColumns - fancy_xrange)/2;

     /* compute the y position after scroll up */
     /* screen coordinate act_y corresponds to act_line */
     if(initial)
     {
       draw_y = act_y - (act_line - fancy_start)*cHeight;  // -1 rausgenommen
     }

     /* start drawing */
     fancy_draw();
     if(initial) fancy_line = abs_line;    /* initial call ? */
	  else fancy_line = 0;
   }


/* 
  characters:
    font 0:     standard size
    font 1:     exponent size
    charset 0:  ascii 
    charset 1:  Greek
    charset 2:  math symbols
*/

inquire_char_box(int * coords,unsigned char c,int charset,int ffont)
     /* inquire surrounding box for character */
   {
      int d,fh;
      d=dcon(); 
      fh = font_height[ffont];
      coords[0] = 0; coords[1] = 0;        /* x0,y0 */ 
      if(charset == 0 && ffont==0) SelectObject(hDC, font[0]);
	      else 
      if(charset == 0 && ffont==1) SelectObject(hDC, font[1]);
	  else
      if(charset == 1 && ffont==0) SelectObject(hDC, symb_font[0]);
	      else 
      if(charset == 1 && ffont==1) SelectObject(hDC, symb_font[1]);

      if(charset == 0 || charset == 1)
      { 
	    GetCharWidth(hDC,c,c,&coords[2]);    /* x1,y1 */
	coords[3]=fh;
      }
	else
      if(charset == 2)
      { 
	 coords[2] = 2*font_width[ffont];
	 if(c=='i')  coords[3] = 3*fh;  /* integral */
	   else 
	 if(c=='I')  coords[3] = 5*fh;  // big integral
	    else 
	 if(c=='S')  coords[3] = 3*fh;   /* sum */ 
     }
     if(hFont) SelectObject(hDC, hFont);
     if(d) dcoff();
   }
draw_math(int x,int y,unsigned char c,int ffont); 

draw_string(int x,int y,unsigned char *c,int lth,int charset,int ffont)
     /* put character to screen */
   {
      int d;

      if(charset == 1) return draw_greek(x,y,*c,ffont);
      if(charset == 2) return draw_math(x,y,*c,ffont);
      d=dcon(); 
      if(ffont==0) SelectObject(hDC, font[0]);
	      else SelectObject(hDC, font[1]);
      
      if(charset == 1) 
      { 
	if(*c == 'p') *c = 227;   /* pi */
      }
      TextOutProp(hDC,x+draw_x,y+draw_y,c,lth);
      SelectObject(hDC, hFont);
      if(d) dcoff();
   }

draw_greek(int x,int y,unsigned char c,int ffont)
   {
     int d; HFONT h;
     d = dcon();
     h = SelectObject(hDC, symb_font[ffont]);
     TextOutSymb(hDC,x+draw_x,y+draw_y,(LPSTR)&c,1);
     SelectObject(hDC, h);
     if(d) dcoff();
   }

draw_math(int x,int y,unsigned char c,int ffont)
     /* put math symbol to screen */
   {
      int d,w,h;

      w = font_width[ffont]; h = font_height[ffont];
      x = x+draw_x; y = y+draw_y;

      d = dcon();
      if(ffont==0) SelectObject(hDC, symb_font[0]);
	      else SelectObject(hDC, symb_font[1]);
      
      if(c == 'i')     // Integral
      { 
	 
	 c = 0xf3; TextOutProp(hDC,x,y+2,(LPSTR)&c,1);   
	 c = 0xf4; TextOutProp(hDC,x,y+h,(LPSTR)&c,1);
	 c = 0xf5; TextOutProp(hDC,x,y+h+h-3,(LPSTR)&c,1);   
      }
      else if(c == 'I')     // big Integral
      { 
	 c = 0xf3; TextOutProp(hDC,x,y+4,(LPSTR)&c,1);   
	 c = 0xf4; TextOutProp(hDC,x,y+h+2,(LPSTR)&c,1);   
	 c = 0xf4; TextOutProp(hDC,x,y+h+h,(LPSTR)&c,1);
	 c = 0xf4; TextOutProp(hDC,x,y+h+h+h-3,(LPSTR)&c,1);
	 c = 0xf5; TextOutProp(hDC,x,y+h+h+h+h-5,(LPSTR)&c,1);   
      }
      else if (c == 'S')
      {
	    /* here we assume that the sum is printed with heigth 3 */
	y = y + h/2;
	MoveTo(hDC,x+w+w,y);
	LineTo(hDC,x,y);
	LineTo(hDC,x+w,y=y+h);
	LineTo(hDC,x,y=y+h);
	LineTo(hDC,x+w+w,y);
      }
      if(hFont) SelectObject(hDC, hFont);
      if(d) dcoff();
   }

draw_brack(int x,int y0,int y1,unsigned char c,int ffont)
     /* put large bracket to screen */
   {
      int d,h,p,w,x0,x1,ym,r,round,left,curl,dd,fat;
	    
	  /* use font for standard sizes */
      if((y1-y0)<=font_height[ffont]+1)
	   return(draw_string(x,y0,&c,1,0,ffont));

      d=dcon(); 

      round = c == '(' || c == ')';
      left  = c == '(' || c == '{' || c == '/';
      curl  = c == '{' || c == '}';
    
      x=x+draw_x; y0=y0+draw_y; y1=y1+draw_y; 
      p = font_height[ffont];
      w = font_width[ffont];           
     
      if (round) p = p/3; else if(curl) p = p/4; 
			  else p=0; /* sqare */
      
      if(left) { x0 = x+ w; x1 = x; }
	  else { x0 = x; x1 = x+ w; }
      x = x + w/2; 
      ym = y0 + (y1-y0)/2;
      dd = w/4; if(left) dd=-dd; 
      if (c == '|') x0 = x1 = x;

      if(font_nr == IDM_FONT_TIMES || font_nr == IDM_FONT_SYS)
	fat = 2; else fat = 1;

      for(r=0;r<fat;r++)
	if (c == '/' || c == '|') 
	 { MoveTo(hDC,x0+r,y0); LineTo(hDC,x1+r,y1); }
      else
      {
	MoveTo(hDC,x0+r,y0);
	LineTo(hDC,x+r,y0+p);
	if(curl)
	{ 
	  LineTo(hDC,x+r,ym-p);
	  LineTo(hDC,x1+r,ym);
	  LineTo(hDC,x+r,ym+p);
	}
	else if (round) LineTo(hDC,x+dd+r,ym);
       LineTo(hDC,x+r,y1-p);
       LineTo(hDC,x0+r,y1);
      }
      if(d) dcoff();
   }


draw_line(int x0,int y0,int x1, int y1)
     /* put line to screen */
   {
     int d,dx,dy;
     d=dcon();
     MoveTo(hDC,x0+draw_x,y0+draw_y);
     LineTo(hDC,x1+draw_x,y1+draw_y);
   /*  
       if(y0 == y1) {dy=1;dx=0;} else {dy=0;dx=1;}
       MoveTo(hDC,x0+draw_x+dx,y0+draw_y+dy);
       LineTo(hDC,x1+draw_x+dx,y1+draw_y+dy);
   */
     if(d) dcoff();
   }

/*******************************************************************
	 display services
/*******************************************************************/

dumpo(LPSTR txt,int l)
  {int i;
   for(i=0;i<l;i++) 
       {my_putoct(((long)txt[i])&0xff);
	if(!((i+1)&7)) my_putc(' ');
       }
   my_newline();
  }

my_putoct(l)
   long l;
   { wsprintf(aux,"%lx ",l); 
     my_puts(aux);
     my_flush();}

my_putint(l)
   long l;
   { wsprintf(aux,"%ld ",l); 
     my_puts(aux);
     my_flush(); }


my_puts(s)
     unsigned char s[];
     {int i=0; unsigned char c;
      while(c = s[i++]) my_putc(c);
      my_flush();
     }

void far_puts(s)
     LPSTR s;
     {int i=0; unsigned char c;
      lstrcpy(buffo,s);
      while(c = buffo[i++]) my_putc(c);
      my_flush();
     }
      
      
my_newline()
     {my_putc('\n');
      my_flush();
     }


my_putc(c)
     unsigned char c;
     {int i;
      char cc;

      c = c & 0xff;

      if(act_line != act_show) my_showpage(act_line);

      if(c == 9)  // TAB  jump to next multiple of 8   19.2.94
      { my_putc(' '); while(o_ptr & 7) my_putc(' '); return(0);}
     
      if(c == FANCY_ON)
      { if(!fancy_on) 
	   
	   fancy_on = 1;
	   fancy_start=act_line+1;
	   my_putc('\n');
	  }
     else if(c == FANCY_OFF) 
	  { 
	   fancy_on = 0;
	   lpuffer[act_line][o_ptr++] = c;   // 15.4.94 Zeile neu
	   fancy_display(fancy_start,1,
				act_y-cHeight*(act_line-fancy_start)); 
	   return(0);
	  }
      
 
      if (c=='\n' || o_ptr>=(LINELENGTH-1) || (!fancy_on && o_ptr>=wColumns)) 
	 {my_flush();
		  
	  if(fancy_on) cc = 0; else cc=' ';
	  for (i=o_ptr; i< LINELENGTH; i++) 
	      lpuffer[act_line][i]=cc; /* fill line*/
	      lpuffer[act_line][LINELENGTH] = 0;
	  if(dribble) dribble_line((char*)lpuffer[act_line],o_ptr,dri_cls);
	  o_ptr = po_ptr = 0; 
	  caret_x = 0;
	  act_y = act_y + cHeight; 
	  caret_y = act_y;
	  act_line ++; abs_line ++;  act_show ++;  /* show line hier neu*/
	  my_scrollup();
	  if(fancy_on) lpuffer[act_line][o_ptr++] = 0;
	 };

      if ((c>= ' ' && c< 0xff) || c==0 || c==FANCY_ON)
	 {lpuffer[act_line][o_ptr]=c; o_ptr++;}
     }

my_flush()
    {   
	  if(po_ptr == o_ptr || fancy_on) return(0);
	  dcon();  
	 if(lpuffer[act_line][0])   /* dont display fancy data */
	  TextOutFix(hDC,(po_ptr) * cWidth,act_y,
		      &lpuffer[act_line][po_ptr],
		      o_ptr-po_ptr+1);
	  dcoff();
	  po_ptr = o_ptr;
	  caret_x = o_ptr * cWidth;
	  return(1);
     }



 my_scrollup()
    {
     int i,j;
     int brk=0;


    if(act_line > MAXLOPUFFER-1)
    { 
      char * lp0;

      lp0 = lpuffer[0];
      for(i=0;i<MAXLOPUFFER;i++) lpuffer[i]=lpuffer[i+1];
      lpuffer[MAXLOPUFFER] = lp0;
      act_line--; fancy_start--; bLine--; 
    }
     for(j=0;j<wColumns;j++) lpuffer[act_line][j]= ' ';

     page_count++;

     if(act_y >= wpLines )
     {  

	 mach_weiss();

     if(page_count < SCROLLUP) page_count = SCROLLUP;

     if(page_mode && ( page_count + SCROLLUP) > (wLines-2))     /* 27.9.93 */
	    { if(!IsIconic(hWnd)) brk=wait_keyboard(); page_count=0;};

	 during_scroll = 1;
	 act_y=act_y - cHeight*SCROLLUP;
	 bLine = bLine + SCROLLUP;
	 caret_y = act_y;
	 ScrollWindow(hWnd,0, -cHeight*SCROLLUP,NULL,NULL);
	 UpdateWindow(hWnd);
	 during_scroll = 0;
	 sel_x =  sel_y = s_x = s_y = -1;
     };
     caret_y = act_y;
     act_show = act_line;
     SetScrollRange(hWnd,SB_VERT,min(act_line-1,wLines),act_line,0);
     SetScrollPos(hWnd,SB_VERT,act_line,1);
       /* redisplay last line */
     if(overwrite_caret) 
      {  
	dcon();    
	if(lpuffer[act_line-1][0])
	  TextOutFix(hDC,0,act_y - cHeight,lpuffer[act_line-1],wColumns);
	dcoff();
      };
    if(brk) TerminalInterrupt();
    }
     
my_refresh()
    {int i,j,v,b;
     if(act_line<2) return(0);
     during_paint = 1;
     if (hFont) SelectObject(hDC, hFont); 
     b = act_line - act_y / cHeight;
     bLine = b;
     act_y = 0;
     act_show = act_line;

/*     if (b < 0) {iwarning("b is negative",b);}
     /*WN*/
      /* find starting point of last previous fancy display */
     if((b >=0) && (lpuffer[b][0] == '\0'))
     {   
	  int j=b, a_y=act_y;
	  while(j>0 && lpuffer[j][1] != FANCY_ON) {j--; a_y=a_y - cHeight;}
	  if(b>j && j>0) fancy_display(j,2,a_y); 
     }  

     for(i=b;i<=act_line;i++)
	  { 
	if (i<0);               /* before start */
	else if(lpuffer[i][0])
	       TextOutFix(hDC,0,act_y,lpuffer[i],wColumns); 
	    else if(lpuffer[i][1] == FANCY_ON) fancy_display(i,2,act_y);
	    act_y=act_y + cHeight;
      };
     act_y=act_y - cHeight;
     /*  if (i_ptr != 0)      27.9.93 */ 
	    show_inputline(1);
     SetScrollPos(hWnd,SB_VERT,act_line,1);
     sel_x=sel_y=s_x=s_y=-1;
     during_paint = 0;
    }

my_showpage(n)
   /* display previous page with bottom line n */
    {int i,j,v,b;
     clear_screen();
     dcon();
     mySetBkMode(hDC,TRANSPARENT);
     act_y=0;
     if(n>act_line) n= act_line;
     b = n - wLines +1; /* base */
     if (b<0) {n = min(n-b,act_line); b=0;}
     bLine = b;
     act_show = n;
	/* find starting point of last previous fancy display */
     {   
	  int j=b-1, a_y=act_y-cHeight;
	  while(j>0 && lpuffer[j][1] != FANCY_ON) {j--; a_y=a_y - cHeight;}
	  if(j>0) fancy_display(j,2,a_y);
     }
	/* display fully visible part */
     for(i=b;i<=n;i++)
	  { if(lpuffer[i][0])
	       TextOutFix(hDC,0,act_y,lpuffer[i],wColumns); 
	    else if(lpuffer[i][1] == FANCY_ON) fancy_display(i,2,act_y); 
       act_y=act_y + cHeight;};
     act_y=act_y - cHeight;
     dcoff();
     SetScrollPos(hWnd,SB_VERT,n,1);
     if(n == act_line)
     {
	if(i_ptr !=0 ) show_inputline(1); else caret_y=act_y; 
     }
     sel_x=sel_y=s_x=s_y=-1;
    }

my_movepage(int n)
    {
     int a,b;
   
     if (act_show == act_line && n>0
		||
	 act_show-wLines<0 && n<0) return(0);

     a = act_show ; 
     b = a - act_y / cHeight;
    // b--;

      if (act_show == act_line && act_y + cHeight < wpLines)
	  { 
	     act_y=act_y + cHeight;
	     b--;
	  }
	else 
	  { 
	    a=a+n; b=b+n;  
	    act_show = a;
	  };
	 mach_weiss();
	 during_scroll = 1;
    
     SetScrollPos(hWnd,SB_VERT,act_show,1);
	 ScrollWindow(hWnd,0, -cHeight*n,NULL,NULL);
	 UpdateWindow(hWnd);
	 during_scroll = 0;
     if(n==1) my_display_line(a,b); else  my_display_line(b,b);
     bLine = b; // 28.5.94
     if(act_show == act_line) show_inputline(1);
    }

my_display_line(int n,int base)
  // write line "n" to window with actual base line "base"
{
     int a_y,b;

     b = n;
     a_y = (n-base)*cHeight;
     dcon();
     mySetBkMode(hDC,TRANSPARENT); 
 
     if (b > -1) { 
       if(lpuffer[b][0] == '\0')
	/* find starting point of last previous fancy display */
     {   
	  while(b>0 && lpuffer[b][1] != FANCY_ON) {b--; a_y=a_y - cHeight;}
	  if(b>0) fancy_display(b,2,a_y); 
     }
	else  TextOutFix(hDC,0,a_y,lpuffer[b],wColumns); 
		 };   
     dcoff();
}
 
test_blank_line(int n)
    {
     int i=0; char c;
loop:     
     if((c=lpuffer[n][i]) == '0' || c == '\n') return(1);
     if(c != ' ' || i++>10) return(0);
     goto loop;
    }

my_print_page(int lo,int hi)
    {int i,j,v,b,upper,act_yy;
     if(act_line<2) return(0);
     during_paint = 1;
     if (hFont) SelectObject(hDC, hFont); 
     b = act_show - act_y / cHeight;
     act_yy = 0; upper = 9999;

     if(hi) 
       { b=b+lo; upper = b+hi-1; }   

       /* find starting point of last previous fancy display */
     {   
	  int j=b;
	  while(j>0 && lpuffer[j][1] != FANCY_ON) 
	       if(test_blank_line(j)) j--; else j=0;
	  if(j>0) b=j; 
     }

     for(i=b;i<=act_line;i++)
	  { 
	if (i<0 || i>upper);               /* before start */
	else if(lpuffer[i][0])
	       TextOutFix(hDC,0,act_yy,lpuffer[i],wColumns); 
	    else if(lpuffer[i][1] == FANCY_ON) fancy_display(i,2,act_yy);
	    act_yy=act_yy + cHeight;
      };
     sel_x=sel_y=s_x=s_y=-1;
     during_paint = 0;
    }
