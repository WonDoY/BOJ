#include<cstdio>

int main(){
	int a[3],res=0;
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	for(int i = 0 ; i < 3 ;i++){
		if(a[i]<=168){
			res=a[i];
			break;
		}
	}
	printf("%s",(!res)? "NO CRASH" : "CRASH");
	(!res) ? true : printf(" %d",res);

	return 0;
}