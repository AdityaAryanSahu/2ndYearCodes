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
   LDR R1, =SRC1
   LDR R2,=SRC2
   LDR R3,[R1]
   LDR R4,[R2]
   UMULL R6,R5,R3,R2
   
STOP
   B STOP
   
SRC1 DCD 0X11110011
SRC2 DCD 0X11111111
	END