import heapq


graph={}
parent={}
distance={}
heuristic={}

with open("graph.txt","r") as file: # storing the graph in nested dictionary
    f=file.readlines()
    for i in f:
        i=i.split(' ')
        if i[0] not in graph:
            graph[i[0]]={}
            distance[i[0]]=1e10
        graph[i[0]][i[1]]=int(i[2])
        if i[1] not in graph:
            graph[i[1]]={}
            distance[i[1]]=1e10
file.close()
# print(graph)
with open("heuristic.txt","r") as file: # storing the graph in nested dictionary
    f=file.readlines()
    for i in f:
        i=i.split(' ')
        heuristic[i[0]]=int(i[1])
file.close()

# print(heuristic)

start='S'#input("Start node: ")
goal='G'#input("Goal node: ")
path=""
cost=0

distance[start]=0
queue=[]
heapq.heappush(queue,(heuristic[start],start))

while len(queue)!=0:
    top=heapq.heappop(queue)
    if top[1]==goal:
        break
    for i in graph[top[1]]:
        distance[i]=graph[top[1]][i]+distance[top[1]]
        parent[i]=top[1]
        heapq.heappush(queue,(heuristic[i],i))
    

while True:
    path+=goal
    next_path=parent[goal]
    cost+=graph[next_path][goal]
    goal=next_path
    if goal==start:
        path+=goal
        break

print(f'path:{path[::-1]}\ncost={cost}')