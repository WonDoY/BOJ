#include<cstdio>

int main(){
	int a,s1,s2,s3;
	s1=s2=s3=0;
	for(int i = 0 ; i < 7 ; i++){
		scanf("%d",&a);
		
		if(a/(100.0)>=1){
			s3+=a;
		}else if(a/(10.0)>=1){
			s2+=a;
		}else{
			s1+=a;
		}		
	}
	printf("%d %d %d",s1,s2,s3);
	return 0;

}