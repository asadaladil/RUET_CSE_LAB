
graph={}
parent={}
visited={}

with open("graph.txt","r") as file: # storing the graph in nested dictionary
    f=file.readlines()
    for i in f:
        i=i.split(' ')
        if i[0] not in graph:
            graph[i[0]]={}
        if i[1] not in graph:
            graph[i[1]]={}
        graph[i[0]][i[1]]=int(i[2])
        graph[i[1]][i[0]]=int(i[2])
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
        if i in visited and i not in node: # already visited but not in node
            node.append(i)
        if i not in parent:
            parent[i]=top
            continue
        if parent[top]!=i: # parent to child and child to parent not possible
            parent[i]=top
    

c="No Cycle"
if node:
    c="Cycle exists"
    p=""
    for i in node:
        p=i
        path=""  
        f=0      
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
                f=0
                break
        if f:
            break


print(f'{c}\npath:{path[::-1]}')
            
   

    
