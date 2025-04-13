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
   ldr r0,=src
		ldr r1,[r0]
		ldr r2,=dst
		
		and r3,r1,#0xf
		and r4,r1,#0xf00;
		and r5,r1,#0xf0000;
		and r6,r1,#0xf000000;
		lsr r4,#4
		lsr r5,#8
		lsr r6,#12
		orr r7,r3
		orr r7,r4
		orr r7,r5
		orr r7,r6
		str r7,[r2]
stop b stop
src dcd 0x01020304
	AREA c,DATA,READWRITE
dst dcd 0
	end