	AREA  RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
   DCD 0X10001000
   DCD Reset_Handler
   ALIGN

   AREA mycode, CODE, READONLY
   ENTRY
   EXPORT Reset_Handler
   
Reset_Handler
    ldr  r0,=A
	ldr r1,=Be
	ldr r2,[r0]
	ldr r3,[r1]
	mul r4,r2,r2
	mla r4,r3,r3,r4
	mul r5,r2,r3
	add r5,r5
	add r6,r5,r4
STOP B STOP
A DCD 2
Be DCD 5
	END