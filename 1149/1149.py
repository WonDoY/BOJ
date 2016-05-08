#1149 dp
red = [0,0]
grn = [0,0]
blu = [0,0]
T = int(input())
for i in range(T):
    lst = input().split()
    for x in range(3):
        lst[x] = int(lst[x])
        if(x == 0):# red
            red.append(min(grn[2*i:2*(i+1)])+lst[x])
            red.append(min(blu[2*i:2*(i+1)])+lst[x])                        
        elif(x == 1):# grn         
            grn.append(min(red[2*i:2*(i+1)])+lst[x])
            grn.append(min(blu[2*i:2*(i+1)])+lst[x])
                   
        elif(x == 2):# blu
            blu.append(min(grn[2*i:2*(i+1)])+lst[x])
            blu.append(min(red[2*i:2*(i+1)])+lst[x])
           
    
    
print(min(min(red[2*T:]),min(grn[2*T:]),min(blu[2*T:])))
