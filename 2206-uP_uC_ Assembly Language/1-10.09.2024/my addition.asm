.model small
.stack 100h
.data
    a db ?
    b db ?
.code
    main proc
        mov AX,@data
        mov DS,AX
        
        mov AH,1
        INT 21h
        mov A,AL
        sub A,48 
        
        mov DL,32
        mov AH,2
        INT 21h
        
        
        mov AH,1
        INT 21h
        mov B,AL
        sub B,48
        
        mov DL,10
        mov AH,2
        INT 21h
        
        mov DL,13    
        mov AH,2
        INT 21h
        
        mov AL,A
        add AL,B
        add AL,48 
        
        mov DL,AL
        mov AH,2
        INT 21h 
        
    main endp
    end main
    