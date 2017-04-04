#include<cstdio>
#define MAX 500001

int main(){
	//int tc ; scanf("%d",&tc);
	//while(tc--){
	char stack[MAX] = {0,};
	char string[MAX] = {0,};
	int stackIndex = -1;
	int n, k ; scanf("%d %d", &n,&k);
	scanf("%s",string);
	for(int i = 0 ; i < n ; i++){
		while(stackIndex>-1 && k!=0){ // 더 작으면 빼고 더 크면 내비둠 
			if(string[i]>stack[stackIndex]){
				stack[stackIndex--] = 0; // 지움
				k--;//k--
			}
			else{
				break;
			}
		}
		stack[++stackIndex] = string[i];
	}
	for(char v = '0' ; v <= '9' ; v++){ // 9
		for(int i = n-1 ; i >= 0 ; i--){ // n
			if(k==0)break;
			if(string[i] == v){
				k--;
				stack[i] = 0;
			}
		}
	}

	int tmpIndex = 0;
	for(int i = 0 ; i < n ; i++){
		if(stack[i]!=0) string[tmpIndex++] = stack[i];
	}
	string[tmpIndex] = 0;
	printf("%s",string);
	//char res[MAX] = {0,};
	/*for(int i = 0 ; i < n ; i++){
		if(stack[i]!=0) res[tmpIndex++] = stack[i];
	}
	
	printf("%s",res);*/
	//}

}
//7 3
//7654321

//6 2
//436436

//7 2
//3191123