from prettytable import PrettyTable
from sympy import ln

value_x=[0.5,1,2,4]
value_y=[ln(2.5),ln(4.2),ln(7.1),ln(9.8)]

table=PrettyTable()
table.field_names=["x","y","x*y","x^2"]
m=len(value_x)
x_2=0
sum_x=0
xy=0
sum_y=0
for i in range(m):
    x,y=value_x[i],value_y[i]
    x_2+=x**2
    xy+=x*y
    sum_x+=x
    sum_y+=y
    table.add_row([x,y,x*y,x**2])
table.add_row([f"Σx={sum_x}",
                    f"Σy={sum_y}",f"Σxy={xy}",
                    f"Σx^2={x_2}"])
a1=(m*xy-sum_x*sum_y)/(m*x_2-sum_x**2)
a0=(sum_y-sum_x*a1)/m
print(table)
print(f"a0={a0:.5f}\na1={a1:.5f}")



    