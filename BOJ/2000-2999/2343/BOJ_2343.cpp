#include<cstdio>
#define MAX 100000
typedef long long ll;
ll n, blue;
ll lesson[MAX] = {0,};
ll result;
ll min, max;
void bs(){
	ll start = min;
	ll end = max;
	ll mid;
	while(1){
		ll sum = 0;
		ll bluerayCount = 1;
		mid = ( start + end ) / 2;
		if(end < start) return; 
		for(int i = 0 ; i < n ; i++){
			sum += lesson[i];
			if(mid < sum) bluerayCount++, sum = lesson[i]; 
		}

		if(bluerayCount > blue) start = mid+1;
		else if(bluerayCount <= blue) end = mid-1, result = mid;
	}
}
int main(){
	min = 1;
	max = 0x0000000fffffffff; 
	ll tmpMin = 0;
	scanf("%lld%lld",&n,&blue);
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &lesson[i]);
		if(tmpMin < lesson[i]) tmpMin = lesson[i];
	}
	bs();
	printf("%lld",(tmpMin > result) ? tmpMin : result);
	return 0;
}

//#include<cstdio>
//// 레슨의 순서가 바뀌면 안된다.
//// 즉, i번 레슨과 j번 레슨을 같은 블루레이에 녹화하려면
//// i와 j 사이의 모든 레슨도 같은 블루레이에 녹화해야함.
//
//// 블루레이의 개수를 가급적 줄이려고 한다. 
//// m개의 블루레이에 모든 레슨을 넣으려고 한다. 
//// 레슨의 길이가 분단위로 주어진다.
//
//// 가능한 블루레이 크기중 최소를 구함.
//
//// 1. 순서가 바뀌면 안된다.
//// 블루레이의 개수는 주어진다.
//// 블루레이의 크기는 m개가 일정하다. 
//// (  ) (  ) (  ) 한 블루레이에 들어가는 시간이 최대이며 최소를 구하여라.
//
//// lesson 의 총합 의 평균은 result 값보다 같거나 작은 결과이다. if(lessonAvg <= result) return true;
//// 검색을 하며 순회했을 때, lessonAvg <= Another lessons <= result->Max lessons
//#define MAX 100000
//typedef long long ll;
//ll n, blue;
//ll lesson[MAX] = {0,};
//ll result;
//ll min, max;
//void bs(){
//	ll start = min;
//	ll end = max;
//	ll mid;
//	while(1){
//		ll sum = 0;
//		ll bluerayCount = 1;
//		mid = ( start + end ) / 2;
//		if(end < start) return; // end < start -> end <= start
//		// 1. 현재 설정된 mid 값 (최소값) 보다 크면 다음 수로 넘어감.
//		// 2. 현재 설정된 mid 값 (최소값) 보다 작거나 같다면 더함.
//		for(int i = 0 ; i < n ; i++){
//			sum += lesson[i];
//			if(mid < sum){ // 합의 값이 설정된 mid 블루레이 길이보다 초과하면 자르고 count
//				bluerayCount++;
//				sum = lesson[i]; // lesson[i]를 더해서 초과했기 때문에 기본값을 lesson[i]로 한다. 
//			}
//		}
//
//		if(bluerayCount > blue){ // 갯수가 많으면 블루레이 길이를 늘려야함. -> 갯수 줄임
//			start = mid+1;
//		}else if(bluerayCount < blue){ // 갯수가 적으면 블루레이 길이를 줄여야함 -> 갯수 늘림.
//			end = mid-1;
//			result = mid;
//		}else if(bluerayCount == blue){ //8%->58% 갯수가 같으면 저장하고 길이를 줄여봄. 더 작은 길이에도 되는지 확인.
//			end = mid-1;
//			result = mid;
//		}
//	}
//}
//int main(){
//	min = 1;
//	max = 0x0000000fffffffff; //0%->8% 
//	ll tmpMin = 0;
//	scanf("%lld%lld",&n,&blue);
//	for(int i = 0 ; i < n ; i++){
//		scanf("%lld", &lesson[i]);
//		if(tmpMin < lesson[i]){ // 58% -> 100%
//			tmpMin = lesson[i];
//		}
//	}
//	bs();
//	printf("%lld",(tmpMin > result) ? tmpMin : result);
//	return 0;
//}
// 8% 틀렸습니다. 
// 58% 틀렸습니다.
// 100% 틀렸습니다.
//9 3
//1 2 3 4 5 6 7 8 9

//7 6
//100 400 300 100 500 101 400

//7 7
//5 9 6 8 7 7 5

//8 7
//3 3 10 10 3 2 6 2

//7 7
//1 5 9 9 9 2 9


