#6293

T=int(input())
string=input()
res=0
cursor=0
for i in range(T):
    
    if(string[i]=='e' and cursor==i):
        res+=1;i+=1;cursor+=1;
    elif(string[i-1]=='e' and cursor<i-1):
        res+=1;i+=1;cursor+=
