	AREA c,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA d,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
  mov r0,#12
  mov r2,#0 ;sum
  mov r1,r0 ;dup
  mov r4,#0
  
loop1 cmp r0,#0
		beq check
		mov r4,#0
       mov r3,r0
mod_q    cmp r3,#0xa
       bcc sum
	   sub r3,#0xa ;rem
	   add r4,#1 ;quotient
	   b mod_q
sum   mul r6,r3,r3
      mul r3,r6
	  add r2,r3
	  mov r0,r4
	  b loop1
check cmp r2,r1
	   moveq r10,#0XAA
	   movne r10,#0xFF
	   ldr r11,=dst
	   str r10,[r11]
	   
stop b stop
	AREA cc,DATA,READWRITE
dst dcd 0
	  end
  