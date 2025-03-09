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
     LDR R0,=SRC
	 LDR R1,[R0]
	 MOV R2,#10
	 MOV R4,#1
LOOP  CMP R1,#0
		BEQ  STORE	
		AND R3,R1,#0XF
		MLA R5,R4,R3,R5
		LSR R1,#4
		MUL R4,R2
		B LOOP
STORE  MOV R11,R5
STOP B STOP
SRC DCD 0X1256
     END
		
		