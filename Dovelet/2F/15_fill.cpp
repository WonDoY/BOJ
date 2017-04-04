#include<cstdio>

int main(){
	float s,w,p;
	bool tW,tR,tQ;
	tW=tR=tQ=true;
	scanf("%f%f%f",&s,&w,&p);
	(s<=4.5 & w>=150 & p>=200)?printf("Wide Receiver "):tW=false;
	(s<=6.0 & w>=300 & p>=500)?printf("Lineman "):tR=false;
	(s<=5.0 & w>=200 & p>=300)?printf("Quarterback "):tQ=false;
	if(!tW){
		if(!tR){
			if(!tQ){
				printf("No positions");
			}
		}
	}
	return 0;
}