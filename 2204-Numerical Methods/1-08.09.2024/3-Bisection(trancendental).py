# for the equation only f(x)=xe^x - 1
from prettytable import PrettyTable
import math

def func_value(x):
    res=x**3+x**2+x+7
    # res=val*(math.e**val)-1
    return res

table=PrettyTable(["Iter","a","b","Xr","f(a)","f(b)","f(Xr)"])
table.float_format=".4"
i=0
a=-2.2
b=-2
e=0.0001
p_Xr=0
for i in range(0,20):
    aa=func_value(a)
    bb=func_value(b)
    Xr=(a+b)/2
    F_Xr=func_value(Xr)
    table.add_row([i+1,a,b,Xr,aa,bb,F_Xr])
    if aa*F_Xr<0:
        b=Xr
    else:
        a=Xr
    if abs(F_Xr)<=e:
        break
    p_Xr=Xr
print(table)
print(f"The root is {Xr:.4f} between that interval\n")
