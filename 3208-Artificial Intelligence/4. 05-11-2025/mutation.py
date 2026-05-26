import random

def bit_flipping_mutation(offspring1,offspring2):
    # print(offspring)
    bit=random.randint(-1,4)
    if bit>=0:
        b=offspring1
        b=list(b)
        if b[bit]=='1': b[bit]='0'
        else: b[bit]='1'
        offspring1="".join(b)
    
    bit=random.randint(-1,4)
    if bit>=0:
        b=offspring2
        b=list(b)
        if b[bit]=='1': b[bit]='0'
        else: b[bit]='1'
        offspring2="".join(b)
    
    return (offspring1,offspring2)


# print(bit_flipping_mutation(list(('10001','10000'))))