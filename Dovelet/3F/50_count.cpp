#include<cstdio>

int main(){
	int n,a,b,ntmp;
	int d,tmp;
	tmp=d=0;
	scanf("%d",&n);
	
	ntmp=n-1;

	for(int i = 1 ; i <= n ;  i++){
		ntmp-=i;
		if(ntmp < 0) {
			ntmp+=i;
			d=ntmp;
			tmp = i;
			break;
		}else if( ntmp==0 ) {
			d=0;
			tmp = i+1;
			break;
		}		
	}

	if(tmp&1){ // odd
		a=tmp-d;
		b=1+d;
	}else if(!(tmp&1)){ // even
		b=tmp-d;
		a=1+d;
	}	

	printf("%d IS %d/%d",n,a,b);
	return 0;
}