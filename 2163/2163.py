#2163

size=input().split()
for i in range(2):
    size[i]=int(size[i])
res = 0
res+= size[0]-1
res+= (size[0])*(size[1]-1)
print(res)

#어떻게 자르던 똑같음 큰쪽으로 자르던 작은쪽으로 자르던
