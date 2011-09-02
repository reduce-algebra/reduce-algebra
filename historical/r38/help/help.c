/*=======================================================================
/*      
/*     REDUCE help interface
/*
/*     Author: H. Melenk, ZIB-Berlin, Nov. 1992
/*
/*
/*=======================================================================
/*
/*     interface:  Help file must have been compiled by
/*                 GNU Texinfo system
/*
/*     compile: UNIX:   cc help.c -DUNIX -o help
/*              DOS:    cl -DMSC -DANSI help.c    
/*                      (for Microsoft C, ansi.sys screen control)
/*                or    cl -DMSC help.c           
/*                      (for Microsoft C, bare screen usage)
/*
/*
/*     call(Unix): help -f helpfile
/*           or    help -f helpfile topic
/*                     where <topic> is an initial help topic.
/*
/*=======================================================================*/ 

#include <stdio.h>
#include <setjmp.h>

#if defined MSC
#include <string.h>
#include <dos.h>
#endif

#ifndef SEEK_SET
#define SEEK_SET 0
#endif

FILE * helpfile;

#define PAGE     0x1f
#define EOL      0x0a
#define MAX_NODE 1000
#define MAX_TABLE 1000
#define NAME_LENGTH  50

char tag[30];
char Node[NAME_LENGTH],Next[NAME_LENGTH],Prev[NAME_LENGTH],Up[NAME_LENGTH];

int node_count;


char  * node_name[MAX_NODE];
long  node_adr[MAX_NODE];
long  table[MAX_TABLE];
int   table_count;


long top_node,act_node;
int bp; char buffer[100]; char out_buffer[100];

long read_number();
long find_node();

#if defined MSC
int  strncasecmp(char * u, char * v,int n);
int  display(long);
int  video=0;
int  fg_color,bg_color;
#endif

jmp_buf more_base;

main(argc,argv)
   char * argv[]; int argc;
 {
     int i; 
     char cmd;
     char*search_node;
     long ll;

#if defined UNIX
     printf(" UNIX ");
#endif
#if defined MSC
#if defined ANSI
     { 
       union REGS regs; 
       regs.h.ah = 0x1a; /* read display code */
       regs.h.al = 0;
       int86(0x10, &regs, &regs);
       video=(regs.h.bl==2) || (regs.h.bl==4) || (regs.h.bl==6)
			    || (regs.h.bl==8) || (regs.h.bl>=0x0c);
       regs.h.ah = 0x08; /* read actual color */
       regs.h.bh = 0;
       int86(0x10, &regs, &regs);
       fg_color=regs.h.ah & 0xf;
       bg_color=(regs.h.ah>>4) & 0x7;
       regs.h.ah = 5;  /* set video page */
       regs.h.al = 1;  /* page number */
       int86(0x10, &regs, &regs);
     }
#endif
     printf(" DOS ");
#endif
     printf(" REDUCE help system \n");
     if(argc<2 || strcmp(argv[1],"-f")) wrong_call(argc,argv);
#if defined MSC     
     helpfile = fopen(argv[2],"r+b");
#else
     helpfile = fopen(argv[2],"r");
#endif     
     if(!helpfile)
     {printf("cannot open help file >%s<\n",argv[2]); my_exit(1);};

     
     /* find table of contents */
     find_TOC();
     top_node = find_node("Top");
     if(!top_node) 
     { printf("Top node not found\n"); my_exit(1);};
     act_node=top_node;
     
     if(argc>3) 
     {
	 ll=find_matching_nodes(argv[3],strlen(argv[3]));
	 if(ll)  goto next_command;
	     else printf("**** no item matching >%s<\n",argv[3]);
     };

  loop:
     display(act_node);

  next_command:
     cmd = command();

     if(cmd == 'q' || cmd == 'Q' || cmd == 'x' || cmd == 'X') my_exit(0);
       else

     if(cmd == '+' || cmd == 'n' || cmd == 'N')
	 { if(Next[0]) {search_node=Next; goto search;}; goto loop;}
       else

     if(cmd == '-' || cmd == 'p' || cmd == 'P')
	 { if(Prev[0]) {search_node=Prev; goto search;}; goto loop;}
       else 

    if(cmd == 't' || cmd == 'T')
	 { act_node=top_node; goto loop;}
       else

     if(cmd == 'U' || cmd == 'u' || cmd == 'U')
	 { if(liter(Up[0])) {search_node=Up; goto search;}; goto loop;}
    
     goto loop;
  
  search:
     ll = find_node(search_node);
     if(ll) {act_node=ll; goto loop;};
     /* printf("\n ****** node >%s< not found\n",search_node);  /* */
     goto loop; 
  }

