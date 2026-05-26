.model small
.stack 100h
.data
    str1 db "Enter Your 2 digit Number: $"
    str2 db 10,13,"Prime Number$"
    str3 db 10,13,"Composite Number$"
    str4 db 10,13,"Not Prime or composite number$"
    A dw ?
    B db ?
    c dw ? 
    d db 10 
    e db 2
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;string print
        lea dx,str1
        mov ah,9
        int 21h
        
        ;taking input
        mov ah,1
        int 21h
        sub al,48
        mov b,al
        
        mov ah,1
        int 21h 
        sub al,48
        mov ah,0
        mov c,ax
        
        ;double digit conversion
        mov al,b
        mul d
        add ax,c
             
        ;change value
        mov a,ax
        
        ;divide by 2
        div e
        mov ah,0
        
        ;loop variable
        mov cx,ax
        cmp cx,0
            jle level2
        
        ;prime check
        level1:
            mov ax,a
            div cl
            cmp ah,0
                je compo
            cmp cx,2
                je prime
            loop level1
        
        ;prime print
        prime:
            lea dx,str2
            mov ah,9
            int 21h
            jmp finish     
                
        ;composite number        
        compo:
            lea dx,str3
            mov ah,9
            int 21h
            jmp finish         
        
        level2:
            lea dx, str4
            mov ah,9
            int 21h
        
        finish:    
            
        
            