#include<cstdio>

int main(){
	int n,cnt=0,k;
	bool t=false;
	scanf("%d%d",&n,&k);
	for(int i = 1; i<=n ; i++){
		if(!(n%i)){
			cnt++;
			if(cnt==k){
				n = i;
				t = true;
				break;
			}
		}
	}
	(t) ? printf("%d",n) : printf("0");
	return 0;
}