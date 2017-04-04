#include<cstdio>
//#include<algorithm>
int a[20];
int main(){
	int n,max=0,min=99;scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d",&a[i]);
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
	}
	if(n==1){
		printf("0");
	}else{
		printf("%d",2*(max-min));
	}
	//std::sort(a,a+n);

	return 0;
}