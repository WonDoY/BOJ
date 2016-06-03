#4963
#2667단지번호붙이기+
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
    
w=1;h=1
while w!=0 and h!=0:
    w,h = map(int,input().split())
    if(w==0 and h==0):
        break;
    matrix =[]

    for x in range(h):
        temp=[]
        string=input().split()
    ##    print(string)
        for y in range(w):
    ##        print(y," " , string[y])
            temp.append(int(string[y]))
        matrix.append(temp)
    ## input

    visit = [[0 for x in range(w)] for y in range(h)]
    q = Queue()
    res=[]
    cnt=0
    for x in range(h):
        for y in range(w):
    ##        print("listin", x,y)
            
            if(matrix[x][y]!=0 and visit[x][y]!=1):
                data=[x,y]
                q.push(data)
                visit[x][y]=1
                cnt+=1
##                print(x,y)
    ##            print("~~~~~~~~~~~",x,y)
            while not q.empty():
                xp,yp = q.pop()
    ##            print(cnt)
    ##            print(xp,yp)
    ##            print(xp>0 and matrix[xp-1][yp]!=0 and visit[xp-1][yp]!=1)
                if(xp>=1 and matrix[xp-1][yp]!=0 and visit[xp-1][yp]!=1):
                    
                    visit[xp-1][yp]=1
                    q.push([xp-1,yp])
                if(xp>=1 and yp>=1 and matrix[xp-1][yp-1]!=0  and visit[xp-1][yp-1]!=1):
                    visit[xp-1][yp-1]=1
                    q.push([xp-1,yp-1])
                    
                if(xp>=1 and yp<w-1 and matrix[xp-1][yp+1]!=0  and visit[xp-1][yp+1]!=1):
                    visit[xp-1][yp+1]=1
                    q.push([xp-1,yp+1])
                if(xp<h-1 and yp>=1 and matrix[xp+1][yp-1]!=0  and visit[xp+1][yp-1]!=1):
                    visit[xp+1][yp-1]=1
                    q.push([xp+1,yp-1])
                if(xp<h-1 and yp<w-1 and matrix[xp+1][yp+1]!=0 and visit[xp+1][yp+1]!=1):
                    visit[xp+1][yp+1]=1
                    q.push([xp+1,yp+1])



                    
    ##            print(xp<T-1 and matrix[xp+1][yp]!=0 and visit[xp+1][yp]!=1)
                if(xp<h-1 and matrix[xp+1][yp]!=0 and visit[xp+1][yp]!=1):
                    visit[xp+1][yp]=1
                    q.push([xp+1,yp])
                    
    ##            print(yp>0 and matrix[xp][yp-1]!=0 and visit[xp][yp-1]!=1)
                if(yp>=1 and matrix[xp][yp-1]!=0 and visit[xp][yp-1]!=1):
                    visit[xp][yp-1]=1
                    q.push([xp,yp-1])
                    
    ##            print(yp<T-1 and matrix[xp][yp+1]!=0 and visit[xp][yp+1]!=1)
                if(yp<w-1 and matrix[xp][yp+1]!=0 and visit[xp][yp+1]!=1):
                    visit[xp][yp+1]=1
                    q.push([xp,yp+1])
                    



    print(cnt)
                

