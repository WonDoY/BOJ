#2475
T=input().split()
res=0
for i in range(5):
    T[i]=int(T[i])
    res+=pow(T[i],2)
print(res%10)
