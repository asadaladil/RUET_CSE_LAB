.model small
.stack 100h
.data
    str1 db "Hello$"
    str2 db 5 dup(?),'$'                        
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        lea si,str1+4
        lea di,str2
        
        mov cx,5
        loop1:
            mov al,[si]
            mov [di],al
            dec si
            inc di
            loop loop1
        
        lea dx,str2
        mov ah,9
        int 21h        