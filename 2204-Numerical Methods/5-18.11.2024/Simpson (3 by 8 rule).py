# Integration for y=1/(1+x) function

def func_value(x):
    return 1/(1+x)

def Simpson_3_by_8_rule(h,x_0,x_n):
    n=int((x_n-x_0)/h)

    result=func_value(x_0)+func_value(x_n)
    print(x_0,",",func_value(x_0))
    for i in range(1,n):
        if i%3==0:
            result+=2*(func_value(x_0+i*h))
        else:
            result+=3*(func_value(x_0+i*h))
        print(x_0+i*h,",",func_value(x_0+i*h))
    print(x_n,",",func_value(x_n))
    
    return result*(3*h/8)

result1=Simpson_3_by_8_rule(1/6,0,1)
# result2=Simpson_3_by_8_rule(10,0,1)
# result3=Simpson_3_by_8_rule(15,0,1)
print(f"For n=5, I= {result1:.5f} from x= 0 to 1")
# print(f"For n=10, I= {result2:.5f} from x= 0 to 1")
# print(f"For n=15, I= {result3:.5f} from x= 0 to 1")
