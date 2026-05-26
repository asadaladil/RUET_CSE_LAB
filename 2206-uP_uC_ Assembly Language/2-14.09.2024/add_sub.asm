.model small
.stack 100h
.data
    A db 7
    B db 2
.code
    main proc
        MOV AX,@DATA
        MOV DS,AX                     
        
        MOV Al,A
        ADD Al,B
        ADD AL,48
                
        MOV Dl,Al        
        MOV AH,2 
        INT 21H
        
        MOV Dl,10
        MOV AH,2
        INT 21H
        
        MOV Dl,13
        MOV AH,2
        INT 21H
        
        MOV AL,A
        SUB AL,B
        ADD AL,48
        
        MOV DL,AL
        MOV AH,2
        INT 21H
        
        
    main endp
end main    