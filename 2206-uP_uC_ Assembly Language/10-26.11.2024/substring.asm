.model small
.stack 100h
.data
    str1 db "aaabcdmb$"
    str2 db "abc$"
    ff db "Substring Found$"
    nf db "Not Found$"
    b db 1
.code
    main proc
        mov ax,@data
        mov ds,ax
        mov es,ax
        
        mov cx,8 ;size of main string str1
        lea si,str1
        lea di,str2
        cld
        mov ax,0
        jmp level1
   
        level1: 
            cmpsb
            jz level2
            cmp ax,0
            jg dsi 
            lea di,str2
            due:
               loop level1
        nfound:
            lea dx,nf
            mov ah,9
            int 21h
            jmp exit
             
        level2:
            inc ax
            cmp [di],'$'
            je found
            jmp due
        dsi:
            dec si
            lea di,str2
            jmp due 
                      
        found:
            lea dx,ff
            mov ah,9
            int 21h       
        
        exit:
        
            
        
            