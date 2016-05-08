#1712

s = input().split()
for x in range(3):
    s[x] = int(s[x])
if(s[1] >= s[2]):
    print(-1)
else :
    print(int(s[0]/(s[2]-s[1]))+1)
