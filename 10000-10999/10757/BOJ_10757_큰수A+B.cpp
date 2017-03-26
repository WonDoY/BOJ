#include<cstdio>
#include<cstring>
using namespace std;

const int MAX = 20000;
char A[MAX];
char B[MAX];
char temp[MAX];
char C[MAX];

void operation(char* aa, char* bb){
	int A_len = strlen(aa);
	int B_len = strlen(bb);
	int maxlen = (A_len > B_len) ? A_len : B_len ;

	B_len--;
	int allcarry = 0;
	for(int i = maxlen-1 ; i >= 0 ; i--){
		int carry = 0;

		if(B_len >= 0){
			if(aa[i] + bb[B_len] > '0'+'9') carry++; 
		}else{ // Carry calculate 
			if(aa[i] > '9') carry++;
		}

		if(B_len >= 0){
			if(carry){
				C[i] = aa[i] + bb[B_len]- 2*'0' -10 + '0'; // 57 + 57 = 18 
				if(i-1 >= 0) aa[i-1]++;
				else allcarry = 1;
			}
			else if(!carry) C[i] = aa[i] + bb[B_len]-'0';

			B_len--;
		}else if(B_len < 0){


			if(i==0 && aa[i] > '9'){
				C[i] = aa[i] - 10;
				allcarry = 1;
			}else{
				if(carry){
					C[i] = aa[i] - 10;
					aa[i-1]++;
				}else if(!carry){
					C[i] = aa[i];
				}
			}
		}


		if(i==0 && allcarry == 1){
			for(int i = maxlen ; i > 0 ; i--) C[i] = C[i-1];
			C[0] = '1';
		}

	}
	printf("%s",C);
	return ;
}

int main(){
	scanf("%s %s",&A, &B);
	int A_len = strlen(A);
	int B_len = strlen(B);

	if(A_len > B_len){
		operation(A,B);
	}else{
		operation(B,A);
	}
	return 0;
}