/* include file for the LISP - PSLLW communication */

#define    YIELD             0
#define    PUTS              1
#define    PUTINT            2
#define    PUTOCT            3
#define    NEWLINE           4
#define    PUTC              5
#define    BINARYOPENREAD    6
#define    BINARYOPENWRITE   7
#define    BINARYCLOSE       8
#define    BINARYREADBLOCK   9
#define    BINARYWRITEBLOCK 10
#define    GETDATE          12
#define    TIMC             13
#define    SIGNAL           14
#define    CD               15
#define    FGETS            16
#define    SYSTEM           17
#define    YESP             18
#define    GETTIME          19
#define    LINELENGTH       20
#define    ASKUSER          21
#define    LSEEK            22
#define    HELP             23
#define    CONNECT_OPEN     24
#define    CONNECT_CLOSE    25
#define    CONNECT_FETCH    26
#define    CONNECT_SEND     27
#define    CONNECT_ASK      28
#define    CONNECT_BLOCK    29
#define    SLEEP            30
#define    PSLL_RESET       31
#define    EXIT_WITH_STATUS 32
#define    PIPE_OPEN        33
#define    PIPE_CLOSE       34
#define    PAGE             35
#define    MENU             36
#define    WIN_PAR          37
#define    FILE_TREE        38
#define    PIPE_WRITE       39


/* functions for callback */


#define PSLCALL_TERMINAL_INTERRUPT  0
#define PSLCALL_RESIZE              1 
#define PSLCALL_GRAPHICS_MODE       3
#define PSLCALL_GRAPHICS_MODE_ON    3
#define PSLCALL_GRAPHICS_MODE_OFF   4
#define PSLCALL_MENU                5
