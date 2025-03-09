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
	 LDR R10,=DST

LOOP1     LDR R1,[R0]
         MOV R3,#0
		 ADD R0,#4
		 MOV R4,#3
		 

LOOP2		CMP R1,#0
			BEQ STORE
			AND R2,R1,#0XF
			LSR R1,#4
			ADD R3,R2
			B LOOP2
STORE      MOV R11,R3
           STR R11,[R10]
		   ADD R10,#4
		   SUBS R4,#1
		   BNE LOOP1
STOP B STOP
      ALIGN
SRC DCD 0X32,0X23,0X43
		AREA MYOCDE,DATA,READWRITE
DST DCD 0,0,0
       END
			