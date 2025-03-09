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
	MOV R1,#10
	MLA R2,R1,R1,R1
	MOV R3,#0
	MOVS R4,R2
LOOP BEQ STOP
	SUBS R4,R4,#2
     BMI STOP
      ADD R3,R3,#1
	  B LOOP
STOP
	B STOP
	END