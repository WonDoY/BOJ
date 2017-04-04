#include<cstdio>

int main(){
	int a,b,c,d;
	int res=0;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	switch(a){
	case 1: res+= 461;break;
	case 2: res+= 431;break;
	case 3: res+= 420;break;
	}
	switch(b){
	case 1:res+= 130; break;
	case 2:res+= 160; break;
	case 3:res+= 118; break;
	}
	switch(c){
	case 1:res+= 100; break;
	case 2:res+= 57; break;
	case 3:res+= 70; break;
	}
	switch(d){
	case 1:res+=167; break;
	case 2:res+=266; break;
	case 3:res+=75; break;
	}
	printf("%s%d%c","Your total Calorie count is ",res,'.');

	return 0;
}