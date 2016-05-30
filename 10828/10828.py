#10828 스택

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
t=int(input())
for x in range(t):
    string = input().split()
    if(len(string)==2):
        stack.push(int(string[1]))
    else : # len 1 , pop size empty top
        if(string[0].find("pop")==0):
            print(stack.pop())
        elif(string[0].find("size")==0):
            print(stack.size())
        elif(string[0].find("empty")==0):
            print(stack.empty())
        elif(string[0].find("top")==0):
            print(stack.top())
            
