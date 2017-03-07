#2506

T = int(input())
s = input().split()
res = 0
cnt = 1
for x in range(len(s)):
    if(int(s[x]) == 1) :
        res += cnt
        cnt += 1
    else:
        cnt = 1
print(res)
