
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
GPIOA_BASE      EQU 0x40010800
RCC_BASE        EQU 0x40021000

; Byte offset of each register in GPIO and RCC
RCC_APB2ENR     EQU 0x18     
GPIO_CRL        EQU 0x00
GPIO_ODR        EQU 0x0C
 
  
__main PROC


    ; Enable the clock to GPIO port A
    ; Load address of reset and clock control (RCC)
    LDR r2, =RCC_BASE       ; Load base address of RCC into r2
    LDR r1, [r2, #RCC_APB2ENR] ; Load the value of RCC_APB2ENR into r1
    ORR r1, r1, #(1 << 2)       ; Set bit 2 (IOPAEN) to enable GPIOA clock
    STR r1, [r2, #RCC_APB2ENR]  ; Store the updated value back into RCC_APB2ENR
	    ; Load GPIO port A base address
    LDR r3, =GPIOA_BASE         ; Load the base address of GPIOA into r3
    
    ; Configure pin PA5 as general-purpose output push-pull
    ; with max speed of 50 MHz
    LDR r1, [r3]     ; Load the value of GPIOA_CRL into r1
    BIC r1, r1, #(15 << 20)     ; Clear bits 23:20 belonging to pin 5
    ORR r1, r1, #(3 << 20)      ; Set bits 23:20 to 0011, configuring PA5 
			        ; as output with max speed 50 MHz
    STR r1, [R3]    ; Store the updated value back into GPIOA_CRL

    ; Set PA5 high to turn on the LED       
    LDR r1, [r3, #GPIO_ODR]	; Load the value of GPIOA_ODR into r1
while
    EOR r1, r1, #(1 << 5)       ; Set bit 5 to 1, which sets PA5 high
    STR r1, [r3, #GPIO_ODR]     ; Store the updated value back into GPIOA_ODR
	mov r2,#0xf4000
	orr r2,r2 ,#0x240
for
	cmp r2,#0
	beq while
	sub r2,r2,#1
	b for
	
stop
    B stop                      ; Infinite loop to keep the program running
    ENDP

    END