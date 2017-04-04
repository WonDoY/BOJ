#include<cstdio>
#include<algorithm>
#define MAX 100
using namespace std;

int input[MAX] = {0,};
int main(){
	int N = 0 , resN = 1;
	scanf("%d",&N); 
	for(int i = 0 ; i < N ; i++) scanf("%d",&input[i]); 

	sort(input,input+100);
	if( (N%2) ==1){
		int tmpIdx = (100-N)+int(N/2);
		resN = input[tmpIdx]*input[tmpIdx];
	}else{
		resN = input[(100-N)+0]*input[(100-N)+N-1];
	}
	printf("%d\n",resN);
	return 0;
}