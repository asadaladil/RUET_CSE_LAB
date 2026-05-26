L1=int(input("Lower bound of first summation-> "))
U1=int(input("Upper bound of first summation-> "))
L2=int(input("Lower bound of second summation-> "))
U2=int(input("Upper bound of second summation-> "))
sum=0
for  i in range(L1, U1+1):
    for j in range(L2, U2+1):
        sum+=(5*i*2*j)
print(sum)