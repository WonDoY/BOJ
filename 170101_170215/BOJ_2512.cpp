#include<cstdio>
#define MAX 10000
typedef long long ll;
ll n;
ll input[MAX];
ll m;
ll result = 0;

void bs(){
	while(m>0){		
		ll avg = 0;
		ll sum = 0;
		ll countNonZero = 0;

		for(int i = 0 ; i < n ; i++){
			sum += input[i];
			if(input[i]>0) countNonZero++;
		}

		if(!countNonZero) return; 
		if(countNonZero > m) return;

		avg = m/countNonZero;
		sum = sum/countNonZero;
		if(sum < avg) avg = sum;

		// avg /= n;  // delete... line.,..
		for(int i = 0 ; i < n ; i++){	
			if(input[i] < avg){
				m -= input[i];
				input[i] -= input[i];			
			}
			else {
				m -= avg;
				input[i] -= avg;
			}
		}
		result += avg;
	}
}


int main(){
	scanf("%lld", &n);
	for(int i = 0 ; i < n ; i++) scanf("%lld", &input[i]);
	scanf("%lld", &m);
	bs();	
	printf("%lld\n",result);
	return 0;
}

//2
//10 20
//12
// out 6

//2
//10 1 
//5
// out 4

//WA tc
//3
//1 1 100
//10000
// out 100

//5
//70 80 30 40 100
//450
// !! 230 ? nope 100

//3
//100 100 100
//300
// out 100

//10
//50 50 50 50 100 100 120 120 200 240
//1000












//#include<cstdio>
//#define MAX 10000
//// 가능한 한 최대의 총 예산을 결정한다.
//// 1. 모든 요청이 배정될 수 있는 경우 요청 금액 그대로 배정
//// 2. 모든 요청 배정될 수 없는 경우 정수 상한액 계산, 
//// 두 조건이 모두 만족하게 배정한다. 
//// 예산들 중 최대 값을 출력.
//
//// @input 
//// n 지방수 [3,10000]
//// input[0...n-1] n개 지방수 요청액 input[k] [1,100000]
//// m 총예산 [n,1,000,000,000]
//typedef long long ll;
//ll n;
//ll input[MAX];
//ll m;
//ll result = 0;
//// 1. 모든 지방의 예산 총합 의 평균 값을 계산한다. 
//// 2. 계산된 평균 값 보다 작거나 같은 지방예산은 총예산에서 - 시킨다.
////  2-1. 평균값이 최대값이 된다.
////  2-2. 총예산이 남았다면 1.의 과정을 반복한다. 
////  
//
//// 결론적으로 예산의 최대 값보다 작은 예산을 요청하는 곳은 값이 0이 되어야한다. 
//
//void bs(){
//	while(m>0){
//		
//		ll avg = 0;
//		ll sum = 0;
//		ll countNonZero = 0;
//		for(int i = 0 ; i < n ; i++){
//			//avg += input[i];
//			sum += input[i];
//			if(input[i]>0) countNonZero++;
//		}
//		if(!countNonZero) return; // WA1: add source code
//		if(countNonZero > m){ // 배정할 예산보다 .. 이게 Critical 이었음..
//			 return ;
//		}
//		//printf("m : %lld / countNonZero : %lld\n",m, countNonZero);
//		avg = m/countNonZero;
//		sum = sum/countNonZero;
//		if(sum < avg) avg = sum;
//		//avg /= n; // end proc 1
//		for(int i = 0 ; i < n ; i++){	
//			if(input[i] < avg){ // !! 예산을 나누는 조건 분할 , avg 보다 작을때 혹은 ...
//				m -= input[i]; 
//				input[i] -= input[i];			
//			}else{
//				m -= avg;
//				input[i] -= avg;
//			}
//		}
//		//printf("+%lld %lld\n",avg, result);
//		result += avg;
//		
//		//printf("avg %lld result %lld countNon %lld remind %lld\n",avg,result,countNonZero,m);
//		// 위로 위치이동..
//		//if(countNonZero > m){ // 배정할 예산보다 .. 
//		//	 return ;
//		//}
//		 
//	}
//}
//
//
//int main(){
//	scanf("%lld", &n);
//	for(int i = 0 ; i < n ; i++) scanf("%lld", &input[i]);
//	scanf("%lld", &m);
//
//	bs();	
//
//	printf("%lld\n",result);
//	return 0;
//}
//
////2
////10 20
////12
//// out 6
//
////2
////10 1 
////5
//// out 4
//
////WA tc
////3
////1 1 100
////10000
//// out 100
//
////5
////70 80 30 40 100
////450
//// !! 230 ? nope 100
//
////3
////100 100 100
////300
//// out 100
//
////10
////50 50 50 50 100 100 120 120 200 240
////1000