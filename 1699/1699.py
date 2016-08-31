#1699
T=int(input())
lst=[0,1,2]
num=[1,4,9,16]
opr=1
for i in range(3,T+1):    
    if(i**0.5-int(i**0.5)==0):opr=i;lst.append(1);num.append(i);continue
    test=i    
    res=0
    test-=opr
    res+=lst[opr]
    index=test
    print(opr,end=" ")
    while(test>0):
        try:
            if(num.index(test)):
                
        except:
        print(index,end=" ")
        test-=index
        res+=lst[index]
        index=test
        
    lst.append(res)
    print()
print(lst[T])
#욕심쟁이
