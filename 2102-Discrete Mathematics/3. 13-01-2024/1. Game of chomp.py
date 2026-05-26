import random as rm
print("Which side you want to take? Player 1 or Player 2\nPlayer",end=' ')
x=int(input())
n=20
if x==1:
    y=False
    a=2
else:
    y=True
    a=1
while True:
    if y is True:
        if n<=4:
            m=n
        else:
            m=rm.randint(1,4)
        n-=m
        print(f"Player {a} takes {m} balls. {n} balls are left")
        y=False
        if n==0:
            print(f"Player {a} is win")
            break
    else:
        ball=0
        while ball>4 or ball<=0:
            ball=int(input("Enter your choice: "))
        n-=ball
        print(f"Player {x} takes {ball} balls. {n} balls are left")
        y=True
        if n==0:
            print(f"Player {x} is win")
            break