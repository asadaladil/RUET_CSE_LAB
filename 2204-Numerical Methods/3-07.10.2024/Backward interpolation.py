from prettytable import PrettyTable
import math

value_x=[1,2,3,4,5]#[1,3,5,7]
value_y=[3.88,3.98,4,3.98,3.9]#[24,120,336,720]
table = PrettyTable()

def create_table(n):
    field=["x","y","∆y"]
    for i in range(2,n+1):
        field.append(f"∆{i}y")
    table.field_names=field


def Backward_difference(n):
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
    
    for i in range(len(value_x)-1,-1,-1):
        row=[value_x[i],value_y[i]]
        for j in range(len(del_value)):
            if i+1>len(del_value[j]):
                row.append("")
                continue
            row.append(del_value[j][i])
        table.add_row(row=row)
    
    p=(n-value_x[-1])/abs(value_x[0]-value_x[1])
    q=p
    result=value_y[-1]
    for i in range(1,len(del_value)+1):
        result+=del_value[i-1][-1]*q/math.factorial(i)
        q*=(p+i)
    
    return result


result=Backward_difference(6)
print(table)
print(result)