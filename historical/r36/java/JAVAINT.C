/* javaint.c:  Copyright (C) Codemist Ltd., 1996.                       */

#include <stdio.h>
/* #include <stdlib.h> */
#include <string.h>
#include "machine.h"
#include "tags.h"
#include "cslerror.h"
#include "externs.h"
#include "read.h"
#include "stream.h"
#include "arith.h"
#include "entries.h"
#include "javahost.h"
#include "javaops.h"
#include "javaglb.h"

/* integers representing exceptions (map to Java exceptions in javaint().  */
#define E_NegativeArraySizeException 1
#define E_OutOfMemoryError           2
#define E_NullPointerException       3
#define E_ArrayIndexOutOfBoundsException 4

#define JSTK_MAX 10000
#ifdef DOWNWARD_STACK /* need to fix up locals too! */
#define push_(sp,v) (*--(sp)=(v))
#define pop_(sp) (*(sp)++)
#define lose_(sp,k) ((sp)+=(k))
#define stk_(sp,k) ((sp)[k])
#define STLO 0
#define STHI 1
#define loc_(lv,k) (*((lv)-(k)))
#else
#define push_(sp,v) (*++(sp)=(v))
#define pop_(sp) (*(sp)--)
#define lose_(sp,k) ((sp)-=(k))
#define stk_(sp,k) (*((sp)-(k)))
#define STLO 1
#define STHI 0
#define loc_(lv,k) ((lv)[k])
#endif

static void jraise(int E_whatever)
{   jsyserr("Exceptions unimplemented");
}

static int java_sizeof(int32 t)
{   switch (t)
    {   default: jsyserr("bad type code to newarray()");
        case T_BOOLEAN: return 1;
        case T_CHAR:    return 1;
        case T_FLOAT:   return 4;
        case T_DOUBLE:  return 8;
        case T_BYTE:    return 1;
        case T_SHORT:   return 2;
        case T_INT:     return 4;
        case T_LONG:    return 8;
        case -1:        return 4;    /* for anewarray */
    }
}

typedef struct JavaArray
{ unsigned32 length;
  /* access long/double by stream as maybe not aligned */
  union { int8 elts8[1]; unsigned8 eltu8[1];
          int16 elts16[1]; unsigned16 eltu16[1]; int32 elt32[1]; } u;
} JavaArray;

static int32 java_newarray(int32 *sp, int32 flavour, int32 refclass, int32 k)
{   /* Note that 'k' is (number of dimensions)-1.                       */
    /* Caller loses junk when k>0 (j_multinewarray).                    */
    /* k>0 not supported yet.                                           */
    JavaArray *res;
    int32 nelts = stk_(sp,0), csize;
    if (nelts < 0) return E_NegativeArraySizeException;
    csize = java_sizeof(flavour)*nelts + sizeof(int32);
    res = (JavaArray *)jmalloc(csize);
    if (res == 0) return E_OutOfMemoryError;
    memset(res, 0, csize);          /* @@@ beware 0 = HR_NULL assumed! */
    res->length = nelts;
    stk_(sp,k) = (int32)res; /*ALPHA*/
    return 0;
}

/* beware host/java rep issues here */
#define HR_NULL 0        /* Host Representation? */
static const union { struct { double d[2]; float f[3]; } s;
                     int32 r[7];
                   } hostflttab = { 0.0, 1.0, 0.0f, 1.0f, 2.0f };
/* Remember many of the following are zero (optimise?) */
#define HR_D0W1 hostflttab.r[0]
#define HR_D0W2 hostflttab.r[1]
#define HR_D1W1 hostflttab.r[2]
#define HR_D1W2 hostflttab.r[3]
#define HR_F0   hostflttab.r[4]
#define HR_F1   hostflttab.r[5]
#define HR_F2   hostflttab.r[6]

typedef union DbleRep { int32 irep[2]; double d; } DbleRep;

