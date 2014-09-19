
/*
 * unexec.c - Convert a running program into an COFF file.
 * 
 * Author:      Winfried Neun
 *
 * Synopsis:
 *      unexec( new_name, a_name, data_start, bss_start )
 *      char *new_name, *a_name;
 *      unsigned data_start, bss_start;
 *
 * Takes a snapshot of the program and makes an COFF format file in the
 * file named by the string argument new_name.
 * If a_name is non-NULL, the symbol table will be taken from the given file.
 * 
 * This is a raw version, not many checks are done,etc.
 * Symbols are stripped from file
 *
 */

#include <stdio.h>
#include <filehdr.h>
#include <aouthdr.h>
#include <scnhdr.h>
#include <reloc.h>
#include <syms.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>

extern char etext, edata;  
#define L_SET 0
#define ETEXT (  ( (unsigned)&etext + (PAGSIZ-1) ) & ~(PAGSIZ-1)  )
#define EDATA (unsigned)&edata

static struct filehdr filhdrold,filhdrnew;
static struct aouthdr aouthdrold,aouthdrnew;
static struct scnhdr scnold,scnnew;

static long STEXT, LNGTEXT;
static long SDATA, LNGDATA;
static long numberofsects;
/* ****************************************************************
 * unexec
 *
 * driving logic
 */

unexec ( nnnnnn_name, o_name, data_start, bss_start )

char *nnnnnn_name, *o_name;
unsigned data_start, bss_start;
{
    FILE *newf;
    int new, a_out = -1 ,i , unexec_error;
    char new_name[256], a_name[256];

    /* Expand both filenames now. Place in seperate static arrays so that
       mallocs are not needed at runtime. Messes up the unexec by
       changing the oldbreakvalue.
     */
    strcpy(new_name, expand_file_name(nnnnnn_name));
    printf (" Data Start at %x, bss start at %x \n",data_start,bss_start);
    if (o_name)
      strcpy(a_name, expand_file_name(o_name));

    if ( a_name && (a_out = open( a_name, 0 )) < 0 )
    {
	perror( a_name );
	return -1;
    }
    if ( (newf = fopen( new_name, "w" )) == NULL )
    {
	perror( new_name );
	return -1;
    }
    fclose(newf);
    new = open( new_name, 1);       /* This fd will be written with zwrite. */

    make_filhdr( new, a_out, data_start, bss_start );
    make_aouthdr ( new, a_out, data_start, bss_start );
    for (i=1;i<numberofsects - 1 ;i++)
            make_scnhdr ( new, a_out, data_start, bss_start );
    make_datascnhdr ( new, a_out, data_start, bss_start );
    make_bssscnhdr ( new, a_out, data_start, bss_start );
	 /*
	copy_sym( new, a_out ) < 0) */
    if(unexec_error == 4711)
    {
	close( new );
	/* unlink( new_name );          /* Failed, unlink new a.out */
	return -1;      
    }

    close( new );
    if ( a_out >= 0 )
	close( a_out );
      mark_x( new_name ); 
    return 0;
}

/* ****************************************************************
 * make_filhdr
 *
 * Make the header in the new a.out from the header in core.
 * Modify the text and data sizes.
 */
static int
make_filhdr( new, a_out, data_start, bss_start )
int new, a_out;
unsigned data_start, bss_start;
{
    unsigned sbrk(), max_addr = sbrk(0);        /* End of allocated space. */

    /* Get symbol table info from header of a.out file if given one. */
    if ( a_out >= 0 )
    {
	if ( read( a_out, &filhdrold, sizeof filhdrold ) != sizeof filhdrold )
	{
	    perror( "Couldn't read header from a.out file" );
	    return -1;
	}

    /*
	if N_BADMAG( hdr )
	{
	    fprintf( stderr, "a.out file doesn't have legal magic number\n" );
	    return -1;
	}
    
	/* Save hdr as it was read in, to find symbol table in a.out file. */
    }
    else
    {
	perror( "symbolfilename* must be specified" );
	return -1;
    }
    /* Construct header from default assumptions.
     * (hdr.a_magic, hdr.a_entry and hdr.a_syms are set above.)
     */
    filhdrnew.f_magic = filhdrold.f_magic;
    filhdrnew.f_nscns = filhdrold.f_nscns;
    printf("** Number of sections: %d \n",numberofsects = filhdrold.f_nscns);
    filhdrnew.f_timdat =filhdrold.f_timdat;
    filhdrnew.f_symptr = 0;
    filhdrnew.f_nsyms  = 0;
    filhdrnew.f_opthdr =filhdrold.f_opthdr;
    filhdrnew.f_flags = filhdrold.f_flags;
    write (new, &filhdrnew,  sizeof filhdrnew);
}


/* ****************************************************************
 * make_aouthdr
 *
 * Make the header in the new a.out from the header in core.
 * Modify the text and data sizes.
 */
static int
make_aouthdr( new, a_out, data_start, bss_start )
int new, a_out;
unsigned data_start, bss_start;
{
    /* Get symbol table info from header of a.out file if given one. */
    if (read( a_out, &aouthdrold, sizeof aouthdrold ) != sizeof aouthdrold )
	{
	    perror( "Couldn't read aout header from coff file" );
	    return -1;
	}
    aouthdrnew.magic = aouthdrold.magic;
    aouthdrnew.vstamp = aouthdrold.vstamp;
    aouthdrnew.tsize = aouthdrold.tsize;
    aouthdrnew.dsize = bss_start - aouthdrold.data_start;
    aouthdrnew.bsize = sbrk(0) - bss_start;
    aouthdrnew.entry = aouthdrold.entry;
    aouthdrnew.text_start = aouthdrold.text_start;
    STEXT = aouthdrold.text_start;
    LNGTEXT = aouthdrold.tsize;
    SDATA   = aouthdrold.data_start;
    LNGDATA = aouthdrnew.dsize;
    aouthdrnew.data_start = aouthdrold.data_start;
    write (new, &aouthdrnew, sizeof aouthdrnew);
}

