#1463 1로 만들기


T= int(input())
cnt = 0

comp3 = [T]
comp2 = [T]
comp1 = [T]

while T!=1:
    min3=min2=min1=10000000
    #prev 3,2,1 -> after 3
    if(comp3[cnt]%3==0):
        min3=int(comp3[cnt]/3)
    if(comp2[cnt]%3==0):
        temp=int(comp2[cnt]/3)
        if(temp<min3): min3=temp
    if(comp1[cnt]%3==0):
        temp=int(comp1[cnt]/3)
        if(temp<min3): min3=temp

    #prev3,2,1-> after 2
    if(comp3[cnt]%2==0):
        min2=int(comp3[cnt]/2)
    if(comp2[cnt]%2==0):
        temp=int(comp2[cnt]/2)
        if(temp<min2): min2=temp
    if(comp1[cnt]%2==0):
        temp=int(comp1[cnt]/2)
        if(temp<min2): min2=temp

    #prev3,2,1 -> after 1
    comp1.append(min(comp3[cnt],comp2[cnt],comp1[cnt])-1)

    #append 
    comp2.append(min2)
    comp3.append(min3)


    cnt+=1
    T=min(comp3[cnt],comp2[cnt],comp1[cnt])
    
##while T!=1:
##    if(T%3==0) :
##        print(T,"3")
##        T=int(T/3)
##    elif(T%2==0) :
##        print(T,"2")
##        T=int(T/2)
##    else:
##        print(T,"1")
##        T-=1
##    cnt+=1

print(cnt)
