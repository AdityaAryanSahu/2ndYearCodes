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
         LDR R0,=VAL1
		 LDR R3,[R0]
		 MOV R1,#1
		 LDR R2,=RES
FACT     CMP R3,#0
          BEQ DONE 
		  MUL R1,R1,R3
		  SUBS R3,R3,#1
		  BL FACT 
DONE STR R1,[R2]
STOP  B STOP
VAL1 DCD 0x00000005
      AREA MYDATA,DATA,READWRITE
RES DCD 0
    END