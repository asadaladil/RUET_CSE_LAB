.model small
.stack 100h
.data
    A db ?
    B db 2 
    C db ?
    str1 db 10,13,"Even Number.$"
    str2 db 10,13,"Odd Number.$"
    str3 db "Enter a number: $"
    str4 db 10,13,"Its not a digit.$"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;string print
        lea dx,str3
        mov ah,9
        int 21h
        
        ;taking input and changing
        mov ah,1
        int 21h
        
        ;char to digit
        mov a,al
        
        ;digit check
        cmp a,'0'
            jge level3
        lea dx,str4
        mov ah,9
        int 21h
        jmp level2
        
        level3:
            cmp a,'9'
                jle level4 
            lea dx,str4
            mov ah,9
            int 21h
            jmp level2                 
        
        ;division:
        level4:
        mov al,a
        mov ah,0
        div B
        
        ;changing remainder
        add ah,48
        mov a,ah 
        
        ;checking
        cmp a,'0'
            je level1
        lea dx,str2
        mov ah,9
        int 21h
        jmp level2
        
        level1:
            lea dx,str1
            mov ah,9
            int 21h
        
        level2:
               endp main
        
        
        
        