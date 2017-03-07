// 1. 성적차이 내에
// 2. 이름 길이가 같다. 
// 깊은빡침........아 코드는 다 짰는데 결론적으로 int 형 초과하기때문에 노답임. 걍 앞으로 longlong 쓰자
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
		
		if( (right_flag - left_flag) <= lev){ // 등수차이가 작거나 같으며, 이름의 길이가 같은 애들
			result += ( name_board[nlen] -1 ); // 지 자신 빼고서
			//printf("equal\n");
		}else if(right_flag - left_flag > lev){ // 등수차이가 커지면 
			int tmplen = strlen( name[left_flag++] ); // left_flag 증가
			name_board[tmplen]--;
			//printf("less than\n");
			result += ( name_board[nlen] - 1 );
		}
		//printBoard();
	} // O(2N)
	printf("%lld",result);
	return 0;
}

