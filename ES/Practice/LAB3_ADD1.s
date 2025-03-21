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
     MOV R0, #12
	MOVS R1, #6
	MOV R8, R0
	MOVS R9, R1
	MOV R3, #0
LOOP1
	MOV R5, R0
	BEQ ZERO
	SUBS R0, R0, R1
	BPL LOOP1
ZERO MOV R0, R1
	MOVS R1, R5
	BEQ STORE
	B LOOP1
STORE MOV R7, R0
	MUL R8, R8, R9
	MOV R0, #0

LOOP2
	SUBS R8,R8,R7
	BLS STOP
	ADD R0,R0,#1
	B LOOP2
STOP B STOP
		END