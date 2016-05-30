#2749 3 : 메모리 초과
def fibo(n):
    flist=[0,1]
    cnt=2
    while(cnt<=n):
        flist.append(flist[cnt-1]+flist[cnt-2])
        cnt+=1
    print(flist[n]%1000000)
fibo(int(input()))
    
