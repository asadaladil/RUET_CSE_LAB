# for the equation x − e^−x=0
from math import sin,cos,tan,pi,e
from prettytable import PrettyTable

table=PrettyTable(["Iter","b_n","b_n+1","(b_n/b_n+1)"])
table.float_format=".5"


a=[0]*50
a[1:5]=[2,0,-1/6,0,1/120,0,-1/5040]
b=[0,1]

def calculate_B(n):
    for i in range(2,n):
        temp=0
        for j in range(1,i):
            temp+=(a[i-j]*b[j])
        b.append(temp)

# def check(x,y):
#     return (y<0 and x>0) or (x<0 and y>0)

def Ramanujan_Func():
    N=25
    calculate_B(N)
    aa=0
    for i in range(2,N):
        aa=b[i-1]/b[i]
        table.add_row([i-1,b[i-1],b[i],aa])
    return aa   

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
    Xr=Ramanujan_Func()

    print(table)
    print(f"An approximation root {Xr:.5f} is found\n")
else:
    print("No such interval found")

