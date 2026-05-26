# for the equation x^3-2x-5=0

from prettytable import PrettyTable

table=PrettyTable(["Iter","Xn","f(x_n)","X_n+1","x_n+1-x_n"])
table.float_format=".5"

def func_value(x):
    res=x**3-2*x-5
    return res

def differentiate_value(x):
    res=3*(x**2)-2
    return res

# def check(x,y):
#     return (y<0 and x>0) or (x<0 and y>0)

def NewtonRaphson_Func(a):
    i=1
    p_Xr=a
    while True:
        func=func_value(p_Xr)
        aa=p_Xr-(func/differentiate_value(p_Xr))
        table.add_row([i,p_Xr,func,aa,abs(aa-p_Xr)])
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
    Xr=NewtonRaphson_Func(2)

    print(table)
    print(f"An approximation root {Xr:.5f} is found\n")
else:
    print("No such interx found")
