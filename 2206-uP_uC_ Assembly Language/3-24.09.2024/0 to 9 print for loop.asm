.model small
.stack 100h
.data
    A db 0
    str1 db "0 to 9 using for loop:",10,13,10,"$"
    str2 db 10,13,"$";for new line
    str3 db 32,"$" ;for space
    
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;print the string
        lea dx,str1
        mov ah,9
        int 21h
                         
        ;for loop
        label1:
            cmp A,9
                jle label2
                jmp label3  
                
        ;value for printing
        label2:
            mov dl,A
            add dl,48
            mov ah,2
            int 21h
            
            lea dx,str3
            mov ah,9
            int 21h
            inc A
            jmp label1
        
        ;breaking the loop
        label3:                              