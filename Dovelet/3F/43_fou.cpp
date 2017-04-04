#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[3]={0,};
	int d;
	for(int i = 0 ; i < 3 ; i++){
		cin >> a[i];
	}
	sort(a,a+3);
	d=a[2]-a[1];
	if(d>a[1]-a[0]){
		d=a[1]-a[0];
	}
	for(int i = 0 ; i < 4 ; i++){
		if(a[0]+d*i!=a[i]){
			printf("%d",a[0]+d*i);
			break;
		}
	}
	return 0;
}