# for the equation x^2.2-69=0
import math
from prettytable import PrettyTable

table=PrettyTable(["Iter","a","b","Xr","f(a)","f(b)","f(Xr)"])
table.float_format=".5"

def func_value(x):
    res=(x**2.2)-69
    #res=x*math.tan(x)+1
    return res

# def check(x,y):
#     return (y<0 and x>0) or (x<0 and y>0)

def False_Position_Func(a,b):
    i=1
    p_Xr=0
    while True:
        aa=func_value(a)
        bb=func_value(b)
        Xr=(a*bb-b*aa)/(bb-aa)
        F_Xr=func_value(Xr)
        table.add_row([i,a,b,Xr,aa,bb,F_Xr])
        if F_Xr==0:
            return Xr
        if aa*F_Xr<0:
            b=Xr
        else:
            a=Xr
        if abs(abs(p_Xr)-abs(Xr))<=E:
            return Xr
        p_Xr=Xr
        i+=1

# N=int(input("What is the Highest Degree of the Equation: "))
# for i in range(N,0,-1):
#     co_eff=int(input(f"The Co-efficient of X^{i} is: "))
#     Co_efficient.append(co_eff)
# Co_efficient.append(int(input("The Constant Value: \n")))
# Co_efficient=Co_efficient[::-1]


E=0.0001
a=6
b=7
flag=1
# F_a=func_value(a)
# for i in range(1,51):
#     F_b=func_value(i)
#     if check(F_a,F_b):
#         b=i
#         flag=1
#         break
#     F_b=func_value(-i)
#     if check(F_a,F_b):
#         b=-i
#         flag=1
#         break
#     i+=1

if flag:
    Xr=False_Position_Func(a,b)

    print(table)
    print(f"A root {Xr:.5f} is found between [{a},{b}] interval\n")
else:
    print("No such interval found")
