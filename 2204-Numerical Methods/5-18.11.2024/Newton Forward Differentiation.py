from prettytable import PrettyTable
import math

# value_x=[1,3,5,7]
# value_y=[24,120,336,720]
value_x=[1.0,1.2,1.4,1.6,1.8,2.0,2.2]
value_y=[2.7183,3.3201,4.0552,4.9530,6.0496,7.3891,9.0250]
table = PrettyTable()

def create_table(n):
    field=["x","y","∆y"]
    for i in range(2,n+1):
        field.append(f"∆{i}y")
    table.field_names=field
    table.float_format=".5"

def Differentiation(a,b):
    return (b-a)/1e-9

def Differentiation2(a,b,c):
    return (c-2*b+a)/1e-18


def Forward_difference(n):
    create_table(len(value_y)-1)
    del_value=[]
    temp=[]
    for i in range(1,len(value_y)):
        temp.append(value_y[i]-value_y[i-1])
    del_value.append(temp)
    
    for i in range(1,len(value_y)-1):
        temp=[]
        for j in range(1,len(del_value[i-1])):
            temp.append(del_value[i-1][j]-del_value[i-1][j-1])
        del_value.append(temp)
    
    for i in range(len(value_x)):
        row=[value_x[i],value_y[i]]
        for j in range(len(del_value)):
            if i+1>len(del_value[j]):
                row.append("")
                continue
            row.append(del_value[j][i])
        table.add_row(row=row)
    
    h=abs(value_x[0]-value_x[1])
    p=(n-value_x[0])/h
    q=p
    result1=0
    result2=0
    x_h=(p+1e-9)
    x_2h=(p+2e-9)
    for i in range(1,len(del_value)+1):
        dy_dp=Differentiation(q,x_h)
        dy_dp_2=Differentiation2(q,x_h,x_2h)
        result1+=del_value[i-1][0]*dy_dp/math.factorial(i)
        if i>1:
            result2+=del_value[i-1][0]*dy_dp_2/math.factorial(i)
        q*=(p-i)
        x_h*=(p-i+1e-9)
        x_2h*=(p-i+2e-9)

    return (result1/h),(result2/h**2)


result=Forward_difference(1.2)
print(table)
print(f"y'(1.2)= {result[0]:.5f}\ny''(1.2)= {result[1]:.5f}")