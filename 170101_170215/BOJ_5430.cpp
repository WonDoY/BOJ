// 가장 중요한 거... 제한 범위를 잘 생각하자, 닫힌 구간, 열린 구간, 반열린 구간
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#define MAX 100001
#define IMAX 400001
using namespace std;
// AC
// R : reverse
// D : Delete
char command[MAX] = {0,};
char inChar[IMAX] = {0,};
int a[MAX] = {0,};
int main(){
	int tc;
	scanf("%d", &tc);
	for(int i = 0 ; i < tc ; i++){
		memset(command,0,MAX);
		memset(inChar,0,IMAX);
		cin >> command;
		int clen = strlen(command);

		int n; 
		scanf("%d", &n); // input num
		//printf("%d\n",n);

		scanf("%s",inChar); // list num		
		int leftflag = 0;
		int rightflag = n;

		//printf("clen : %d\n", clen);
		//printf("%d, %d\n", leftflag, rightflag);
		if(inChar[0]=='\n'){
			clen = 0;
		}
		else{
			inChar[0] = ',';
			inChar[strlen(inChar)-1] = ',';
			char* token = strtok(inChar, ",");
			int ti = 0;
			while(token != NULL){
				a[ti++] = atoi(token);
				token = strtok(NULL, ",");
			}
		}
		
		
		bool reverse = false;
		for(int comm = 0 ; comm < clen ; comm++){
			if(command[comm] == 'R'){
				reverse = !reverse;
			}else if(command[comm] == 'D'){
				if(!reverse){ // left
					leftflag++;
				}else if(reverse){
					rightflag--;
				}
			}
		}

		//printf("==	%d, %d\n", leftflag, rightflag);
		if(leftflag <= rightflag){
			printf("[");
			if(!reverse){
				for(int i = leftflag ; i < rightflag ; i++){
					printf("%d",a[i]);
					if(i!=rightflag-1) printf(",");
				}
			}else if(reverse){
				for(int i = rightflag-1 ; i >= leftflag ; i--){
					printf("%d",a[i]);
					if(i!=leftflag) printf(",");
				}
			}
			printf("]\n");			
		}else{
			printf("error\n");
		}

		//p
	}
	return 0;
}