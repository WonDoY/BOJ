#2420
x = input().split()
res = 0
for i in range(len(x)):
    x[i]= int(x[i])
res = x[0] - x[1]
if(res<0):res=-res
print(res)

#문제잘읽자..
