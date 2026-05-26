.model small
.stack 100h
.data
    A db 3,8,7,2,1,105
    C db 5
    
    f db 105
    
    i db 1
    d db 6
    str1 db 'Not Found$'
.code
    main proc
        mov ax,@data
        mov ds,ax
             
        
        ;linear searching     
        mov si,0
        mov cx,0
        mov cl,d
        loop1:
            mov al,A[si]
            cmp al,f
            je next
            inc si
            inc i
            loop loop1
            
        lea dx,str1
        mov ah,9
        int 21h
        jmp finish
        
        next:
            mov dl,i
            add dl,48
            mov ah,2
            int 21h
        
        finish:        
            
                     
            
                
            
        
        