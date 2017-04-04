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
	
	int flagL = 0; // ���� �÷���
	int flagR = legoNum-1; // ������ �÷��� 
	ll sum;
	while(flagL<flagR){
		sum = lego[flagL] + lego[flagR]; // ���� ���ؼ�  �־��� ���� �񱳸� �Ѵ�. 

		// �������� �����̹Ƿ� 
		// flagL�� ������Ű�� ���� ����.
		// flagR�� ���ҽ�Ű�� ���� ����.

		// �� == �־������� ������ ������ ���� ũ��.
		// �� < �־����� ���� �� �����Ƿ� �������� Left++
		// �� > �־����� ���� �� ũ�Ƿ� ���հ��� right--
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
	while(scanf("%lld",&need)==1){ // tc ������ �Է����� �־����Ƿ�, scanf �Է°����� ��ȯ
		boolResult = false; // ��� ���� �����ϴ��Ŀ� ���� �����Ǵ� boolResult ����
		scanf("%d",&legoNum); // lego ����
		need *= 10000000; // �Է¹��� x�� ���� ȯ���� ��Ŵ.
		for(int i = 0 ; i < legoNum ; i++) scanf("%lld",&lego[i]); // �Է��� ����.
		sort(lego,lego+legoNum); // �Է¹��� ���� ���� ��Ŵ. 
		slide(); // ������������ ���ĵ� ���� ������ 0.....n-1���� �����������ĵȰ��� Ž��

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


// ������ ������ �� �Ŵϱ� ���ĵ� ���� input���� �ְ�...
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
//	while (scanf("%d", &x) == 1) //�Է��� �ִٸ� scanf�� 1�� ����
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
