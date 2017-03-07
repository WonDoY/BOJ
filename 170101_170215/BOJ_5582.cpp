// 5582
// ���� �κ� ���ڿ� CS
// string s > t , t�� s�� ����
// ���� [1,4000]
// 
// input 
// ���ڿ� A 
// ���ڿ� B 
// output
// �ι��ڿ��� ��� ���Ե� �κ� ���ڿ� �� ���� �� ���� ���̸� ����Ѵ�.

//a: ABRACADABRA
//b: ECADADABRBCRDARA
//4000, 4000 �̶�� �ϸ�... 
// strcmp �� �Ἥ == 0 �̶��.. ? 
//�׷� �ð��ʰ� �� �� ������ 
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 4002
using namespace std;
char a[MAX] = {0,};
char b[MAX] = {0,};
int table[MAX][MAX] = {0,};
int result = 0;
int cnt = 0;
void printTable(int alen, int blen){
	for(int ai = 1 ; ai <= alen ; ai++){
		for(int bi = 1 ; bi <= blen ; bi++){
			printf("%2d",table[ai][bi]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%s", a);
	scanf("%s", b);
	int alen = strlen(a);
	int blen = strlen(b);
	for(int ai = 1 ; ai <= alen ; ai++){
		for(int bi = 1 ; bi <= blen ; bi++){
			cnt = 0;
			if(a[ai-1]==b[bi-1]) cnt=1;
			if(cnt==1){
				table[ai][bi] = cnt + table[ai-1][bi-1];
			}
			result = max(result, table[ai][bi]);
		}
	}
	//printTable(alen,blen);
	printf("%d",result);
	return 0;
}