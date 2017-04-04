#include<iostream>
#include<cstdio>
using namespace std;

int play(int cs, int ptos)
{
	if(cs > ptos) return 0;
	else if(cs == ptos) return 4;
	else if(cs < ptos)
	{
		return ptos - cs + 4;
	}
}
int main()
{
	int t;
	cin >> t;

	int cs, ptos;
	while(t--)
	{
		cin >> cs >> ptos;
		cout << play(cs, ptos) << endl;
	}
	return 0;
}