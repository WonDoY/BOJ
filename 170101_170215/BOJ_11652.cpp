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
//	sort(card,card+n); // ī�带 �Է¹޴´�. �׸��� �������� �����Ѵ�.
//
//	int selectIndex = 0; 
//	long long selectNumber = card[0];
//	dic[0].first = 0;
//	dic[0].second = card[0];
//
//	for(int i = 0 ; i < n ; i++){ // ������ ������ �� ���� counting �Ѵ�. 
//		if(selectNumber!=card[i]){ // ���� ������ ���� ī����ڰ� �ٸ��� ���� �ε����� �Ѿ ī��Ʈ�Ѵ�.
//			dic[++selectIndex].second = card[i];
//			dic[selectIndex].first = 0;
//			selectNumber = card[i];
//		}else{ // ���� ������ ���� ī����� ���ٸ� counting +1 �Ѵ�. 
//			dic[selectIndex].first+=1;
//		}
//	}
//	selectIndex++; // ���������� ���ͼ� +1 �Ѵ�. ������ ���� �Ѽ�-1 �̱⶧����
//	sort(dic,dic+selectIndex); // pair�� counting �� first �� �����Ѵ�. 
//
//	long long tmpMin = dic[selectIndex-1].second; // ... ���� ������ ���� counting�� ���� �Ǿ��ִ�.
//	for(int i = selectIndex-1 ; i >= 0 ; i--){ // ���� ���� ���� ã�´�. 
//		if(tmpMin > dic[i].second){ // ���� �ּҰ����� ������ ���� ��ü�Ѵ�. 
//			tmpMin = dic[i].second; 
//		}
//		if(i>=1){ // i ���� ũ�ų� ���ٸ� ������ ���Ͽ� ������ ���� ���� �����Ƿ� Ȯ���Ѵ�. 
//			if(dic[i].first != dic[i-1].first){
//				break;
//			}
//		}else{ // ��� counting �� ���� ���������� ���ٸ� ���Ѵ�. 
//			if(tmpMin > dic[i].second){
//				tmpMin = dic[i].second;
//			}
//		}
//	}
//	printf("%lld\n",tmpMin); // ������� ����Ѵ�. 
//	return 0;
//}
//
//// 27%... ���� Ʋ�ȴٰ� ���...
//// 100%.. ���� Ʋ�ȴٰ� ���..