my_exit(n)
   int n;
   {
#if defined ANSI
      if(n) getch();
     { 
       union REGS regs;
	    more_putc(0x1b); more_putc('[');
	    more_putc('0'); more_putc(';'); 
	    more_putc('4'); more_putc('0'+bg_color); more_putc(';');
	    more_putc('3'); more_putc('0'+fg_color); 
	    more_putc('m');
       regs.h.ah = 5;  /* set video page */
       regs.h.al = 0;  /* page number */
       int86(0x10, &regs, &regs);
     }
#endif
    exit(n);
   }



command()
   {
    char c; int n;
    long ll;

  loop:
    printf("\n Enter: "); 
    printfhighlight("+ - u t s q ?");
    if(table_count>0) printf(" or a reference number\n");
  nextchar:
    n=0;
#if defined MSC
    c=getch(); putchar(c);   /* input without return */
#else    
    c=getchar();
#endif
    if(digit(c)) goto number;

    if(c == ' ' || c == EOL) goto nextchar;
    if (c == '+' || c == '-' || c == 'u' || c == 'U'
		 || c == 't' || c == 'T'
		 || c == 'q' || c == 'Q'
		 || c == 'x' || c == 'X'
	) return(c);
    if (c == '?' || c== 'h'  || c == 'H') goto help;
    if (c == 's' || c== 'S') goto find;
    goto loop;

 number:
    n= 10*n+(c-'0');
    c=getchar();
    if(digit(c)) goto number;
    if(0<n && n<=table_count)
      {act_node = table[n]; return('d');}

     /* search item entered from terminal */
 find:
    bp =0;
    while((c=getchar()) != EOL)
      if(c!=' ' || bp>0) buffer[bp++]=c;
    buffer[bp] = 0;
    ll=find_matching_nodes(buffer,bp);
    if(!ll) printf("**** no item matching >%s<\n",buffer);
    goto loop;

 help:
    printf("\n Enter command terminated by Return Key:\n");
    printf(" +   browse forwards to next topic on same level.\n");
    printf(" -   browse backwards on same level.\n");
    printf(" u   return to next upper level (directory).\n");
    printf(" t   return to top directory.\n");
    printf(" nnn (nnn a number): \n");
    printf("     select the nnn-th topic from menu or context,\n");
    printf("         don't enclose number in sqare brackets.\n");
    printf(" s cccc (cccc sequence of characters): \n");
    printf("     search topics which match the character sequence:\n");
    printf("         not case sensitive, no wildcard;\n");
    printf("         result is a selection menu.\n");
    printf(" q   quit help.\n");
  goto loop;
 }
    
    
   
