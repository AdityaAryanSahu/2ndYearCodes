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
		LDR R6,=RESULT
		 MOV R2,#0
		 LDR R0,=V1
		 LDR R1,[R0]
		 mov r4,#0
UP    
		CMP R1,#0Xa
		BCC STORE
		 SUB R1,#0XA
		 ADD R2,#1
		 B UP
STORE 
			STRB R1,[R6],#1
			add r4,#1
			MOV R1,R2
			MOV R2,#0
			CMP R1,#0xA
			BCS UP
			STRB R1,[R6]
			add r4,#1
			MOV R3,R6
			LDR R2,=PACKED
			LDR R6, =RESULT
			
UP1    
			LDRB R0,[R6],#1
			LDRB R1,[R6],#1
			LSL R1,#4
			ORR R1,R0
			STRB R1,[R2],#1
			SUB R4,#2
			CMP R4,#0
			bmi STOP
			BNE UP1
STOP B STOP
V1 DCD 0xABFF
		AREA mydata,DATA,READWRITE
RESULT DCD 0,0,0,0,0,0,0,0
PACKED DCD 0
		END