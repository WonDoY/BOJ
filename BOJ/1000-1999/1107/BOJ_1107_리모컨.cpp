#include<cstdio>
#include<vector>
#include<queue>
#include<memory.h>
#include<utility>
#define make_pair(a,b) mp(a,b)
using namespace std;

typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<VI> VVI;

const int MAX = 1500000;
int gap = 10000000;
int goal;
int m;

VVI noButton;
int vmap[MAX];

struct info{
	int x; // channel
	int c; // count
	info(int xi, int ci):x(xi), c(ci){}
};

int min2(int a, int b){
	return (a<b)?a:b;
}

int main(){
	scanf("%d%d", &goal,&m);
	VB use = VB(10, true);
	VVI noButton = VVI(12, VI(0,0));
	for(int i = 0 ; i < m ; i++){
		int un;
		scanf("%d", &un);
		use[un]=false;
	}

	for(int i = 0 ; i < 10 ; i++){
		if(use[i]){
			noButton[1].push_back(i);
		}
	}

	memset( vmap, -1, sizeof(vmap) );

	// one button
	// two button
	// ...
	// n button -> min(Goal)
	VB chaLen = VB(20, false);
	chaLen[0] = true;
	queue<info> Q;
	Q.push(info(100,0));
	vmap[100] = 0;
	while(!Q.empty()){
		info here = Q.front(); Q.pop();

		int c = here.c; // button count
		int x = here.x; // channel

		if(x == goal) break;

		if(0 <= x){
			if(x-1 >= 0){
				if(vmap[x-1]==-1){ // 
					Q.push(info(x-1, c+1));
					vmap[x-1] = c+1;
				}
			}
			if(vmap[x+1]==-1){
				Q.push(info(x+1, c+1));
				vmap[x+1] = c+1;
			}
		}

		if(0 <= c && c < 10){ // c == 0 .... 
			if(chaLen[c+1] == false){
				chaLen[c+1] = true;

				if(c+1 == 1){
					for(auto iter = noButton[1].begin() ; iter != noButton[1].end() ; iter++){
						int channel = *iter;
						if(vmap[channel] == -1){
							vmap[channel] = c+1;
							Q.push(info(channel, c+1));
						}

						for(auto i2 = noButton[1].begin() ; i2 != noButton[1].end() ; i2++){
							if(channel*10 + (*i2) >= 10){
								noButton[2].push_back(channel*10 + (*i2));
							}
						}
					}
				}
				else if(1 < c+1 && c+1 < 7){ // 2 c -> 1 -
					for(auto iter = noButton[c+1].begin() ; iter != noButton[c+1].end() ; iter++){
						int channel = *iter;
						if(vmap[channel] == -1){
							vmap[channel] = c+1;
							Q.push(info(channel, c+1));
						}

						for(auto i2 = noButton[1].begin() ; i2 != noButton[1].end() ; i2++){
							noButton[c+2].push_back(channel*10 + (*i2));
						}
					}
				}

				// 1자리 일때 돌고
				// 2자리 일때 돌고
				// 3자리 일때 돌고

			}
		}
	}

	printf("%d", vmap[goal]);
	return 0;
}

// 37% WA


