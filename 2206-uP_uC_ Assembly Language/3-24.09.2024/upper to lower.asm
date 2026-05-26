.model small
.stack 100h
.data
    letter db ?
    str1 db "Enter Your Uppercase Letter: $"
    str2 db "The corresponding Lowercase Letter is: $"
    str3 db "Enter Your Lowercase Letter: $"          
    str4 db "The corresponding Uppercase Letter is: $"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;print the first string
        lea dx,str1
        mov ah,9
        int 21h
        
        ;taking input
        mov ah,1
        int 21h
        
        ;change variable
        mov letter,al
        
        ;new line
        mov dl,10
        mov ah,2
        int 21h
        
        ;back to first
        mov dl,13
        mov ah,2
        int 21h
        
        ;print the string
        lea dx,str2
        mov ah,9
        int 21h
        
        ;change to lowercase
        mov al,letter
        add al,32           
        
        ;print it
        mov dl,al
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
        
        ;new line
        MOV DL,10
        MOV AH,2
        INT 21H
        
        ;print the second string
        lea dx,str3
        mov ah,9
        int 21h
        
        ;taking input
        mov ah,1
        int 21h
        
        ;change variable
        mov letter,al
        
        ;new line
        mov dl,10
        mov ah,2
        int 21h
        
        ;back to first
        mov dl,13
        mov ah,2
        int 21h
        
        ;print the string
        lea dx,str4
        mov ah,9
        int 21h
        
        ;uppercase
        mov dl,letter
        sub dl,32
        
        ;print
        mov ah,2
        int 21h
        
         