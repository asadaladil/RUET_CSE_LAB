# ∀x∃y P(x,y) , P(x,y): x+y>0
x=[]
y=[]

a=int(input("Total Number of value of x->"))
b=int(input("Total Number of value of y->"))

print("taking value of x")
x=list(map(int,input().split()))

print("taking value of y")
y=list(map(int,input().split()))
    
b=True
for i in x:
    a=False
    for j in y:
        m=bool(i+j>0)
        a=m or a
    if not a:
        b=False
        break
    
print(f"\nfor ∀x∃y P(x,y) , P(x,y): x+y>0 statement is {b}")


