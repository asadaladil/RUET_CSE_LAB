
# Tournament selection
import random

def Tournament_selection(population_fitness):
    selected=[]
    cnt=0
    while cnt!=6:
        index1=random.randint(0,len(population_fitness)-1)
        index2=random.randint(0,len(population_fitness)-1)
        # selecting based on fitness value higher 
        if population_fitness[index1][1]>population_fitness[index2][1]:
            selected.append(population_fitness[index1])
            
        elif population_fitness[index1][1]<population_fitness[index2][1]:
            selected.append(population_fitness[index2])
            
        elif population_fitness[index1][1]!=0 or population_fitness[index2][1]!=0:
            i=random.choice([index1,index2])
            selected.append(population_fitness[i])
            
        else:
            continue
        cnt+=1
    
    return selected