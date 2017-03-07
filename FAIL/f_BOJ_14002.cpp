#include<cstdio>
#include<algorithm>
#define MAX 1001
using namespace std;
int input[MAX] = {0,};
int size;
// 10 20 10 30 20 50
//  1  2  1  3  2  4
// 10 20 10 11 12 50
//  1  2  1  2  3  4 // max 보다 작으면 초기화
//  1  2  1  2  3  4
//  

// 10 20 10
int table[MAX] = {0,};
int data[MAX] = {0,};

int main(){
	scanf("%d", &size);
	for(int i = 1 ; i <= size ; i++) scanf("%d",&input[i]);
	int maxCount = 1;
	table[1] = 1;
	for(int i = 2 ; i <= size ; i++){
		int cnt = 1;
		for(int j = i-1 ; j >= 1 ; j--){ // 이전을 탐색
			if( input[j] < input[i] ){ // 현재 수 보다 작은 수가 있을 때 
				if(cnt <  table[j]+1) cnt = table[j]+1; // 그때 카운트 된게 더 많거나 같다면 해당 카운트+1로 바꿈.
			}
			else if( input[j] == input[i] ){
				if(cnt < table[j])	cnt = table[j];
			}
		}
		table[i] = cnt;
		maxCount = max(maxCount,table[i]);
	}
	//for(int i = 1 ; i <= size ; i++) printf("%2d ",input[i]);
	//printf("\n");
	//for(int i = 1 ; i <= size ; i++) printf("%2d ",table[i]);
	//printf("\n");
	//printf("\n");
	bool del = false;
	int tmpIndex = 0 ;
	for(int i = 1 ; i <= size ; i++){
		data[i] = 10000;
		if(del) table[i] = 0;
		if(table[i] == maxCount){
			tmpIndex = i;
			del = true;
		}		
	}
	int tmpCount = maxCount;
	for(int i = tmpIndex ; i >= 1 ; i--){
		if(table[i] == tmpCount){
			tmpCount--;
		}else{
			table[i] = 0;
		}
	}

	for(int i = 1 ; i <= size ; i++){
		if(data[table[i]] > input[i] && data[table[i]-1] < input[i]){
			data[table[i]] = input[i];
		}
	}


	printf("%d\n",maxCount);
	for(int i = 1 ; i <= maxCount ; i++){
		printf("%d",data[i]);
		if(i!=maxCount){
			printf(" ");
		}
	}

	return 0;
}