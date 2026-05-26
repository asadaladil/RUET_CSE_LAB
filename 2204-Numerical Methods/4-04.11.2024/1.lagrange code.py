import math
def lagranje(x,n):
    res=1.0
    A=upper_part(x,n)
    for i in range(len(arr_x)):
        if i==n:
            continue
        res*=(arr_x[n]-arr_x[i])
    res=(A/res)*arr_y[n]
    return res

def upper_part(x,n):
    res=1.0
    for i in range(len(arr_x)):
        if i==n:
            continue
        res*=(x-arr_x[i])
    return res


arr_x=[]
arr_y=[]
n=int(input())
for i in range(n):
    x,y=map(float,input().split())
    arr_x.append(x)
    arr_y.append(y)

val=float(input())
final=0.0
for i in range(n):
    final+=lagranje(val,i)
print(f"y({val})={final:.5f}")
print(f"Error: {abs(final-math.log(val)):.5f}")