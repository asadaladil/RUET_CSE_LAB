TITLE PGM1_1: SAMPLE PROGRAM
.MODEL SMALL 

.STACK 100H  

.DATA
    A DW 2
    B DW 5
    SUM DW ? 
    
.CODE
    MAIN PROC
        ;initialize DS 
        
        MOV AX,@DATA
        MOV DS,AX      
        
        ;add the number
        
        MOV AX,A
        ADD AX,B
        MOV SUM,AX
        
        ;exit to DOS 
        
        MOV AX,4C00H
        INT 21H 
    
MAIN ENDP
    END MAIN  
    