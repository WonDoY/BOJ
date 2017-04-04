#include<cstdio>

int main(){
	int x[4],y[4];
	bool t = false;
	for(int i = 0 ; i < 4 ; i++){
		scanf("%d%d",&x[i],&y[i]);
	}
	// x[0] y[0]
	// x[1] y[1]

	// x[2] y[2]
	// x[3] y[3]

	if(x[0] <= x[2] && x[2] <= x[1] && 
		y[0] <= y[2] && y[2] <= y[1]) t =true;
	if(x[2] <= x[0] && x[0] <= x[3] && 
		y[0] <= y[2] && y[2] <= y[1]) t =true;
	if(x[0] <= x[2] && x[2] <= x[1] && 
		y[2] <= y[0] && y[0] <= y[3]) t =true;
	if(x[2] <= x[0] && x[0] <= x[3] && 
		y[2] <= y[0] && y[0] <= y[3]) t =true;


	printf("%s",(t)?"Overlap":"No overlap");
	
	return 0;
}