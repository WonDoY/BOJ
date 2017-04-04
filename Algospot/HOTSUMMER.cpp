#include<iostream>
using namespace std;

int main()
{
	int t , res;
	
	cin >> t;
	while(t--)
	{
		res = 0;
		int sum = 0;
		cin >> res;
		int use[9] = {0,};
		for(int i = 0 ; i < 9 ; i++)
		{
			cin >> use[i];
			sum += use[i];
		}
		if(sum <= res) cout << "YES" << endl;
		else cout << "NO" << endl;

	}
	return 0;
}