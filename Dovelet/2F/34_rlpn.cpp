#include<cstdio>
int inp[2][4];
void solve(){
	for(int i = 0 ; i < 2 ; i++){
		scanf("%i%i",&inp[i][0],&inp[i][1]); // left bottom coord
		scanf("%i%i",&inp[i][2],&inp[i][3]); // right top coord

		// Attempt failed 1
		//if(i == 1){
		//	if( inp[i][0] == inp[0][0] &&
		//		inp[i][1] == inp[0][1] &&
		//		inp[i][2] == inp[0][2] &&
		//		inp[i][3] == inp[0][3]){
		//			printf("rectangle\n");
		//			return;
		//	}
		//}
		// Attempt failed 1
		// input data 
		// 1 1 50000 50000 1 1 50000 50000
	}

	int xleft = inp[1][0];
	int xright = inp[1][2];		
	int xbottom = inp[1][1];
	int xtop = inp[1][3];

	int left = inp[0][0];
	int right = inp[0][2];		
	int bottom = inp[0][1];
	int top = inp[0][3];

	int xres = 0 ;
	int yres = 0 ;

	if(left < xleft && xleft <right ||
		left < xright && xright <right ||
		left == xleft ||
		right == xright){ // 겹치는 조건
			xres = 2;
	}else if(right ==  xleft || left == xright){ // 교점일 조건
		xres = 1;
	}else{ // 겹치지 않음
		xres = 0;
	}

	if(xres == 0){
		if(xleft < left && left <xright 
			|| xleft < right && right < xright){ // 겹치는 조건
				xres = 2;
		}else if(right ==  xleft || left == xright){ // 교점일 조건
			xres = 1;
		}else{ // 겹치지 않음
			xres = 0;
		}
	}

	// Attempt failed 2 
	// 1 1 50000 50000 1 7171 50000 50000

	//printf("%d < %d < %d\n", bottom , xbottom , top);
	//printf("%d < %d < %d\n", bottom , xtop , top);
	if(bottom < xbottom && xbottom < top || 
		bottom < xtop && xtop < top ||
		bottom == xbottom ||
		top == xtop){ // 겹치는 조건
			yres = 2;
	}else if(bottom ==  xtop || top == xbottom){ // 교점일 조건
		yres = 1;
	}else{ // 겹치지 않음
		yres = 0;
	}

	if(yres == 0){
		if(xbottom < bottom && bottom < xtop || 
			xbottom < top && top < xtop){ // 겹치는 조건
				yres = 2;
		}else if(bottom ==  xtop || top == xbottom){ // 교점일 조건
			yres = 1;
		}else{ // 겹치지 않음
			yres = 0;
		}
	}

	//printf("xres : %d , yres : %d\n",xres, yres);
	if(xres*yres == 4){
		printf("rectangle\n");
		return ;
	}
	if(xres*yres == 2){
		printf("line\n");
		return ;
	}
	if(xres*yres == 1){
		printf("point\n");
		return ;
	}
	printf("none\n");
}

int main(){
	solve();
	return 0;
}


// this source was failed. so new source file made 
//#include<cstdio>
//
//int x[4],y[4];
//int a[2][4],b[2][4];
//int t;
//int solve(int a, int b, int c, int i, int j, int k){
//	if(x[a] <= x[b] && x[b] <= x[c] && 
//		y[i] <= y[j] && y[j] <= y[k]){
//			// x ; 0 2 1
//			// y ; 0 2 1					
//
//				t=0;
//				printf("## %s","rectangle");
//
//	}
//	return 0;
//}
//
//
//int main(){
//	t=3;
//	
//	for(int i = 0 ; i < 4 ; i++){
//		scanf("%d%d",&x[i],&y[i]);
//	}
//	a[0][0]
//	a[0][1]
//	a[1][0]
//	a[1][1]
//
//	
//	// x[0] y[0]
//	// x[1] y[1]
//
//	// x[2] y[2]
//	// x[3] y[3]
//	solve(0, 2, 1, 0, 2 ,1);
//	solve(0, 2, 1, 2, 0 ,3);
//	solve(2, 0 ,3, 0 ,2, 1);
//	solve(2, 0, 3 ,2, 0, 3);	
//
//
//
//	if(x[0]==x[2] && y[0]==y[2] || // 0 0 2 2
//		x[0]==x[2] && y[1]==y[3] || // 0 0 2 1
//		x[1]==x[3] && y[1]==y[3] ||
//		x[1]==x[3] && y[0]==y[2]){
//			t=0;
//			printf("# %s","rectangle");
//	}else if(x[0]==x[3] && y[0]==y[3] ||
//		x[1]==x[2] && y[0]==y[3] ||
//		x[1]==x[2] && y[1]==y[2] ||
//		x[0]==x[3] && y[1]==y[2]){
//			t=2;
//	}
//
//	switch(t){
//	case 0:
//		printf("%s","rectangle"); break;
//	case 1:
//		printf("%s","line"); break;
//	case 2:
//		printf("%s","point"); break;
//	case 3:
//		printf("%s","none"); break;
//	}
//	return 0;
//}