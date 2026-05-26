
from datetime import datetime
count=0
memory={}
memory={
    0:0,
    1:1,
}
def fibonacci(n):
    global count
    count+=1
    if n<=1:
        return n
    elif n in memory:
        return memory[n]
    count+=1
    memory[n]=fibonacci(n-1)+fibonacci(n-2)
    return memory[n]

def itr_fibonacci(n):
    A=[0,1,-1]
    if n<=1:
        return A[n]
    for i in range(2,n+1):
        A[2]=A[0]+A[1]
        A[0]=A[1]
        A[1]=A[2]
    return A[2]
    
    

# arr=[]
# with open ("Fibonacci.txt",mode="r") as file:
#     file1=file.readlines()
#     for i in file1:
#         arr.append(int(i))
# for i in arr:
#     val=fibonacci(i)
#     print(f"steps for n={i} is {count}")
#     count=0
#     memory.clear()
t1=datetime.now()
print(itr_fibonacci(999))
print(fibonacci(999))
t2=datetime.now()
print(t2-t1)

#20577 last value for iterative