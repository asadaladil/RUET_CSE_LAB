import re

A=input().lower()
A=A.strip()
B=A.replace('+',' ').replace('-'," -").replace('='," = ").replace("x^2","x*x").replace("y^2","y*y").split(' ')
on=False
Co_ef={
    "x*x":0.0,
    "y*y":0.0,
    "xy":0.0,
    "x":0.0,
    "y":0.0
}
cons=0
for i in range(len(B)):
    if on==True:
        str_p=re.sub(r'[-.]?\d+','',B[i])
        B[i]=B[i].replace(str_p,'')
        if B[i]=='':
            B[i]='1'
        if str_p not in Co_ef:
            if str_p=='':
                cons-=float(B[i])
            continue
        Co_ef[str_p]-=float(B[i])
    elif B[i]!='=':
        str_p=re.sub(r'[-.]?\d+', '',B[i])
        B[i]=B[i].replace(str_p,'')
        if B[i]=='':
            B[i]='1'
        if str_p not in Co_ef:
            if str_p=='':
                cons+=float(B[i])
            continue
        Co_ef[str_p]+=float(B[i])
    if B[i]=='=':
        on=True
for i in Co_ef.items():
    print(i)
print(cons)


"""
x^2+y^2+0xy-8x-10y+1=0
x^2+y^2+0xy-2x-2y-3=0
4x^2+4y^2+0xy-8x+24y-17=0
x^2+y^2+0xy+0x+0y-25=0
x^2+y^2+0xy+8x+4y-5=0
2x^2+2y^2+0xy-1x+3y+1=0
100x^2+100y^2+0xy-200x-400y+100=0
3x^2+3y^2+0xy+6x-24y-57=0
20000x^2+20000y^2+0xy-40000x+12000y-12000=0
x^2+y^2-0xy-8x+0y+0=0
2x^2+1.5y^2+10.6=0
25.7589x^2+30.5879y^2+10.25x+4.15y+12.75=0
25.7589x^3+10.25x+4.15y+12.75=0
x+y+10=5x^2-6y^2

"""
