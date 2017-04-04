lst = []
for i in range(1,100):
    for j in range(i):
        lst.append(i)
s = input().split()
res=0
for i in range(int(s[0])-1,int(s[1])):    
    res += lst[i]
print(res)
