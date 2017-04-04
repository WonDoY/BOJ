#include<cstdio>
// 내각만알면끝인데
int main(){
	int input,out[2] ={0,};
	scanf("%d",&input);
	out[0]=(input-2)*180;
	out[1]=input*(180)-out[0];
	printf("%d %d",out[0],out[1]);
	return 0;
}