/* ****************************************************************
 * make_scnhdr
 *
 * Make the header in the new section and copy the section from core.
 */
static int
make_scnhdr( new, a_out, data_start, bss_start )
int new, a_out;

unsigned data_start, bss_start;
{   off_t oldpos,oldoldpos;
    /* Get symbol table info from header of a.out file if given one. */ 
    if (read( a_out, &scnold, sizeof scnold ) != sizeof scnold )
	{   
	    perror( "Couldn't read text scn header from coff file" ); 
	    return -1; 
	}   
    oldoldpos = tell (new);
    write (new, &scnold , sizeof scnold );
    oldpos = tell (new);
    /* copy the portion from memory to file */
    lseek(new,scnold.s_scnptr,L_SET);
    write(new,scnold.s_paddr,scnold.s_size);
    lseek(new,oldpos,L_SET);
     printf("** Written %s hdr to %d: start: %x lng : %x vaddr : %x \n",
          scnold.s_name,oldoldpos,scnold.s_scnptr,scnold.s_size,scnold.s_vaddr);
    return (0);   
}

int end_sdata;
 
/* ****************************************************************
 * make_datascnhdr
 *
 * Make the header in the new a.out from the header in core.
 * Modify the text and data sizes.
 */
static int
make_datascnhdr( new, a_out, data_start, bss_start )
int new, a_out;
unsigned data_start, bss_start;
{   off_t oldpos,oldoldpos;
    /* Get symbol table info from header of a.out file if given one. */
    if (read( a_out, &scnold, sizeof scnold ) != sizeof scnold )
	{
	    perror( "Couldn't read data scn header from coff file" );
	    return -1;
	}   
    scnold.s_size = bss_start - scnold.s_paddr;
    oldoldpos = tell (new);
    write (new, &scnold , sizeof scnold ); 
    oldpos = tell (new);
    lseek(new,scnold.s_scnptr,L_SET);
    write(new,scnold.s_paddr,scnold.s_size);
    lseek(new,oldpos,L_SET);
    printf("** Written %s hdr to %d: start: %x lng : %x  vaddr : %x\n",
          scnold.s_name,oldoldpos,scnold.s_scnptr,scnold.s_size,scnold.s_vaddr);
    end_sdata = scnold.s_paddr + scnold.s_size;
    return (0);   
} 
int sbsssize;

/* ****************************************************************
 * make_sbssscnhdr
 * 
 */ 
static int 
make_sbssscnhdr( new, a_out, data_start, bss_start ) 
int new, a_out; 
unsigned data_start, bss_start; 
{   off_t oldpos,oldoldpos;
    /* Get symbol table info from header of a.out file if given one. */ 
    if (read( a_out, &scnold, sizeof scnold ) != sizeof scnold ) 
	{ 
	    perror( "Couldn't read sbss header from coff file" ); 
	    return -1; 
	}    
    scnold.s_paddr = end_sdata;
    scnold.s_vaddr = end_sdata;
    sbsssize =  scnold.s_size ;
    oldpos = tell (new);

    write (new, &scnold , sizeof scnold );
    printf("** Written %s hdr to %d: start: %x lng : %x  vaddr : %x\n", 
          scnold.s_name,oldpos,scnold.s_scnptr,scnold.s_size,scnold.s_vaddr); 


}
/* ****************************************************************
 * make_bssscnhdr
 * 
 * Make the header in the new a.out from the header in core. 
 * Modify the t
 */
static int
make_bssscnhdr( new, a_out, data_start, bss_start )
int new, a_out;
unsigned data_start, bss_start;
{   off_t oldpos,oldoldpos;
    /* Get symbol table info from header of a.out file if given one. */
    if (read( a_out, &scnold, sizeof scnold ) != sizeof scnold )
        {
            perror( "Couldn't read sbss header from coff file" );
            return -1;
        }
    scnold.s_paddr = end_sdata ;
    scnold.s_vaddr = end_sdata ;
    printf(" sbrk(0) = %x \n",sbrk(0));
    scnold.s_size = sbrk(0) - end_sdata ;
    oldpos = tell (new);
 
    write (new, &scnold , sizeof scnold );
    printf("** Written %s hdr to %d: start: %x lng : %x vaddr : %x\n",
          scnold.s_name,oldpos,scnold.s_scnptr,scnold.s_size,scnold.s_vaddr);
 
 
}

/* ****************************************************************
 * mark_x
 *
 * After succesfully building the new a.out, mark it executable
 */
static
mark_x( name )
char *name;
{
    struct stat sbuf;
    int um;
 
    um = umask( 777 );
    umask( um );
    if ( stat( name, &sbuf ) == -1 )
    {
        perror ( "Can't stat new a.out" );
        fprintf( stderr, "Setting protection to %o\n", 0777 & ~um );
        sbuf.st_mode = 0777;
    }
    sbuf.st_mode |= 0111 & ~um;
    if ( chmod( name, sbuf.st_mode ) == -1 )
        perror( "Couldn't change mode of new a.out to executable" );
 
}
