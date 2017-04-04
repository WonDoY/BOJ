#include<cstdio>
#include<algorithm>
#define MAX 1000001
using namespace std;
typedef long long ll;
ll a[MAX] = {0,};
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	int c = 1;
	int m = 0;
	ll r = 0;
	for(int i = 0 ; i < n ; i++){
		if(a[i]==a[i+1]){
			c++;
		}else{
			c = 1;
		}
		if(m < c){
			r = a[i];
			m = c;
		}
	}
	printf("%lld",r);
	return 0;
}
//#include<cstdio>
//#include<algorithm>
//#define MAX 2000000
//using namespace std;
//long long card[MAX] = {0,};
//pair<int, long long> dic[MAX];
//int main(){
//
//	int n; scanf("%d", &n);
//	for(int i = 0 ; i < n ; i++) scanf("%lld",&card[i]);
//	sort(card,card+n); // 카드를 입력받는다. 그리고 오름차순 정렬한다.
//
//	int selectIndex = 0; 
//	long long selectNumber = card[0];
//	dic[0].first = 0;
//	dic[0].second = card[0];
//
//	for(int i = 0 ; i < n ; i++){ // 정렬한 것으로 각 수를 counting 한다. 
//		if(selectNumber!=card[i]){ // 현재 선택한 수와 카드숫자가 다르면 다음 인덱스로 넘어가 카운트한다.
//			dic[++selectIndex].second = card[i];
//			dic[selectIndex].first = 0;
//			selectNumber = card[i];
//		}else{ // 현재 선택한 수와 카드수가 같다면 counting +1 한다. 
//			dic[selectIndex].first+=1;
//		}
//	}
//	selectIndex++; // 마지막으로 나와서 +1 한다. 세어진 것이 총수-1 이기때문에
//	sort(dic,dic+selectIndex); // pair를 counting 된 first 로 정렬한다. 
//
//	long long tmpMin = dic[selectIndex-1].second; // ... 가장 마지막 것이 counting이 많이 되어있다.
//	for(int i = selectIndex-1 ; i >= 0 ; i--){ // 가장 작은 값을 찾는다. 
//		if(tmpMin > dic[i].second){ // 현재 최소값보다 작으면 값을 교체한다. 
//			tmpMin = dic[i].second; 
//		}
//		if(i>=1){ // i 보다 크거나 같다면 이전과 비교하여 루프를 나갈 것이 있으므로 확인한다. 
//			if(dic[i].first != dic[i-1].first){
//				break;
//			}
//		}else{ // 모든 counting 된 것이 마지막까지 같다면 비교한다. 
//			if(tmpMin > dic[i].second){
//				tmpMin = dic[i].second;
//			}
//		}
//	}
//	printf("%lld\n",tmpMin); // 결과값을 출력한다. 
//	return 0;
//}
//
//// 27%... 에서 틀렸다고 뜬다...
//// 100%.. 에서 틀렸다고 뜬다..