#include<cstdio>
#include<iostream>

int main(){
	int a,b,c,d;
	int res;
	//scanf("%d%d%d%d",&a,&b,&c,&d);
	std::cin>>a>>b>>c>>d;
	// a < b
	// c <= b + d
	res =-(b-a-c);
	//printf("%d",res);
	std::cout<<res;
	return 0;
}

