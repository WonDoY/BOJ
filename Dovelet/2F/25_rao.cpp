#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int a[3];
	for(int i = 0 ; i < 3 ; i++) scanf("%d",&a[i]);
	sort(a,a+3);
	int x[3];
	for(int i = 0 ; i < 3 ; i++) x[i]=a[i]*a[i];
	if(x[2]==x[1]+x[0]){
		printf("right");
	}else if(x[2]>x[1]+x[0]){
		printf("obtuse");
	}else if(x[2]<x[1]+x[0]){
		printf("acute");
	}
	
	return 0;
}