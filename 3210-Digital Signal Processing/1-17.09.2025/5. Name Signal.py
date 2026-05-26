import numpy as np
import matplotlib.pyplot as plt


name="MD. ASAD-AL-ADIL"
name=np.array([ord(x) for x in name])

markerline,stemlines,baseline=plt.stem(name)
plt.setp(markerline, color='black')
plt.setp(baseline, color='black')
plt.setp(stemlines, color='black')

plt.title("ASCII VALUE SIGNAL")
plt.xlabel("Index")
plt.ylabel("ASCII Value")
plt.grid(True)
plt.show()
