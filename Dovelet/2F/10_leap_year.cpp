#include<cstdio>

int main(){
	int n;
	bool t=false;
	scanf("%d",&n);
	if(n%4==0){
		t=true;
		if(n%400==0){
			t=true;
		}
		else if(n%100==0){
			t=false;
		}
	}
	printf("%s",(t)?"YES":"NO");
	return 0;
}