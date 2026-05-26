.model small
.stack 100h
.data
    a db 10101011b
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        mov cl,8 
        mov bl,0                       
                    
        ;main loop
        level1:
            shr a,1
            jc level2
        level3:
            loop level1
            jmp finish
        
        ;increase b    
        level2:
            inc bl
            jmp level3        
        
        finish:
            add bl,48
            mov dl,bl
            mov ah,2
            int 21h
        
            
                    