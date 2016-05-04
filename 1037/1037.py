n = int(input())
cnt = 0

String = input()
String = String.split(' ')
L = list()
while(cnt < n):
    L.append(int(String[cnt]))
    cnt += 1    
##L.sort()
res = max(L) * min(L)
print(res)


##num=int(input())
##data=input().split()
##data=[int(i) for i in data]
##print(min(data)*max(data))
