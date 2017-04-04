#include<iostream>
using namespace std;
int main(){
	int n;
	bool t =false;
	cin>>n;
	for(int i = 1 ; i <= n/2+1 ; i++){
		if(i*i==n){
			t = true;
		}
		if(i*i>n){
			break;
		}
	}
	printf("%s",(t)?"yes":"no");

	return 0;

}