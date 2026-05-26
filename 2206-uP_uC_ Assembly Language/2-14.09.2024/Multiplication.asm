                         .model small
.stack 100h
.data
    A db ?
    B db ?
    Q db ?
    R db ?
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;input 1        
        MOV AH,1
        INT 21H        
        
        ;moving input 1
        MOV A,AL
        SUB A,48
                 
        ;printing space         
        MOV Dl,32
        MOV AH,2
        INT 21H
                       
        ;input 2               
        MOV AH,1
        INT 21H
        
        ;moving input 2
        MOV B,AL
        SUB B,48
        
        ;printing new line
        MOV Dl,10
        MOV AH,2
        INT 21H
        
        ;back to start of new line
        MOV Dl,13
        MOV AH,2
        INT 21H
        
        ;doing multiplication        
        mov al,A 
        mov bl,B
        mul bl
        add ax,48
        
        ;printing product
        mov dx,ax
        mov ah,2
        int 21h
        
        
    main endp
end main    