/* Some of the following optimise if we know double's only need to be   */
/* 32-bit aligned.                                                      */
static int32 *sim_i2d(int32 *sp)
{   DbleRep u;
    u.d = (double)stk_(sp,0);
    stk_(sp,0) = u.irep[STHI];
    push_(sp, u.irep[STLO]);
    return sp;
}
static int32 *sim_d2i(int32 *sp)
{   DbleRep u;
    u.irep[STLO] = pop_(sp);
    u.irep[STHI] = stk_(sp,0);
    stk_(sp,0) = (int32)u.d;
    return sp;
}
static int32 *sim_l2d(int32 *sp) { jsyserr("l2d"); return sp;}
static int32 *sim_d2l(int32 *sp) { jsyserr("d2l"); return sp;}
static int32 *sim_f2l(int32 *sp) { jsyserr("f2l"); lose_(sp,1); return sp;}
static int32 *sim_l2f(int32 *sp) { jsyserr("l2f"); push_(sp,0); return sp;}
static int32 *sim_f2d(int32 *sp)
{   DbleRep u;
    u.d = (double)stk_((float *)sp,0);
    stk_(sp,0) = u.irep[STHI];
    push_(sp, u.irep[STLO]);
    return sp;
}
static int32 *sim_d2f(int32 *sp)
{   DbleRep u;
    u.irep[STLO] = pop_(sp);
    u.irep[STHI] = stk_(sp,0);
    stk_((float *)sp,0) = (float)u.d;
    return sp;
}

static Code_Attribute *findcodeattr(Attribute_Info *v, unsigned32 n)
{   int i;
    for (i = 0; i<n; i++)
        if (v[i].sort == ATT_Code)
            return v[i].uattr.code;
    return 0;
}

#define case3(a,b,c) case a: case b: case c
#define case2(a,b) case a: case b

void javaint(ClassFile *cf)
{
    int32 *sp, *lv;
    int32 *spbase;
    int8 *pc;                /* @@@ */
    Cp_Info *cp;           /* litpool */ /* @@@ init */
    int32 t1, t2, t3;        /* make more local? */
    int32 pb;                /* beware live round main loop (see j_wide) */
    int32 sv;                /* stack val */
    JavaArray *sv_qua_array;
    int32 ao;                /* array index (tidy?) */
    int32 op;
    int32 r1,r2;
    unsigned32 r1u;
    lv = (int32 *)jmalloc(JSTK_MAX * sizeof(*sp));
    loc_(lv,0) = HR_NULL;    /* arg[] */
    sp = lv;
    spbase = lv+1; /* !DOWNWARD_STACK */
/* Provisional placing of following block (maybe share with 'invoke').  */
    cp = cf->constant_pool;
    {   int i;
        for (i = 0; i < cf->methods_count; i++)
        {   unsigned32 n = cf->methods[i].name_index;
            if (0 < n && n < cf->constant_pool_count &&
                cp[n].tag == CONSTANT_Utf8 &&
                memcmp(cp[n].u.utf8, "main", 4) == 0)
            {   Code_Attribute *p = findcodeattr(cf->methods[i].attributes,
                                             cf->methods[i].attributes_count);
                if (p == 0) jsyserr("no code for main");
                pc = (int8 *)p->code; goto foundmain;
            }
        }
        jsyserr("no main()");
        return;
    }
foundmain:
    jdebug("Execution...");
#define u8i_(pc) (*(pc)++ & 255)
#define s8i_(pc) (*(pc)++)
#define s16i_(pc) (t1 = s8i_(pc), t1<<8 | u8i_(pc))
#define u16i_(pc) (t1 = u8i_(pc), t1<<8 | u8i_(pc))
#define s32i_(pc) (t1 = s8i_(pc), t1 = t1<<8 | u8i_(pc), \
                   t1 = t1<<8 | u8i_(pc), t1<<8 | u8i_(pc))
#define cp_maybe_string_(d) \
  (cp[d].tag == CONSTANT_String ? cp[cp[d].u.val].u.val : cp[d].u.val)
   
