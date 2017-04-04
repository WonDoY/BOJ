#include<cstdio>
int a[4];
int main(){
	for(int i = 0 ; i < 4 ; i++) scanf("%d",&a[i]);
	int t,st,tmp1,tmp2;
	for(int i = 0 ; i < 3 ; i++){
		st=0;
		scanf("%d",&t);
		tmp1=tmp2=t;
		while(1){			
			if(tmp1>0){
				tmp1-=a[0];
				st++;
			}
			if(tmp2>0){
				tmp2-=a[2];
				st++;
			}
			if(tmp1>0){
				tmp1-=a[1];
				st--;
			}
			if(tmp2>0){
				tmp2-=a[3];
				st--;
			}
			if((tmp1<=0)&(tmp2<=0)) break;
		}
		switch(st){
		case 0:
			printf("none\n"); break;
		case 1:
			printf("one\n");break;
		case 2:
			printf("both\n");break;
		}
	}
	
	return 0;
}