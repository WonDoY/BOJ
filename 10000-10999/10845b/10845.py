#10845 큐
#10828 스택

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
t=int(input())
for x in range(t):
    string = input().split()
    if(len(string)==2):
        queue.push(int(string[1]))
    else : # len 1 , pop size empty top
        if(string[0].find("pop")==0):
            print(queue.pop())
        elif(string[0].find("size")==0):
            print(queue.size())
        elif(string[0].find("empty")==0):
            print(queue.empty())
        elif(string[0].find("front")==0):
            print(queue.front())
        elif(string[0].find("back")==0):
            print(queue.back())
            
