.model small
.stack 100h
.data 
    str1 db "Enter a binary value upto 16 bits: $"
    str2 db 10,13,"Reverse Pattern: $"
    a db 0
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;str print
        lea dx,str1
        mov ah,9
        int 21h
        mov cx,16
        mov bx,0
        mov ax,'&'
        push ax
        
        ;input taking
        input:
            cmp a,16
                je str
            mov ah,1
            int 21h
            cmp al,0dh
                je str
            sub al,48
            mov ah,0
            shl bx,1
            or bx,ax  
            inc a
            jmp input
            
        str:
            lea dx,str2
            mov ah,9
            int 21h
            cmp bx,0
                je zero
            jmp output
                
        zero:
            mov dx,30h
            mov ah,2
            int 21h
            jmp finish            
        
        output:
            cmp a,0
                je finish
            shr bx,1
            jc level1
            jnc level2
            jmp finish
        
        level1:
            mov dx,'1'
            mov ah,2
            int 21h 
            dec a
            jmp output
        
        level2:
            mov dx,'0'
            mov ah,2
            int 21h
            dec a
            jmp output
        
        finish:            
                   