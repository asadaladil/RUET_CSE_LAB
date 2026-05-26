
def _gcd(a,b):
    if b==0:
        return a
    return _gcd(b,a%b)

a,b=map(int,input("Write 2 integers-> ").split(" "))
print(f"\nThe GCD of {a} and {b} is {_gcd(a,b)}")