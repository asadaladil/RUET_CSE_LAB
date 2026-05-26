import numpy as np
import matplotlib.pyplot as plt

image=np.random.randint(0,255,size=(28,28))
plt.imshow(image,cmap='gray')
plt.colorbar(label="Pixel Intensity")
plt.show()

# print(image)