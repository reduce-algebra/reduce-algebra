;;	TITLE	imul.asm
;;  imulwat.asm      Copyright (C) Codemist Ltd, 1993-94
;;
;; This code implements Imultiply and Idivide in 80386 (and up) assembly
;; code. The argument passing conventions are as used by Watcom C, so if
;; other compilers are used please think about any alterations that are
;; thereby needed. Note that I use the register calling convention here.
;;

	.386P
	.387

;
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
_TEXT	segment dword public 'CODE'
	assume	CS:_TEXT
	public	Imultiply_
Imultiply_	proc near
	push	EAX
	mov	EAX, EBX
	mul	EDX
	add	EAX, ECX
	adc	EDX, 0
        add     EAX, EAX
        adc     EDX, EDX
        shr     EAX, 1
	pop	ECX
	mov	DWORD PTR [ECX], EAX
	mov	EAX, EDX
	ret	0
Imultiply_	endp
_TEXT	ENDS
;
;  unsigned32 Idiv10_9(unsigned32 *qp, unsigned32 high, unsigned32 low)
;  {
;      uns64 p = ((uns64)high << 31) | (uns64)low;
;      *qp = (unsigned32)(p / (uns64)1000000000U);
;      return (unsigned32)(p % (uns64)1000000000U);
;  }
;
_TEXT	segment dword public 'CODE'
	assume	CS:_TEXT
	public	Idiv10_9_
Idiv10_9_	proc near
	push	EAX
	mov	EAX, EBX
	shl	EAX, 1
	shr	EDX, 1
	rcr	EAX, 1			; That glued together 31+31 bits
	mov	ECX, 1000000000
	div	ECX
	pop	ECX
	mov	DWORD PTR [ECX], EAX
	mov	EAX, EDX
	ret	0
Idiv10_9_	endp
_TEXT	ENDS
;
;  unsigned32 Idivide(unsigned32 *qp, unsigned32 a, unsigned32 b, unsigned32 c)
;  {
;      uns64 p = ((uns64)a << 31) | (uns64)b;
;      *qp = (unsigned32)(p / (uns64)c);
;      return (unsigned32)(p % (uns64)c);
;  }
;
	_TEXT	segment dword public 'CODE'
	assume	CS:_TEXT
	public Idivide_
_qp$ = 8
_a$ = 12
_b$ = 16
_c$ = 20
Idivide_	proc near
	push	EAX
	mov	EAX, EBX
	shl	EAX, 1
	shr	EDX, 1
	rcr	EAX, 1			; That glued together 31+31 bits
	div	ECX
	pop	ECX
	mov	DWORD PTR [ECX], EAX
	mov	EAX, EDX
	ret	0
Idivide_	endp
_TEXT	ENDS
END
