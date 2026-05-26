# for the general polynomial equation

from prettytable import PrettyTable
Co_efficient=[]

table=PrettyTable(["Iter","a","b","Xr","f(a)","f(b)","f(Xr)"])
table.float_format=".5"

def func_value(val):
    res=Co_efficient[0]
    for i in range(1,len(Co_efficient)):
        res+=(val**i)*Co_efficient[i]
    return res

def check(x,y):
    return (y<0 and x>0) or (x<0 and y>0)

def Bisection_Func(a,b):
    i=1
    p_Xr=0
    while True:
        aa=func_value(a)
        bb=func_value(b)
        Xr=(a+b)/2
        F_Xr=func_value(Xr)
        table.add_row([i,a,b,Xr,aa,bb,F_Xr])
        if F_Xr==0:
            return Xr
        if aa*F_Xr<0:
            b=Xr
        else:
            a=Xr
        if abs(abs(p_Xr)-abs(Xr))<=e:
            return Xr
        p_Xr=Xr
        i+=1

N=int(input("What is the Highest Degree of the Equation: "))
for i in range(N,0,-1):
    co_eff=int(input(f"The Co-efficient of X^{i} is: "))
    Co_efficient.append(co_eff)
Co_efficient.append(int(input("The Constant Value: ")))
Co_efficient=Co_efficient[::-1]


e=0.0001
a=0
b=0
flag=0
F_a=func_value(a)
for i in range(1,51):
    F_b=func_value(i)
    if check(F_a,F_b):
        b=i
        flag=1
        break
    F_b=func_value(-i)
    if check(F_a,F_b):
        b=-i
        flag=1
        break
    i+=1

if flag:
    Xr=Bisection_Func(2.6,2.7)

    print(table)
    print(f"A root {Xr:.5f} is found between [{a},{b}] interval\n")
else:
    print("No such interval found")
