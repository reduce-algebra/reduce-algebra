/*
 * "cwin.h"                                   1995-99, A C Norman
 *
 * This defines the public interface supported by the "cwin" window
 * interface.  This header file may be used by anybody for any purpose.
 *
 * This is version 2.0, September 1995
 */

/*
 * The code here is provides a windowed framework in which reasonably
 * ordinary C code can run.  The functions described here are the
 * interface.  Version for Windows 95 as well as win32s and Windows NT.
 */

/* Signature: 7f7ab8b1 19-Feb-1999 */

#ifndef header_cwin_h
#define header_cwin_h 1

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The "C" code will eventually be entered at cwin_main() in what looks like a
 * normal way.  The function cwin_main() MUST return. There is no provision
 * for anything like the exit() function present in normal C libraries. The
 * reason for this uncomfortable situation is that my window manager code
 * needs to regain cotrol to close things down and tidy up at the end.
 * Furthermore conflicts between C++ exceptions and C "setjmp" appear to make
 * it hard to find a reliable way of skipping down stack frames across the
 * two languages.  So I have to insist that that user deals will all
 * necessary unwinding by hand. Apologies.
 */
extern int cwin_main(int argc, char *argv[]);

/*
 * cwin_full_program_name is a string like "d:\xxx\yyy\something.exe"  This is
 * made available so that applications can edit it to generate names of
 * resource files (eg by just altering the ".exe" bit on the end into some
 * other suffix.
 */
extern char *cwin_full_program_name;

/*
 * programName[] holds just the "something" out of cwin_full_program_name.
 */
extern char programName[64];

/*
 * Something that is SPECIAL and IMPORTANT to this code is that all the
 * code executed via cwin_main() must arrange to call
 *           cwin_poll_window_manager();
 * every so often.  If this does not happen the window system will become
 * unresponsive.
 */
extern void cwin_poll_window_manager();

/*
 * To finish off you can either return from cwin_main(), or you can go
 *        cwin_exit(n);
 * The system will forcibly close down for you if the EXIT item on
 * the FILE menu or the CLOSE item on the SYSTEM menu gets selected.  But
 * direct use of the C function "exit()" is not considered proper.
 */

extern void cwin_exit(int return_code);

/*
 * To be on the safe side I make exit() a macro for cwin_exit(). This is
 * a function that does not exist! It is declared here so that attempts to
 * call it will lead to suitable link-time diagnostics.
 */
#undef exit
#define exit(n) cwin_exit(n)
extern void cwin_exit(int n);

/*
 * If, when the program is stopping, cwin_pause_at_end has been set to
 * be non-zero (by default it will be zero) then an alert box is displayed
 * forcing the user to give positive confirmation before the main window
 * is closed.  This does not give an opportunity to cancel the exit, just to
 * read the final state of the screen...   This effect does not occur if
 * program exit is caused by selecting EXIT from the FILE menu or CLOSE
 * from the system menu. That is (deliberate in my code) because in those
 * cases the user has taken explicit interactive action to terminate the
 * program so an extra prompt seems unnecessary.
 */
extern int cwin_pause_at_end;


/*
 * cwin_minimize() indicates that the window should be shrunk to be just
 * an icon.
 */
extern void cwin_minimize();

/*
 * cwin_maximize() indicates that the window should be restored to
 * regular size. I do know that in Windows the term "maximize" would more
 * usually indicate expansion to fill the whole screen, and what I am
 * doing here is a "restore to normal size", but I have chosen not to
 * provide an option that explodes windows to full screen size.
 */
extern void cwin_maximize();

/*
 * Rather than using putchar() and printf(), here are the calls
 * the can be made to get output onto the screen.  NOTE that cwin_puts()
 * is more like fputs than puts in that it just dumps the characters in its
 * string to the screen [it does not add an extra newline in the way that
 * puts does].
 * These functions support printable ASCII characters.
 * I have not thought too hard about TAB and FormFeed here... yet.
 * Some control codes may be used to change fonts and colours, but at
 * present I will not document that here.
 */
extern void cwin_putchar(int c);
extern void cwin_puts(const char *s);
extern void 
#ifdef _MSC_VER
            __cdecl
