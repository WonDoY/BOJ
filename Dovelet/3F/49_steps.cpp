#include<cstdio>

int main(){
	int x,y;
	bool xt,yt,t;
	scanf("%d%d",&x,&y);
	(x&1)?xt=true:xt=false; // false = even
	(y&1)?yt=true:yt=false;

	t=false;
	if(x==y){
		t=true;
		if((!xt)&(!yt)){
			printf("%d",x+y);
		}else{
			printf("%d",x+y-1);
		}
	}else if(x-2==y){
		t=true;
		if((!xt)&(!yt)){
			printf("%d",x+y);
		}else{
			printf("%d",x+y-1);
		}
	}
	(!t)?printf("No Number"):false;
	
	
	
	return 0;
}