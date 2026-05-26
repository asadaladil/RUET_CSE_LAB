a=int(input("\nTotal member of Set A-> "))
b=int(input("Total member of Set B-> "))
print("Taking Set A")
A=list(map(int,input().split()))
A=set(A)
print("Taking Set B")
B=list(map(int,input().split()))
B=set(B)
C=[]
on=True
for i in A:
    F=i**3+i**2-i-1
    if F not in B:
        print(f"It is not a Function As there is no element in co-domain for domain {i}\n")
        on=False
        break
    C.append(F)
if on:
    C=set(C)
    print("One-to-One-> Yes") if len(A)==len(C) else print("One-to-One-> No")
    print("Onto-> Yes") if B==C else print("Onto-> No")
