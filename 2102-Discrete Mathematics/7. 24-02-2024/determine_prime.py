import math
integer=[]
def is_prime(n):
    if n in integer:
        return True
    return False

def mersene(n):
    x=int(math.log2(n+1))
    return (is_prime(x) and 2**x==n+1)

def twin(n):
    return is_prime(n)

with open("input.txt","r") as file:
    a=file.readlines()
    for i in a:
        integer.append(int(i))
    file.close()

a=int(input("Write an Integer-> "))

if is_prime(a):
    print(f"{a} is a prime number\n")
    if mersene(a):
        print(f"{a} is a mersene prime number\n")
    else:
        print(f"{a} is not a mersene prime number\n")
    if(twin(a+2)):
        print(f"{a} has twin prime\n")
    else:
        print(f"{a} has not twin prime\n")
else:
    print(f"{a} is not a prime number\n")
