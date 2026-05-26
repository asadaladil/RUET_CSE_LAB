.model small
.stack 100h
.data
    str1 db "My name is Adil$" 
    v db 0
    c db 0 
    chk db 0
    vowel db "aeiou$" 
    
.code
    main proc
        mov ax,@data
        mov ds,ax
        mov es,ax
        
        
        ;conver to lowercase
        mov cx,15
        lea si,str1
        lower:
            mov al,[si]
            cmp al,32
            je due1
            cmp al,90
            jle convert
            due1:
                inc si
                loop lower    
            lea si,str1
            mov cx,15    
            jmp level1
        
        convert:
            add al,32
            mov [si],al
            jmp due1
        
        level1:
            lea di,vowel
            mov al,[si]
            mov chk,0
            cmp al,32
            je due3
            
            level2:                 
                cmp al,[di]
                je vowell
                due4:
                    inc di
                    cmp [di],'$'
                    je due2 
                    jmp level2
                
            due2:
                cmp chk,0
                je conso
            due3:    
                inc si
                loop level1 
                jmp print
        
        vowell:
            inc v 
            mov chk,1
            jmp due4
        conso:
            inc c
            jmp due3
        
        print:
            mov dl,v
            add dl,48
            mov ah,2
            int 21h
            mov dl,c
            add dl,48
            mov ah,2
            int 21h                             
           