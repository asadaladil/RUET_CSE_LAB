n=int(input("Enter the value: "))
print(n,end=' ')
while n!=1:
    if n%2==0:
        n/=2
        print(int(n),end=' ')
    else:
        n*=3
        n+=1
        print(int(n),end=' ')
print("\n")