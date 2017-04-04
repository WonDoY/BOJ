#include<cstdio>
#define MAX 26
int l,c ;
bool out[MAX] = {0,};
void search(int arr[], int n, int s){
	if(n == l){
		int vow = 0, cns = 0;
		for(int i = 0 ; i < n ; i++){
			switch(arr[i]){
			case 'a'-'a':case 'e'-'a':case 'i'-'a':case 'o'-'a':case 'u'-'a':vow++; break;
			default: cns++; break;
			}
		}
		if(vow>0&&cns>1){
			for(int i = 0 ; i < n ; i++){
				printf("%c",arr[i]+'a');
			}
			printf("\n");
		}
		return;
	}
	else{ // 여기서 배열에 값을 넣어주면 되는데 어떻게 해야할지~ 모르겠다~
		for(int i = s ; i < MAX ; i++){
			if(out[i]){
				s = i;
				break;
			}
		}
		if(!out[s]){
			return ;
		}
		arr[n] = s;
		search(arr, n+1, s+1);
		search(arr, n, s+1);
	}
}
void solve(){
	int arr[15] = {0,};
	search(arr, 0, 0);
}
int main(){
	scanf("%d%d",&l,&c);
	char ch = 0;
	
	for(int i = 0 ; i < c ; ){
		scanf("%c",&ch);
		if('a'<= ch && ch <='z'){
			out[ch-'a'] = true;
			i++;
		}
	}
	solve();
	return 0;
}