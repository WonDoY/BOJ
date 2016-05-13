#2530

T=input().split()
t=int(input())
h=(int(T[0])+int(t/3600))%24
t-=int(t/3600)*3600
m=(int(T[1])+int(t/60))
t=t%60
s=(int(T[2])+int(t))
if(s/60>=1):
    m+=1;s=s%60
if(m/60>=1):
    m=m%60;h=(h+1)%24
print(h,m,s)
#꼼꼼히좀생각하자
