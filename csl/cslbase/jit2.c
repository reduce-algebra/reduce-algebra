/* jit2.c                   Copyright (C) 2006-2008, Codemist Ltd */
/*                                                and J O'Connell */

/*
 * Helper functions for just in time compiler. A lot of this
 * is architecture-independent, but a few places are concerned with
 * the particular encoding of relative branches etc.
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




/* Signature: 4308698a 24-May-2008 */

#ifndef WIN32
#include <sys/mman.h>
#endif
#include "headers.h"
#include "bytes.h"
#include "jit.h"

/*
 * The following function is provided so that during debugging the JIT can
 * generate calls to it in the compiled code. It is then a convenient place
 * to set a debugger break-point. As can be seen, it does not do anything
 * beyond that!
 */
extern void break_here();

void break_here()
{
}

reloc_table *labels_table;
reloc_table *callers_table;
reloc_table *jumpers_table;
variables_table *vars_table;
reloc_table *disassembler_labels;

/*
 * Having a fixed-size buffer for collecting compiled code in is a temporary
 * situation!
 */
unsigned char codebuffer[8192];
unsigned long codep;

/*************************************************************************/

reloc_table *add_label_to_table(reloc_table *table,
                                char *label, unsigned long pos)
{
    /* new element added to end of list */
    reloc_table *new,*current;
    current = table; /* set current to head of list */
#ifdef JDEBUG
    /* check for any duplicate labels before adding. */
    /* labels determined by programmer so only needed while coding */
    reloc_table *tmp;
    tmp = table;
    while (tmp != NULL)
    {   if (strcmp(tmp->label,label)==0)
        {   printf("\nError in reloc table\nDuplicate entry: %s\n",label);
            return table;
        }
        else tmp = tmp->next;
    }
#endif
    /* Any elements added yet? */
/*
 * Hmmm - do I like using malloc()???
 */
    if (current == NULL)
    {   current = malloc(sizeof(reloc_table));
        current->next = table;
        table = current;
        current->label = (char*)malloc(strlen(label)+1);
        strcpy(current->label,label);
        current->pos = pos;
    }
    else
    {   /* Already elements in list */
        while (current->next != NULL) current = current->next;
        /* Now at end of linked list */
        new = malloc(sizeof(reloc_table));
        current->next = new;
        new->next = NULL;
        new->label = (char*)malloc(strlen(label)+1);
        strcpy(new->label,label);
        new->pos = pos;
    }
    return table;
}

reloc_table* add_caller_to_table(reloc_table *table,
                                 char *label, unsigned long pos)
{
    /* new element added to end of list */
    reloc_table *new, *current;
    current = table; /* set current to head of list */
    /* Any elements added yet? */
    if (current == NULL)
    {   current = malloc(sizeof(reloc_table));
        current->next = table;
        table = current;
        current->label = (char*)malloc(strlen(label)+1);
        strcpy(current->label,label);
        current->pos = pos;
    }
    else
    {   /* Already elements in list */
        while (current->next != NULL) current = current->next;
        /* Now at end of linked list */
        new = malloc(sizeof(reloc_table));
        current->next = new;
        new->next = NULL;
        new->label = (char*)malloc(strlen(label)+1);
        strcpy(new->label,label);
        new->pos = pos;
    }
    return table;
}


reloc_table* add_dis_label_to_table(reloc_table* table,
                                    char* label, unsigned long pos)
{
    /* 
     * New element added to the end of the list.
     * Allow duplicates
     */
    reloc_table *current,*new;
    current = table; /* set current to head of list */

    /* Any elements added yet? */
    if (current == NULL) 
    {   current = malloc(sizeof(reloc_table));
        current->next = table;
        table = current;
        current->label = (char*)malloc(strlen(label)+1);
        strcpy(current->label,label);
        current->pos = pos;
    }
    else
    {   /* Already elements in list */
        while (current->next != NULL) current = current->next;
        /* Now at end of linked list */
        new = malloc(sizeof(reloc_table));
        current->next = new;
        new->next = NULL;
        new->label = (char*)malloc(strlen(label)+1);
        strcpy(new->label,label);
        new->pos = pos;
    }
    return table;
}

variables_table* add_var_to_table(variables_table *table,
                                  int addr, unsigned long pos)
{
    /* 
     * New element added to the end of the list.
     * Allow duplicates
     */
    variables_table *current,*new;
    current = table; /* set current to head of list */

    /* Any elements added yet? */
    if (current == NULL)
    {   current = malloc(sizeof(variables_table));
        current->next = table;
        table = current;
        current->addr = addr;
        current->pos = pos;
    }
    else
    {   /* Already elements in list */
        while (current->next != NULL) current = current->next;
        /* Now at end of linked list */
        new = malloc(sizeof(variables_table));
        current->next = new;
        new->next = NULL;
        new->addr = addr;
        new->pos = pos;
    }
    return table;
}

void startcode()
{
    codep=0;
}

void putbyte(int c)
{
    /* check for buffer overflow */
    codebuffer[codep++]=c;
}

/*
 * For the next few, consider endian-ness of the target machine.
 */

void put2bytes(int c)
{
    putbyte((c>>8) & 0xff);
    putbyte(c & 0xff);
}

void put3bytes(int c)
{
    putbyte(c>>16 & 0xff);
    putbyte((c>>8) & 0xff);
    putbyte(c & 0xff);
}

