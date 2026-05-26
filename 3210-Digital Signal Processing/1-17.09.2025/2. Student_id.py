import numpy as np
import matplotlib.pyplot as plt

roll="2103064"
data=np.array([int(x) for x in roll])
print(f"Elements of data: {data}")
print(f"Summation of the data: {np.sum(data)}")
print(f"Mean of the data: {(np.mean(data)):.4}")
print(f"Variance of the data: {np.var(data):.4}")

sq_data=data**2
print(sq_data)

markerline,stemlines,baseline=plt.stem(data)

plt.setp(markerline, color='black')
plt.setp(baseline, color='black')
plt.setp(stemlines, color='black')
plt.xlabel("Index")
plt.ylabel("ID Digit")
plt.grid(True)
plt.show()