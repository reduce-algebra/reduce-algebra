/* $Id$ */

#include "config.h"

#include "wxfwin.h"

#include <cstdio>



int main(int argc, char *argv[])
{
    std::fprintf(stderr, "wxshowmathdemo not implemented yet\n");
    return 1;
}

// A dummy definition that is needed because of wxfwin.cpp

int windowed_worker(int argc, const char *argv[],
                    fwin_entrypoint *fwin_main)
{   return 0;
}

