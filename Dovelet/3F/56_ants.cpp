#include<cstdio>

int main(){
	int min, max;
	int len, n;
	int ant;
	min = max = 0;
	scanf("%d %d",&len, &n);
	for(int i = 0 ; i < n ; i++){
		// 2 6 7 
		scanf("%d", &ant);
		// 2> 6> 7>
		if(len/2 >= ant){
			if(max <= len - ant){
				max = len - ant;
			}
		}else if(len/2 < ant){
			if(max <= ant){
				max = ant;				
			}
		}

		if(len/2 <= ant){
			if(min <= len - ant){
				min = len - ant;
			}
		}else if(len/2 > ant){
			if(min <= ant){
				min = ant;
			}
		}
		//printf(" %d %d\n",min,max);
	}
	printf("%d %d\n",min,max);
	return 0;
}