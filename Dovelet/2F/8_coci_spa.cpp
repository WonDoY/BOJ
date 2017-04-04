#include<cstdio>

int main(){
	int h,m;
	scanf("%d%d",&h,&m);
	if(m<45){
		m=60-(45-m);
		h--;
	}else{
		m-=45;
	}
	if(h<0)h=23;
	printf("%d %d",h,m);
	return 0;
}