#1158 조세퍼스 문제
# 1~N명 원 둘러 앉음.
# 양의 정수 M (<=N)
# 원에서 제거 되는 순서를 출력

def Jose(N,M):
    people=[x for x in range(1,N+1)]
    cnt=-1
    res=[]
    while True:
        if(len(people)==1):
            res.append(people[0]);break
        for i in range(M): # 시간초과떴으면 이부분 cnt=(cnt+M)%len(people)로 수정..
            cnt=(cnt+1)%len(people)
        
        res.append(people[cnt])
        people.remove(people[cnt])        
        cnt-=1

    return res
        
N,M=input().split()
N,M=int(N),int(M)
result=Jose(N,M)
print("<",end="")
for x in range(N):
    if(x==N-1):
        print(str(result[x]),end="");break
    print(str(result[x])+", ",end="")
print(">")
          
