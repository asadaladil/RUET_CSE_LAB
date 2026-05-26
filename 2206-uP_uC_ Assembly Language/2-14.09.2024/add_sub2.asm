.model small
.stack 100h
.data
    A db ?
    B db ?
.code
    main proc
        MOV AX,@DATA
        MOV DS,AX
        
        ;input 1
        MOV AH,1
        INT 21H
        
        ;moving input 1
        MOV A,AL
        SUB A,48
                
        ;printing space        
        MOV DL,32
        MOV AH,2
        INT 21H
        
        ;input 2
        MOV AH,1
        INT 21H
        
        ;moving input 2
        MOV B,AL
        SUB B,48
        
        ;printing new line
        MOV DL,10
        MOV AH,2
        INT 21H
        
        ;back to start of new line
        MOV DL,13
        MOV AH,2
        INT 21H
        
        ;doing addition
        MOV AL,A
        ADD AL,B
        ADD AL,48
        
        ;print the add result
        MOV DL,AL
        MOV AH,2
        INT 21H
        
        ;printing new line
        MOV DL,10
        MOV AH,2
        INT 21H
        
        ;back to start of new line
        MOV DL,13
        MOV AH,2
        INT 21H 
        
        ;doing subtraction
        MOV AL,A
        SUB AL,B
        ADD AL,48
        
        ;print the sub result
        MOV DL,AL
        MOV AH,2
        INT 21H
    main endp
end main    