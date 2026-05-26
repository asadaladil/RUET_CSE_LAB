.model small
.stack 100h
.data
    ap db 10,13,"Your Grade: A+$"
    a db 10,13,"Your Grade: A$"
    am db 10,13,"Your Grade: A-$"
    bpp db 10,13,"Your Grade: B+$"
    b db 10,13,"Your Grade: B$"
    bm db 10,13,"Your Grade: B-$"
    c db 10,13,"Your Grade: C$"
    d db 10,13,"Your Grade: D$"
    f db 10,13,"Your Grade: F$"
    inp db "Your Marks: $"
    inv db 10,13,"Invalid Marks$"
    
    aa dw 101
    a1 db "101$"
.code
    main proc
        mov ax,@data
        mov ds,ax
        
        ;print string
        lea dx,inp
        mov ah,9
        int 21h
        lea dx,a1
        mov ah,9
        int 21h
                           
        cmp aa,100
            jg level0
            
        cmp aa,80
            jge level1
            
        cmp aa,75
            jge level2 
        
        cmp aa,70
            jge level3
        
        cmp aa,65
            jge level4
        
        cmp aa,60
            jge level5
        
        cmp aa,55
            jge level6
        
        cmp aa,50
            jge level7
        
        cmp aa,40
            jge level8
        
        cmp aa,39
            jle level9
        
        level0:
            lea dx, inv
            mov ah,9
            int 21h
            jmp finish                            
            
        level1:
            lea dx,ap
            mov ah,9
            int 21h
            jmp finish
        
        level2:
            lea dx,a
            mov ah,9
            int 21h
            jmp finish
        
        level3:
            lea dx,am
            mov ah,9
            int 21h
            jmp finish
        
        level4:
            lea dx,bpp
            mov ah,9
            int 21h
            jmp finish
        
        level5:
            lea dx,b
            mov ah,9
            int 21h
            jmp finish
        
        level6:
            lea dx,bm
            mov ah,9
            int 21h
            jmp finish
        
        level7:
            lea dx,c
            mov ah,9
            int 21h
            jmp finish
        
        level8:
            lea dx,d
            mov ah,9
            int 21h
            jmp finish
        
        level9:
            lea dx,f
            mov ah,9
            int 21h
            jmp finish
        
        finish:
            endp main                                         