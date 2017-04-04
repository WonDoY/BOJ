#include<cstdio>

int main(){
	int x,b,cnt=1;
	scanf("%d",&x);
	b = x;
	while(x){
		x=x/10;
		if( (b%cnt) >= cnt/2 && cnt!=1){
		b+=cnt-b%cnt;
		}else{
		b-=(b%cnt);
		}
		cnt*=10;
	}
	

	printf("%d", b);
	
	
	return 0;
}