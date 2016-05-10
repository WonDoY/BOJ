#2576
res1=0
res2=100
for i in range(7):
    num=int(input())
    if(num%2==1):
        res1+=num;
        if(res2>num):res2=num
if(res2==100):print(-1)
else:
    print(res1);print(res2)
