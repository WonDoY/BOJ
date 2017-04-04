#3111
class Stack:
    lst = []
    def __init__(self):
        self.lst = []
    def push(self,s):
        self.lst.append(s)
    def pop(self):
        self.lst.pop()
    
A = input()
T = input()
stack=Stack()
x=0
res =''
while True:
    
    equal = True
    step = 0
    
    for i in range(len(A)): #search
        
        if(len(T)==x+i):
            equal = False
            break
        elif(T[x+i] != A[i]):            
            step += 1
            equal = False
            break        
        step+=1
    if(not equal):        
        for i in range(x,x+step):
            res += T[i]
        x+=step
    elif(equal):        
        x+=step
    
    if(x==len(T)):
        break
    

print(res)
        
    

