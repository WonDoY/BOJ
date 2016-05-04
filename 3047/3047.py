data = input().split()
data = [int(i) for i in data]
data.sort()

string = input()


for i in range(0,3):
    if string[i] == 'A' :  print(data[0])
    elif string[i] == 'B' : print(data[1])
    elif string[i] == 'C' : print(data[2])

    
    
    
