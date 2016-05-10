#2579

T=int(input())
lst=[0,0,0]
step1=[0,0,0]#
step2=[0,0,0]
for i in range(T):
    lst.append(int(input()))
    step1.append(max(step1[i+1],step2[i+1])+lst[i+3])
    step2.append(max(step1[i],step2[i])+lst[i+2]+lst[i+3])

print(max(step1[T+2],step2[T+2]))
    
