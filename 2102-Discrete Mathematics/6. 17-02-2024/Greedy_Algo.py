coin=int(input("Amount of coin change-> "))
A=[25,10,5,1]
a=0
B=[]
count=0
while coin!=0:
    if A[a]<=coin:
        count+=1
        coin-=A[a]
        if coin==0:
            B.append((A[a],count))
    else:
        B.append((A[a],count))
        a+=1
        count=0
print(B)

