from datetime import datetime
class Sorting_Algorithm:
    def __init__(self) -> None:
        pass
    def Bubble_Sort(self,A):
        n=len(A)
        for i in range(n):
            flag=True
            for j in range(n-1):
                if A[j]>A[j+1]:
                    A[j],A[j+1]=A[j+1],A[j]
                    flag=False
            if flag:
                break

    def Insertion_sort(self,A):
        n=len(A)
        for i in range(1,n):
            value=A[i]; 
            j=i-1
            while (j>=0 and A[j]>value):
                A[j+1]=A[j] 
                j=j-1
            A[j+1]=value
    
    def Selection_Sort(self,A):
        n=len(A)
        for i in range(n):
            mn=i
            j=i+1
            while(j<n):
                if(A[j]<A[i]):
                    mn=j
                j+=1
            A[i],A[mn]=A[mn],A[i]
    

with open("./output/input.txt",mode="r") as file1:
    data = file1.readlines()
    val=[]
    for i in data:
        val.append(int(i))
    A=[]
    B=[1000,5000,10000,15000,20000]
    for i in range(0,5):
        temp=[]
        for j in range(0,B[i]):
            temp.append(val[j])
        A.append(temp)

    with open("./output/output.txt",mode="a") as file:
        sort=Sorting_Algorithm()
        for i in range(5):
            file.write(str(B[i])+": ")
            #file.write("Insertion Sort\n")
            # t1=datetime.now()
            # sort.Insertion_sort(A[i])
            # t2=datetime.now()
            # k=str(t2-t1)
            # file.write(k+"\n")
            # file.write("Bubble Sort\n")
            # t1=datetime.now()
            # sort.Bubble_Sort(A[i])
            # t2=datetime.now()
            # k=str(t2-t1)
            # file.write(k+"\n")
            # file.write("Selection Sort\n")
            t1=datetime.now()
            sort.Selection_Sort(A[i])
            t2=datetime.now()
            k=str(t2-t1)
            file.write(k+"\n")
        print("Done")


# ss=[10,9,8,7,6,5,4,3,2,1]
# sorted=Sorting_Algorithm()
# print(sorted.Insertion_sort(ss))

        