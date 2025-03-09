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

      ;;FULL DESCENDING STACK
    MOV R0,#5
	 MOV R1,#6
	MOV R2,#2
	MOV R3,#3
	MOV R4,#1
	MOV R5,#10
	MOV R6,#22
	  
	  STMDB SP!,{R0-R6}
	  MOV R3,#7
	  MOV R2,R3
	  
	  MOV R0,SP

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
			LDMIA SP!,{R0-R6}
STOP B STOP
     ALIGN
	END
			