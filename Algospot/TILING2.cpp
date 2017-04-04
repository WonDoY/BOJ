#include<iostream>
#include<cstdio>
using namespace std;

//int tiling(int t)
//{
//	if(t == 1) return 1;
//	else if(t == 2) return 2;
//	else return tiling(t-1) + tiling(t-2);
//}
int tiling2(int t)
{
	int n_2, n_1,n;
	n_2 = 1;
	n_1 = 2;
	n = n_1 + n_2;
	int count = 3;
	if(t == 1) return 1;
	else if(t == 2) return 2;
	else
	{
		while(count < t)
		{
			count++;
			n_2 = n_1;
			n_1 = n;
			n = n_2 + n_1;
			n = (n%1000000007);
		}
		return n;
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int tt;
		cin >> tt;

		cout << tiling2(tt) << endl;
	}
}