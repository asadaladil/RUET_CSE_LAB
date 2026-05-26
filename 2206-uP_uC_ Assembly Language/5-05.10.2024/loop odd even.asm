.model small
.stack 100h
.data
    str1 db "0 to 9 odd even number print:",10,13,"$"
    od db "->ODD Number",10,13,"$"
    eve db "->EVEN Number",10,13,"$"
    a dw 0
    b db 2
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;string print
        lea dx,str1
        mov ah,9
        int 21h
             
        ;loop     
        level1:
            cmp a,9
                jg finish
            mov ax,a
            div b
            cmp ah,0
                je even
            jmp odd    
        
        even:
            mov dx,a
            add dx,48
            mov ah,2
            int 21h
            lea dx,eve
            mov ah,9
            int 21h
            inc a
            jmp level1
        
        odd:
            mov dx,a
            add dx,48
            mov ah,2
            int 21h
            lea dx,od
            mov ah,9
            int 21h
            inc a
            jmp level1                
        
        finish:
                
        
                