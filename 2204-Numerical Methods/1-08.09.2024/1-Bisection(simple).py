# for the equation only f(x)=x^3-x-2
from prettytable import PrettyTable

Co_efficient=[1,0,-1,-2][::-1]

def func_value(val):
    res=Co_efficient[0]
    for i in range(1,4):
        res+=(val**i)*Co_efficient[i]
    return res

table=PrettyTable(field_names=["Iter","a","b","Xr","f(a)","f(b)","f(Xr)"])
table.float_format=".4"
i=0
a=1
b=2
e=0.0001
p_Xr=0
for i in range(0,20):
    aa=func_value(a)
    bb=func_value(b)
    Xr=(a+b)/2
    F_Xr=func_value(Xr)
    table.add_row([i+1,a,b,Xr,aa,bb,F_Xr])
    if F_Xr==0:
        break
    if aa*F_Xr<0:
        b=Xr
    else:
        a=Xr
    if abs(abs(p_Xr)-abs(Xr))<=e:
        break
    p_Xr=Xr
print(table)
print(f"The root is {Xr:.4f} between that interval\n")

#dark+