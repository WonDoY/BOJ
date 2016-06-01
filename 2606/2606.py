#2606 바이러스
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
queue=Queue()

N = int(input()) # 컴 대수
M = int(input()) # rule 갯수
l = [[] for x in range(N+1)]
visit = [0 for x in range(N+1)]

for x in range(M):
    start,finish = map(int, input().split())
    
    l[start].append(finish)
    l[finish].append(start)

queue.push(1)
count=0
while queue.empty()!=1:
    p = queue.pop()
##    print(p,end=" ")
    if(visit[p]!=1):
        visit[p]=1
        count+=1
##        print(visit)
        for x in range(len(l[p])):
            queue.push(l[p][x])
    
    
        
print(count-1)
    
    

