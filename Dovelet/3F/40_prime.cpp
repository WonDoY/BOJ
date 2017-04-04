#include<iostream>
using namespace std;

int main(){
	int n ;
	bool t = false;
	cin >> n;
	for(int i = 2 ; i < n ;i++){
		if(!(n%i)){
			t = true;
		}
	}
	printf("%s", (t)?"not prime":"prime");
	return 0;
}