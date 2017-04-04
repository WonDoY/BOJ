#include<cstdio>
#include<algorithm>
#define MAX 1000
using namespace std; 
int N;
int width;
int input[MAX];
int note[MAX][MAX];
pair<int,int> dp[MAX];
// 1. �̸��� ���̸� �ִ´�. 
// 2. ���� �� +1(����)�� �� �̸�
// 3. �̶� �� ���� ���� ������
// 4. �̸��� ������� �־����.
// ������ ���� �������� ����

// tc�� ������. 
// Full �� �ٿ� ��ä��� ���. 
// Not Full �� �ٿ� ��ä���� �ʴ� ���.
// �� ����� ���� 
// 1. Full - Not Full
// 2. Full - Full
// 3. NF - F
// 4. NF - NF
// ������ ä���ٸ�, ���� ���� ������ �����ϴ� �� ������ �ȴ�.
// ��ä���� ����� ���̺��
// ��ä���� �ʾ��� ��� ���̺��� �ʿ��ϴ�.

// pair<int,int>
//  first = (Full)    
// second = (NotFull) 

// F F F
// F N F
// F N N 
// F F N
// �׷��� ������ ���� �������� ����.
// 2���� ���� �߰� �ɰ��� ����

// F F / (F/N)
// F N / (F/N)
// N F / (F/N)
// N N / (F/N)....
// �� �� ���� �ּҸ� ����. 
// input[x...y] + (y-x (������ ������ ���� - 1 �̹Ƿ�)) <= width
// ä��� ��� ä���� �ʴ� ���.
void initTable(){
	for(int i = 0 ; i <= width ; i++){
		dp[i].first = dp[i].second = 0;
	}
}
int main(){
	scanf("%d %d",&N, &width);
	for(int i = 0 ; i < width ; i++) scanf("%d",&input[i]);

	return 0;
}