#endif
            cwin_printf(const char *fmt, ...);
extern void cwin_vfprintf(const char *fmt, va_list a);

/*
 * cwin_linelength holds the number of normal-sized (ie the basic
 * fixed-pitch font being used) characters that fit across the screen.
 * Its value can change at any time. When the screen is minimized its value
 * will remain at the pre-minimized value. An attempt is made to create
 * the initial window to make this have the value 80.
 */
extern int cwin_linelength;

#ifdef SOMETIME_LATER_ON
/* Transliteration between Roman and Greek alphabets */
extern char latinOf[26];
#endif /* SOMETIME_LATER_ON */

/*
 * ensure_screen() causes the display to catch up with whatever else has
 * been going on.
 */
extern void cwin_ensure_screen();

/*
 * cwin_getchar() behaves rather as one might expect getchar() to - it
 * grabs a character from the keyboard input buffer.
 */
extern int cwin_getchar();

/*
 * cwin_getchar_nowait() is just like cwin_getchar() except that if
 * no character is immediately available it returns EOF instead of
 * waiting.
 */
extern int cwin_getchar_nowait();

/*
 * If any characters had already been typed and were waiting to be
 * read, this abandons them.
 */
extern void cwin_discard_input();

/*
 * cwin_set_prompt() tells cwin what string (of up to 32 characters)
 * should be used as a prompt.
 */
extern void cwin_set_prompt(const char *s);

/*
 * The following is just for use by REDUCE. It adjusts menu entries
 * to support loading packages and setting/clearing REDUCE switches.
 */
extern void cwin_menus(char **modules, char **switches);

/*
 * cwin_interrupt_pending can be set by the "interrupt" menu and is intended
 * to be used to halt calculations in the main program. It gets set to 1
 * on "INTERRUPT" and to 3 on "BACKTRACE".
 */
extern int cwin_interrupt_pending;

/*
 * Short messages can be displayed at the left middle and right of the
 * main title-ribbon of your window.  These functions set the text to be
 * displayed there.  If there is not much room then only the middle one
 * will remain visible.  Each message should be limited to around 30 chars
 * (and will be best if kept shorter than that).  The default position is that
 * the left position displays the time & date, the middle one the name of
 * the program being run and the right one is blank. cwin_report_left(NULL)
 * or cwin_report_mid(NULL) re-instate the default display. Use
 * cwin_report_left("") to get an empty left message.
 */
extern void cwin_report_left(const char *msg);
extern void cwin_report_mid(const char *msg);
extern void cwin_report_right(const char *msg);

/*
 * The following four strings may be updated (but PLEASE keep within the
 * length limit) to make the display in the "ABOUT" box reflect your
 * particular application.
 */
extern char about_box_title[32];       /* "About XXX";           */
extern char about_box_description[32]; /* "XXX version 1.1";     */
                                       /* <icon appears here>    */
extern char about_box_rights_1[32];    /* "Copyright Whoever";   */
extern char about_box_rights_2[32];    /* "Date or whatever";    */

/*
 * The HELP drop-down menu in cwin always has some basic items on it, but
 * the user can add more by calling cwin_setHelpFile() where arg 1 is the
 * text to appear on the menu and arg 2 identifies the help file that will be
 * opened if the menu item is selected. Specifying NULL as the second item
 * removes the key. The information about help keys is kept in the registry
 * not in any file that CSL has direct access to, and the new help items may
 * not be visible until the user exits from CSL and re-starts it.
 */
extern void cwin_set_help_file(const char *key, const char *path);

#ifdef SOMETIME_LATER_ON

/*
 *  Now a simple graphics interface...
 */
  
typedef double transform[3][3];

extern void cwin_circle(unsigned colour, double size, transform c);

extern void cwin_point(unsigned colour, transform c);

extern void cwin_line(unsigned colour, double size, transform c);

extern void cwin_square(unsigned colour, double size, transform c);

extern void cwin_show();

extern void cwin_clear();

#endif /* SOMETIME_LATER_ON */


#ifdef __cplusplus
}
#endif

#endif /* header_cwin_h */

/* end of "cwin.h" */

