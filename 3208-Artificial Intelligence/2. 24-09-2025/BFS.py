
graph={}
parent={}

with open("graph.txt","r") as file: # storing the graph in nested dictionary
    f=file.readlines()
    for i in f:
        i=i.split(' ')
        if i[0] not in graph:
            graph[i[0]]={}
        graph[i[0]][i[1]]=int(i[2])
        if i[1] not in graph:
            graph[i[1]]={}
file.close()
# print(graph)

start='S'#input("Start node: ")
goal='G'#input("Goal node: ")
path=""
cost=0

queue=[]
queue.append(start)

while len(queue)!=0:
    top=queue[0]
    queue.pop(0)
    f=0
    for i in graph[top]:
        if i not in parent: # if a child got parent, no parent update
            queue.append(i)
            parent[i[0]]=top
        if top==goal:
            f=1
            break
    if f:
        break
    
    
while True:
    path+=goal
    next_path=parent[goal]
    cost+=graph[next_path][goal]
    goal=next_path
    if goal==start:
        path+=goal
        break

print(f'path:{path[::-1]}\ncost={cost}')
    
