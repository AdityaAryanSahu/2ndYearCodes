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
     MOV R2,#0
      MOVS R1,#7
LOOP BEQ END
     SUBS R1,R1,#2
     BMI END
      ADD R2,R2,#1
	  B LOOP
	  
STOP B STOP
END