#include<cstdio>

int main(){
	int e,f,c;
	int hav,rem;
	int res = 0;
	scanf("%d%d%d",&e,&f,&c);
	hav = e+f;
	while(1){
		res += hav/c;
		hav = hav/c + hav%c;
		if(hav < c) break;
	}
	printf("%d\n",res);

	return 0;
}