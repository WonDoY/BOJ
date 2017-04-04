#include<cstdio>

int main(){
	int a=0,t[6]={0,};
	while(1){
		scanf("%d",&a);
		if(a==-1)break;
		else a/=10;
		switch(a){
		case 10: case 9: t[1]++;break;
		case 8: t[2]++; break;
		case 7: t[3]++; break;
		case 6: t[4]++; break;
		default : t[5]++; break;
		}
		t[0]++;
	}
	for(int i = 0 ; i < 6 ; i++)
		printf("%d\n",t[i]);
	return 0;
}