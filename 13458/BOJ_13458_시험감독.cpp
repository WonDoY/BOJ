#include<cstdio>
#include<vector>
using namespace std;

typedef long long lld;
typedef vector<lld> VI;

int main(){
	int n;
	scanf("%d",&n);
	VI test = VI(n);
	for(int i = 0 ; i < n ; i++){
		scanf("%lld", &test[i]);
	}
	lld a,b;
	scanf("%lld%lld",&a,&b);

	lld ans = 0;
	for(int i = 0 ; i < n ; i++){
		ans++;
		test[i] -= a;
		if(test[i] > 0){ // �ְ������� ���� ���ڸ�, �ΰ����� ������.
			if( (test[i]%b) > 0){ // �ΰ������� ��ġ���� +1 �ؾ��ϴ� ���
				ans += (test[i]/b) + 1;
			}else if( (test[i]%b) == 0){ // �ΰ����� ��ġ���� *n ���� �� ����
				ans += (test[i]/b); 
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
// 63% WA - lld?