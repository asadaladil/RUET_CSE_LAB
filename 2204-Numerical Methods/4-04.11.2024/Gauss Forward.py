from prettytable import PrettyTable
import math

# value_x=[1.00,1.05,1.10,1.15,1.20,1.25,1.30]
# value_y=[2.7183,2.8577,3.0042,3.1582,3.3201,3.4903,3.6693]
value_x=[0,1,2,3,4,5,6]
value_y=[6.9897,7.4036,7.7815,8.1291,8.4510,8.7506,9.0309]
table = PrettyTable()

def create_table(n):
    field=["x","y","∆y"]
    for i in range(2,n+1):
        field.append(f"∆{i}y")
    table.field_names=field
    table.float_format=".5"


def Gauss_Central_Forward(n):
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
    
    mid=math.ceil(len(value_y)/2)-1
    p=(n-value_x[mid])/abs(value_x[0]-value_x[1])
    q=1
    result=value_y[mid]
    for i in range(0,len(del_value)):
        if i%2==0:
            q*=(p-i)
            m=int(len(del_value[i])/2)
        else:
            q*=(p+i)
            m=int(len(del_value[i])/2)
        result+=del_value[i][m]*q/math.factorial(i)
    
    return result

val=1.17
result=Gauss_Central_Forward(val)
print(table)
print(f"y({val})={result:.5f}\nError:{abs(math.e**val-result):.5f}")


