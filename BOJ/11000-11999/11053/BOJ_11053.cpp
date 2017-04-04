#include<cstdio>
#include<algorithm>
#define MAX 1001
using namespace std;
int a[MAX] = {0,};
int size;
// 10 20 10 30 20 50
//  1  2  1  2  1  2 
//  1  2  2  3  3  4
//  
// 10 20 10 11 12 50
//  1  2  1  2  3  4 // max 보다 작으면 초기화
//  1  2  2  2  2  3 
int b[MAX][3] = {{0,0,0},{1,1,0}};

int main(){
	scanf("%d", &size);
	for(int i = 1 ; i <= size ; i++){
		scanf("%d",&a[i]);
	}

	int max_1 = 1;
	for(int i = 2 ; i <= size ; i++){
		// max 보다 크다면
		//if(a[i] > max_1){
		//	max_1 = a[i];
		//	b[i][0] = b[i-1][0] + 1;
		//}
		//else{
		//	b[i][0] = b[i-1][0];
		//}

		int cnt = 1;
		for(int j = i-1 ; j >= 1 ; j--){ // 이전을 탐색
			if( a[j] < a[i] ){ // 현재 수 보다 작은 수가 있을 때 
				if(cnt <  b[j][1]+1) cnt = b[j][1]+1; // 그때 카운트 된게 더 많거나 같다면 해당 카운트+1로 바꿈.
			}
			else if( a[j] == a[i] ){				
				if(cnt < b[j][1])	cnt = b[j][1];
			}
		}
		b[i][1] = cnt;
		max_1 = max(max_1,b[i][1]);
		//if(b[i][1] >= b[i][0]){
		//	b[i][0] = b[i][1]; 
		//	max_1 = a[i];
		//}
	}
	/*for(int i = 1 ; i <= size ; i++) printf("%2d ",a[i]);
	printf("\n");
	for(int i = 1 ; i <= size ; i++) printf("%2d ",b[i][0]);
	printf("\n");
	for(int i = 1 ; i <= size ; i++) printf("%2d ",b[i][1]);
	printf("\n");*/
	printf("%d",max_1);

	return 0;
}

//6
//10 20 10 30 20 50


//8
//10 20 10 11 12 20 10 30

//9
//10 50 60 70 11 12 13 14 15

//10
//1 6 8 3 4 10 1 2 3 4
//4

//6
//10 1 10 30 20 20
//3

//8
//10 20 30 5 10 20 30 40  
//5
//
//20
//2 54 77 21 14 32 68 47 22 10 6 85 77 85 111 140 25 43 31 11
// 8

//14
//10 10 10 10 12 15 10 13 14 10 20 15 16 17
// 7

//#include<cstdio>
//#include<algorithm>
//#define MAX 1001
//using namespace std;
//int a[MAX] = {0,};
//int size;
//// 10 20 10 30 20 50
////  1  2  1  2  1  2 
////  1  2  2  3  3  4
////  
//// 10 20 10 11 12 50
////  1  2  1  2  3  4 // max 보다 작으면 초기화
////  1  2  2  2  2  3 
//int b[MAX][3] = {0,};
//
//int main(){
//	scanf("%d", &size);
//	for(int i = 1 ; i <= size ; i++){
//		scanf("%d",&a[i]);
//	}
//	int max_1 = 0;
//	int max_2 = 0;
//	int min_2 = a[1];
//	for(int i = 1 ; i <= size ; i++){
//		if(a[i] > max_1){ // max 보다 크다면
//			max_1 = a[i];
//			b[i][0] = b[i-1][0] + 1;
//		}else{
//			b[i][0] = b[i-1][0];
//		}
//		if(a[i] < max_2){ // max 보다 작으면 초기화
//			
//			if(min_2 < a[i]){
//				if
//				b[i][1] = 2;
//			}else if(min_2 > a[i]){
//				min_2 = a[i];
//				b[i][1] = 1;
//			}else{
//				b[i][1] = 1;
//			}
//			max_2 = a[i];
//		}else{ // max 보다 크면 값 저장 
//			max_2 = a[i];
//			b[i][1] += b[i-1][1] + 1;
//		}
//		if(b[i][1] >= b[i][0]){
//			b[i][0] = b[i][1]; 
//			max_1 = a[i];
//		}
//	}
//	//for(int i = 1 ; i <= size ; i++) printf("%2d ",a[i]);
//	//printf("\n");
//	//for(int i = 1 ; i <= size ; i++) printf("%2d ",b[i][0]);
//	//printf("\n");
//	//for(int i = 1 ; i <= size ; i++) printf("%2d ",b[i][1]);
//	//printf("\n");
//	printf("%d",max(b[size][0],b[size][1]));
//
//	return 0;
//}