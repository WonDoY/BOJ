#include<cstdio>

int main(){
	int n, spd[2]={0,} ,time[2]={0,},res=0;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d%d",&spd[0],&time[0]);
		res+=(spd[0])*(time[0]-time[1]);
		time[1]=time[0];
	}
	printf("%d miles",res);

	return 0;
}