#define cp1_(d) (cp[d].u.val)
#define cp2_(d) (cp[(d)+1].u.val)
    for (pb = 0;;) switch (jdebug("trace %d", op = u8i_(pc)), op)
    {
default:    jsyserr("Illegal java op %d/%s", op, jdecodeopname(op));
            break;
unimp:      jsyserr("Unimplemented java op %d/%s", op, jdecodeopname(op));
            break;
case j_bipush: push_(sp, s8i_(pc)); break;
case j_sipush: push_(sp, s16i_(pc)); break;
case j_ldc1:   t2 = u8i_(pc); push_(sp, cp_maybe_string_(t2)); break;
case j_ldc2:   t2 = u16i_(pc); push_(sp, cp_maybe_string_(t2)); break;
case j_ldc2w:  t2 = u16i_(pc); push_(sp, cp1_(t2)); push_(sp, cp2_(t2)); break;
case j_aconst_null: push_(sp, HR_NULL); break;
case j_iconst_m1: push_(sp, -1); break;
case j_iconst_0: push_(sp, 0); break;
case j_iconst_1: push_(sp, 1); break;
case j_iconst_2: push_(sp, 2); break;
case j_iconst_3: push_(sp, 3); break;
case j_iconst_4: push_(sp, 4); break;
case j_iconst_5: push_(sp, 5); break;
case j_lconst_0: push_(sp, 0); push_(sp, 0); break;
case j_lconst_1: push_(sp, 0); push_(sp, 0); break;
case j_fconst_0: push_(sp, HR_F0); break;
case j_fconst_1: push_(sp, HR_F1); break;
case j_fconst_2: push_(sp, HR_F2); break;
case j_dconst_0: push_(sp, HR_D0W1); push_(sp, HR_D0W2); break;
case j_dconst_1: push_(sp, HR_D1W1); push_(sp, HR_D1W2); break;

case3(j_iload,j_fload,j_aload):
            push_(sp, loc_(lv,pb+u8i_(pc))); pb = 0; break;
case3(j_iload_0,j_fload_0,j_aload_0): push_(sp, loc_(lv,0)); break;
case3(j_iload_1,j_fload_1,j_aload_1): push_(sp, loc_(lv,1)); break;
case3(j_iload_2,j_fload_2,j_aload_2): push_(sp, loc_(lv,2)); break;
case3(j_iload_3,j_fload_3,j_aload_3): push_(sp, loc_(lv,3)); break;
/* Could use sv1,sv2 if lots of registers on my target.         */
case2(j_lload,j_dload): pb += u8i_(pc);           /* STHI, STLO */
                        sv = loc_(lv, pb+0); push_(sp, sv);
                        sv = loc_(lv, pb+1); push_(sp, sv); pb = 0; break;
case2(j_lload_0,j_dload_0): push_(sp, loc_(lv,0)); push_(sp, loc_(lv,1)); break;
case2(j_lload_1,j_dload_1): push_(sp, loc_(lv,1)); push_(sp, loc_(lv,2)); break;
case2(j_lload_2,j_dload_2): push_(sp, loc_(lv,2)); push_(sp, loc_(lv,3)); break;
case2(j_lload_3,j_dload_3): push_(sp, loc_(lv,3)); push_(sp, loc_(lv,4)); break;

case3(j_istore,j_fstore,j_astore):
            loc_(lv, pb+u8i_(pc)) = pop_(sp); pb = 0; break;
case3(j_istore_0,j_fstore_0,j_astore_0): loc_(lv,0) = pop_(sp); break;
case3(j_istore_1,j_fstore_1,j_astore_1): loc_(lv,1) = pop_(sp); break;
case3(j_istore_2,j_fstore_2,j_astore_2): loc_(lv,2) = pop_(sp); break;
case3(j_istore_3,j_fstore_3,j_astore_3): loc_(lv,3) = pop_(sp); break;
/* Could use sv1,sv2 if lots of registers on my target.         */
case2(j_lstore,j_dstore): pb += u8i_(pc);         /* STHI, STLO */
                        sv = pop_(sp); loc_(lv, pb+1) = sv;
                        sv = pop_(sp); loc_(lv, pb+0) = sv; pb = 0; break;
case2(j_lstore_0,j_dstore_0): loc_(lv,1)=pop_(sp); loc_(lv,0)=pop_(sp); break;
case2(j_lstore_1,j_dstore_1): loc_(lv,2)=pop_(sp); loc_(lv,1)=pop_(sp); break;
case2(j_lstore_2,j_dstore_2): loc_(lv,3)=pop_(sp); loc_(lv,2)=pop_(sp); break;
case2(j_lstore_3,j_dstore_3): loc_(lv,4)=pop_(sp); loc_(lv,3)=pop_(sp); break;

case j_iinc: pb += u8i_(pc); loc_(lv, pb) += s8i_(pc); pb = 0; break;

case j_wide: pb = u8i_(pc) << 8; break;

case j_newarray: if ((t1 = java_newarray(sp, u8i_(pc), 0, 0)) != 0)
                 {   jraise(t1);
                 }
                 break;
case j_anewarray: t2 = u16i_(pc);
                 if ((t1 = java_newarray(sp, -1, cp1_(t2), 0)) != 0)
                 {   jraise(t1);
                 }
                 break;
case j_multinewarray: t2 = u16i_(pc); t3 = u8i_(pc)-1;
                 t1 = java_newarray(sp, -1, cp1_(t2), t3);
                 sp += t3;
                 if (t1 != 0)
                 {   jraise(t1);
                 }
                 break;

case j_arraylength:
            if ((sv_qua_array = (JavaArray *)stk_(sp,0)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            stk_(sp,0) = sv_qua_array->length;
            break;

case3(j_iaload,j_faload,j_aaload):
            ao = pop_(sp);
            if ((sv_qua_array = (JavaArray *)stk_(sp,0)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)ao >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            stk_(sp,0) = sv_qua_array->u.elt32[ao];
            break;
case2(j_laload,j_daload):
            ao = pop_(sp);
            if ((sv_qua_array = (JavaArray *)stk_(sp,0)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)ao >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            stk_(sp,0) = sv_qua_array->u.elt32[2*ao+STHI];
            push_(sp, sv_qua_array->u.elt32[2*ao+STLO]);
            break;
case j_baload:   ao = pop_(sp);
            if ((sv_qua_array = (JavaArray *)stk_(sp,0)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)ao >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            stk_(sp,0) = sv_qua_array->u.elts8[ao];
            break;
case j_caload:   ao = pop_(sp);
            if ((sv_qua_array = (JavaArray *)stk_(sp,0)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)ao >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            stk_(sp,0) = sv_qua_array->u.eltu16[ao];
            break;
case j_saload:   ao = pop_(sp);
            if ((sv_qua_array = (JavaArray *)stk_(sp,0)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)ao >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            stk_(sp,0) = sv_qua_array->u.elts16[ao];
            break;
            
case3(j_iastore,j_fastore,j_aastore):
            if ((sv_qua_array = (JavaArray *)stk_(sp,2)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)(ao = stk_(sp,1)) >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            sv_qua_array->u.elt32[ao] = stk_(sp,0);
            lose_(sp,3);
            break;
case2(j_lastore,j_dastore):
            if ((sv_qua_array = (JavaArray *)stk_(sp,3)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)(ao = stk_(sp,2)) >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            sv_qua_array->u.elt32[2*ao+STLO] = stk_(sp,0);
            sv_qua_array->u.elt32[2*ao+STHI] = stk_(sp,1);
            lose_(sp,4);
            break;
case j_bastore:
            if ((sv_qua_array = (JavaArray *)stk_(sp,2)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)(ao = stk_(sp,1)) >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            sv_qua_array->u.eltu8[ao] = stk_(sp,0);
            lose_(sp,3);
            break;
case2(j_sastore,j_castore):
            if ((sv_qua_array = (JavaArray *)stk_(sp,2)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
            if ((unsigned32)(ao = stk_(sp,1)) >= sv_qua_array->length)
            {   jraise(E_ArrayIndexOutOfBoundsException);
            }
            sv_qua_array->u.eltu16[ao] = stk_(sp,0);
            lose_(sp,3);
            break;

case j_nop:     break;
case j_pop:     lose_(sp,1); break;
case j_pop2:    lose_(sp,2); break;
case j_dup:     sv = stk_(sp, 0); push_(sp, sv); break;
case j_dup2:    sv = stk_(sp, 1); push_(sp, sv);
                sv = stk_(sp, 1); push_(sp, sv);  break;
case j_dup_x1:  sv = stk_(sp, 0); stk_(sp, 0) = stk_(sp, 1);
                stk_(sp, 1) = sv; push_(sp, sv); break;
case j_dup2_x1: r1 = stk_(sp, 0); r2 = stk_(sp, 1); stk_(sp,0) = stk_(sp,2);
                stk_(sp,1) = r1; stk_(sp,2) = r2; push_(sp, r2); push_(sp,r1);
                break;
case j_dup_x2:  sv = stk_(sp, 0); push_(sp, sv); stk_(sp,1) = stk_(sp,2);
                stk_(sp,2) = stk_(sp,3); stk_(sp,3) = sv; break;
case j_dup2_x2: sv = stk_(sp, 1); push_(sp, sv); stk_(sp,2) = stk_(sp,4);
                stk_(sp,4) = sv;
                sv = stk_(sp, 1); push_(sp, sv); stk_(sp,2) = stk_(sp,4);
                stk_(sp,4) = sv; break;
case j_swap:    sv = stk_(sp, 0); stk_(sp, 0) = stk_(sp, 1);
                stk_(sp, 1) = sv;  break;

case j_iadd:    r1 = pop_(sp); stk_(sp,0) += r1; break;
case j_ladd:    goto unimp;
case j_fadd:    goto unimp;
case j_dadd:    goto unimp;
case j_isub:    r1 = pop_(sp); stk_(sp,0) -= r1; break;
case j_lsub:    goto unimp;
case j_fsub:    goto unimp;
case j_dsub:    goto unimp;
case j_imul:    r1 = pop_(sp); stk_(sp,0) *= r1; break;
case j_lmul:    goto unimp;
case j_fmul:    goto unimp;
case j_dmul:    goto unimp;
case j_idiv:    r1 = pop_(sp); stk_(sp,0) /= r1; break;
case j_ldiv:    goto unimp;
case j_fdiv:    goto unimp;
case j_ddiv:    goto unimp;
case j_irem:    r1 = pop_(sp); stk_(sp,0) %= r1; break;
case j_lrem:    goto unimp;
case j_frem:    goto unimp;
case j_drem:    goto unimp;
case j_ineg:    stk_(sp,0) = -stk_(sp,0); break;
case j_lneg:    goto unimp;
case j_fneg:    goto unimp;
case j_dneg:    goto unimp;

case j_ishl:    r1 = pop_(sp); stk_(sp,0) <<= r1&31; break;
#ifdef HOST_SHIFT_SIGNED
case j_ishr:    r1 = pop_(sp); stk_(sp,0) >>= r1&31; break;
#else
case j_ishr:    goto unimp;
#endif
case j_iushr:   r1 = pop_(sp); stk_(sp,0) = (unsigned32)stk_(sp,0) >> r1&31; break;
case j_lshl:    goto unimp;
case j_lshr:    goto unimp;
case j_lushr:   goto unimp;
case j_iand:    r1 = pop_(sp); stk_(sp,0) &= r1; break;
case j_land:    stk_(sp,2) &= stk_(sp,0); stk_(sp,3) &= stk_(sp,1);
                lose_(sp,2); break;
case j_ior:     r1 = pop_(sp); stk_(sp,0) |= r1; break;
case j_lor:     stk_(sp,2) |= stk_(sp,0); stk_(sp,3) |= stk_(sp,1);
                lose_(sp,2); break;
case j_ixor:    r1 = pop_(sp); stk_(sp,0) ^= r1; break;
case j_lxor:    stk_(sp,2) ^= stk_(sp,0); stk_(sp,3) ^= stk_(sp,1);
                lose_(sp,2); break;

case j_i2l:     r1u = stk_(sp,0); push_(sp, -(r1u >> 31)); break;
case j_i2f:     stk_((float *)sp,0) = (float)stk_(sp,0); break;
case j_i2d:     sp = sim_i2d(sp); break;
case j_l2i:     lose_(sp,1); break;
case j_l2f:     sp = sim_l2f(sp); break;
case j_l2d:     sp = sim_l2d(sp); break;
case j_f2i:     stk_(sp,0) = (int32)stk_((float *)sp,0); break;
case j_f2l:     sp = sim_f2l(sp); break;
case j_f2d:     sp = sim_f2d(sp); break;
case j_d2i:     sp = sim_d2i(sp); break;
case j_d2l:     sp = sim_d2l(sp); break;
case j_d2f:     sp = sim_d2f(sp); break;

#define signext_(w,n) ((((w) & (1<<n)-1) ^ (1<<n-1)) - (1<<n-1))
case j_int2byte:    stk_(sp,0) = signext_(stk_(sp,0), 8); break;
case j_int2char:    stk_(sp,0) = stk_(sp,0) & 0xffff; break;
case j_int2short:   stk_(sp,0) = signext_(stk_(sp,0), 16); break;

#define condbr(TEST) t2 = s16i_(pc); if (TEST) pc += t2-3
case j_ifeq:    condbr(pop_(sp) == 0); break;
case j_ifnull:  condbr(pop_(sp) == HR_NULL); break;
case j_iflt:    condbr(pop_(sp) < 0); break;
case j_ifle:    condbr(pop_(sp) <= 0); break;
case j_ifne:    condbr(pop_(sp) != 0); break;
case j_ifnonnull: condbr(pop_(sp) != HR_NULL); break;
case j_ifgt:    condbr(pop_(sp) > 0); break;
case j_ifge:    condbr(pop_(sp) >= 0); break;
case j_if_icmpeq: sv = pop_(sp); condbr(pop_(sp) == sv); break;
case j_if_icmpne: sv = pop_(sp); condbr(pop_(sp) != sv); break;
case j_if_icmplt: sv = pop_(sp); condbr(pop_(sp) < sv); break;
case j_if_icmpgt: sv = pop_(sp); condbr(pop_(sp) > sv); break;
case j_if_icmple: sv = pop_(sp); condbr(pop_(sp) <= sv); break;
case j_if_icmpge: sv = pop_(sp); condbr(pop_(sp) >= sv); break;
case j_lcmp:
case j_fcmpl:
case j_fcmpg:
case j_dcmpl:
case j_dcmpg:
case j_if_acmpeq:
case j_if_acmpne:
case j_goto:    t2 = s16i_(pc); pc += t2-3; break;
case j_goto_w:  t2 = s32i_(pc); pc += t2-5; break;
case j_jsr:     t2 = s16i_(pc); push_(sp,(int32)pc); pc += t2-3; break; /*ALPHA*/
case j_jsr_w:   t2 = s32i_(pc); push_(sp,(int32)pc); pc += t2-5; break; /*ALPHA*/
case j_ret:     t2 = u8i_(pc); pc = (int8 *)stk_(sp, t2); break; /*ALPHA*/
case j_ret_w:   t2 = u16i_(pc); pc = (int8 *)stk_(sp, t2); break; /*ALPHA*/

case j_ireturn:
case j_lreturn:
case j_freturn:
case j_dreturn:
case j_areturn:
case j_return:
case j_breakpoint:

case j_tableswitch:
case j_lookupswitch:

case j_putfield: goto unimp;
case j_getfield:
            if ((sv_qua_array = (JavaArray *)stk_(sp,0)) == HR_NULL) /*ALPHA*/
            {   jraise(E_NullPointerException);
            }
case j_putstatic: goto unimp;
case j_getstatic: t2 = u16i_(pc);
            push_(sp, (int32)&java_PrintStream); /* @@@ */
            break;     /* @@@ */

case j_invokevirtual: t2 = u16i_(pc);
            cf = (ClassFile *)*spbase;
            if (cf != &java_PrintStream)
                 jsyserr("invokevirtual");
            if (cf->methods_count == 1 && /* @@@ */
                cf->methods[0].access_flags & ACC_NATIVE)
            {   sp = ((JavaBuiltin)(cf->methods[0].attributes))(spbase);
            }
            else
            {   lv = spbase;
                spbase = sp+1;
                goto unimp;
            }
            break;

case j_invokenonvirtual: goto unimp;
case j_invokestatic:     goto unimp;
case j_invokeinterface:  goto unimp;

case j_athrow:           goto unimp;

case j_new:              t2 = u16i_(pc);
                         term_printf("NEW %d %d %.8x\n",
                             t2, cp[t2].tag, cp_maybe_string_(t2));
                         goto unimp;
case j_checkcast:        goto unimp;
case j_instanceof:       goto unimp;
case j_monitorenter:     goto unimp;
case j_monitorexit:      goto unimp;

    }
}
