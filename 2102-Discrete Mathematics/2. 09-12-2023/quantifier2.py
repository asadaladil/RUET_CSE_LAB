# ∃x∀y P(x,y) , P(x,y): x-y<0
x=[]
y=[]

a=int(input("Total Number of value of x->"))
b=int(input("Total Number of value of y->"))

print("taking value of x")
x=list(map(int,input().split()))

print("taking value of y")
y=list(map(int,input().split()))
    
a=True
for i in x:
    a=True
    for j in y:
        m=bool(i-j<0)
        a= (a and m)
    if a:
        break

print(f"\nfor ∃x∀y P(x,y) , P(x,y): x-y<0 statement is {a}")



