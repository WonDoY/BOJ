##import time
#1644
#소수의연속합
####s=time.time()
##prime=list()
##for i in range(2,4000000):
##    prime_true=True
##    for x in range(len(prime)):
##        if(i%prime[x]==0):
####            print(i,prime[x])
##            prime_true=False
##            break
##    if(prime_true):
##        prime.append(i)
####print("input : ",end="")
####f=time.time()-s
####print(f)
##T=int(input())
### 2 3 5 7
####start=time.time()
##
####if(prime[len(prime)-1]==T):res=1
##res=0
##for i in range(len(prime)):
##    s=prime[i]
##    if(s==T):res+=1;break
##    for j in range(i+1,len(prime)):
##        s+=prime[j]
##        if(s==T):res+=1;break
##        elif(s>T):break
##    
##print(res)
####end=time.time()-start
####print(end)
##    
# fail 1 : 시간초과 
# fail 2 : 런타임에러
N=int(input())
n=int(N**0.5)+1
seive=[1]*(N+1)
if N==1:
    print(0)
    exit()
 
seiveList=[]
for i in range(2,N+1):
    if seive[i]==0:continue
    seiveList+=[i]
    for j in range(2*i,N+1,i):
        seive[j]=0
  
#print(len(seiveList))
i=-1
j=0
s=seiveList[0]
count=0
#print(seiveList)
seiveList+=[0]
while 1:
    if j==len(seiveList)-1:break
    #print(s,i,j)
    if s==N:
        count+=1
        i+=1
        s-=seiveList[i]
  
    elif s<N:
        j+=1
        s+=seiveList[j]
  
    elif s>N:
        i+=1
        s-=seiveList[i]
  
print(count)
