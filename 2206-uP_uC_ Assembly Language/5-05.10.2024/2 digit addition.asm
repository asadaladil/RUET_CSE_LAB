.model small
.stack 100h
.data
    str1 db "Enter your 1st 2 digit no: $"
    str2 db 10,13,"Enter your 2nd 2 digit no: $"
    str3 db 10,13,"Addition: $"
    str4 db 10,13,"The result goes to 3 digits$"
    a db ?
    b db ?
    c db ? 
    d db ?
    e db 10
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;taking input1:
        lea dx,str1
        mov ah,9
        int 21h
        mov ah,1
        int 21h
        sub al,48
        mov a,al
        
        mov ah,1
        int 21h
        sub al,48
        mov b,al
        
        ;taking input2:
        lea dx,str2
        mov ah,9
        int 21h
        mov ah,1
        int 21h
        sub al,48
        mov c,al
        
        mov ah,1
        int 21h
        sub al,48
        mov d,al
        
        ;double digit conversion1
        mov al,a
        mul e
        mov bl,b
        mov bh,0
        add ax,bx
        mov cx,ax
        
        ;double digit conversion2
        mov al,c
        mul e
        mov bl,d
        mov bh,0
        add ax,bx
        mov bx,ax
        
        ;addition
        mov ax,cx
        add ax,bx
        mov bx,ax
        
        ;checking 100>
        cmp ax,100
            jge digit3
        jmp print    
            
        digit3:
            lea dx,str4
            mov ah,9
            int 21h
            jmp finish
        
        print:
            lea dx,str3
            mov ah,9
            int 21h
            
            ;division
            mov ax,bx
            div e
            add al,48
            add ah,48
            mov a,al
            mov d,ah
            
            mov dl,a
            mov ah,2
            int 21h
            
            mov dl,d
            mov ah,2
            int 21h
        
        finish:
            endp main      
            
        
         
        
        
            