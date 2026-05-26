# for the general polynomial equation

from prettytable import PrettyTable
Co_efficient=[]

table=PrettyTable(["Iter","a","b","Xr","f(a)","f(b)","f(Xr)","Ep"])
table.float_format=".4"

def func_value(val):
    res=Co_efficient[0]
    for i in range(1,len(Co_efficient)):
        res+=(val**i)*Co_efficient[i]
    return res

def Bisection_Func(a,b):
    i=1
    p_Xr=0
    Ep=0
    while True:
        aa=func_value(a)
        bb=func_value(b)
        Xr=(a+b)/2
        F_Xr=func_value(Xr)
        table.add_row([i,a,b,Xr,aa,bb,F_Xr,Ep])
        if aa*F_Xr<0:
            b=Xr
        else:
            a=Xr
        Ep=abs(Xr-p_Xr)*100/Xr
        if Ep<=e:
            return Xr
        p_Xr=Xr
        i+=1

N=int(input("What is the Highest Degree of the Equation: "))
for i in range(N,0,-1):
    co_eff=int(input(f"The Co-efficient of X^{i} is: "))
    Co_efficient.append(co_eff)
Co_efficient.append(int(input("The Constant Value: ")))
Co_efficient=Co_efficient[::-1]


e=0.05
a=0
b=0
flag=0
F_a=func_value(a)
for i in range(1,51):
    F_b=func_value(i)
    if (F_b<0 and F_a>0) or (F_a<0 and F_b>0):
        b=i
        flag=1
        break
    i*=-1
    F_b=func_value(i)
    if (F_b<0 and F_a>0) or (F_a<0 and F_b>0):
        b=i
        flag=1
        break
    i*=-1
    i+=1

if flag:
    Xr=Bisection_Func(a,b)

    print(table)
    print(f"A root {Xr:.5f} is found between [{a},{b}] interval")
else:
    print("No such interval found")
