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
        LDR R0, =SRC     ; Address of first element
        LDR R2, =SRC
        ADD R2, R2, #(4 * 3)  ; Address of last element

        LDR R7, =SRC2    ; Destination array
        MOV R8, #4       ; Number of elements

LOOP    
        CMP R0, R2       ; If start >= end, stop
        BCS LOOP2 

        LDR R1, [R0]     ; Load first number  
        LDR R4, [R2]     ; Load last number
        STR R4, [R0]     ; Swap first with last
        STR R1, [R2]     ; Swap last with first

        ADD R0, R0, #4   ; Move forward
        SUB R2, R2, #4   ; Move backward
        B LOOP

LOOP2   
        LDR R1, [R11]    ; Load value from SRC
        STR R1, [R7]     ; Store in SRC2
        SUBS R8, #1      ; Decrement counter
        ADD R7, R7, #4   ; Move to next SRC2 location
        ADD R11, R11, #4 ; Move to next SRC location
        BNE LOOP2

STOP    
        B STOP

	AREA MYDATA, DATA, READWRITE, ALIGN=4
SRC     DCD 0X00001132,0X00001123,0X000004511,0X00005634
SRC2    DCD 0,0,0,0
	END
