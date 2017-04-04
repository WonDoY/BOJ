#include<cstdio>

int main(){
	int n = 10000, tmp;
	for(int i = 1 ; i <= n; i++){
		tmp = i*i;
		if(tmp>=100000000){
			tmp%=100000;
		}else if(tmp>1000000){
			tmp%=10000;
		}else if(tmp>10000){
			tmp%=1000;
		}else if(tmp>100){
			tmp%=100;
		}else{
			tmp%=10;
		}
		//printf("=%d ",tmp);
		(tmp==i)?printf("%d\n",i):false;
	}
	return 0;
}