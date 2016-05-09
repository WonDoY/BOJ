#2156

step=[[0,0,0],[0,0,0],[0,0,0]]
res = 0
T=int(input())
for x in range(T):
    s=int(input())
    step[0].append(s)
    if(s==0):
        step[1].append(max(step[1][2+x],step[2][2+x]))
        step[2].append(max(step[1][2+x],step[2][2+x]))
    elif(x<=2):       
        step[1].append(max(max(step[1][:x+1]),max(step[2][:x+1]))+step[0][2+x]+step[0][3+x])
        step[2].append(max(max(step[1][:x+2]),max(step[2][:x+2]))+step[0][3+x])
    else:
        step[1].append(max(max(step[1][x-3:x+1]),max(step[2][:x+1]))+step[0][2+x]+step[0][3+x])
        step[2].append(max(max(step[1][x-3:x+2]),max(step[2][:x+2]))+step[0][3+x])
    if(res < step[1][3+x]): res = step[1][3+x]
    if(res < step[2][3+x]): res = step[2][3+x]
print(res)

#10 977 200 517 851 23 662 880 815 26 214
#6 1 1 0 0 1 1 
