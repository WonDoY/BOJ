#include<cstdio>

int main(){
	int a[5];
	int d,r;
	for(int i = 0 ; i < 4 ; i++){
		scanf("%d",&a[i]);
		if(i==1){
			d=a[i]-a[i-1];
			r=a[i]/a[i-1];
		}
		if(i>1){
			if(d==a[i]-a[i-1]){
				a[4]=a[0]+4*d;
			}else if(r==a[i]/a[i-1]){
				a[4]=a[0]*r*r*r*r;
			}
		}
	}
	for(int i = 0 ; i < 5 ; i++) printf("%d ",a[i]);
	return 0;
}