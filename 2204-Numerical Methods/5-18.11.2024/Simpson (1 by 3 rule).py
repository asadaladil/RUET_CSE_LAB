# Integration for y=1/(1+x) function

def func_value(x):
    return 1/(1+x)

def Simpson_1_by_3_rule(h,x_0,x_n):
    n=int((x_n-x_0)/h)

    result=func_value(x_0)+func_value(x_n)
    print(x_0,",",func_value(x_0))
    for i in range(1,n):
        if i%2==0:
            result+=2*(func_value(x_0+i*h))
        else:
            result+=4*(func_value(x_0+i*h))
        print(x_0+i*h,",",func_value(x_0+i*h))
    print(x_n,",",func_value(x_n))
    return result*(h/3)

result1=Simpson_1_by_3_rule(1/6,0,1)
# result2=Simpson_1_by_3_rule(0.25,0,1)
# result3=Simpson_1_by_3_rule(0.125,0,1)
# result4=Simpson_1_by_3_rule(0.1,0,1)
print(f"For h=0.5, I= {result1:.5f} from x= 0 to 1")
# print(f"For h=0.25, I= {result2:.5f} from x= 0 to 1")
# print(f"For h=0.125, I= {result3:.5f} from x= 0 to 1")
# print(f"For h=0.1, I= {result4:.5f} from x= 0 to 1")
