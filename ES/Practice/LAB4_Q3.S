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
	  LDR R1,[R0] ;NUMBER HEXA
	  MOV R2,#0
	  MOV R3,#16
	  MOV R6,#16
	  AND R4,R1,#0XF
	  LSR R1,#4
	  MOV R5,R4 ;R5 FINAL ANSWER
LOOP1    CMP R1,#0
        BCS   STORE
		AND R4,R1,#0XF
	    LSR R1,#4
		MLA R5,R4,R3,R5
		MUL R3,R6
STORE  MOV R11,R5
STOP B STOP
SRC DCD 0XC
       END
		
			