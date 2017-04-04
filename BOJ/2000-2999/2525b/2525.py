#2525

Time=input().split()
Hour=int(Time[0])
Minu=int(Time[1])
Cons=int(input())
##if(len(Cons)!=1):Hour+=int(Cons[0]);Minu+=int(Cons[1]);
##else:Minu+=int(Cons[0])
##if(Minu>=60):Hour+=1;Minu=Minu%60
Hour+=int(Cons/60)
Minu+=Cons%60
if(Minu>=60):Minu=Minu%60;Hour+=1
Hour=Hour%24

print(Hour,Minu)

#문제 잘읽자 분단위임
