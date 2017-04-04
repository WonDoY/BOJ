#include<cstdio>

int main(){
	int a,b,c,d,s;
	int tmpa,tmpc;
	int N,B;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&s);
	N=B=0;
	tmpa=a; tmpc=c;
	for( int i = 0 ; i < s ; i++ ){
		if(tmpa>0){
			N++;
			tmpa--;
			if(tmpa-1 < 0){
				tmpa = -b;
			}
		}else if(tmpa<0){
			N--;
			tmpa++;
			if(tmpa+1 > 0){
				tmpa = a;
			}
		}

		if(tmpc>0){
			B++;
			tmpc--;
			if(tmpc-1 < 0){
				tmpc = -d;
			}
		}else if(tmpc<0){
			B--;
			tmpc++;
			if(tmpc+1 > 0){
				tmpc = c;
			}
		}
	}

	printf("%s",(N>B)?"Nikky" :(N<B)?"Byron":"Tied");

	return 0;
}
