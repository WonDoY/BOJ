#include<cstdio>

int main(){
	int a,d,an;
	bool t =false;
	scanf("%d%d%d",&a,&d,&an);
	for(int i = 0 ; i < 100000 ; i++){
		if(an==a+d*i){
			an = i+1;
			t=true; break;
		}
	}
	
	(t)?printf("%d",an):printf("X");
	return 0;

}