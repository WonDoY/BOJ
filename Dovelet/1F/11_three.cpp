#include<cstdio>
int a,b,tmpres,res=0,c=0,cnt=0;
int main(){
	scanf("%d%d",&a,&b);
	while(b){
		tmpres = a*(b%10);
		printf("%d\n",tmpres);
		b/=10; c=cnt++;
		while(c--){
			tmpres*=10;
		}
		res+=tmpres;
	}
	printf("%d\n",res);

	return 0;
}