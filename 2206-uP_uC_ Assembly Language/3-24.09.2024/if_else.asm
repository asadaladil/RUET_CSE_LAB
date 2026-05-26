.model small
.stack 100h
.data
    A db 10
    str1 db "Positive$"
    str2 db "Negative$"
    str3 db "Zero$"
    
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;comparing values
        cmp A,0
            je label1
            jg label2
            jl label3
        
        ;A==0
        label1:
             lea dx,str3
             mov ah,9
             int 21h
             jmp label4
        
        ;A>0     
        label2:
             lea dx,str1
             mov ah,9
             int 21h
             jmp label4 
        
        ;A<0     
        label3:
             lea dx,str2
             mov ah,9
             int 21h
             jmp label4
        
        ;breaking condition
        label4:
                    