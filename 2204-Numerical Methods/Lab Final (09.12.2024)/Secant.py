# f(x)=x^3-4x-9

def f(x):
    return x**3-4*x-9

def secant(x0,x1):

    i=1
    if f(x0)*f(x1)>=0:
        print("Invalid Interval")
        return

    while(abs(x1-x0)>=0.0001):
        f0=f(x0)
        f1=f(x1)
        x2=(x0*f1-x1*f0)/(f1-f0)
        x0=x1
        x1=x2
        print(f"i={i}, x0={x0:.5f}, x1={x1:.5f}, f(x0)={f0:.5f}, f(x1)={f1:.5f}, x2={x2:.5f}, del_x={(x1-x0):.5f}\n")
        i+=1

    return x1

res=secant(2,3)
print(f"{res:.5f}")


