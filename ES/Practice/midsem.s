	AREA cc,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA dd,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
		ldr r0,=src
		ldr r1,[r0]
		mov r3,#0  ;sum even places
		mov r4,#0   ;sum odd places
		ldr r10,=dst
		
		;sum calc
loop cmp r1,#0
     beq next
	 and r5,r1,#0xf
	 lsr r1,#4
	 and r6,r1,#0xf
	 lsr r1,#4
	 add r3,r5
	 add r4,r6
	 b loop
	 
next	 mov r9,#2

        ;bcd conversion starts
next_num	 ldr r6,=digits
			mov r0,#0
			mov r1,#0
up    cmp r3,#0xa
       bcc store
	   sub r3,#0xa
	   add r1,#1
	   b up
store  strb r3,[r6],#1
       add  r0,#1
       mov r3,r1
	   mov r1,#0
	   cmp r3,#0xa
	   bcs up
	   strb r3,[r6]
	    ldr r6,=digits
	   add r0,#1
up1    ldrb r7,[r6],#1
		ldrb r8,[r6],#1
		lsl r8,#4
		orr r8,r7
		strb r8,[r10],#1
		sub r0,#2
		cmp r0,#0
		bmi next_num
		bne up1
		mov r3,r4
		subs r9,#1
		bne next_num
stop b stop
src dcd 0x82828282
   AREA c,DATA,READWRITE
digits  dcd 0,0,0,0,0,0,0,0,0
dst dcd 0
	end
	   
	   
	   
	   