display(adr)
   long adr;
   { 
    char c;
    int i;
    int state;
    long ll;
    char * bv;
    

    /*  printf("display node: %ld\n",adr); /*  */

    if(seek_char(adr)) 
     {printf("cannot find file position %lx\n",adr); my_exit(1);};
     
    Next[0]=0; Prev[0]=0; Up[0]=0; 

 loop:
    read_tag();
    if(!strcmp(tag,"File:"))
      {read_string(tag); goto loop;}
       else 
    if(!strcmp(tag,"Node:"))
      {read_string(Node); goto loop;}
       else
    if(!strcmp(tag,"Next:"))
      {read_string(Next); goto loop;}
       else
    if(!strcmp(tag,"Prev:"))
      {read_string(Prev); goto loop;}
       else
    if(!strcmp(tag,"Up:"))
       read_string(Up);
      else
    {printf("\n *** unknown node tag:>%s<",tag); /*exit(1);*/};

    if(setjmp(more_base)) goto done;

    more_open();
    for(i=0;i<71;i++) more_putc('='); 
    more_putc(EOL);
     
    state = 0; bp=0; table_count=0;
    while((c=read_char()) != PAGE)
     {   
       more_putc(c);
    
       /* look for menu and note entries */
	    if(c == '*' && state==0) state=2;
       else if(c == ':' && state==2) state=4;
       else if(c == ':' && state==4)
       { /* menu entry found */
	 buffer[bp]=0;
	 /*  printf("menu entry: >%s<\n",buffer);  */
	 bv = buffer;
	 if(!strncmp(bv,"note ",5)) bv=bv+5;
	 ll = find_node(bv);
	 if(ll && table_count<MAX_TABLE)
	  { table_count++;
	    table[table_count]=ll;
	    sprintf(out_buffer,"[%d]",table_count);
	    highlight_on();
	    for(i=0;out_buffer[i];i++) more_putc(out_buffer[i]);
	    highlight_off();            
	    state=0; bp=0;
	  };
	}
       else if(state==2 && bp<NAME_LENGTH
	       && (liter(c) || digit(c) || c==' ')) 
		    {if(c!=' ' || bp>0) buffer[bp++]=c;}
       else {
	     if(c=='*') state=2; else state=0; 
	     bp=0;
	    };
     };
  
   done:
     more_close();

   }

FILE * pfeife = NULL;
int  use_pipe = 0, more_line_count;

more_open()
   {
     FILE * loc;
     more_line_count=0;
     pfeife = stdout;
     use_pipe = 0;
#if defined UNIX
     loc = popen("more","w");
     if(loc) { pfeife = loc; use_pipe = 1;}
#endif
      
#if defined ANSI
      more_putc(0x1b); more_putc('['); 
      more_putc('3'); more_putc('7');
      more_putc(';'); more_putc('4'); more_putc('4'); more_putc('m');
      more_putc(0x1b); more_putc('[');
      more_putc('2'); more_putc('J');
#endif

    }

more_putc(c)
   char c;
   { 
      int i;
      char d=0;

      if(use_pipe) putc(c,pfeife);
      else
      {
       putchar(c);
       if(c==EOL)
       { if(more_line_count++ >= 22)
	  {more_line_count=0;
#if defined MSC
	   highlight_on();
	   printf("--More--");
	   highlight_off();
	   d = getch();
	   for (i=0;i<30;i++) putchar(8);
#else           
	   printf("--More--\n");
	   d = getchar();
#endif      
           if(d == 'q' || d == 'Q') longjmp(more_base,1);
      }}  } 
   }
 
more_close()
  {
#if defined UNIX
   if(use_pipe) pclose(pfeife);
#endif
   use_pipe=0;
  }

long find_node(s)
   char * s;
   { int i;
     i=0;
     while(i<node_count && (s[0] !=node_name[i][0] ||strcmp(s,node_name[i])))
        {
         i++; 
      /* printf("%d(%d) suchen: >%s< >%s< \n",i,node_count,s,node_name[i]); */
       }
     if(i<node_count) return(node_adr[i]);
     printf("node not found: >%s< \n",s);
     return(0);
   }
    

find_matching_nodes (s,lth)
   char * s; int lth;
   { int i=0,j=0,k=1; char * t;
	 /* printf("find_node_case >%s< %d\n",s,lth); */
     more_open();
     while(i<node_count && (t=node_name[i]))
       { k=1;
	 while (t[0] && (k=strncasecmp(s,t,lth))) t++;
	    /* { printf(">%s< >%s< %x\n",s,t,k);t++;};*/ 
	 if(!k && j<MAX_TABLE)
	 { 
	   j++;
	   table[j]=node_adr[i]; 
	   t=node_name[i];
	   while(*t) more_putc(*t++);
	   sprintf(out_buffer,"[%d]",j);
	   highlight_on();
	   t=out_buffer; while(*t) more_putc(*t++); 
	   highlight_off();
	   more_putc(EOL);
	 }
	 i++;
       }
     more_close();
     if(j) table_count=j;
     return (j);
   }

