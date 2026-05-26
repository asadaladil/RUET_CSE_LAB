.model small
.stack 100h
.data
    A db 9,3,7,2,1,5,8,9,4,9 
    C dw 10
    d db 10 
    str1 db ' $'
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;using bubble sort
        mov ax,0 
        mov bx,0
        mov cx,0
        mov cx,c
        
        loop1: 
            dec cx
            jcxz finish   
            lea si,A
            loop2:
                mov bl,[si]
                mov al,[si+1]
                cmp bl,al
                jg next
                due:
                    inc si
                    loop loop2
            dec c
            cmp c,0
            je finish
            mov cx,c
            jmp loop1
        
        next:
            mov [si],al
            mov [si+1],bl
            jmp due
        
        finish:
            lea si,A
            mov cx,0
            mov cl,d
            print:
                mov dl,[si]
                add dl,48
                mov ah,2
                int 21h
                
                lea dx, str1
                mov ah,9
                int 21h
                inc si
                loop print         
                
                
            
        
        