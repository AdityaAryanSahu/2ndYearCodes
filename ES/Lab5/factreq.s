	AREA RESET, DATA, READONLY
	EXPORT __Vectors
	
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	LDR r1, =num
	LDR r1,[r1]
	BL fact1
	LDR r1, =fact
	STR r2,[r1]
STOP B STOP
fact1 CMP r1, #1
	BEQ exit
	PUSH {r1}
	PUSH {LR}
	SUB r1, #1
	BL fact1
	POP {LR}
	POP {R1}
	MUL r2,r1,r2
	BX LR
exit MOV r2, #1
	BX LR
num DCD 0x04
	AREA data, DATA
fact DCD 0