#2747 피보나치 수

def fibo(n):
    flist=[0,1]
    cnt=2
    while(cnt<=n):
        flist.append(flist[cnt-1]+flist[cnt-2])
        cnt+=1
    print(flist[n])
fibo(int(input()))
    
