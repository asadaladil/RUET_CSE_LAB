import numpy as np
import matplotlib.pyplot as plt


A=3
f=2
t=np.linspace(1,-1,1000)
x=A*np.sin(2*np.pi*f*t)
# print(type(t))
plt.plot(t,x)
# plt.stem(t,x)
plt.grid(True)
plt.style.use('ggplot')
a=np.random.seed(11)
# print(a)
# plt.hist(np.random.randn(1000))
# plt.show()

a=np.array([6,5,4,3])

print(np.sort(a))