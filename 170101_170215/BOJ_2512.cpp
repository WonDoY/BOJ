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
//// ������ �� �ִ��� �� ������ �����Ѵ�.
//// 1. ��� ��û�� ������ �� �ִ� ��� ��û �ݾ� �״�� ����
//// 2. ��� ��û ������ �� ���� ��� ���� ���Ѿ� ���, 
//// �� ������ ��� �����ϰ� �����Ѵ�. 
//// ����� �� �ִ� ���� ���.
//
//// @input 
//// n ����� [3,10000]
//// input[0...n-1] n�� ����� ��û�� input[k] [1,100000]
//// m �ѿ��� [n,1,000,000,000]
//typedef long long ll;
//ll n;
//ll input[MAX];
//ll m;
//ll result = 0;
//// 1. ��� ������ ���� ���� �� ��� ���� ����Ѵ�. 
//// 2. ���� ��� �� ���� �۰ų� ���� ���濹���� �ѿ��꿡�� - ��Ų��.
////  2-1. ��հ��� �ִ밪�� �ȴ�.
////  2-2. �ѿ����� ���Ҵٸ� 1.�� ������ �ݺ��Ѵ�. 
////  
//
//// ��������� ������ �ִ� ������ ���� ������ ��û�ϴ� ���� ���� 0�� �Ǿ���Ѵ�. 
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
//		if(countNonZero > m){ // ������ ���꺸�� .. �̰� Critical �̾���..
//			 return ;
//		}
//		//printf("m : %lld / countNonZero : %lld\n",m, countNonZero);
//		avg = m/countNonZero;
//		sum = sum/countNonZero;
//		if(sum < avg) avg = sum;
//		//avg /= n; // end proc 1
//		for(int i = 0 ; i < n ; i++){	
//			if(input[i] < avg){ // !! ������ ������ ���� ���� , avg ���� ������ Ȥ�� ...
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
//		// ���� ��ġ�̵�..
//		//if(countNonZero > m){ // ������ ���꺸�� .. 
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