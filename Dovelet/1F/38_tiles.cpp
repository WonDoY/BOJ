#include<cstdio>

int main(){
	float right, left, part, whole, r, l;
	bool t = false, tt = false;
	scanf("%f%f",&right,&left);
	// 8*8
	part = 0;

	right = right/8;
	left = left/8;
	
	if(right-(int)right > 0){		
		t = true;
	}
	
	if(left-(int)left > 0){	
		tt = true;		
	}
	
	right = (int)right;
	left = (int)left;
	(t) ? part=(int)left : false;
	(tt) ? part+=(int)right : false;
	(t&&tt) ? part++ : false;
	whole = right*left;

	printf("The number of whole tiles is %.0f part tiles is %.0f\n",whole,part);
	return 0;
}