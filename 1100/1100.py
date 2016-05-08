#1100
cnt = 0
for i in range(8):
    string = input()
    for j in range(8):
        if((i+j)%2==0 and string[j] == 'F'): cnt+=1
print(cnt)
