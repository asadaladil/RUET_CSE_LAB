.model small
.stack 100h
.data
    A db 1,2,3,4,5
      db 6,7,8,9,1
      db 2,3,4,5,6
      db 7,8,9,1,2
      db 3,4,5,6,7
    
    b db 5
    nl db 10,13,'$'
    spc db 32,'$'  
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;3rd row and 3rd column will be zero
        ;using based-indexed addressing mode
        
        mov si,2
        mov bx,0
        mov cx,5 
        
        col:
            ;mov al,A[bx][si] ;for checking  
            mov A[bx][si],0
            add bx,5
            loop col
        
        mov bx,10
        mov si,0
        mov cx,5
        
        row:
            mov A[bx][si],0
            inc si
            loop row
            
        
        ;print
        lea si,A
        loop1:
            mov cx,5
            ;mov si,0
            loop2: 
                mov dl,[si] 
                add dl,48
                mov ah,2
                int 21h
                
                lea dx,spc
                mov ah,9
                int 21h
                inc si
                loop loop2
                
            dec b
            cmp b,0
            je finish
            
            lea dx,nl
            mov ah,9
            int 21h
            inc bp
            jmp loop1
        
        finish:       
                          