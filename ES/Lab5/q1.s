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
    LDR R0,=ARR
	MOV R3,#4
	MOV R9,#1
LOOP1 ADD R9,R9,#1
      ADD R10,R9,#1
	  MLA R2,R9,R3,R0
	  CMP R9,#5
	  BGE STOP
LOOP2 CMP R10,#5
      BGE LOOP1
	  MLA R5,R9,R3,R0 
	  MLA R6,R10,R3,R0
	  LDR R7,[R5]
	  LDR R8,[R6]
	  CMP R8,R7
	  BLT SETMAX
	  ADD R10,R10,#1
	  B LOOP2
SETMAX LDR R11,[R6]
       LDR R12,[R2]
	   STR R11,[R2]
	   STR R12,[R6]
	   ADD R10,R10,#1
	   B LOOP2
STOP B STOP
     AREA MYDATA,DATA,READWRITE
ARR DCD 9,5,6,1,2
    END