find_TOC()
  {
     node_count=0;
  loop1:
     skip_char(PAGE);
     skip_char(EOL);
     read_tag();
     /*    printf("tag: %s\n",tag);  /*  */
     if(strcmp(tag,"TagTable:")) goto loop1;
     skip_char(EOL);
  loop2:
     read_tag();
     /*   printf("tag(Node?): %s\n",tag); /* */ 
     if(strcmp(tag,"Node:")) return(0);
     read_string(buffer);
     node_name[node_count] = (char*)malloc(strlen(buffer)+1);
     if(!node_name[node_count])
      {printf("ran out of memory\n"); my_exit(1);};
     strcpy(node_name[node_count],buffer);
     node_adr[node_count]=read_number();
     /*     printf("node %s %d\n",node_name[node_count],
		  node_adr[node_count]);  /* */
     node_count++;
     if (node_count > MAX_NODE)
      {printf("too many nodes found\n"); my_exit(1);};
     goto loop2;
  }
     
read_tag()
  {
   char c; int i;
   i=0;
   while((c=read_char()) && i<30
     && (digit(c) || liter(c) || c==' ' || (i==0 && c==EOL)))
	 if(c!=EOL && c!=' ')tag[i++]=c;
   if(c==':') tag[i++]=c;
   tag[i]=0;
   return(0);
  }

liter(c)
  char c;
  { return( (c>='a' && c<='z') || (c>='A' && c<='Z') || c == '_');}

digit(c)
  char c;
  { return(c>='0' && c<='9');}

read_string(s)
  char * s;
  {
   char c; int i;
   i=0;
   while((c=read_char())
     && (digit(c) || liter(c) || c==':' || c==' ' || c=='.'
	    || c=='(' || c==')' || c=='!' || c=='_' || c=='-'|| c=='?'
            || c=='*'))
       { s[i++]=c; if(i==1 && c==' ')i--;}
   s[i]=0;
   return(0);
  }

long read_number()
  {
   char c; long n;
   n=0;
   while((c=read_char()) && digit(c)) n = n*10 + (c-'0');
   return(n);
  }

/* buffered file io */

int b_ptr=0,b_size=-1;
#define BUFFLEN 2048
char buffo[BUFFLEN];

read_char()
   {
    char c;
    if(b_ptr<b_size) return(buffo[b_ptr++]);
    if(feof(helpfile))
     {printf("unexpected EOF found in help file\n"); my_exit(1);};
    b_size = fread(buffo,1,BUFFLEN,helpfile);
    b_ptr=1;
    return(buffo[0]);
  }

skip_char(u)
   char u;
  {
    char c;
  loop:
    if(read_char()==u) return(0);
    goto loop;
  }

seek_char(adr)
   long adr;
  {
     b_size=-2;
     return(fseek(helpfile,adr,SEEK_SET));
  }

/* error handlers */
wrong_call(argc,argv)
   char * argv[]; int argc;
  {
   int i;

   for(i=0;i<argc;i++)  printf("%s\n",argv[i]);
   printf("usage: help -f <file> [ <topic> ]\n ");
   my_exit(1);
  }

#if defined MSC

  /* Microsoft C does not support strncasecmp */

strncasecmp(char * u, char * v,int n)
   { 
     char cu,cv;
     int r=1;

     while(r && (n-- > 0))
     { cu = *u++; cv = *v++;
       if('a' <= cu) cu = cu-32;
       if('a' <= cv) cv = cv-32;
       r = (cu == cv);
     }
     return(!r);
   }

#endif

printfhighlight(s)
   char * s;
   {
     while(*s)
       {if(*s !=' ' && *s != EOL)
	  {   
	      highlight_on(); 
	      putchar(' '); 
	      putchar(*s);  
	      putchar(' ');
	      highlight_off(); 
	  }
	  else putchar(*s);
	  s++;
   }   }

  
highlight_on()
  {
#if defined ANSI
	if(video)    
	{
	    putchar(0x1b); putchar('[');
	    putchar('4'); putchar('3'); putchar('m');

	}
	else
	{
	    putchar(0x1b); putchar('[');
	    putchar('5'); putchar('m');
	}
#endif
  }

highlight_off()
  {
#if defined ANSI
	    more_putc(0x1b); more_putc('[');
	    more_putc('0'); more_putc(';'); 
	    more_putc('4'); more_putc('4');
	    more_putc('m');
#endif
   }
