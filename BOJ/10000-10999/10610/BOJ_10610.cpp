#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 100000
using namespace std;
int main(){
	char n[MAX]; scanf("%s",n); // runtime error &n -> n
	bool zeroNothing = true;
	int sum = 0;
	for(int i = 0 ; n[i] != 0 ; i++){
		sum += (int)(n[i] - '0');
		if(n[i] == '0'){
			zeroNothing = false;
		}
	}
	
	if(sum%3!=0 || zeroNothing){
		printf("-1\n");
	}else{
		sort(n,n+strlen(n));
		for(int i = strlen(n)-1 ; i >= 0 ; i--){
			printf("%c",n[i]);
		}
	}
	
	return 0;
}