#1932

T = int(input())
lst = [[0]]
for i in range(T):
    test = input().split()
    for x in range(int(len(test))):
        test[x] = int(test[x])
    dp = [0 for i in range(len(test)) ]

    for x in range(int(len(test))):
        if(x==0):
            dp[x] += lst[i][0] + test[x]
        elif(x==len(test)-1):
            dp[x] += lst[i][len(lst[i])-1] + test[x]
        else :
            dp[x] += max(lst[i][x-1],lst[i][x]) + test[x]
    lst.append(dp)
print(max(lst[T]))

    
