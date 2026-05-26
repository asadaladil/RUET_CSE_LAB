
graph={}
parent={}
visited=[]

def child_store(node):
    for i in graph[node]:
        if i not in visited:
            queue.insert(0,i)
            parent[i]=node

def goal_check():
    while len(queue)!=0:
        top=queue.pop(0)
        if top not in visited:
            visited.append(top)
        else:
            return top
        if top==goal:
            return top
    return 0
        

with open("graph2.txt","r") as file: # storing the graph in nested dictionary
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
if start==goal:
    path=goal
else:
    visited.append(start)
    child_store(start)
    while True:
        node=goal_check()
        if node==goal:
            break
        if node==0:
            queue=visited.copy()
            continue
        child_store(node)

while True:
    path+=goal
    next_path=parent[goal]
    cost+=graph[next_path][goal]
    goal=next_path
    if goal==start:
        path+=goal
        break

print(f'path:{path[::-1]}\ncost={cost}')    
