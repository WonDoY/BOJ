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
    
    
def dfs(lst,sx,sy,fx,fy):
    stack = Stack(sx,sy)
    lst[sx][sy] += 1
    x,y = sx,sy
    while (fx != x or fy !=y):
        
        if(lst[x+1][y] == 1) :
            lst[x+1][y] += 1
            x += 1; stack.push(x,y)
        elif(lst[x-1][y] == 1) :
            lst[x-1][y] += 1
            x -= 1; stack.push(x,y)
        elif(lst[x][y+1] == 1) :
            lst[x][y+1] += 1
            y += 1; stack.push(x,y)        
        elif(lst[x][y-1]== 1) :
            lst[x][y-1] += 1
            y -= 1; stack.push(x,y)
        else :
            x,y = stack.pop()
            lst[x][y] += 1
            if(lst[x+1][y] == 1 or lst[x][y+1] == 1 or lst[x-1][y] == 1 or lst[x][y-1] == 1 ):
                stack.push(x,y)
        print("sol... / ",x,y,len(stack.lst))
        for i in range(max(sx+2,fx+2)):
            for j in range(max(sy+2,fy+2)):
                print(lst[i][j],end=" ")
            print()
    print("RESULT :",len(stack.lst),"\n\n\n\n\n")
    return len(stack.lst)
            
        
            
        

maze = []
m,n = input().split()
m = int(m)
n = int(n)
for i in range(m+2):
    
    if(i!=0 and i!=m+1):
        string = input()
    slst = []
    
    for j in range(n+2):
        
##        print(i,j)
##        print(maze)
##        print(slst)
        if(i==0 or i == m+1): slst += [0]
        elif(j==0 or j == n+1): slst += [0]
        else :  slst += [int(string[j-1])]
    maze.append(slst)
maze_2 = []

for i in range(len(maze)):
    slt = []
    for j in range(len(maze[0])):
        slt.append(maze[i][j])
    maze_2.append(slt)


a= dfs(maze,1,1,m,n)
b= dfs(maze_2,m,n,1,1)
print(min(a,b))
