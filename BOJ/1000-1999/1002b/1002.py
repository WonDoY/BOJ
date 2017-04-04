def sol(x,y,r,X,Y,R):
    distance = pow(pow(abs(X-x),2) + pow(abs(Y-y),2),1/2)
    if(x==X and y==Y) :
        if(r==R):
            return -1
        return 0
    if(r > distance+R or R > distance+r): return 0
    elif(r == distance+R or R == distance+r) : return 1
    if (r+R) == distance :
        return 1
    elif (r+R) > distance :
        return 2
    elif (r+R) < distance :
        return 0

    
T = int(input())

for x in range(T):
    lst = input().split()
    x1 = int(lst[0]); y1 = int(lst[1]); r1 = int(lst[2]);
    x2 = int(lst[3]); y2 = int(lst[4]); r2 = int(lst[5]);
    res = sol(x1,y1,r1,x2,y2,r2)
    print(res)
    
