#2455

res=0
d=0
for i in range(4):
    st=input().split()
    for j in range(2):
        st[j]=int(st[j])
    d+=st[1]-st[0]
    if(res<d):res=d
print(res)
#2455문제랑 똑같음 중등부-초등부
