.model small
.stack 100h
.data
    A db ?
    B db ?
    Q db ?
    R db ?
    str1 db "Enter Your 1st Number: $"
    str2 db "Enter Your 2nd Number: $"
    sum db "Sum=$"
    subb db "Subtraction=$"
    mult db "Multiplication=$"
    quo db "Quotient=$"
    rem db "Remainder=$"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;first string print
        lea DX,str1
        mov ah,9
        int 21h                        
        
        ;input 1        
        MOV AH,1
        INT 21H        
        
        ;moving input 1
        MOV A,AL
        SUB A,48
        
        ;printing new line
        MOV Dl,10
        MOV AH,2
        INT 21H
        
        ;back to start of new line
        MOV DL,13
        MOV AH,2
        INT 21H
        
        ;second string print
        lea DX,str2
        mov ah,9
        int 21h                 
                       
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
        
        ;sum word printong
        lea dx,sum
        mov ah,9
        int 21h
        
        ;doing addition
        mov al,A
        add al,b
        add al,48
        
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
        
        ;sub word print
        lea dx,subb
        mov ah,9
        int 21h
        
        ;doing subtraction
        MOV AL,A
        SUB AL,B
        ADD AL,48                
        
        ;print the sub result
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
        
        ;mult word print
        lea dx,mult
        mov ah,9
        int 21h
        
        ; doing multiplication        
        mov al,A 
        mov bl,B
        mul bl
        add ax,48
        
        ;printing product
        mov dx,ax
        mov ah,2
        int 21h 
        
        ;printing new line
        MOV DL,10
        MOV AH,2
        INT 21H
        
        ;back to start of new line
        MOV DL,13
        MOV AH,2
        INT 21H
        
        ;Quo word print
        lea dx,quo
        mov ah,9
        int 21h
        
        ;doing division
        mov al,A 
        mov ah,0
        div B
        mov Q,al
        add Q,48
        mov R,ah
        add R,48
        
        ;printing quotient
        mov dl,Q
        mov ah,2
        int 21h
        
        ;printing new line
        MOV DL,10
        MOV AH,2
        INT 21H
        
        ;back to start of new line
        MOV DL,13
        MOV AH,2
        INT 21H
        
        ;rem word print
        lea dx,rem
        mov ah,9
        int 21h
        
        ;printing remainder
        mov dl,R
        mov ah,2
        int 21h
        
        
    main endp
end main    