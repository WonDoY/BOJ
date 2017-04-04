#include<cstdio>

void solve(int tc){
	int inp[4][2] = {0,};
	int xres, yres;
	xres = 0;
	yres = 0;
	for(int i = 0 ; i < tc ; i++){
		scanf("%i%i",&inp[i][0],&inp[i][1]);
	}

	if(tc==1){
		printf("%d\n",-1);
		return ;
	}
	else{
		for(int i = 0 ; i < tc ; i++)
			for(int j = i+1 ; j < tc ; j++){
				if(inp[i][0]!=inp[j][0]){
					xres = inp[i][0]-inp[j][0];
					(xres < 0) ? xres = -xres: false ;
				}
				if(inp[i][1]!=inp[j][1]){
					yres = inp[i][1]-inp[j][1];
					(yres < 0) ? yres = -yres: false ;
				}
			}
		// try to fail 1 start
		if(!(xres*yres)){
			printf("%d\n",-1);		
		}else{
			printf("%d\n",xres*yres);		
		}
		// try to fail 1 end
		
	}
}

int main(){
	int t;
	scanf("%d",&t);
	solve(t);
	return 0;
}