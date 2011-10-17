	TITLE	imul.asm
;;  imulnt.asm      Copyright (C) Codemist Ltd, 1993
;;
;; This code implements Imultiply and Idivide in 80386 (and up) assembly
;; code.  In fact two versions of the functions are provided, one for
;; the usual "__cdecl" calling conventions (all args passed on the stack)
;; and one for the Microsoft so-called "fastcall" where two args are passed
;; in registers.  Name conventions permit the two versions to co-exist.
;;
	.386P
if @Version gt 510
.model FLAT
else
_TEXT	SEGMENT PARA USE32 PUBLIC 'CODE'
_TEXT	ENDS
_DATA	SEGMENT DWORD USE32 PUBLIC 'DATA'
_DATA	ENDS
CONST	SEGMENT DWORD USE32 PUBLIC 'CONST'
CONST	ENDS
_BSS	SEGMENT DWORD USE32 PUBLIC 'BSS'
_BSS	ENDS
_TLS	SEGMENT DWORD USE32 PUBLIC 'TLS'
_TLS	ENDS
FLAT	GROUP _DATA, CONST, _BSS
	ASSUME	CS: FLAT, DS: FLAT, SS: FLAT
endif
;   
;  unsigned32 Imultiply(unsigned32 *rlow,
;                       unsigned32 a, unsigned32 b, unsigned32 c)
;  {
;      /* uns64 is a 64-bit integral type here */
;      uns64 r = (uns64)a*(uns64)b + (uns64)c;
;      *rlow = (unsigned32)(r & 0x7fffffff);
;      return (unsigned32)(r >> 31);
;  }
;  
PUBLIC	_Imultiply
_TEXT	SEGMENT
_rlow$ = 8
_a$ = 12
_b$ = 16
_c$ = 20
_Imultiply PROC NEAR
	mov	eax, DWORD PTR _b$[esp-4]
	mul	DWORD PTR _a$[esp-4]
	mov	ecx, DWORD PTR _rlow$[esp-4]
	add	eax, DWORD PTR _c$[esp-4]
	adc	edx, 0			; carry into top half
        add     eax, eax
        adc     edx, edx
        shr     eax, 1
	mov	DWORD PTR [ecx], eax
	mov	eax, edx
	ret	0
	nop
	nop
_Imultiply ENDP
_TEXT	ENDS
;  unsigned32 Idiv10_9(unsigned32 *qp, unsigned32 high, unsigned32 low)
;  {
;      uns64 p = ((uns64)high << 31) | (uns64)low;
;      *qp = (unsigned32)(p / (uns64)1000000000U);
;      return (unsigned32)(p % (uns64)1000000000U);
;  }
;  
PUBLIC	_Idiv10_9
_TEXT	SEGMENT
_qp$ = 8
_high$ = 12
_low$ = 16
_Idiv10_9 PROC NEAR
	mov	edx, DWORD PTR _high$[esp-4]
	mov	eax, DWORD PTR _low$[esp-4]
	shl	eax, 1
	shr	edx, 1
	rcr	eax, 1			; That glued together 31+31 bits
	mov	ecx, 1000000000
	div	ecx
	mov	ecx, DWORD PTR _qp$[esp-4]
	mov	DWORD PTR [ecx], eax
	mov	eax, edx
	ret	0
	nop
	nop
_Idiv10_9 ENDP
_TEXT	ENDS
;  unsigned32 Idivide(unsigned32 *qp, unsigned32 a, unsigned32 b, unsigned32 c)
;  {
;      uns64 p = ((uns64)a << 31) | (uns64)b;
;      *qp = (unsigned32)(p / (uns64)c);
;      return (unsigned32)(p % (uns64)c);
;  }
;  
PUBLIC	_Idivide
_TEXT	SEGMENT
_qp$ = 8
_a$ = 12
_b$ = 16
_c$ = 20
_Idivide PROC NEAR
	mov	edx, DWORD PTR _high$[esp-4]
	mov	eax, DWORD PTR _low$[esp-4]
	shl	eax, 1
	shr	edx, 1
	rcr	eax, 1			; That glued together 31+31 bits
	mov	ecx, DWORD PTR _c$[esp-4]
	div	ecx
	mov	ecx, DWORD PTR _qp$[esp-4]
	mov	DWORD PTR [ecx], eax
	mov	eax, edx
	ret	0
	nop
	nop
	nop
_Idivide ENDP
;;
;; Now for the versions that take args in registers.
;;
_TEXT	ENDS
;   
;  unsigned32 Imultiply(unsigned32 *rlow,
;                       unsigned32 a, unsigned32 b, unsigned32 c)
;  {
;      /* uns64 is a 64-bit integral type here */
;      uns64 r = (uns64)a*(uns64)b + (uns64)c;
;      *rlow = (unsigned32)(r & 0x7fffffff);
;      return (unsigned32)(r >> 31);
;  }
;  
PUBLIC	@Imultiply@16
_TEXT	SEGMENT
@Imultiply@16 PROC NEAR
	mov	eax, DWORD PTR 4[esp]
	mul	edx
	add	eax, DWORD PTR 8[esp]
	adc	edx, 0			; carry into top half
        add     eax, eax
        adc     edx, edx
        shr     eax, 1
	mov	DWORD PTR [ecx], eax
	mov	eax, edx
	ret	8
	nop
	nop
	nop
	nop
	nop
	nop
@Imultiply@16 ENDP
_TEXT	ENDS
;  unsigned32 Idiv10_9(unsigned32 *qp, unsigned32 high, unsigned32 low)
;  {
;      uns64 p = ((uns64)high << 31) | (uns64)low;
;      *qp = (unsigned32)(p / (uns64)1000000000U);
;      return (unsigned32)(p % (uns64)1000000000U);
;  }
;  
PUBLIC	@Idiv10_9@12
_TEXT	SEGMENT
@Idiv10_9@12 PROC NEAR
	mov	eax, DWORD PTR 4 [esp]
	shl	eax, 1
	shr	edx, 1
	rcr	eax, 1			; That glued together 31+31 bits
	push	1000000000
	div	DWORD PTR [esp]
	mov	DWORD PTR [ecx], eax
	pop	eax
	mov	eax, edx
	ret	4
	nop
	nop
	nop
	nop
	nop
	nop
@Idiv10_9@12 ENDP
_TEXT	ENDS
;  unsigned32 Idivide(unsigned32 *qp, unsigned32 a, unsigned32 b, unsigned32 c)
;  {
;      uns64 p = ((uns64)a << 31) | (uns64)b;
;      *qp = (unsigned32)(p / (uns64)c);
;      return (unsigned32)(p % (uns64)c);
;  }
;  
PUBLIC	@Idivide@16
_TEXT	SEGMENT
@Idivide@16 PROC NEAR
	mov	eax, DWORD PTR 4 [esp]
	shl	eax, 1
	shr	edx, 1
	rcr	eax, 1			; That glued together 31+31 bits
	div	DWORD PTR 8[esp]
	mov	DWORD PTR [ecx], eax
	mov	eax, edx
	ret	8
	nop
	nop
	nop
@Idivide@16 ENDP
_TEXT	ENDS
END