//#include<cstdio>
//// 레슨의 순서가 바뀌면 안된다.
//// 즉, i번 레슨과 j번 레슨을 같은 블루레이에 녹화하려면
//// i와 j 사이의 모든 레슨도 같은 블루레이에 녹화해야함.
//
//// 블루레이의 개수를 가급적 줄이려고 한다. 
//// m개의 블루레이에 모든 레슨을 넣으려고 한다. 
//// 레슨의 길이가 분단위로 주어진다.
//
//// 가능한 블루레이 크기중 최소를 구함.
//
//// 1. 순서가 바뀌면 안된다.
//// 블루레이의 개수는 주어진다.
//// 블루레이의 크기는 m개가 일정하다. 
//// (  ) (  ) (  ) 한 블루레이에 들어가는 시간이 최대이며 최소를 구하여라.
//
//// lesson 의 총합 의 평균은 result 값보다 같거나 작은 결과이다. if(lessonAvg <= result) return true;
//// 검색을 하며 순회했을 때, lessonAvg <= Another lessons <= result->Max lessons
//#define MAX 100000
//typedef long long ll;
//ll n, blue;
//ll lesson[MAX] = {0,};
//ll result;
//ll min, max;
//void bs(){
//	ll start = min;
//	ll end = max;
//	ll mid;
//	while(1){
//		ll sum = 0;
//		//ll bluerayCount = 0;
//		ll bluerayCount = 1;
//		mid = ( start + end ) / 2;
//		if(end <= start) return; // end < start -> end <= start
//		// 1. 현재 설정된 mid 값 (최소값) 보다 크면 다음 수로 넘어감.
//		// 2. 현재 설정된 mid 값 (최소값) 보다 작거나 같다면 더함.
//		for(int i = 0 ; i < n ; i++){
//			sum += lesson[i];
//			if(mid < sum){ // 합의 값이 설정된 mid 블루레이 길이보다 초과하면 자르고 count
//				//printf("%lld ",sum-lesson[i]);
//				bluerayCount++;
//				sum = lesson[i]; // lesson[i]를 더해서 초과했기 때문에 기본값을 lesson[i]로 한다. 
//			}
//			//else if(mid == sum){ // 합의 값과 mid 블루레이 길이와 같으면 sum을 0으로 초기화 count++;
//			//	//printf("%lld ",sum);
//			//	bluerayCount++;
//			//	sum = 0;
//			//}
//			//// else if(mid > sum) 작은 경우는 해당되지 않음.
//			//if(sum > 0 && i==n-1){ 
//			//	//printf("%lld ",sum);
//			//	bluerayCount++;
//			//}
//		}
//		//printf("\n");
//		//printf("	%lld count : %lld\n",mid , bluerayCount);
//
//		if(bluerayCount > blue){ // 갯수가 많으면 블루레이 길이를 늘려야함. -> 갯수 줄임
//			start = mid+1;
//		}else if(bluerayCount < blue){ // 갯수가 적으면 블루레이 길이를 줄여야함 -> 갯수 늘림.
//			end = mid;
//		}else if(bluerayCount == blue){ //8%->58% 갯수가 같으면 저장하고 길이를 줄여봄. 더 작은 길이에도 되는지 확인.
//			end = mid;
//			result = mid;
//		}
//		// WA Code
//		//result = mid;
//		//if(bluerayCount > blue){
//		//	start = mid+1;
//		//}else if(bluerayCount <= blue){
//		//	end = mid-1;
//		//}else if(bluerayCount == blue){
//		//	return;
//		//}
//	}
//}
//int main(){
//	min = 1;
//	max = 0x0000000fffffffff; //0%->8% 아.. 이거네 왜 10000으로 설정했냐 레슨의 길이는 각 레슨의 길이가 10000이지... 
//	//printf("%lld",max);
//	ll tmpMin = 0;
//	scanf("%lld%lld",&n,&blue);
//	for(int i = 0 ; i < n ; i++){
//		scanf("%lld", &lesson[i]);
//		if(tmpMin < lesson[i]){ // 58% -> 100% 아... min 이 아니라 tmpMin이지!!!!!!!!!!!!!!
//			tmpMin = lesson[i];
//		}
//	}
//	bs();
//	printf("%lld",(tmpMin > result) ? tmpMin : result);
//	//printf("%lld",result);
//	return 0;
//}
// 8% 틀렸습니다. 
// 58% 틀렸습니다.
// 100% 틀렸습니다.
//9 3
//1 2 3 4 5 6 7 8 9

//7 6
//100 400 300 100 500 101 400

//7 7
//5 9 6 8 7 7 5

//8 7
//3 3 10 10 3 2 6 2

//7 7
//1 5 9 9 9 2 9