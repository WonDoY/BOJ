#include<cstdio>
int swap(int *x, int *y){
	float tmp = *x;
	*x= *y;
	*y= tmp;
	return 0;
}
int main(){
	
	int a[2],b[2];
	bool t[2] ;
	for(int i = 0 ; i < 2 ; i++) scanf("%d",&a[i]);
	for(int i = 0 ; i < 2 ; i++) scanf("%d",&b[i]);
	(a[0]>a[1])? swap(&a[0],&a[1]):false;
	(b[0]>b[1])? swap(&b[0],&b[1]):false;

	if(a[0] < b[0] && b[0] < a[1]){
		t[0]=false;
	}else{
		t[0]=true;
	}
	if(a[0] < b[1] && b[1] < a[1]){
		t[1]=false;
	}else{
		t[1]=true;
	}

	if((!t[0]&t[1]) || (t[0]&!t[1])){
		printf("%s","cross");
	}else{
		printf("%s","not cross");
	}

	return 0;
}