#2501

T=input().split();N=int(T[0]);K=int(T[1]);
lst=[]
for i in range(1,int(N/2)+1):
    if(N%i==0):  lst.append(i)
lst.append(N)
if(K>len(lst)):print(0)
else:print(lst[K-1])
