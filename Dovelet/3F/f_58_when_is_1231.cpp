#include<cstdio>
enum day{sun, mon, tue, wed, thu, fri, sat};
typedef day D;
D date;
int main(){
	// ¿±≥‚æ∆¥‘ 365
	// 2 28¿œ
	// sun ~ sat 
	// 0 ~ 6
	int month, num;
	int day[7] = {0,}
		, sum = 0;
	scanf("%d %d",&month ,&num);
	for(int i = 0 ; i < num ; i++){
		scanf("%d",&day);
	}
	scanf("%d", &sum);
	int temp = 0;
	
	for(int i = 1 ; i <= 31 ; i++){
		temp = 0;
		for(int j = 0 ; j < 7 ; j++){
			temp += day[j] + i;
		}
		printf("%d\n",temp);
	}
	

	return 0;
}