#10804
def reverseList(lst, a, b):
    n = 0
    l = int((b-a)/2)
    
##    print("====",a,b,"=====")
    for x in range(a-1 ,a+l):
        temp = lst[x]
        lst[x] = lst[b-n-1]
        lst[b-n-1] = temp
        n+=1
##    print(lst)
        
lst = [x for x in range(1,21)]
index = []

for i in range(10):
    a,b = (input().split())
    index.append([int(a),int(b)])

for i in index:
    reverseList(lst,i[0],i[1])

st = ""
for i in range(20):
    st += str(lst[i])+" "

print(st)
    

