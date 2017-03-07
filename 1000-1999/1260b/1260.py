#1260 DFS BFS
class Queue:
    data=[]

    def __init__(self):
        self.data=[]

    def push(self, x):
        self.data.insert(0,x)

    def pop(self):
        if(self.empty()==1):
            return -1
        return self.data.pop()

    def size(self):
        return len(self.data)

    def empty(self):
        if(len(self.data)!=0):return 0
        return 1

    def front(self):
        if(self.empty()==1):
            return -1
        return self.data[len(self.data)-1]

    def back(self):
        if(self.empty()==1):
            return -1
        return self.data[0]
class Stack:
    data=[]

    def __init__(self):
        self.data=[]

    def push(self, x):
        self.data.append(x)

    def pop(self):
        if(self.empty()==1):
            return -1
        return self.data.pop()

    def size(self):
        return len(self.data)

    def empty(self):
        if(len(self.data)!=0):return 0
        return 1

    def top(self):
        if(self.empty()==1):
            return -1
        return self.data[len(self.data)-1]
stack=Stack()
queue=Queue()

N,M,V=map(int,input().split())
##print(N,M,V)

l=[[] for x in range(N)]
l.insert(0,0)





for x in range(M):
    s,f=map(int,input().split())
    l[s].append(f)
    l[f].append(s)

##while True:
# DFS
visit=[0 for x in range(N+1)]
node = V
stack.push(node)
print(node,end=" ")
visit[node]=1
cnt=1
while (cnt!=N): # 출력횟수를 세기로..
    
    turn = True # 돌아와야함.
    for x in range(len(l[node])):
        if(visit[l[node][x]]==0):
            stack.push(l[node][x])
##            print("node","[",node,"]","[",x,"]",l[node][x], end=" ")
            print(l[node][x],end=" ")
            visit[l[node][x]]=1
            cnt+=1
            turn = False
            node = l[node][x]
            break
    if(turn):
        node=stack.pop()
print()
    
    

# BFS
visit=[0 for x in range(N+1)]
node = V
queue.push(node)

while queue.empty()!=1:    

    p=queue.pop()        
    if(visit[p]!=1):
        print(p,end=" ")
    if(visit[p]==0):
##        print("[",node,"]")
        visit[p]=1
        for x in range(len(l[p])):
            queue.push(l[p][x])
##    print("\np /",p," / ",queue.data)
    
print()
    
