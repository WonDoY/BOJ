#2605

T=int(input())
s=input().split()
lst = []
for x in range(len(s)):
    lst.insert(len(lst)-int(s[x]),x+1)
for x in range(len(lst)):
    print(lst[x],end=" ")
