#1212
T=(input())
binary=int(T[0])
l=False
if(binary>=4):binary-=4;print('1',end='');l=True
if(binary>=2):binary-=2;print('1',end='')
elif(l): print('0',end='')
if(binary>=1):binary-=1;print('1',end='')
else: print('0',end='')

for x in range(1,len(T)):
    temp=''
    binary=int(T[x])
    if(binary>=4):binary-=4;print('1',end='')
    else: print('0',end='')
    if(binary>=2):binary-=2;print('1',end='')
    else: print('0',end='')
    if(binary>=1):binary-=1;print('1',end='')
    else: print('0',end='')
    
    
    



#출력초과
