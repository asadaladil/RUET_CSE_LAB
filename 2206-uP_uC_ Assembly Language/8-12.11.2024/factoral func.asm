.model small    ;for 8 factorial only
.stack 100h
.data
    str1 db "Enter your number: $"
    str2 db 10,13,"Factorial value is $"
    a dw 10
    b dw ?
    c dw ?
.code        
    main proc
        mov ax,@data
        mov ds,ax
        mov dx,'&'
        push dx 
        
        ;print str
        lea dx,str1
        mov ah,9
        int 21h
        
        ;input
        mov ah,1
        int 21h
        sub al,48
        call Factorial
        
        str:
            mov bx,ax                
            lea dx,str2
            mov ah,9
            int 21h
        
        level1:
            cmp bx,0
                je level2
            mov ax,bx
            mov dx,0
            div a
            push dx
            mov bx,ax
            jmp level1
            
        level2:
            pop dx
            cmp dx,'&'
                 je finish
            add dx,48
            mov ah,2
            int 21h
            jmp level2                             
         
     Factorial proc 
        mov cx,0 
        mov cl,al
        mov ax,1
        jcxz done
        
        fact:
            mul cx
            loop fact
        done:
            ret
    
    finish:       
            