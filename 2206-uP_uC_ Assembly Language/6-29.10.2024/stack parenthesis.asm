.model small
.stack 100h
.data
    str1 db "Enter your expression: $"
    str2 db 10,13,"Invalid Bracket Sequence.$"
    str3 db 10,13,"Valid Bracket Sequence.$"
    str4 db 10,13,"No Bracket Sequence$"
    a db 2 ;2 for no bracket
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;str print
        lea dx,str1
        mov ah,9
        int 21h
        
        ;last of stack
        mov ax,'&'
        push ax
        
        input:
            mov ah,1
            int 21h
            
            cmp al,0dh  ;newline
                je finish
            
            cmp al,'('
                je level2
            cmp al,'{'
                je level2
            cmp al,'['
                je level2
                
            pop bx
            
            cmp al,')'
                je next1 
            cmp al,'}'
                je next2
            cmp al,']'
                je next3
            
            push bx ;as al=letter or number    
            jmp input              
            
                        
        level2:
            mov a,0
            mov ah,0
            push ax
            jmp input
        
        next1:
            cmp bx,'('
                je input
            mov a,1
            jmp input
            
        next2:
            cmp bx,'{'
                je input
            mov a,1
            jmp input
             
        next3:
            cmp bx,'['
                je input
            mov a,1
            jmp input                        
        
        finish:
            cmp a,2
                je level4
            cmp a,1
                je level1
            pop bx
            cmp bx,'&'    
                je level3    
            jmp level1    
        
        level1:
            lea dx,str2
            mov ah,9
            int 21h
            jmp endd
        
        level3:
            lea dx,str3
            mov ah,9
            int 21h
            jmp endd
        
        level4:
            lea dx,str4
            mov ah,9
            int 21h    
        
        endd:    
                                                       
        
        