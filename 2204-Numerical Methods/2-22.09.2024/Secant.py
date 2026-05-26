# for the general polynomial equation
# for the equation x^3-2x-5=0

from prettytable import PrettyTable
Co_efficient=[]

table=PrettyTable(["Iter","X_n-1","X_n","X_n+1","f(Xn)","X_n+1 - X_n"])
table.float_format=".6"

def func_value(x):
    res=Co_efficient[0]
    for i in range(1,len(Co_efficient)):
        res+=(x**i)*Co_efficient[i]
    return res

# def check(x,y):
#     return (y<0 and x>0) or (x<0 and y>0)

def Secant_Func(x0,x1):
    i=1
    p_Xr=0
    while True:
        f0=func_value(x0)
        f1=func_value(x1)
        if f0==f1 or f0==f1==0:
            return x0
        x2=(x0*f1-x1*f0)/(f1-f0)
        table.add_row([i,x0,x1,x2,f1,abs(x2-x1)])

        if abs(x2-x1)<=E:
            return x2
        x0=x1
        x1=x2
        i+=1

N=int(input("What is the Highest Degree of the Equation: "))
for i in range(N,0,-1):
    co_eff=int(input(f"The Co-efficient of X^{i} is: "))
    Co_efficient.append(co_eff)
Co_efficient.append(int(input("The Constant Value: \n")))
Co_efficient=Co_efficient[::-1]


E=0.0001
a=2
b=3
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
    Xr=Secant_Func(a,b)

    print(table)
    print(f"A root {Xr:.6f} is found between [{a},{b}] interval\n")
else:
    print("No such interval found")
