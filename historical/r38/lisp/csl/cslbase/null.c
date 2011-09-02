/* null.c                           Copyright (C) 2003-2007 Codemist Ltd */


/*
 * Copyright (c) 2004 A C Norman, Codemist Ltd
 * 
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 */



/* Signature: 0e7cda0e 18-Jan-2007 */

/*
 * There are some places where the autoconf/automake system wants to create
 * a Makefile that will include a certain file on a conditional basis. At
 * present in some such cases I find it messy to avoid including any file at
 * all so I sometimes compile and link in this little file - not because it
 * does anything but because in other cases something more useful might be
 * included instead!
 */

char *unused_string = "This file is a dummy one";


/* end of null.c */
