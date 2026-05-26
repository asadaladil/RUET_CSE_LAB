import numpy as np
from prettytable import PrettyTable

value_x=[0,1,2,3,4,5,6]
value_y=[71,89,67,43,31,18,9]
table=PrettyTable()
table.field_names=["x","y","x^2","x^3","x^4","x*y","x^2*y"]

m=len(value_x)
x_2=0
x_3=0
x_4=0
x2y=0
sum_x=0
xy=0
sum_y=0
for i in range(m):
    x,y=value_x[i],value_y[i]
    x_2+=x**2
    xy+=x*y
    sum_x+=x
    sum_y+=y
    x_3+=x**3
    x_4+=x**4
    x2y+=(x**2)*y
    table.add_row([x,y,x**2,x**3,x**4,x*y,(x**2)*y])
table.add_row([f"Σx={sum_x}",f"Σy={sum_y}",
                    f"Σx^2={x_2}",f"Σx^3={x_3}",
                    f"Σx^4={x_4}",f"Σxy={xy}",
                    f"Σx^2*y={x2y}"])

A=np.array([[m,sum_x,x_2],
            [sum_x,x_2,x_3],
            [x_2,x_3,x_4]])
B=np.array([sum_y,xy,x2y])
X=np.linalg.solve(A,B)

print(table)
print(f"a0={X[0]:.2f}\na1={X[1]:.2f}\na2={X[2]:.2f}")