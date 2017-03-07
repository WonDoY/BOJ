#include<cstdio>
#include<algorithm>
#define MAX 201
using namespace std;
// N
// 1~N # of student 
//
// <<e.g>> ~ 3 7 5 2 6 1 4
// 0 : 3 7 5 2 6 1 4
// 1 : 3 7(4)5 2 6 1 
// 2 : 3 4 5 2 6 1(7)
// 3 :(1)3 4 5 2 6 7
// 4 : 1(2)3 4 5 6 7
// output min(# of move) 
// �Ű��� ���� ���� �ֳ� 
// ��... 

// 1 2 3 4 5 6 7 �� ����� ���ؼ� �� ���� �� ���� �Ѵ�. ���߿� �ű�� ���� �ּ�.
// 3 7 5 2 6 1 4 �� input ���� �־�����.
//
// 2 5 2 2 1 5 3 ���� �ڱ� ��ġ���� �Ÿ� 
// TC 1. ���� �� �� ���� �Űܺ���?
//  1 3 7 5 2 6 4
//> 0 1 4 1 3 0 3
//  1 3 5 2 6 4 7
//> 0 1 2 3 1 2 0
//  1 2 3 5 6 4 7
//> 0 0 0 1 1 2 0
//  1 2 3 4 5 6 7
//> 0 0 0 0 0 0 0
// ����� �� 4���� �ű�� �ߴٸ�.
// ��...

// �׷��� ����� �ϸ� ������ ���������ʰ� �׶� �׶� ��ġ�� �ű�� ���̱⿡
// �߸��� ���......�ΰͰ���..

// �� ��쿡�� �˾Ƽ� �ֵ��� ���� ������ ������ �ȴ´�. 
// �ٵ� �ֵ��� ���� ��� ������ �´� ����!�� ���´�.��� ���̵ǰ�,
// �׷��Ƿ� 9�������� �����ϴ�....���� �� ���� �� ������ ����...
// 


int N ; // N [2,200]
int result = 0;
int table[MAX][2] = {0,};
void printTable(){
	printf("\n	Table Result %3d\n",result);
	for(int i = 0 ; i <= N ; i++) printf("%2d", table[i][0]);
	printf("\n");
	for(int i = 0 ; i <= N ; i++) printf("%2d", table[i][1]);
	printf("\n");
	//for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][2]);
	//printf("\n");
}
int main(){
	scanf("%d",&N);
	int maxcnt = 1;
	
	for(int i = 0 ; i < N ; i++){
		scanf("%d",&table[i][0]);
		int cnt = 1;
		for(int j = i-1 ; j >= 0 ; j--){ // ������ Ž��
			if( table[j][0] < table[i][0] ){ // ���� �� ���� ���� ���� ���� �� 
				if(cnt <  table[j][1]+1) cnt = table[j][1]+1; // �׶� ī��Ʈ �Ȱ� �� ���ų� ���ٸ� �ش� ī��Ʈ+1�� �ٲ�.
			}
			else if( table[j][0] == table[i][0] ){				
				if(cnt < table[j][1]) maxcnt = table[j][1];
			}
		}
		table[i][1] = cnt;
		//printTable();
		maxcnt = max(maxcnt,table[i][1]);
	}
	printf("%d",N-maxcnt);
	return 0;
}
//void printTable(){
//	printf("\n	Table Result %3d\n",result);
//	for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][0]);
//	printf("\n");
//	for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][1]);
//	printf("\n");
//	for(int i = 1 ; i <= N ; i++) printf("%2d", table[i][2]);
//	printf("\n");
//}
//int main(){
//	scanf("%d", &N);
//	for(int i = 1 ; i <= N ; i++){
//		scanf("%d", &table[i][1]); // �� �Է�
//		table[i][0] = i; // ������� �ִ´�. 
//	}
//	// ��ȸ�� ���� �����Ѵ�. 
//	while(1){
//		bool seq = false;
//		int max = 0;
//		int maxIdx = 0;
//		for(int i = 1 ; i <= N ; i++){
//			table[i][2] = abs(table[i][1]-table[i][0]);
//			if(max <= table[i][2]){
//				max = table[i][2];
//				maxIdx = i;
//			}
//		} 
//		// ��ȸ�ؼ� ���� �Ÿ��� �� ���� �ٲ��ش�. 
//		//���࿡ ��� ���� ���ٸ� ���� ���� ���� ���� �ε����� �ٲ۴�.
//		printTable();
//		if(max==0) seq = true;
//		else{
//			result++;
//			printf("moving....%d",table[maxIdx][1]);
//			int tmp = table[maxIdx][1];
//			if(table[maxIdx][1] < maxIdx){
//				//[1].... maxIdx
// 				for(int i = maxIdx ; i > tmp ; i--){
//					swap(table[i][1],table[i-1][1]);
//				}
//			}else if(table[maxIdx][1] > maxIdx){
//				// maxIdx..... [1]
//				for(int i = maxIdx ; i < tmp ; i++){
//					swap(table[i][1],table[i+1][1]);
//				}
//			}else{
//				printf("Need Debug..\n");
//			}
//			
//		}
//		if(seq) break; // �̰� �����൵ �Ǳ��ϰڴ�.
//
//	}
//	
//	return 0;
//}