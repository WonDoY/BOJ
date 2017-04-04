#include<cstdio>

int main(){
	int n,be=0,af=0;
	bool t=false;
	scanf("%d",&n);
	for(int i = 1; i < n;i++){
		be+=i;
	}
	for(int i = n+1 ; i<2*n;i++){
		af+=i;
		if(be==af){
			t=true;
			break;
		}else if(af>be){
			break;
		}
	}
	printf("%c",(t)?'O':'X');
	return 0;
}