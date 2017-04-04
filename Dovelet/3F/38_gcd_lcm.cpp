#include<cstdio>

int main(){
	int a,b,max,res1=1,res2=1;
	bool ta,tb,t;
	scanf("%d%d",&a,&b);
	(a>b) ? max=a : max=b ;
	
	t=false;
	for(int i = 2 ; i <= max ; i++){
		ta=tb=false;
		if(!(a%i)) ta=true;
		if(!(b%i)) tb=true;
		
		if(ta&tb){
			res1*=i;
			res2*=i;
			a/=i;b/=i;
			i=1;
		}
	}
	res2*=a*b;
	printf("%d %d",res1,res2);
	return 0;
}