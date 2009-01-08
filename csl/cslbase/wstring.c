/*
wstring.c

Copyright (C) 2003-2006 Gil Dabah, http://ragestorm.net/distorm/
This library is licensed under the BSD license. See the file COPYING.
*/


#include "wstring.h"

/*
// Protected buffers.
void strcpy_WS(_WString* s, const char* buf)
{
	s->pos = (unsigned int)strlen(buf);
	if (s->pos >= MAX_TEXT_SIZE - 1) s->pos = MAX_TEXT_SIZE-1;
	memcpy((char*)s->p, buf, s->pos);
	s->p[s->pos] = '\0';
}

void strcat_WS(_WString* s, const char* buf)
{
	unsigned int l = (unsigned int)strlen(buf);
	if ((s->pos + l) >= MAX_TEXT_SIZE - 1) l = MAX_TEXT_SIZE - s->pos - 1;
	memcpy((char*)&s->p[s->pos], buf, l);
	s->pos += l;
	s->p[s->pos] = '\0';
}*/

void _FASTCALL_ strcpy_WS(_WString* s, const char* buf)
{
	s->pos = (unsigned int)strlen(buf);
	memcpy((char*)s->p, buf, s->pos + 1);
}

void _FASTCALL_ strcpylen_WS(_WString* s, const char* buf, unsigned int len)
{
	s->pos = len;
	memcpy((char*)s->p, buf, len + 1);
}

void _FASTCALL_ strcatlen_WS(_WString* s, const char* buf, unsigned int len)
{
	memcpy((char*)&s->p[s->pos], buf, len + 1);
	s->pos += len;
}
