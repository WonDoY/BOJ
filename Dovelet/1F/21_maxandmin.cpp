#include<cstdio>
#include<iostream>
#define MIN(a,b) (a>b)?b:a
#define MAX(a,b) (a<b)?b:a
using namespace std;
int x,y;
int main(){	
	//scanf("%d%d",&x,&y);		
	cin>>x>>y;
	x =MAX(MIN(x,y),x);
	cout<<x;
	//printf("%d",);
	return 0;
}