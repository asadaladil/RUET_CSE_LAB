# Integration for y=1/(1+x) function
import math

def func_value(x):
    #return 1/(1+x**2)
    return (x-x**2)**(-0.5)

def Trapezoid(n,x_0,x_n):
    h=((x_n-x_0)/n)
    result=func_value(x_n)
    #print(x_0,",",func_value(x_0))
    for i in range(1,n):
        result+=2*(func_value(x_0+i*h))
        print(x_0+i*h,",",func_value(x_0+i*h))
    print(x_n,",",func_value(x_n))
    return result*(h/2)

result1=Trapezoid(10,0,0.5)
# result2=Trapezoid(0.25,0,1)
# result3=Trapezoid(0.125,0,1)
# result4=Trapezoid(0.1,0,1)
print(f"For h=0.5, I= {result1:.5f} from x= 0 to 1")
# print(f"For h=0.25, I= {result2:.5f} from x= 0 to 1")
# print(f"For h=0.125, I= {result3:.5f} from x= 0 to 1")
# print(f"For h=0.1, I= {result4:.5f} from x= 0 to 1")
