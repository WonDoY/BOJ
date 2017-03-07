#include<cstdio>
#define MAX 5001
int josep[MAX] = {0,};
int result[MAX] = {0,};
int main(){
	int N, M, rem;
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N ; i++){
		josep[i] = i+1;
	}
	rem = N;
	int move = 0;
	int resIndex = 0;
	while(rem){
		for(int i = 0 ; i < N ; i++){
			if(josep[i]>0) move++;
			if(move == M){
				result[resIndex++] = josep[i];
				josep[i] = 0;
				rem--;
				move = 0;
			}
		}
	}
	printf("<");
	for(int i = 0 ; i < N ; i++){
		if(i < N-1) printf("%d, ",result[i]);
		else printf("%d",result[i]);
	}
	printf(">\n");
	return 0;
}