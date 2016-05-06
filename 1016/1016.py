lst = input().split()
m = int(lst[0])
M = int(lst[1])
res = M-m+1
cnt = 2
notprime = set([])
##print(res,cnt)
while cnt*cnt <= M:
    
    
    for x in range(int(m/pow(cnt,2)),M):
        if(cnt*cnt*x > M):
            break
        elif(cnt*cnt*x >= m):
            if(len(notprime&{cnt*cnt*x}) == 0):
                notprime.add(cnt*cnt*x)
        
        
##        print(res,cnt, "->",cnt*cnt)
    cnt += 1    

print(res-len(notprime))
