#1978 소수찾기

def isP(n):
    divisors=[]
    for i in range(1,n + 1) :
        if n % i == 0 :
            divisors = divisors + [i]
            if(len(divisors) >= 3):
                break
##    print (divisors)
    if len(divisors) == 2:
##        print ('Prime Number')
        return True
    else :
##        print ('Is not prime Number')
        return False
    
t=int(input())
lst=[int(x) for x in input().split()]
cnt = 0
for x in lst:
    if(isP(x)):
        cnt+=1

print(cnt)
