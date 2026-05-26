import math

def f(x):
    e=math.e
    return e**(2*x)-e**x-2
def Simpson_1_3(x0,xn,h):
    n=int((xn-x0)/h)

    result=f(x0)+f(xn)
    for i in range(1,n):
        if i%2==0:
            result+=4*f(x0+i*h)
        else:
            result+=2*f(x0+i*h)
    
    return result*(h/3)

res=Simpson_1_3(0,1,0.1)
print(f"{res:.5f}")