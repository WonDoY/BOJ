#2577
res=1
for i in range(3):
    num=int(input()); res=res*num
lst = [0 for i in range(10)]

while res>0:
    
    lst[(res%10)]+=1
    res=int(res/10)

for i in range(10):
    print(lst[i])
