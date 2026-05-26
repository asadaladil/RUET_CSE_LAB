import math

def f(x):
    e=math.e
    return e**(2*x)-e**x-2
def Trapezoidal(x0,xn,h):
    n=int((xn-x0)/h)

    result=f(x0)+f(xn)
    for i in range(1,n):
        result+=2*f(x0+i*h)
    
    return result*(h/2)

res=Trapezoidal(0,1,0.1)
print(f"{res:.5f}")