from prettytable import PrettyTable


table=PrettyTable()
table.field_names=(["n","x","y","z"])
table.float_format=".4"

xx,yy,zz=0,0,0
x,y,z=0,0,0
i=0
while(abs(xx-x) or abs(yy-y) or abs(zz-z))>=0.0001 or i==0:
    i+=1
    x,y,z=xx,yy,zz
    xx=(9-2*y-z)/10
    yy=(-44-2*xx+2*z)/20 # x=xx
    zz=(22+2*xx-3*yy)/10  # x=xx,y=yy
    table.add_row([i,xx,yy,zz])

print(table)

