	;;; Directives
	PRESERVE8
	THUMB
	; Vector Table Mapped to Address 0 at Reset
	; Linker requires __Vectors to be exported
	AREA RESET, DATA, READONLY
	EXPORT __Vectors
		
__Vectors
	DCD 0x20001000
	; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	; The program
	; Linker requires Reset_Handler
	AREA MYCODE, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
;;;;;;;;;;User Code Starts from the next
line;;;;;;;;;;;;
; int a = 23;
; int b = 0x45;
	mov r0,#0x00000012
	mov r1,#0
	mov r2,#0
	
	
For
	cmp r1,#32
	beq exit
	lsrs r0,r0,#1
	bcs addone
	lsl r2,r2,#1
due
	add r1,r1,#1
	b For
addone
	lsl r2,r2,#1
	orr r2,r2,#1
	b due
exit
	