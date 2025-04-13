	AREA C,DATA,READONLY
	EXPORT __Vectors
n equ 7
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA dd,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	ldr r0,=src
	mov r2,#n
	mov r3,#0xff  ;min
	mov r4,#0  ;sec min
	
	
loop1 	ldr r1,[r0],#4
		stmda sp!,{r1}
		subs r2,#1
		bne loop1
		
		mov r2,#n
loop2        ldmib sp!,{r1}
		       cmp r1,r3
			   bcc swap
			   cmp r1,r4
			   movcc r4,r1
			   b next
swap          mov r4,r3
				mov r3,r1
next           subs r2,#1
				bne loop2
				mov r8,#1
				cmp r4,#0
				beq stop
				mov r7,r4
				bl fact
				ldr r10,=dst
				str r4,[r10],#4
				str r8,[r10]
				
stop b stop
fact cmp r7,#1
     bxeq lr
	 mul r8,r7
	 sub r7,#1
	 b fact
src dcd 8,12,7,4,5,0,0
	AREA cc,DATA,READWRITE
dst dcd 0
	end
		
		