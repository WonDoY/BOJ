#include<cstdio>

int main(){
	int n,cal;
	int bottom, top;
	bottom = top = 0;
	scanf("%d",&n);

	for(int i = 1 ;  i <= n ; i++){
		cal = (i*(i+1)) / 2 ; 
		if(cal >= n){
			
			top = cal - n;
			bottom = i;
			int temp = cal;
			for(int i = 1 ; i <= n ; i++){
				cal = (i*(i+1)) / 2;
				if(cal > top){
					top = cal - top;
					break;
				}
			}
			if(temp==1){
				top = bottom = 1;
			}
			break;
		}
	}

	printf("%d %d\n",bottom ,top);
	return 0;
}