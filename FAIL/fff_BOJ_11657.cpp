#include <iostream>
#include <cmath>
using namespace std;
int dist[501][501];   
int result[501];         //�ּ� ��� �� �ֽ�ȭ
int main(){

	int N,M;
	int A,B,C;

	scanf("%d %d",&N,&M);


	for(int i = 0 ; i <= N ; i++){
		for(int j = 0 ; j<=N ; j++){
			if(i==j){
				dist[i][j]=0;
			}
			else{
				dist[i][j]=10000000;
			}
		}
	}

	for(int i=0;i<M;i++){ 
		scanf("%d %d %d",&A,&B,&C);
		dist[A][B] = min(C, dist[A][B]);
	}

	for(int i=1;i<=N;i++){
		result[i] = dist[1][i];         //�ʱ� ����
	}



	while(1){   //��ȭ ������ ���� �ݺ� / ���� ����Ŭ->-1���
		int count=0;
		for(int k = 1 ; k <= N ; k++){
			for(int i = 1 ; i <= N ; i++){
				if(result[k] > result[i]+dist[i][k]){
					result[k] = result[i]+dist[i][k];
				}
				else{
					count++; 
				}
			}
		}
		if(count==N*N) break;      //�� �̻� result[]�� ��ȭ�� ���� ���-> Ž�� ����
		if(result[1]<0){cout<<-1<<endl; return 0;}   //���� ����Ŭ ����
	}
	for(int i=2;i<=N;i++){
		if(result[i]==10000000){
			printf("-1\n");
		}
		else{
			printf("%d\n",result[i]);
		}
	}


	return 0;
}