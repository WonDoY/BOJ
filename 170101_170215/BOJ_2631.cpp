#include<cstdio>
#include<algorithm>
#define MAX 201
using namespace std;
// N
// 1~N # of student 
//
// <<e.g>> ~ 3 7 5 2 6 1 4
// 0 : 3 7 5 2 6 1 4
// 1 : 3 7(4)5 2 6 1 
// 2 : 3 4 5 2 6 1(7)
// 3 :(1)3 4 5 2 6 7
// 4 : 1(2)3 4 5 6 7
// output min(# of move) 
// 옮겼을 때의 값이 있나 
// 음... 

// 1 2 3 4 5 6 7 을 만들기 위해서 저 수를 재 정렬 한다. 그중에 옮기는 것을 최소.
// 3 7 5 2 6 1 4 가 input 으로 주어지고.
//
// 2 5 2 2 1 5 3 원래 자기 위치와의 거리 
// TC 1. 가장 먼 것 부터 옮겨본다?
//  1 3 7 5 2 6 4
//> 0 1 4 1 3 0 3
//  1 3 5 2 6 4 7
//> 0 1 2 3 1 2 0
//  1 2 3 5 6 4 7
//> 0 0 0 1 1 2 0
//  1 2 3 4 5 6 7
//> 0 0 0 0 0 0 0
// 결론은 총 4번을 옮기긴 했다만.
// 음...

// 그런데 저대로 하면 순서를 생각하지않고 그때 그때 위치로 옮기는 것이기에
// 잘못된 방법......인것같고..

// 각 경우에서 알아서 애들을 빼서 넣으면 순서를 꽂는다. 
// 근데 애들을 빼는 즉시 무조건 맞는 순서!를 갖는다.라는 말이되고,
// 그러므로 9번문제와 동일하다....가장 긴 수열 과 동일한 문제...
// 


int N ; // N [2,200]
int result = 0;
int table[MAX][2] = {0,};
void printTable(){
	printf("\n	Table Result %3d\n",result);
	for(int i = 0 ; i <= N ; i++) printf("%2d", table[i][0]);
	printf("\n");
	for(int i = 0 ; i <= N ; i++) printf("%2d", table[i][1]);
	printf("\n");
	//for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][2]);
	//printf("\n");
}
int main(){
	scanf("%d",&N);
	int maxcnt = 1;
	
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&table[i][0]);
		int cnt = 1;
		for(int j = i-1 ; j >= 0 ; j--){ // 이전을 탐색
			if( table[j][0] < table[i][0] ){ // 현재 수 보다 작은 수가 있을 때 
				if(cnt <  table[j][1]+1) cnt = table[j][1]+1; // 그때 카운트 된게 더 많거나 같다면 해당 카운트+1로 바꿈.
			}
			else if( table[j][0] == table[i][0] ){				
				if(cnt < table[j][1]) maxcnt = table[j][1];
			}
		}
		table[i][1] = cnt;
		//printTable();
		maxcnt = max(maxcnt,table[i][1]);
	}
	printf("%d",N-maxcnt);
	return 0;
}
//void printTable(){
//	printf("\n	Table Result %3d\n",result);
//	for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][0]);
//	printf("\n");
//	for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][1]);
//	printf("\n");
//	for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][2]);
//	printf("\n");
//}
//int main(){
//	scanf("%d", &N);
//	for(int i = 1 ; i <= N ; i++){
//		scanf("%d", &table[i][1]); // 수 입력
//		table[i][0] = i; // 순서대로 넣는다. 
//	}
//	// 순회한 값을 저장한다. 
//	while(1){
//		bool seq = false;
//		int max = 0;
//		int maxIdx = 0;
//		for(int i = 1 ; i <= N ; i++){
//			table[i][2] = abs(table[i][1]-table[i][0]);
//			if(max <= table[i][2]){
//				max = table[i][2];
//				maxIdx = i;
//			}
//		} 
//		// 순회해서 가장 거리가 먼 것을 바꿔준다. 
//		//만약에 모든 값이 같다면 같은 값의 가장 왼쪽 인덱스를 바꾼다.
//		printTable();
//		if(max==0) seq = true;
//		else{
//			result++;
//			printf("moving....%d",table[maxIdx][1]);
//			int tmp = table[maxIdx][1];
//			if(table[maxIdx][1] < maxIdx){
//				//[1].... maxIdx
// 				for(int i = maxIdx ; i > tmp ; i--){
//					swap(table[i][1],table[i-1][1]);
//				}
//			}else if(table[maxIdx][1] > maxIdx){
//				// maxIdx..... [1]
//				for(int i = maxIdx ; i < tmp ; i++){
//					swap(table[i][1],table[i+1][1]);
//				}
//			}else{
//				printf("Need Debug..\n");
//			}
//			
//		}
//		if(seq) break; // 이거 지워줘도 되긴하겠다.
//
//	}
//	
//	return 0;
//}