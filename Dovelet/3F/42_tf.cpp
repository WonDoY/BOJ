// 시간 오래걸렸음 문제있음
#include<cstdio>
#include<cmath>

int main(){
	int n,o,p,tmp;
	bool t=false;
	scanf("%d",&n);

	for(o = 1 ; o <= n ; o+=2){
		for(p = 0 ; p <= n ; p++){
			tmp = o*pow((double)2,p);
			if(tmp == n){
				t=true;printf("%d %d",o,p);break;
			}
			if(tmp > n){
				break;
			}
		}
		if(t) break;
	}
	
	return 0;
}