from math import atan2
from random import randint
from turtle import color
import matplotlib.pyplot as plt

p,q=1e10,1e10

def cross_p(o,a,b):
    return (a["x"]-o["x"])*(b["y"]-o["y"])-(a["y"]-o["y"])*(b["x"]-o["x"])

def draw_line(A,B):
    x=[A["x"],B["x"]]
    y=[A["y"],B["y"]]
    ax.plot(x, y, color="#0995db")
    plt.pause(0.1)
    return

def Graham_scan(points):
    n=len(points)
    hull=[]
    hull.append(points[0])
    for i in range(1,3):
        hull.append(points[i])
        draw_line(hull[-2],hull[-1])
    for i in range(3,n):
        while len(hull)>1 and cross_p(hull[-2],hull[-1],points[i])<=0:
            hull.pop()

            if len(ax.lines)>1:
                ax.lines[-1].set_color("#db0913")
                plt.pause(0.1)
                ax.lines[-1].remove()

        hull.append(points[i])
        draw_line(hull[-2],hull[-1])

    hull.append(points[0]) #last point
    draw_line(hull[-2],hull[-1])    
    return hull

points=[]
X=[20,2,16,7,16,19,18,16,5,17,6,12,3,15,14,10,20,14,11,8]#[i["x"] for i in points]
Y=[8,20,19,2,2,7,11,16,14,13,17,7,11,7,3,10,10,20,3,12]#[i["y"] for i in points]
j=0
with open("point.txt",mode="r") as file:
    for line in file:
        x,y=line.split(' ')
        X.append(int(x))
        Y.append(int(y))
    for i in range(20):
        temp={}
        temp["x"]=X[i]#randint(1,20)
        temp["y"]=Y[i]#randint(1,20)
        #file.write(f"{str(temp["x"])} {str(temp["y"])}\n")
        points.append(temp)
        if q>temp["y"]:
            p,q=temp["x"],temp["y"]
            j=i
points[0],points[j]=points[j],points[0]

points[1:]=sorted(points[1:], 
                  key=lambda point:atan2(point["y"]-q,point["x"]-p))

# Coordinates of the points

plt.ion()  # Turn on interactive mode
fig, ax = plt.subplots()
ax.set_xlim(0,23)
ax.set_ylim(0,23)
# Draw the points
ax.scatter(X,Y, color="#bc09db",s=18)  # s is the size of the points
for i in range(len(X)):
    plt.text(X[i],Y[i], f'({X[i]},{Y[i]})', fontsize=9, ha='center',va='bottom',font="Times New Roman")
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Convex Hull-Graham Scan')
hull=Graham_scan(points)
for i in range(len(ax.lines)):
    ax.lines[i].set_color("#0ad118")

rx=[]
ry=[]
for p in points:
    if p not in hull:
        rx.append(p["x"])
        ry.append(p["y"])
ax.scatter(rx,ry, color="#db040f",s=18)  
plt.ioff()  # Turn off interactive mode
plt.show()