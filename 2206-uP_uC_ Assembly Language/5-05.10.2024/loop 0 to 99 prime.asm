.model small
.stack 100h
.data
    str1 db "0 to 99 Prime Number Print: ",10,13,"$"
    str2 db "->Prime Number",10,13,"$"
    str3 db "->Composite Number",10,13,"$"
    str4 db "->Not Prime or composite number",10,13,"$"
    A dw 0
    B db ?
    c db ? 
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
        
        main_loop:
            cmp a,99
                jg finish                  
            mov ax,a
            
            ;for 0 and 1
            mov cx,ax
            cmp cx,1
                jle level2
            
            ;divide by 2
            div e
            mov cl,al    
            
            ;check
            subloop:
            mov ax,a
            div cl
            cmp ah,0
                je compo
            cmp cx,2
                je prime
            loop subloop               
            
            ;prime print
            prime:
                mov ax,a
                div d
                mov b,al
                mov c,ah
                
                ;number print
                mov dl,b
                add dl,48
                mov ah,2
                int 21h
                
                mov dl,c
                add dl,48
                mov ah,2
                int 21h
                
                ;prime print
                lea dx,str2
                mov ah,9
                int 21h
                inc a
                jmp main_loop     
                    
            ;composite number        
            compo:
                mov ax,a
                div d
                mov b,al
                mov c,ah
                
                ;number print
                mov dl,b
                add dl,48
                mov ah,2
                int 21h
                
                mov dl,c
                add dl,48
                mov ah,2
                int 21h
                
                lea dx,str3
                mov ah,9
                int 21h
                inc a
                jmp main_loop        
            
            level2:
                mov ax,a
                div d
                mov b,al
                mov c,ah
                
                ;number print
                mov dl,b
                add dl,48
                mov ah,2
                int 21h
                
                mov dl,c
                add dl,48
                mov ah,2
                int 21h
                
                lea dx, str4
                mov ah,9
                int 21h
                inc a
                jmp main_loop
            
        finish:    
            
        
            