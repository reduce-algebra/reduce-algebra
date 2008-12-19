/*
 * foxdemo.cpp
 */


/**************************************************************************
 * Copyright (C) 2008, Codemist Ltd.                     A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

/* Signature: 284ce507 25-May-2008 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "fx.h"


int main(int argc,char *argv[])
{
    FXApp a("foxdemo", "foxdemo");   // Arguments are just used as
                                     // registry keys
    a.init(argc, argv);              // captures args and opens display
    FXMainWindow *win =
        new FXMainWindow(&a,         // application
                        "foxdemo",   // windows name
                        NULL,        // icon
                        NULL,        // icon
                        DECOR_ALL,   // all options
                        100,         // x position
                        100,         // y position
                        300,         // width
                        200);        // height
    FXButton *b =
       new FXButton(win,             // parent window
                    "QUIT",          // text
                     NULL,           //icon
                     &a,             // target for messages
                     FXApp::ID_QUIT, // selector code
                     BUTTON_NORMAL | // options
                        LAYOUT_FILL_X |
                        LAYOUT_FILL_Y);
    b->setFont(                      // specify font for the text
        new FXFont(&a, "serif", 36));

    a.create();                      // create window hierarchy
    win->show();                     // make window visible
    return a.run();                  // run until closed
}
