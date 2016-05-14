#1212
T=(input())
res=''

for x in range(len(T)):
    temp=''
    binary=int(T[x])
    print('binary',binary)
    if(binary>=4):binary-=4;temp=temp+'1'
    else: temp=temp+'0'
    if(binary>=2):binary-=2;temp=temp+'1'
    else: temp=temp+'0'
    if(binary>=1):binary-=1;temp=temp+'1'
    else: temp=temp+'0'    
    res=res+temp    
    print('temp',temp,'T',T)
    
if(res.find('0')<1):
    res=res[res.find('0')+1:]
    if(res.find('0')<1):
        res=res[res.find('0')+1:]
print(res)

#출력초과
