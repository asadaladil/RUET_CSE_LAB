import numpy as np
import matplotlib.pyplot as plt

x=np.array([x for x in range(11)])
y1=x
y2=x**2
y3=2**x
plt.title("Comparison between y=x,y=x^2,y=2^x")
plt.xlabel("X Values")
plt.ylabel("Y Values")
plt.plot(x,y1)
plt.plot(x,y2)
plt.plot(x,y3)
plt.ylim(0,50)
plt.show()