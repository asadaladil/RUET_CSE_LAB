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

;	MOV R0,#0
;	MOV R1,#1
;	MOV R2,#2
	
;FOR
;	CMP R2,#10
;	BEQ DONE
;	ADD R3,R0,R1
;	MOV R0,R1
;	MOV R1,R3
;	ADD R2,R2,#1
;	B FOR
	
;DONE
;	END
	
	MOV R0,#1
	MOV R1,#1
	MOV R2,#1
FOR
	CMP R0,#20
	BEQ DONE
	ADD R1,R1,#2
	ADD R2,R2,R1
	ADD R0,R0,#1
	B FOR
DONE
	END
	
	