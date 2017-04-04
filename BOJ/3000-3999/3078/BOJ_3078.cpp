// 1. �������� ����
// 2. �̸� ���̰� ����. 
// ������ħ........�� �ڵ�� �� ®�µ� ��������� int �� �ʰ��ϱ⶧���� �����. �� ������ longlong ����
#include<cstdio>
#include<cstring>
#define MAX 300010
typedef long long ll;
ll name_board[30] = {0,};

int left_flag = 0;
int right_flag = 0;
char name[MAX][30] = {0,};
int stu, lev;
void printBoard(){
	for(int i = 1 ; i < 21 ; i++){
		printf("%3lld",name_board[i] );
	}
	printf("\n");
}
int main(){
	
	ll result = 0;
	scanf("%d %d",&stu, &lev);

	for(int i = 0 ; i < stu ; i++, right_flag++){
		scanf("%s", name[i]);

		int nlen = strlen(name[i]);
		name_board[nlen]++; 
		
		if( (right_flag - left_flag) <= lev){ // ������̰� �۰ų� ������, �̸��� ���̰� ���� �ֵ�
			result += ( name_board[nlen] -1 ); // �� �ڽ� ����
			//printf("equal\n");
		}else if(right_flag - left_flag > lev){ // ������̰� Ŀ���� 
			int tmplen = strlen( name[left_flag++] ); // left_flag ����
			name_board[tmplen]--;
			//printf("less than\n");
			result += ( name_board[nlen] - 1 );
		}
		//printBoard();
	} // O(2N)
	printf("%lld",result);
	return 0;
}

