# for the equation 1/(x+1)^0.5=0
import math
from prettytable import PrettyTable

table=PrettyTable(["Iter","Xn","g(x_n)","x_n+1-x_n"])
table.float_format=".5"

def func_value(x):
    res=1/(x+1)**0.5
    #res=0.5+math.sin(x)
    return res

# def check(x,y):
#     return (y<0 and x>0) or (x<0 and y>0)

def iteration_Func(a):
    i=1
    p_Xr=a
    while True:
        aa=func_value(p_Xr)
        table.add_row([i,p_Xr,aa,abs(p_Xr-aa)])
        if aa==0:
            return aa
        if abs(abs(p_Xr)-abs(aa))<=E:
            return aa
        p_Xr=aa
        i+=1

# N=int(input("What is the Highest Degree of the Equation: "))
# for i in range(N,0,-1):
#     co_eff=int(input(f"The Co-efficient of X^{i} is: "))
#     Co_efficient.append(co_eff)
# Co_efficient.append(int(input("The Constant value: \n")))
# Co_efficient=Co_efficient[::-1]


E=0.0001
# a=2
# b=3
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
    Xr=iteration_Func(0.5)

    print(table)
    print(f"A root {Xr:.5f} is found\n")
else:
    print("No such interx found")
