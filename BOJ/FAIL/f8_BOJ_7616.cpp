#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 11111

using namespace std;
const int INF = 0x00FFFFFF;
int caseCount;
bool impossible;
int numOfPeople; // ~[1,100]
int numOfIntersection; // ~[2,5000]
int flow[MAX][MAX];
int capacity[MAX][MAX];
int parent[MAX];
int node[MAX];
queue<int> Q;
vector< vector<int> > graph; // 인접리스트로 연결표시

void printResult(); // 결과값 출력
void init(); // 매 tc 시 변수들 초기화
void addEdge(int start, int end); // 간선추가
bool isPath(int source, int sink); // source 1 부터 sink 2 까지

int main(){
	while(1){
		init();
		scanf("%d %d ", &numOfPeople, &numOfIntersection);
		if(numOfPeople + numOfIntersection == 0) break;

		graph = vector< vector<int> >(2*numOfIntersection+1);
		for(int start = 0 ; start < numOfIntersection ; start++){
			graph[2*start].push_back(2*start+1);
			capacity[2*start][2*start+1] = 1;
			while(1){
				char spaceOrEnter = 0;
				int next = 0;
				scanf("%d%c", &next, &spaceOrEnter);
				addEdge(2*start+1, 2*(next-1));
				if(spaceOrEnter == '\n') break;
			}
		} // test case input

		int source = 1;
		int sink = 2;
		memset(parent, -1, sizeof(parent) );
		for(int people = 1 ; people <= numOfPeople ; people++){
			if( !isPath(source, sink) ){
				impossible = true;
				break;
			}
		}

		printResult();
	}
	return 0;
}



bool isPath(int source, int sink){
	bool ret = false;

	Q.push(source);
	int dist[MAX];
	bool visited[MAX];
	memset(visited, false, sizeof(visited) );
	for(int i = 0 ; i < MAX ; i++) dist[i] = INF;
	
	int here = source;
	parent[here] = -1;
	dist[here] = 0;
	while(true){

		if(here == 2) break;
		int next = -1;
		visited[here] = true;

		for(int there = 0 ; there < 2*numOfIntersection+1 ; there++){
			if(capacity[here][there] - flow[here][there] > 0 &&
				dist[there] > dist[here] + 1){
					dist[there] = dist[here] + 1;
					parent[there] = here;
			}

			if(!visited[there] && dist[there] < INF &&
				(next == -1 || dist[there] < dist[next]) ){
					next = there;
			}
		} 
		if(next == -1) return false;
		here = next;
	}

	for(int p = sink ; p != source ; p = parent[p]){
		if(parent[p] == -1){ // 유량을 sink까지 흘려보내지 못했다면 false
			return ret;  
		}
		else{ // sink까지 흘려보냈다면
			flow[parent[p]][p] += 1; 
			flow[p][parent[p]] -= 1; 
		}
	}

	return ret = true; // sink까지 성공적으로 흘려보냈다.
	// 이 과정이 성공적으로 끝까지 되면 
}

void addEdge(int start, int end){
	if(start == end) return ;

	if(capacity[start][end] == 0 && capacity[end][start] == 0){
		graph[start].push_back(end);
		capacity[start][end] = 1;
	}

	return ;
}

void init(){
	impossible = false;
	numOfPeople = 0;
	numOfIntersection = 0;
	memset(flow, 0, sizeof(flow) );
	memset(capacity, 0, sizeof(capacity) );
	memset(node, 0 , sizeof(node) );
	return ;
}

void printResult(){
	printf("Case %d:\n", ++caseCount);
	if(impossible){
		printf("impossible\n");
	}
	else if(!impossible){ // 가능하면
		for(int z = 0; z < 2*numOfIntersection + 1 ; z++){
			if(flow[1][z]==1){
				printf("1 %d", z/2 + 1);
				int here = z;
				while(1){
					if(here == 2) break;
					for(int there = 0 ; there < 2*numOfIntersection+1 ; there++){
						if(flow[here][there] == 1){// && (flow[here][0] > 0 || here == 1)){
							if(there % 2 == 0){
								printf(" %d", (there/2) + 1);
							}
							here = there;
							break;
						}
					}
				}
				puts("");
			}
		}
	}
	puts("");

	return ;
}
// 25% Runtime Error
// 25%.. WA
// WA 
//3 6
//3 4 5 6
//3 4 5 6
//1 2 4
//1 2 3 5
//1 2 4 6
//1 2 5
//0 0
//
//3 6
//3 4 5 6
//3 4 5 6
//1 2 4
//1 2 3 5
//1 2 4 6
//1 2 5
//10 2
//2
//1
//3 7
//3 4 6 7
//5 6 7
//1
//1 5
//4 2
//1 2
//1 2
//4 13
//3 4 5 6
//9 10 11 12
//1 7 13
//1 7
//1 6 8
//1 5 9
//3 4 10 12
//5 11
//2 6 11
//2 7
//2 8 9
//2 7
//2 3
//3 5
//3 4 5
//3 4 5
//1 2
//1 2
//1 2
//4 5
//3 4 5
//3 4 5
//1 2
//1 2
//1 2
//3 12
//3 4 5 6
//9 10 11 12
//1 7
//1 7
//1 6 8
//1 5 9
//3 4 10 12
//5 11
//2 6 11
//2 7
//2 8 9
//2 7
//2 7
//3 4 5
//5 7
//1 5 7
//1
//1 2 3
//7
//2 3 6
//2 7
//3 4
//5 7
//1 5 7
//1 5
//2 3 4
//7
//2 3 6
//0 0