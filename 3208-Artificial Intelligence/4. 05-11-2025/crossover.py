
def single_point_crossover(selected): 
    n=len(selected)
    point=3
    selected=[i[0] for i in selected]
    pair=[]
    for i in range(int(n/2)):
        pair.append((i,n-i-1)) # 1-6, 2-5,3-4 pair making 
    
    offspring=[]
    for i in pair:
        p1=selected[i[0]]
        p2=selected[i[1]]
        
        o1=p1[0:point]+p2[point:]
        o2=p2[0:point]+p1[point:]
        offspring.append((o1,o2))
    
    return offspring