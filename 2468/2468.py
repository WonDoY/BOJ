#2468
class queue:
    lst = []
    
    def __init__(self):
        lst = []

    def put(self,x,y): # 맨앞에 넣음
        self.lst.insert(0,[x,y])        

    def get(self): # 끝에서 뽑아냄
        x,y = self.lst.pop()        
        return x,y

    def isEmpty(self):
        if(len(self.lst) != 0): return False
        return True

    def empty(self): # empty is the method of clearing list in Queue instance.
        self.lst = []
        
res = 0 
def BFS(size):
    Q = queue()
    global res
    global area
    
    for depth in range(0,101):
        MIN = 0
        safe = [] # 초기화
        for i in range(T+2):
            lst = []
            lst = [0 for x in range(T+2)]
            safe.append(lst)
        for i in range(1,size+1):
            
            for j in range(1,size+1):
                safe_true = False
                if(depth < area[i][j] and safe[i][j] == 0):
                    
                    safe_true = True

                    Q.put(i,j)
                    while not Q.isEmpty() :

                        safe[i][j] += 1
                        y,x = Q.get()

                        for row, col in [(y+1,x),(y,x+1),(y-1,x),(y,x-1)]:

                            if(depth < area[row][col] and safe[row][col] == 0):

                                Q.put(row,col)
                                safe[row][col] += 1

                if(safe_true):
                    MIN += 1
                safe_true = False
        if(res < MIN) : res = MIN
        if (MIN == 0): break
                
T = int(input())
area = []
for i in range(T+2):
    lst = []
    if(i!=0 and i!=T+1): string = input().split()
    for j in range(T+2):        
        if (i==0 or i==T+1 or j==0 or j==T+1): lst.append(0)
        else: lst.append(int(string[j-1]))
    area.append(lst)
BFS(T)
print(res)
    

