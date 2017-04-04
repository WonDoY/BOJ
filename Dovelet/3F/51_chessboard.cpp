#include<cstdio>

void solve(int input);

int main(){
	int input = 0;
	scanf("%d",&input);
	solve(input);
	return 0;
}

void solve(int input){
	int n = input;
	int res[2] = {0,0}; // res[0] res[1]

	int before = 1; 
	int after = 3;
	int result = 1;
	for(int i = 1 ; !(before <= n && n < after) ; i++){
		//printf("before : %d, after : %d\n", before, after);
		before = after;
		after = after + 2*(i+1);
		result++;
	}
	//printf("before : %d, after : %d\n", before, after);
	res[0] = result;
	res[1] = result;
	int temp = (after-before-1)/2;
	//printf("after - before - 1 / 2 ; %d\n", temp);
	//printf("n-before : %d\n",n-before);
	if(result%2){ // odd 3
		if(temp >= n-before){
			res[0] = result-(n-before);
			res[1] = result;
		}else if(temp < n-before){
			res[0] = result+1-((result+1)-(n-before-temp));
			res[1] = result+1;
		}
	}else if(!(result%2)){ 
		if(temp >= n-before){
			res[0] = result;
			res[1] = result-(n-before);
		}else if(temp < n-before){
			res[0] = result+1;
			res[1] = result+1-((result+1)-(n-before-temp));
		}
	}
	//printf("res : %d\n",result);
	/*if(before <= n && n <= after){

	}*/

	printf("%d %d\n", res[0], res[1]);
}