#include<cstdio>

int main(){
	int a,b,max;
	bool t,ta,tb ;
	t=ta=tb=false;
	scanf("%d%d",&a,&b);
	(a>=b)?max=a:max=b;
	for(int i = 2 ; i < max ; i++){
		ta=tb=false;
		(!(a%i))?ta=true:false;
		(!(b%i))?tb=true:false;
		if(ta&tb){
			t=true;
			break;
		}
	}
	printf("%s",(t)?"no":"yes");
	return 0;
}