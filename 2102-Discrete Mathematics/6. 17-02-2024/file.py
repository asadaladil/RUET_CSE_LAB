# import matplotlib.pyplot as plt
# from scipy.interpolate import make_interp_spline
# import numpy as np

# # Original x and y data points
# x_values = np.array([100, 200, 250, 260, 270])
# y_values = np.array([10, 20, 30, 40, 60])

# # Generate more x values from the original range
# x_smooth = np.linspace(x_values.min(), x_values.max(), 300)

# # Generate a cubic B-spline interpolation function for the original x and y values
# spl = make_interp_spline(x_values, y_values, k=3)  # k is the degree of the spline

# # Use the interpolation function to create smooth y values
# y_smooth = spl(x_smooth)

# # Now we use matplotlib to plot the smooth values
# plt.plot(x_smooth, y_smooth)

# # You can also plot the original points for reference
# plt.scatter(x_values, y_values, color='red')

# # Adding titles and labels
# plt.title('Smoothed Curve')
# plt.xlabel('x values')
# plt.ylabel('y values')
import matplotlib.pyplot as plt
# First dataset
# Plot the first dataset with a red line
Size=[0,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]
Time1=[0,0.0999,0.2999,0.6,0.7,0.9001,1.1,1.55,2.1999,2.6010,2.9020]
Time2=[0,0.105,0.434235,0.948037,1.800259,2.646585,4.802048,8.310971,11.186535,14.267181,18.083052]
plt.plot(Size, Time1, 'r-', label='Quick Sort')

# Plot the second dataset with blue squares
plt.plot(Size, Time2, 'b-', label='Bubble Sort')

# Optionally, add a legend to distinguish the datasets
plt.legend()

# Add titles and labels
plt.title('Quick Sort vs Bubble Sort')
plt.xlabel('Total numbers')
plt.ylabel('Time')

# Show the combined graph
plt.show()