void put4bytes(int c)
{
    putbyte((c>>24) & 0xff);
    putbyte((c>>16) & 0xff);
    putbyte((c>>8) & 0xff);
    putbyte(c & 0xff);
}

/*
 * Do I want to rely on a C compiler having "long long" as a 64-bit type?
 */
void put5bytes(long long c)
{
    putbyte((c>>32) & 0xff);
    putbyte((c>>24) & 0xff);
    putbyte((c>>16) & 0xff);
    putbyte((c>>8) & 0xff);
    putbyte(c & 0xff);
}

void put_little_endian(Lisp_Object c)
{
    putbyte(c & 0xff);
    putbyte((c>>8) & 0xff);
    putbyte((c>>16) & 0xff);
    putbyte((c>>24) & 0xff);
}

void put_addr(void *c)
{
    /* 
     * Store the variable's address in the reloc table.  
     * Address will be put into the code at linkage.
     * Doing it at the end allows for peephole optimisations.  
     * If it was added now that would mess that up.
     * NB the case "void *" to "int" here that is only going to
     * be valid on 32-bit machines.
     */
    vars_table = add_var_to_table(vars_table, (int)c, codep);
    put4bytes(0x00000000);
}

int isreg(int reg)
{
    /* return true if it is a register */
    if(0x0 <= reg && reg <= 0x7) return 1;
    else return 0;     /* else it is a memory location */
}

void call_rel_fn(char *label)
{
    /* all calls are a relative 32bit signed offset */
    putbyte(0xe8); /* call */
    callers_table = add_caller_to_table(callers_table, label, codep);
    put4bytes(0xfcffffff); /* address */
}

void jump(char *label)
{
    /* jump must be rel32 for now */
    putbyte(0xe9);
    jumpers_table = add_caller_to_table(jumpers_table, label, codep);
    put4bytes(0xffffffff);
}

void cond_jump(char *label, int cond)
{
    /* jump must be rel32 for now */
    put2bytes(cond);
    jumpers_table = add_caller_to_table(jumpers_table, label, codep);
    put4bytes(0xffffffff);
}

void add_label(char *label)
{
    labels_table = add_label_to_table(labels_table, label, codep);
}

void add_disassembler_label(char *label)
{
    disassembler_labels =
        add_dis_label_to_table(disassembler_labels, label, codep);
/* FIXME rename these fns to more generic like dupe, nodupe */
}

void Jcall_abs_fn(void *addr_big_endian)
{
    /* overwrites %eax register */
    /* Jpush(1,EDI);     preserve A_reg */
    /* push_A_reg(); */
    putbyte(0xb8);
    put_addr(addr_big_endian);
    put2bytes(0xffd0);
    /* pop_A_reg(); */
    /* Jpop(1,EDI); */
}

void free_labels_table(reloc_table *head)
{
    reloc_table *next;
    while (head != NULL)
    {   free(head->label);
        next = head->next;
        free(head);
        head = next;
    }
}

void free_var_table(variables_table *head)
{
    variables_table *next;
    while (head != NULL)
    {   next = head->next;
        free(head);
        head = next;
    }
}

void reloc_calls()
{
    reloc_table *callerlist = callers_table;
    reloc_table *labellist = labels_table;
    int found = 0;
    unsigned long caller = 0;
    unsigned long offset = 0;
    unsigned long saved_codep = codep;
    while (callerlist != NULL)
    {   labellist = labels_table;
        found = 0;
        while (labellist != NULL)
        {   if (strcmp(callerlist->label,labellist->label)==0)
            {   /* calculate relative call offset and update code */
                caller = callerlist->pos;
                /* -4 because offset starts at the next instruction following the call instruction */
                offset = labellist->pos  - callerlist->pos - 4;
                codep = caller;
                                
                /* write offset to codebuffer[codep] */
                put_little_endian(offset);
                                
                /* break from while loop */
                found = 1;
                labellist = NULL;
            }
            else labellist = labellist->next;
        }
        if (!found) printf("\nBUG IN RELOC TABLE: %s %lu\n",callerlist->label, callerlist->pos);
        callerlist = callerlist->next;
    }
    codep = saved_codep;
}

void reloc_jumps()
{
    reloc_table *jumperlist = jumpers_table;
    reloc_table *labellist = labels_table;
    int found = 0;
    unsigned long jumper = 0;
    unsigned long offset = 0;
    unsigned long saved_codep = codep;
    while (jumperlist != NULL)
    {   labellist = labels_table;
        found = 0;
        while (labellist != NULL)
        {   if (strcmp(jumperlist->label,labellist->label)==0)
            {   /* -4 because offset is from next instruction */
                /* calculate relative jump offset and update code */
                jumper = jumperlist->pos;
                offset = labellist->pos  - jumperlist->pos - 4;
                codep = jumper;
                
                /* write offset to codebuffer[codep] */
                /* put4bytes(offset); */
                put_little_endian(offset);
                                
                /* break from while loop */
                found = 1;
                labellist = NULL;
            }
            else labellist = labellist->next;
        }
        if (!found) printf("\nBUG IN RELOC TABLE: %s %lu\n",jumperlist->label,jumperlist->pos);
        jumperlist = jumperlist->next;
    }
    codep = saved_codep;
}

void reloc_vars()
{
    variables_table *varlist = vars_table;
    unsigned long saved_codep = codep;
    while(varlist != NULL)
    {   codep = varlist->pos;
        put_little_endian(varlist->addr);
        varlist = varlist->next;
    }
    codep = saved_codep;
}

/* end of jit2.c */
