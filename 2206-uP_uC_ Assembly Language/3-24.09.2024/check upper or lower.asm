.model small
.stack 100h
.data
    A db ?
    str1 db "Enter a Letter: $"
    str2 db "The corresponding uppercase letter is $"
    str3 db "The corresponding lowercase letter is $"
    str4 db "It is not Letter$"
    str5 db 10,13,"$"
    
.code
    main proc
        mov ax,@data
        mov ds,ax  
        
        ;str1 print
        lea dx,str1
        mov ah,9
        int 21h
        
        ;taking input
        mov ah,1
        int 21h
        mov A,al
        
        ;new line
        lea dx,str5
        mov ah,9
        int 21h
        
        ;comparing values
        cmp A,97
            jge label1
            jl label2
        
        ;A>=97
        label1:
             cmp A,122
                jg label3
                jle label4
        
        ;A<97     
        label2:
             cmp A,65
                jge label5
              
        
        ;A>122     
        label3:
             lea dx,str4
             mov ah,9
             int 21h
             jmp label7
        
        ;lower case letter
        label4:
            ;print uppercase
            lea dx,str2
            mov ah,9
            int 21h
            
            mov al,A
            sub al,32
            
            mov dl,al
            mov ah,2
            int 21h
            jmp label7
        
        ;A<=90
        label5:
            cmp A,90
                jg label3
                jle label6
        
        ;upper case letter
        label6:
            
            ;print lowercase
            lea dx,str3
            mov ah,9
            int 21h 
            
            mov al,A
            add al,32
            
            mov dl,al
            mov ah,2
            int 21h
            jmp label7
        
        ;breaking condition
        label7:
                       
                
       
                                                 