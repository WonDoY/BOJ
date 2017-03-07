#include<cstdio>
#define MAX 10000
int res[MAX] = {0,1,0,};
int main(){
	int tc = 0;
	int input = 0;
	int temp = 2;
	int interval = 0;
	int cnt = 0;
	scanf("%d", &tc);
	for(int i = 2, temp = 2; i < 1010 ;i++, temp=i){
		interval = temp;
		if(!res[temp]){ // 0
			//prime number			
			temp+=interval;
		}
		while(temp<2000){			
			// prime number is not
				res[temp] = 1;
				temp += interval;
			
		}
	}
	//for(int i = 1 ; i < 100 ; i++){
	//	printf("%d : %d \n",i,res[i]);
	//}
	for(int i = 0 ; i < tc ; i++){
		scanf("%d", &input);
		if(!res[input]){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}