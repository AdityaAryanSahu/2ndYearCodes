		AREA reset,DATA,READONLY
	EXPORT __Vectors
	
__Vectors
	  DCD 0x10001000
	  DCD Reset_Handler
	  ALIGN
	  AREA cc, CODE,READONLY
		  ENTRY
	  EXPORT Reset_Handler
	  
Reset_Handler
	ldr r0,=src1
	ldr r1,=src2
	ldr r2,[r0] ;num1
	ldr r3,[r1] ;num2
	mov r7,#1
   mov r6,#10
   mov r0,#0
   mov r1,#0
   
   
   ;hex conversion from bcd of num1
loop cmp r2,#0  
     beq next1
	 and r5,r2,#0xf
	 lsr r2,#4
	 mul r5,r7
	 mul r7,r6
	 add r0,r5
	 b loop
	 
	  ;hex conversion from bcd of num2
next1	 mov r7,#1
loop2 cmp r3,#0
     beq next2
	 and r5,r3,#0xf
	 lsr r3,#4
	 mul r5,r7
	 mul r7,r6
	 add r1,r5
	 b loop2
	 
next2	 mov r3,r1
	 mov r2,r0
	add r1,r2,r3
	mov r2,#0
	mov r3,#0
	ldr r4,=digits
	ldr r5,=dst


   ;bcd conversion of sum
up   cmp r1,#0xa
     bcc store
	 sub r1,#0xa
	 add r2,#1
	 b up
store strb r1,[r4],#1
	add r3,#1
      mov r1,r2
	  mov r2,#0
	  cmp r1,#0xa
	  bcs up
	  strb r1,[r4]
	  add r3,#1
	  ldr r4,=digits
	  
up1  ldrb r0,[r4],#1
     ldrb r1,[r4],#1
	 lsl r1,#4
	 orr r1,r0
	 strb r1,[r5],#1
	 sub r3,#2
	 cmp r3,#0
	 bmi stop
	 bne up1
stop b stop
src1 dcd 0x19990000
src2 dcd 0x30000000
	AREA c,DATA,READWRITE
digits dcd 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
dst dcd 0
	end
	 
	