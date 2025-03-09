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
	MOV R2,#7
	LDR R10,=DST
	
LOOP  LDR R1,[R0],#4
	STR R1,[R10],#4
      SUBS R2,#1
	  BNE LOOP
	  
	  MOV R2,#7
	  LDR R0,=DST

LOOP1  MOV R3,R2
		MOV R4,R0 
       LDR R1,[R0]
	   MOV R6,R1
	   MOV R11,R0
LOOP2  ADD R4,#4
       LDR R5,[R4]
	    SUBS R3,#1
		BEQ EXCHANGE
	   CMP R6,R5
	   BLS LOOP2
	   MOV R11,R4
	   MOV R6,R5
	   B LOOP2
	   
EXCHANGE   STR R6,[R0]
			ADD R0,#4
			STR R1,[R11]
			SUBS R2,#1
			BNE LOOP1
STOP B STOP
     ALIGN
SRC DCD 5,6,2,3,1,10,22
	AREA MYCODE,DATA,READWRITE
DST DCD 0
	END
			