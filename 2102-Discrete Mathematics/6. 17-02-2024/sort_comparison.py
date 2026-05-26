from datetime import datetime
import matplotlib.pyplot as plt
from Sorting_Algorithm import Sorting_Algorithm
sort=Sorting_Algorithm()
Size=[]
Time1=[]
Time2=[]
with open("Input.txt",mode="r") as file1:
    num=file1.readlines()
with open("Output.txt",mode="a") as file:
    file.write("FOR Quicksort       FOR BUBBLE SORT\n")
    B=[]
    a=0
    for r in num:
        if r!='\n':
            B.append(int(r.strip('\n')))
            a+=1
        else:
            A=B
            start_time=datetime.now()
            x=sort.Quick_Sort(A)
            finish_time=datetime.now()
            k=str(finish_time-start_time)
            file.write(k+'             ')
            k=k.replace(':','0')
            Time1.append(float(k)*100)
            start_time=datetime.now()
            y=sort.Bubble_Sort(A)
            finish_time=datetime.now()
            k=str(finish_time-start_time)
            file.write(k+'\n')
            k=k.replace(':','0')
            Time2.append(float(k))
            B.clear()
            Size.append(a-1)
            a=0


# First dataset
# Plot the first dataset with a red line
plt.plot(Size, Time1, 'r-', label='Quick Sort')

# Plot the second dataset with blue squares
plt.plot(Size, Time2, 'b-', label='Bubble Sort')

# # Optionally, add a legend to distinguish the datasets
plt.legend()

# Add titles and labels
plt.title('Two Datasets on a Single Graph')
plt.xlabel('X values')
plt.ylabel('Y values')

# Show the combined graph
plt.show()

