.model small
.stack 100h
.data 
    str1 db "Enter a binary value upto 16 bits: $"
    str2 db 10,13,"Hexadecimal Value: $"
    a dw 16
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
            mov ah,1
            int 21h
            cmp al,0dh
                je str
            sub al,48
            mov ah,0
            shl bx,1
            or bx,ax
            loop input
        
        str:
            lea dx,str2
            mov ah,9
            int 21h
            cmp bx,0
                je zero
            jmp level1
        
        zero:;if bx=0 at first
            mov dx,30h
            mov ah,2
            int 21h
            jmp finish            
            
        level1: ;push the remainder into stack
            cmp bx,0
                je level2
            mov dx,0    
            mov ax,bx
            div a
            push dx    
            mov bx,ax
            jmp level1               
        
        level2: ;pop the stack value and comparison
            pop bx
            cmp bx,'&'
                je finish
            cmp bx,9
                jg hexa    
            add bx,48
            mov dx,bx
            mov ah,2
            int 21h
            jmp level2
        
        hexa:
            add bx,55
            mov dx,bx
            mov ah,2
            int 21h
            jmp level2    
            
        finish: