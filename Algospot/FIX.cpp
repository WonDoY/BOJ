#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		int A[20] = {0,};
		int sum = 0;
		int tt;
		cin >> tt;
		int idx = 0;
		while(tt--)
		{
			cin >> A[idx] ; // 11 /  12ÀÌ¶ף¸י
			
			if(idx+1 == A[idx++]) sum++;
		}
		cout << sum << endl;
	}
}