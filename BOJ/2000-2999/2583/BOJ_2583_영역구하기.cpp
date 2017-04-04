#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

struct info{
	int r;
	int c;
	int count;
	info(int ir, int ic, int icnt) : r(ir), c(ic), count(icnt) {}
};

VVI imap;
VVI visited;

int dr[] = {1,-1,0,0};
int dc[] = {0,0, 1,-1};

int area[10000];

int main(){
	int row, col, rec; 
	int count = -1;
	scanf("%d %d %d", &row, &col, &rec);
	imap = VVI(row, VI(col, 0) );
	visited = VVI(row, VI(col, 0) );
	for(int i = 0 ; i < rec ; i++){
		int c1, r1, c2, r2;
		scanf("%d %d %d %d", &c1, &r2, &c2, &r1);
		r1 = row - r1;
		r2 = row - r2;

		for(int r = r1 ; r < r2 ; r++)
			for(int c = c1 ; c < c2 ; c++) imap[r][c] = 1;
			
		
	}

	for(int r = 0 ; r < row ; r++){
		for(int c = 0 ; c < col ; c++){
			queue<info> q;
			if(imap[r][c]!=1 && !visited[r][c]){
				q.push(info(r,c,1));
				visited[r][c] = true;
				count++;
			}
			while(!q.empty()){
				info here = q.front(); q.pop();

				for(int i = 0 ; i < 4 ; i++){
					int tr = here.r + dr[i];
					int tc = here.c + dc[i];
					if(0 <= tr && tr < row && 0 <=tc && tc < col){
						if(!visited[tr][tc] && imap[tr][tc] == 0){
							visited[tr][tc] = true;
							q.push(info(tr,tc,1));
						}
					}
				}

				area[count]++;
			}
		}
	}

	sort(area, area+count+1);
	if(count==-1) printf("%d\n", 0);
	else{
		printf("%d\n",count+1);
		for(int i = 0 ; i < count+1 ; i++){
			printf("%d ", area[i]);
		}
	}

	return 0;
}