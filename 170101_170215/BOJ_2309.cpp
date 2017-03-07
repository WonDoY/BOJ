#include<cstdio>
#include<algorithm>
#define MAX 10
int input[MAX] = {0,};
int res[8] = {0,};

void INPUT(){
	for(int i = 1 ; i < MAX ; i++){
		scanf("%d",&input[i]);
	}
	std::sort(input,input+10);
}

void RESULT(){
	for(int i = 1 ; i < 8 ; i++){
		printf("%d\n",input[res[i]]);
	}
}

bool resret = false;
void search(int resindex, int inputidx, int sum){ // res index 	
	if(sum==100 && resindex == 8){
		//RESULT();
		resret = true;
		return ;
	}
	if(sum>100 || resindex>=8){
		return;
	}
	if(resret){
		return ;
	}

	for(int i = inputidx ; i < MAX ; i++){
		if(resret) return ;
		res[resindex] = i;
		search(resindex+1, i+1, sum+input[i]);
		
		// 1 -> 2 
		// 2 -> 3
		// 3 -> 4
	}
}

void solve(){
	search(1, 1, 0);
}

int main(){
	INPUT();
	solve();
	RESULT();
	return 0;
}