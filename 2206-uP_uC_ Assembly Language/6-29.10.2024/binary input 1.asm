.model small
.stack 100h
.data 
    str1 db "Enter a binary number: $"
    str2 db 10,13,"You Entered: $"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;str print
        lea dx,str1
        mov ah,9
        int 21h
        
        ;taking input
        mov bl,0
        input:
            mov ah,1
            int 21h
              
            cmp al,0dh
                je str
            
            sub al,48    
            shl bx,1
            mov ah,0
            or bx,ax
            jmp input
        
        ;str print
        str:
            lea dx,str2
            mov ah,9
            int 21h
            mov cx,16
        
        Print:
            shl bx,1
            jc one
            jnc zero
            
        compare:    
            loop print
        jmp finish
        
        one:
            mov dl,49
            mov ah,2
            int 21h
            jmp compare
        zero:
            mov dl,48
            mov ah,2
            int 21h
            jmp compare
        
        finish:                 
            
                    
            
                
                