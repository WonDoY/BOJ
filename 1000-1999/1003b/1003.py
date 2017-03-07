# 1003 

def fibo(n) :
    fibonacci = [[1,0],[0,1]]
    
    cnt = 2
    while cnt <= n :
        fibon = [0,0]
        for i in range(0,2) :
            fibon[i] = fibonacci[cnt-1][i]+fibonacci[cnt-2][i]
        fibonacci.append(fibon)
        cnt += 1
    print(fibonacci[n][0],fibonacci[n][1])

for i in range(int(input()) ):
    fibo(int(input()))
        
        
