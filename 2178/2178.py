#2178
class Stack:
    lst = []
    index = -1
    def __init__(self,x,y):
        self.lst = [[x,y]]
    def push(self,xdata,ydata):
        self.lst.append([xdata,ydata])
    def pop(self):        
        a,b = self.lst.pop()
        return a,b
    
    
##def dfs(lst,sx,sy,fx,fy):
##    stack = Stack(sx,sy)
##    lst[sx][sy] += 1
##    x,y = sx,sy
##    while (fx != x or fy !=y):
##        
##        if(lst[x+1][y] == 1) :
##            lst[x+1][y] += 1
##            x += 1; stack.push(x,y)
##        elif(lst[x-1][y] == 1) :
##            lst[x-1][y] += 1
##            x -= 1; stack.push(x,y)
##        elif(lst[x][y+1] == 1) :
##            lst[x][y+1] += 1
##            y += 1; stack.push(x,y)        
##        elif(lst[x][y-1]== 1) :
##            lst[x][y-1] += 1
##            y -= 1; stack.push(x,y)
##        else :
##            x,y = stack.pop()
##            lst[x][y] += 1
##            if(lst[x+1][y] == 1 or lst[x][y+1] == 1 or lst[x-1][y] == 1 or lst[x][y-1] == 1 ):
##                stack.push(x,y)
####        print("sol... / ",x,y,len(stack.lst))
####        for i in range(max(sx+2,fx+2)):
####            for j in range(max(sy+2,fy+2)):
####                print(lst[i][j],end=" ")
####            print()
####    print("RESULT :",len(stack.lst),"\n\n\n\n\n")
##    return len(stack.lst)
##            
##            
##        
##
##maze = []
##m,n = input().split()
##m = int(m)
##n = int(n)
##for i in range(m+2):
##    
##    if(i!=0 and i!=m+1):
##        string = input()
##    slst = []
##    
##    for j in range(n+2):
##        
####        print(i,j)
####        print(maze)
####        print(slst)
##        if(i==0 or i == m+1): slst += [0]
##        elif(j==0 or j == n+1): slst += [0]
##        else :  slst += [int(string[j-1])]
##    maze.append(slst)
##visit = []
##
##for i in range(len(maze)):
##    slt = []
##    for j in range(len(maze[0])):
##        slt.append(maze[i][j])
##    visit.append(False)
##
##
##a= dfs(maze,1,1,m,n)
##
##print(min(a,b))

##def DFS(lst, x, y, fx, fy, l):
##    global mmm
##    if(x == fx and y == fy):
##        if(mmm > l): mmm = l
##        return mmm
####    for i in range(fx+2):
####            for j in range(fy+2):
####                print(lst[i][j],end=" ")
####            print()
####    print(x,y)
####    print()
##    lst[y][x] = 0
##    
##    if(y > 1 and maze[y-1][x] != 0):
##        DFS(lst,x,y-1, fx, fy,l+1)
##    if(y < fy and maze[y+1][x] != 0):
##        DFS(lst,x,y+1,fx, fy,l+1)
##    if(x > 1 and maze[y][x-1] != 0):
##        DFS(lst,x-1,y,fx, fy,l+1)
##    if(x < fx and maze[y][x+1] != 0):
##        DFS(lst,x+1,y,fx, fy,l+1)
##    lst[y][x] = 1
##    
##
##
##
##maze = []
##m,n = input().split()
##m = int(m)
##n = int(n)
##mmm = m*n
##for i in range(m+2):
##    
##    if(i!=0 and i!=m+1):
##        string = input()
##    slst = []
##    
##    for j in range(n+2):
##        
####        print(i,j)
####        print(maze)
####        print(slst)
##        if(i==0 or i == m+1): slst += [0]
##        elif(j==0 or j == n+1): slst += [0]
##        else :  slst += [int(string[j-1])]
##    maze.append(slst)
##
##DFS(maze,1,1,m,n,1)
##print(mmm)

##maze = []
##def DFS(x, y, fx, fy, l):
##    global mmm
##    global maze
##    if(x == fy and y == fx):
##        if(mmm > l): mmm = l
##        return mmm
##    
##    maze[y][x] = 0
##    if(y >= 1 and maze[y-1][x] != 0):
##        DFS(x,y-1, fx, fy,l+1)
##    if(y <= fy+1 and maze[y+1][x] != 0):
##        DFS(x,y+1,fx, fy,l+1)
##    if(x >= 1 and maze[y][x-1] != 0):
##        DFS(x-1,y,fx, fy,l+1)
##    if(x <= fx+1 and maze[y][x+1] != 0):
##        DFS(x+1,y,fx, fy,l+1)
##    maze[y][x] = 1
##
##m,n = input().split()
##m = int(m)
##n = int(n)
##mmm = m*n
##for i in range(m+2):
##    
##    if(i!=0 and i!=m+1):
##        string = input()
##    slst = []
##    
##    for j in range(n+2):
##        if(i==0 or i == m+1): slst += [0]
##        elif(j==0 or j == n+1): slst += [0]
##        else :  slst += [int(string[j-1])]
##    maze.append(slst)
##
##DFS(1,1,m,n,1)
##print(mmm)

maze = []
def DFS( srow, scol, frow, fcol ,d):
    global res
    if( srow == frow and scol == fcol) :
        if(d < res) : res = d
        return

##    for i in range(frow+2):
##        for j in range(fcol+2):
##            print(maze[i][j],end="")
##        print()
##    print(res,"\n\n\n")
        

    maze[srow][scol] = 0
    if(srow > 0 and maze[srow-1][scol] != 0) :
        DFS(srow-1, scol, frow, fcol, d+1)
    if(srow < frow+1 and maze[srow+1][scol] != 0):
        DFS(srow+1, scol, frow, fcol, d+1)
    if(scol > 0 and maze[srow][scol-1] != 0) :
        DFS(srow,scol-1, frow, fcol, d+1)
    if(scol < fcol+1 and maze[srow][scol+1] != 0) :
        DFS(srow,scol+1, frow, fcol, d+1)
    maze[srow][scol] = 1
        

lst = input().split()
row = int(lst[0])
col = int(lst[1])
res = row*col
for i in range(row+2):
    lst = []
    if(i!=0 and i!=row+1): string = input()
    for j in range(col+2):
        if (i==0 or i==row+1 or j==0 or j==col+1): lst.append(0)
        else: lst.append(string[j-1])
    maze.append(lst)

DFS(1,1,row,col,1)
print(res)

        
        




