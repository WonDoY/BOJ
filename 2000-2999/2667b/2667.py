#2667단지번호붙이기
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
    
T=int(input())
matrix =[]

for x in range(T):
    temp=[]
    string=input()
##    print(string)
    for y in range(T):
##        print(y," " , string[y])
        temp.append(int(string[y]))
    matrix.append(temp)

visit = [[0 for x in range(T)] for y in range(T)]
q = Queue()
res=[]
for x in range(T):
    for y in range(T):
##        print("listin", x,y)
        cnt=0
        if(matrix[x][y]!=0 and visit[x][y]!=1):
            data=[x,y]
            q.push(data)
            visit[x][y]=1
            cnt+=1
##            print("~~~~~~~~~~~",x,y)
        while not q.empty():
            xp,yp = q.pop()
##            print(cnt)
##            print(xp,yp)
##            print(xp>0 and matrix[xp-1][yp]!=0 and visit[xp-1][yp]!=1)
            if(xp>=1 and matrix[xp-1][yp]!=0 and visit[xp-1][yp]!=1):
                
                visit[xp-1][yp]=1
                q.push([xp-1,yp])
                cnt+=1
                
##            print(xp<T-1 and matrix[xp+1][yp]!=0 and visit[xp+1][yp]!=1)
            if(xp<T-1 and matrix[xp+1][yp]!=0 and visit[xp+1][yp]!=1):
                visit[xp+1][yp]=1
                q.push([xp+1,yp])
                cnt+=1
##            print(yp>0 and matrix[xp][yp-1]!=0 and visit[xp][yp-1]!=1)
            if(yp>=1 and matrix[xp][yp-1]!=0 and visit[xp][yp-1]!=1):
                visit[xp][yp-1]=1
                q.push([xp,yp-1])
                cnt+=1
##            print(yp<T-1 and matrix[xp][yp+1]!=0 and visit[xp][yp+1]!=1)
            if(yp<T-1 and matrix[xp][yp+1]!=0 and visit[xp][yp+1]!=1):
                visit[xp][yp+1]=1
                q.push([xp,yp+1])
                cnt+=1

        if(cnt!=0):
##            print(cnt)
            res.append(cnt)

print(len(res))
res.sort()
for i in res:
    print(i)
            

