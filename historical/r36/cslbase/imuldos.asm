	TITLE	imul.asm
;;  imuldos.asm      Copyright (C) Codemist Ltd, 1993-94
;;
;; This code implements Imultiply and Idivide in 80386 (and up) assembly
;; code. The argument passing conventions are as used by Zortech C, so if
;; other compilers are used please think about any alterations that are
;; thereby needed.
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
	public	_Imultiply
_rlow$ = 8
_a$ = 12
_b$ = 16
_c$ = 20
_Imultiply	proc near
	mov	EAX, DWORD PTR _b$[ESP-4]
	mul	DWORD PTR _a$[ESP-4]
	mov	ECX, DWORD PTR _rlow$[ESP-4]
	add	EAX, DWORD PTR _c$[ESP-4]
	adc	EDX, 0			; carry into top half
        add     EAX, EAX
        adc     EDX, EDX
        shr     EAX, 1
	mov	DWORD PTR [ECX], EAX
	mov	EAX, EDX
	ret	0
	nop
	nop
_Imultiply	endp
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
	public	_Idiv10_9
_qp$ = 8
_high$ = 12
_low$ = 16
_Idiv10_9	proc near
	mov	EDX, DWORD PTR _high$[ESP-4]
	mov	EAX, DWORD PTR _low$[ESP-4]
	shl	EAX, 1
	shr	EDX, 1
	rcr	EAX, 1			; That glued together 31+31 bits
	mov	ECX, 1000000000
	div	ECX
	mov	ECX, DWORD PTR _qp$[ESP-4]
	mov	DWORD PTR [ECX], EAX
	mov	EAX, EDX
	ret	0
	nop
	nop
_Idiv10_9	endp
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
	public _Idivide
_qp$ = 8
_a$ = 12
_b$ = 16
_c$ = 20
_Idivide	proc near
	mov	EDX, DWORD PTR _high$[ESP-4]
	mov	EAX, DWORD PTR _low$[ESP-4]
	shl	EAX, 1
	shr	EDX, 1
	rcr	EAX, 1			; That glued together 31+31 bits
	mov	ECX, DWORD PTR _c$[ESP-4]
	div	ECX
	mov	ECX, DWORD PTR _qp$[ESP-4]
	mov	DWORD PTR [ECX], EAX
	mov	EAX, EDX
	ret	0
	nop
	nop
	nop
_Idivide	endp
_TEXT	ENDS
END
