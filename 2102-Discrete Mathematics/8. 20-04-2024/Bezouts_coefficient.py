def quotient_gcd(a,b,q):
    if b==0: return a,q
    q.append(int(a/b))
    return quotient_gcd(b,a%b,q)

def Bezouts_coefficient(a,b):
    s=[1,0]
    t=[0,1] # Back Extended algorithm
    q=[] # q is used to store the quotient values
    _gcd,q=quotient_gcd(a,b,q)
    if 0 in q:
        q.remove(0)
    for i in range(2,len(q)+1):
        s.append(s[i-2]-q[i-2]*s[i-1])
        t.append(t[i-2]-q[i-2]*t[i-1])
    return s[-1],t[-1],_gcd