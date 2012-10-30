
/*
   Header file to export from graphics module
*/


extern char   *fancy_lines[];
extern int     fancy_xrange;
extern int     fancy_yrange;
extern int     fancy_tab;
extern int     font_width[2];
extern int     font_height[2];
extern int     xOffset;
extern int     yOffset;
extern int     boldGraphics;
extern int     graphIndex;
extern GC    **textGC;
extern GC      clearGC;
extern Boolean PostScriptMode;

extern OutputPixmapList *outputPixmapList;

extern void QueryCharDimensions();
extern void GetDefaultCharSizes();
extern void setupGraphics();
extern void PlaceSomeGraphics();

extern void enquire_char_box();
extern void draw_string();
extern void draw_math();
extern void draw_brack();
extern void draw_line();
extern void warning();
