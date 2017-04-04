#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll result = 0;
ll start[10][2];
ll finish[5][2];
int N, startCount = 0;
ll x, y;
ll dir [5][2] = { {1,0},
{-1,0},
{0,1},
{0,-1},
{0,0} };

int main(){
	scanf("%d", &N);
	scanf("%lld %lld", &start[0][0], &start[0][1]);

	for(int running = 0 ; running < N ; running++){
		scanf("%lld %lld",&x, &y);
		ll minComp = 0x7fffffffffffffff;
		for(int fi = 0 ; fi < 5 ; fi++){
			finish[fi][0] = x + dir[fi][0];
			finish[fi][1] = y + dir[fi][1];
			for(int si = 0 ; si <= startCount ; si++){
				ll tmpMin = abs(finish[fi][0] - start[si][0]) + abs(finish[fi][1] - start[si][1]);
				if(tmpMin < minComp) minComp = tmpMin;
			}
		}
		int tmpCnt = -1;
		ll tmpStart[10][2] = {0,};
		for(int fi = 0 ; fi < 5 ; fi++){
			for(int si = 0 ; si <= startCount ; si++){
				ll tmpMin = abs(finish[fi][0] - start[si][0]) + abs(finish[fi][1] - start[si][1]);
				if(tmpMin == minComp){
					if(tmpCnt>-1 
					&& tmpStart[tmpCnt-1][0] != finish[fi][0]
					&& tmpStart[tmpCnt-1][1] != finish[fi][1])
					{
						//printf("not equal\n");
						tmpStart[++tmpCnt][0] = finish[fi][0];
						tmpStart[tmpCnt][1] = finish[fi][1];
					}
					else if(tmpCnt<0){
						tmpStart[++tmpCnt][0] = finish[fi][0];
						tmpStart[tmpCnt][1] = finish[fi][1];
					}
				}
			}
		}
		startCount = tmpCnt;
		//printf("=	=	=	=	=	=\n min Compare : %lld\n",minComp);
		for(int si = 0 ; si <= tmpCnt ; si++){
			start[si][0] = tmpStart[si][0];
			start[si][1] = tmpStart[si][1];
			//printf("%lld %lld\n",tmpStart[si][0], tmpStart[si][1]);
		}
		result += minComp;

	}
	printf("%lld\n", result);
	return 0;
}