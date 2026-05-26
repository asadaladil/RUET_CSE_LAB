.model small
.stack 100h
.data
    A db ?
    str1 db 10,13,"Decimal number: 10$"
    str2 db 10,13,"Decimal number: 11$"
    str3 db 10,13,"Decimal number: 12$"
    str4 db 10,13,"Decimal number: 13$"
    str5 db 10,13,"Decimal number: 14$"
    str6 db 10,13,"Decimal number: 15$"
    str7 db 10,13,"DEcimal number: $"
    
    inp db "Enter Your Hexadecimal number: $"
    inv db 10,13,"Invalid Input$" 

.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;taking input
        lea dx,inp
        mov ah,9
        int 21h
        
        mov ah,1
        int 21h
        mov a,al
        
        cmp a,48 ;0<
            jl level0
        cmp a,57 ;9<
            jle level1
        cmp a,65 ;A
            je level2
        cmp a,66 ;B
            je level3
        cmp a,67 ;C
            je level4
        cmp a,68 ;D
            je level5
        cmp a,69 ;E
            je level6
        cmp a,70 ;F
            je level7                    
        
        level0:
            lea dx,inv
            mov ah,9
            int 21h
            jmp finish
        
        level1:
            lea dx,str7
            mov ah,9
            int 21h

            mov dl,a
            mov ah,2
            int 21h
            jmp finish
        
        level2:
             lea dx,str1
             mov ah,9
             int 21h
             jmp finish
            
        level3:
             lea dx,str2
             mov ah,9
             int 21h
             jmp finish
        
        level4:
             lea dx,str3
             mov ah,9
             int 21h
             jmp finish
        
        level5:
             lea dx,str4
             mov ah,9
             int 21h
             jmp finish
            
        level6:
             lea dx,str5
             mov ah,9
             int 21h
             jmp finish
        
        level7:
             lea dx,str6
             mov ah,9
             int 21h
        
        finish:
            endp main                                               
            
            
                    