def fibonacci(n):
    if n==0:
        return 0
    if n<=2:
        return 1
    if value[n]!=0:
        return value[n]
    value[n]=fibonacci(n-1)+fibonacci(n-2)
    return value[n]

n=int(input("Enter a value: "))
value=[0]*(n+1)
print(f"{n} no. fibonacci number is {fibonacci(n)}")