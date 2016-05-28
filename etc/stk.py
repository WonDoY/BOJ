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
