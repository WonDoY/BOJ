#2562

res=0
x,y=0,0
for i in range(9):
    string = input().split()
    for j in range(9):
        string[j]=int(string[j])
        if(res<string[j]):res=string[j];x,y=i,j
print(res)
print(x+1,y+1)
    
#행열+1 이유로 틀림
#8x8로 생각했네...
