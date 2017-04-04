#1789
T=int(input())
for i in range(T):    
    T-=i
    if(T<i):T=i;break;
print(T)
