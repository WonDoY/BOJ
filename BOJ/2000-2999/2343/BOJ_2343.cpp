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
//// ������ ������ �ٲ�� �ȵȴ�.
//// ��, i�� ������ j�� ������ ���� ��緹�̿� ��ȭ�Ϸ���
//// i�� j ������ ��� ������ ���� ��緹�̿� ��ȭ�ؾ���.
//
//// ��緹���� ������ ������ ���̷��� �Ѵ�. 
//// m���� ��緹�̿� ��� ������ �������� �Ѵ�. 
//// ������ ���̰� �д����� �־�����.
//
//// ������ ��緹�� ũ���� �ּҸ� ����.
//
//// 1. ������ �ٲ�� �ȵȴ�.
//// ��緹���� ������ �־�����.
//// ��緹���� ũ��� m���� �����ϴ�. 
//// (  ) (  ) (  ) �� ��緹�̿� ���� �ð��� �ִ��̸� �ּҸ� ���Ͽ���.
//
//// lesson �� ���� �� ����� result ������ ���ų� ���� ����̴�. if(lessonAvg <= result) return true;
//// �˻��� �ϸ� ��ȸ���� ��, lessonAvg <= Another lessons <= result->Max lessons
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
//		// 1. ���� ������ mid �� (�ּҰ�) ���� ũ�� ���� ���� �Ѿ.
//		// 2. ���� ������ mid �� (�ּҰ�) ���� �۰ų� ���ٸ� ����.
//		for(int i = 0 ; i < n ; i++){
//			sum += lesson[i];
//			if(mid < sum){ // ���� ���� ������ mid ��緹�� ���̺��� �ʰ��ϸ� �ڸ��� count
//				bluerayCount++;
//				sum = lesson[i]; // lesson[i]�� ���ؼ� �ʰ��߱� ������ �⺻���� lesson[i]�� �Ѵ�. 
//			}
//		}
//
//		if(bluerayCount > blue){ // ������ ������ ��緹�� ���̸� �÷�����. -> ���� ����
//			start = mid+1;
//		}else if(bluerayCount < blue){ // ������ ������ ��緹�� ���̸� �ٿ����� -> ���� �ø�.
//			end = mid-1;
//			result = mid;
//		}else if(bluerayCount == blue){ //8%->58% ������ ������ �����ϰ� ���̸� �ٿ���. �� ���� ���̿��� �Ǵ��� Ȯ��.
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
// 8% Ʋ�Ƚ��ϴ�. 
// 58% Ʋ�Ƚ��ϴ�.
// 100% Ʋ�Ƚ��ϴ�.
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
//// ������ ������ �ٲ�� �ȵȴ�.
//// ��, i�� ������ j�� ������ ���� ��緹�̿� ��ȭ�Ϸ���
//// i�� j ������ ��� ������ ���� ��緹�̿� ��ȭ�ؾ���.
//
//// ��緹���� ������ ������ ���̷��� �Ѵ�. 
//// m���� ��緹�̿� ��� ������ �������� �Ѵ�. 
//// ������ ���̰� �д����� �־�����.
//
//// ������ ��緹�� ũ���� �ּҸ� ����.
//
//// 1. ������ �ٲ�� �ȵȴ�.
//// ��緹���� ������ �־�����.
//// ��緹���� ũ��� m���� �����ϴ�. 
//// (  ) (  ) (  ) �� ��緹�̿� ���� �ð��� �ִ��̸� �ּҸ� ���Ͽ���.
//
//// lesson �� ���� �� ����� result ������ ���ų� ���� ����̴�. if(lessonAvg <= result) return true;
//// �˻��� �ϸ� ��ȸ���� ��, lessonAvg <= Another lessons <= result->Max lessons
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
//		// 1. ���� ������ mid �� (�ּҰ�) ���� ũ�� ���� ���� �Ѿ.
//		// 2. ���� ������ mid �� (�ּҰ�) ���� �۰ų� ���ٸ� ����.
//		for(int i = 0 ; i < n ; i++){
//			sum += lesson[i];
//			if(mid < sum){ // ���� ���� ������ mid ��緹�� ���̺��� �ʰ��ϸ� �ڸ��� count
//				//printf("%lld ",sum-lesson[i]);
//				bluerayCount++;
//				sum = lesson[i]; // lesson[i]�� ���ؼ� �ʰ��߱� ������ �⺻���� lesson[i]�� �Ѵ�. 
//			}
//			//else if(mid == sum){ // ���� ���� mid ��緹�� ���̿� ������ sum�� 0���� �ʱ�ȭ count++;
//			//	//printf("%lld ",sum);
//			//	bluerayCount++;
//			//	sum = 0;
//			//}
//			//// else if(mid > sum) ���� ���� �ش���� ����.
//			//if(sum > 0 && i==n-1){ 
//			//	//printf("%lld ",sum);
//			//	bluerayCount++;
//			//}
//		}
//		//printf("\n");
//		//printf("	%lld count : %lld\n",mid , bluerayCount);
//
//		if(bluerayCount > blue){ // ������ ������ ��緹�� ���̸� �÷�����. -> ���� ����
//			start = mid+1;
//		}else if(bluerayCount < blue){ // ������ ������ ��緹�� ���̸� �ٿ����� -> ���� �ø�.
//			end = mid;
//		}else if(bluerayCount == blue){ //8%->58% ������ ������ �����ϰ� ���̸� �ٿ���. �� ���� ���̿��� �Ǵ��� Ȯ��.
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
//	max = 0x0000000fffffffff; //0%->8% ��.. �̰ų� �� 10000���� �����߳� ������ ���̴� �� ������ ���̰� 10000����... 
//	//printf("%lld",max);
//	ll tmpMin = 0;
//	scanf("%lld%lld",&n,&blue);
//	for(int i = 0 ; i < n ; i++){
//		scanf("%lld", &lesson[i]);
//		if(tmpMin < lesson[i]){ // 58% -> 100% ��... min �� �ƴ϶� tmpMin����!!!!!!!!!!!!!!
//			tmpMin = lesson[i];
//		}
//	}
//	bs();
//	printf("%lld",(tmpMin > result) ? tmpMin : result);
//	//printf("%lld",result);
//	return 0;
//}
// 8% Ʋ�Ƚ��ϴ�. 
// 58% Ʋ�Ƚ��ϴ�.
// 100% Ʋ�Ƚ��ϴ�.
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