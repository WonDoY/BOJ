import time
#1644
#소수의연속합

T=int(input())
# 2 3 5 7
start=time.time()
prime=list()
for i in range(2,T+1):
    prime_true=True
    for x in range(len(prime)):
        if(i%prime[x]==0):
##            print(i,prime[x])
            prime_true=False
            break
    if(prime_true):
        prime.append(i)
if(prime[len(prime)-1]==T):res=1
else:res=0
for i in range(len(prime)):
    s=prime[i]
    for j in range(i+1,len(prime)):
        s+=prime[j]
        if(s==T):res+=1;break
        elif(s>T):break
    
print(res)
end=time.time()-start
##print(end)
    
# fail 1 : 시간초과 

