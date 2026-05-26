from math import atan2
import matplotlib.pyplot as plt

p,q=1e10,1e10
time=0.05
def cross_p(o,a,b):
    return (a["x"]-o["x"])*(b["y"]-o["y"])-(a["y"]-o["y"])*(b["x"]-o["x"])

def draw_line(A,B):
    x=[A["x"],B["x"]]
    y=[A["y"],B["y"]]
    ax.plot(x,y,color="black")
    plt.pause(time)
    return

def Graham_scan(points):
    n=len(points)
    hull=[]
    hull.append(points[0])
    for i in range(1,2):
        hull.append(points[i])
        draw_line(hull[-2],hull[-1])
    for i in range(2,n):
        while len(hull)>1 and cross_p(hull[-2],hull[-1],points[i])<=0:
            hull.pop()

            if len(ax.lines)>1:
                ax.lines[-1].remove()
                plt.pause(time)

        hull.append(points[i])
        draw_line(hull[-2],hull[-1])

    hull.append(points[0])
    draw_line(hull[-2],hull[-1])    
    return hull

points=[]
X=[20,2,16,7,16,19,18,16,5,17,6,12,3,15,14,10,20,14,11,8]
Y=[8,20,19,2,2,7,11,16,14,13,17,7,11,7,3,10,10,20,3,12]
j=0
for i in range(20):
    temp={}
    temp["x"]=X[i]
    temp["y"]=Y[i]
    points.append(temp)
    if q>temp["y"]:
        p,q=temp["x"],temp["y"]
        j=i
points[0],points[j]=points[j],points[0]
points[1:]=sorted(points[1:], 
                  key=lambda point:atan2(point["y"]-q,point["x"]-p))

plt.ion()
fig,ax = plt.subplots()
ax.set_xlim(0,23)
ax.set_ylim(0,23)
ax.scatter(X,Y, color="black",s=30)
for i in range(len(points)):
    x,y=points[i]["x"],points[i]["y"]
    plt.text(x,y,f'({x},{y})-{i+1}',fontsize=10,ha='left',va='top',font="Arial")
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Convex Hull-Graham Scan')
hull=Graham_scan(points)  
plt.ioff() 
plt.show()