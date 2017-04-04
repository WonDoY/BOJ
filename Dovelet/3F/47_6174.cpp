#include<cstdio>
#include<algorithm>

using namespace std;
int main(){
	int n,max,min,cnt=0 ; 
	int s[4];
	scanf("%d",&n);	
	while(n!=6174){
		for(int i = 0 ; i < 4 ; i++){
			s[i]=n%10;
			n/=10;
		}
		sort(s,s+4);		
		max=s[3]*1000+s[2]*100+s[1]*10+s[0];
		min=s[0]*1000+s[1]*100+s[2]*10+s[3];
		n=max-min;
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}