from prettytable import PrettyTable


table=PrettyTable()
table.field_names=(["n","x","y","z"])
table.float_format=".4"

xx,yy,zz=0,0,0
x,y,z=1000,1000,1000
i=0
while(abs(xx-x) or abs(yy-y) or abs(zz-z))>=0.0001:
    i+=1
    x,y,z=xx,yy,zz
    xx=(9-2*y-z)/10
    yy=(-44-2*x+2*z)/20
    zz=(22+2*x-3*y)/10
    table.add_row([i,xx,yy,zz])

print(table)
