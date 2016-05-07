#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int mcnt, ncnt, cnt, t, data, idx;
	int x, y, sum, ans, temp;
	int n[100];

	cin >> t;
	while(t--)
	{
		ans = 0; cin >> ncnt >> mcnt; temp = mcnt; sum = 0 ;
		while(mcnt--)
		{
			cin >> x;			
			for(int i = 0 ; i < mcnt ; i++)	x *= 10;
			sum += x;
		}
		x= sum;
		mcnt = temp;
		sum = 0 ;
		while(mcnt--)
		{
			cin >> y;
			for(int i = 0 ; i < mcnt ; i++)	y *= 10;
			sum += y;
		}
		y = sum;
		mcnt = temp;

		temp = ncnt; cnt = 0;
		while(ncnt--) cin >> n[cnt++];
		ncnt = temp;
		cnt = 0 ;
		while( cnt < ncnt )
		{
			idx = 0;
			data = 0;
			sum = 0;
			temp = mcnt;
			while( mcnt-- )
			{
				data = n[(cnt + idx++)% ncnt];
				for(int i = 0 ; i < mcnt ; i++)	data *= 10;
				sum += data;
			}
			cnt++; mcnt = temp;

			if( y >= sum && sum >= x) ans++;			
		}
		printf("%d\n",ans);		
	}
	return 0;
}