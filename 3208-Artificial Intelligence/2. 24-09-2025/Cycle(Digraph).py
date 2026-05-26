
graph={}
parent={}
visited={}

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
node=[]

queue=[]
queue.append(start)

while len(queue)!=0:
    top=queue[0]
    queue.pop(0)
    visited[top]=1
    for i in graph[top]:
        if i not in visited:
            queue.insert(0,i)
        if i in parent:
            node.append(i) # previous defined parent are stored in node.
        parent[i]=top
    

c="No Cycle"
if node:
    c="Cycle exists"
    p=""
    f=0
    for i in node:
        p=i
        path=""        
        while True:
            path+=p
            try:
                p=parent[p]
            except:
                c="No Cycle"
                path=""
                break
            if p==path[0]:
                path+=p
                f=1
                break
            if len(path)>len(graph):
                break
        if f:
            break
   
print(f'{c}\npath:{path[::-1]}')
    
