#include<stdio.h>

int main(){



	int n,m,k;
	int team = 100;
	scanf("%d %d %d", &n, &m, &k);
	//team = k; // ������ִ��� 	
	//// ������ ���� ������
	// ������ ���� ���߳� ��......
	//if(k==0 || team > m) team = m; // ���ڷθ���� �ִ�����
	//if(team > n/2) team = n/2; // ���ڷ� ������ִ�����
	team = (n+m-k)/3 ;
	if(team > m) team = m;
	if(team > n/2) team = n/2;

	printf("%d\n", team);

	return 0;
}
// tc
// 5 3 4 
// 1
// 2 1 1
// 0
// 5 3 6
// 2
// 3 3 6
// 1
// 10 4 14
// 4
// 10 4 11
// 3