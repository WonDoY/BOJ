#include<cstdio>
int inh,inm,ins;
int input;
int h,m,s;
int main(){
	scanf("%d%d%d%d",&inh,&inm,&ins,&input);
	h = input/3600;
	m = (input%3600)/60;
	s = (input%60);
	ins = (ins+s);
	(ins >= 60) ? m++,ins = ins%60  : false ; 	
	inm = (inm+m);
	(inm >= 60) ? h++,inm = inm%60 : false ;
	inh = (inh+h)%24;
	printf("%d %d %d",inh,inm,ins);
	
	return 0;
}