#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void uni(int x,int y);
void check(int x,int y);
int find(int x);

int parent[1000000];

int main(){

	int N,M;
	int cal,a,b;

	fill(parent,parent+1000001,-1);

	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>cal>>a>>b;
		if(cal==0)uni(a,b);
		if(cal==1)check(a,b);
	}

}


void uni(int x,int y){

	int rx = find(x);
	int ry = find(y);

	if(rx==ry)return ;
	if(parent[rx]>parent[ry]){
		parent[ry]+=parent[rx];
		parent[rx]=ry;
	}
	else{
		parent[rx]+=parent[ry];
		parent[ry]=rx;
	} 
}

void check(int x,int y){
	if(find(x)==find(y))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int find(int x){

	//if(parent[x]<0) return x;
	//return find(parent[x]);

	while(parent[x]>=0)
		x=parent[x];
	return x;
} 