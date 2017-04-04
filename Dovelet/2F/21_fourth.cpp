// 생각이없다

#include<cstdio>

int main(){
	int x[3],y[3];
	int a1,a2,b1,b2;
	a1=a2=b1=b2=0;
	int ac=0,bc=0;
	for(int i=0;i<3;i++){
		scanf("%d%d",&x[i],&y[i]);
		if(x[0]!=x[i]){
			a2++;
			ac=i;
		}else{
			a1++;
		}
		if(y[0]!=y[i]){
			b2++;
			bc=i;
		}else{
			b1++;
		}
	}
	printf("%d",(a1&1)?x[0]:x[ac]);
	printf(" %d",(b1&1)?y[0]:y[bc]);


	return 0;	
}