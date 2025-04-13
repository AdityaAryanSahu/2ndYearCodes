	AREA c,DATA,READONLY
	EXPORT __Vectors
n equ 7
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA d,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	ldr r0,=src
	mov r2,#n
	mov r3,#0 ;max
	mov r4,#0  ;sec max
loop1   ldr r1,[r0],#4
		stmda sp!,{r1}
		subs r2,#1
		bne loop1
		mov r2,#n
		mov r0,sp
		
loop2   ldmib sp!,{r1}
		cmp r1,r3
	    bcs swap
		cmp r1,r4
		movcs r4,r1
		b next
swap   mov r4,r3
		mov r3,r1
next subs r2,#1
		bne loop2
		mov r8,#1
		cmp r4,#0
		beq stop
		mov r7,r4
		bl fact
		ldr r10,=dst
		str r4,[r10],#4
		str r8,[r10]
Nstop b stop
fact cmp r7,#1
      bxeq lr
	 mul r8,r7
	 subs r7,#1
	 bne fact
src dcd 5,4,1,4,9,8,6,8
		AREA cc,DATA,READWRITE
dst dcd 0
	end