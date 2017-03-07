#include<cstdio>
#define LAN 10000
typedef long long ll;
int have;
ll need;
ll having[LAN];
// 2^31 - 1
ll maxLine;
ll minLine;
ll resultLine;
int condition(ll div){
	ll sum = 0;
	for(int i = 0 ; i < have ; i++){
		sum += having[i]/div;
		//printf("%lld\n",sum);
		if(need <= sum) return -1; // 바꾼게 need < sum -> need <= sum 인데 ...
	}
	//printf("	%lld\n",sum);
	if(need == sum) return 0;
	return 1;
}
// 값이 더 크면 div를 올림
void bs(){
	ll start = minLine;
	ll end = maxLine;
	ll mid;
	while(1){
		mid = (start+end)/2;
		//mid = ((start+end)/2.0-(start+end)/2 > 0)? (start+end)/2+1: (start+end)/2;
		//printf("<%lld [%lld] %lld> \n",start,mid,end);
		if(end < start)return;
		
		switch(condition(mid)){
		case -1:
			start = mid+1;
			resultLine = mid;
			break;
		case 0:
			resultLine = mid;
			return;
		case 1:
			end = mid-1;
			break;
		}
	}
}

int main(){
	minLine = 1;
	maxLine = 0;
	//printf("%lld\n",maxLine);
	scanf("%lld%d", &have, &need);
	for(int i = 0 ; i < have ; i++){
		scanf("%lld", &having[i]);
		if(maxLine < having[i]) maxLine = having[i]+1;
	}
	bs();
	printf("%lld\n",resultLine);

	return 0;
}
//4 11
//802
//743
//457
//539

//2 1000
//501
//502