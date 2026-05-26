import heapq


graph={}
parent={}
distance={}

with open("graph.txt","r") as file: # storing the graph in nested dictionary
    f=file.readlines()
    for i in f:
        i=i.split(' ')
        if i[0] not in graph:
            graph[i[0]]={}
            distance[i[0]]=1e10
        graph[i[0]][i[1]]=int(i[2]) # edge is directed
        if i[1] not in graph:
            graph[i[1]]={}          # store the child also as key
            distance[i[1]]=1e10
file.close()
# print(graph)

start='S'#input("Start node: ")
goal='G'#input("Goal node: ")
path=""
cost=0

distance[start]=0
queue=[]
heapq.heappush(queue,(0,start))

while len(queue)!=0:
    top=heapq.heappop(queue)
    if top[1]==goal:
        break
    for i in graph[top[1]]:
        if distance[i]>(graph[top[1]][i]+distance[top[1]]): # if the distance is less than before then change the distance
            distance[i]=graph[top[1]][i]+distance[top[1]]
            parent[i]=top[1]
            heapq.heappush(queue,(distance[i],i))

while True:
    path+=goal
    next_path=parent[goal]
    cost+=graph[next_path][goal]
    goal=next_path
    if goal==start:
        path+=goal
        break

print(f'path:{path[::-1]}\ncost={cost}')