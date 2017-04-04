#include<cstdio>
#include<algorithm>
#define MAX 1000000
using namespace std;
typedef long long ll;
ll need;
int legoNum;
ll lego[MAX];
ll result[2] = {0,};
bool boolResult = false;

void slide(){
	
	int flagL = 0; // 왼쪽 플레그
	int flagR = legoNum-1; // 오른쪽 플레그 
	ll sum;
	while(flagL<flagR){
		sum = lego[flagL] + lego[flagR]; // 합을 더해서  주어진 값과 비교를 한다. 

		// 오름차순 정렬이므로 
		// flagL을 증가시키면 총합 증가.
		// flagR을 감소시키면 총합 감소.

		// 합 == 주어진값이 같으면 무조건 제일 크다.
		// 합 < 주어진값 합이 더 작으므로 총합증가 Left++
		// 합 > 주어진값 합이 더 크므로 총합감소 right--
		if(sum == need){ 
			result[0] = lego[flagL];
			result[1] = lego[flagR];
			boolResult = true;
			return;
		}
		else if(sum < need) flagL++;
		else if(sum > need)	flagR--;
	}
}

int main(){
	while(scanf("%lld",&need)==1){ // tc 여러개 입력으로 주어지므로, scanf 입력갯수를 반환
		boolResult = false; // 결과 값이 존재하느냐에 따라서 결정되는 boolResult 변수
		scanf("%d",&legoNum); // lego 갯수
		need *= 10000000; // 입력받은 x에 단위 환산을 시킴.
		for(int i = 0 ; i < legoNum ; i++) scanf("%lld",&lego[i]); // 입력을 받음.
		sort(lego,lego+legoNum); // 입력받은 것을 정렬 시킴. 
		slide(); // 오름차순으로 정렬된 것을 가지고 0.....n-1까지 오름차순정렬된것을 탐색

		if(boolResult) printf("yes %lld %lld\n", result[0], result[1]);
		else printf("danger\n");
	}
	return 0;
}

//#include<cstdio>
//#include<cmath>
//
//#include<algorithm>
//#define MAX 1000000
//using namespace std;
//typedef long long ll;
//ll x;
//int n;
//ll L[MAX];
//ll R[2] = {0,};
//bool boolResult = false;
//void slide(){
//	boolResult = false;
//	int flagL = 0;
//	int flagR = n-1;
//	ll max = -1;
//	while(flagL<flagR){
//		ll sum = L[flagL] + L[flagR];
//		if(sum == x){
//			if(max < abs(L[flagL]-L[flagR])){
//				max = abs(L[flagL]-L[flagR]);
//				R[0] = L[flagL];
//				R[1] = L[flagR];
//				boolResult = true;
//				break;
//			}
//		}else if(sum < x) flagL++;
//		else if(sum > x) flagR--;
//		
//	}
//}
//
//int main(){
//	while(scanf("%lld",&x)==1){
//		scanf("%d",&n);
//		x*=10000000;
//		for(int i = 0 ; i < n ; i++) scanf("%lld",&L[i]);
//		sort(L,L+n);
//		slide();
//		if(boolResult) printf("yes %lld %lld", R[0], R[1]);
//		else printf("danger");
//	}
//	return 0;
//}


// 어차피 정렬을 할 거니까 정렬된 값을 input으로 넣고...
//
//#include    <cstdio>
//#include    <vector>
//#include    <algorithm>
//#pragma warning (disable : 4996)
//
//std::vector<int> parts;
//int bs(int num, int s, int e)
//{
//	int start = s, end = e;
//	int mid;
//	while (start <= end)
//	{
//		mid = (start + end) / 2;
//		if (parts[mid] == num)  return mid;
//		else if (parts[mid] < num)   start = mid + 1;
//		else end = mid - 1;
//	}
//	return -1;
//}
//
//int main()
//{
//	int x, n;
//	bool flg;
//
//	while (scanf("%d", &x) == 1) //입력이 있다면 scanf는 1을 리턴
//	{
//		x *= 10000000;
//		scanf("%d", &n);
//		int tmp;
//		for (int i = 1; i <= n; ++i)
//		{
//			scanf("%d", &tmp);
//			parts.push_back(tmp);
//		}
//		std::sort(parts.begin(), parts.end());
//		flg = false;
//		for (int i = 0; i < parts.size(); ++i)
//		{
//			int temp = bs(x - parts[i], i + 1, parts.size() - 1);
//			if (temp != -1)
//			{
//				flg = true;
//				printf("yes %d %d\n", parts[i], parts[temp]);
//				break;
//			}
//		}
//		if (!flg)
//			printf("danger\n");
//
//		parts.clear();
//	}
//}
//
//
