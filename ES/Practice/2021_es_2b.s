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
   ldr r0,=num
   ldr r1,[r0]
   mov r2,#0
   mov r3,#2
   mov r4,r1
   ldr r10,=dest
   cmp r1,#2
   beq prime
loop subs r1,r3
      beq not_prime
	  bpl loop
       add r3,#1
	   cmp r3,r4
	   bne loop
prime     mov r11,#0xaa
	  str r11,[r10]
      b STOP
not_prime  mov r11,#0xff
	  str r11,[r10]
STOP b STOP
num dcd 14
   AREA DA,DATA, READWRITE
dest dcd 0
	end
