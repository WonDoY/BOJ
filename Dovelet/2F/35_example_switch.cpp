#include<cstdio>

int main(){
	int n,m,out;
	bool t=false;
	scanf("%d%d",&n,&m);
	if(n%4==0){
		t=true;
		if(n%400==0){
			t=true;
		}
		else if(n%100==0){
			t=false;
		}
	}
	switch(m){
	case 1:case 3:case 5:case 7:case 8:case 10:case 12: 
		out=31;
		break;
	case 2:
		(t)?out=29:out=28;
		break;
	case 4:	case 6:case 9:case 11:
		out=30;
		break;
	}
	printf("%d",out);
	return 0;
}