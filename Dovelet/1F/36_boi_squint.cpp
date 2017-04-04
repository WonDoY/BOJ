#include<cstdio>
#include<cmath>
int main(){
	unsigned long long n, tmpa, tmpb, tmp;
	scanf("%llu",&n);
	tmpa = 0;
	tmpb = 3037000500;
	while(1){
		tmp = (tmpa+tmpb)/2;
		if(tmp*tmp > n) tmpb = tmp-1;
		else if(tmp*tmp < n) tmpa = tmp+1;
		if(tmp*tmp >= n && (tmp-1)*(tmp-1) <= n) break;
		//printf("%llu / %llu / %llu\n",tmpa,tmp,tmpb);
	}
	if(!n) tmp=0;
	printf("%llu",tmp);
	//9,223,372,036,854,775,807
	return 0;
}

//int main(){
//	/*long long n, i;
//	
//	scanf("%lld",&n);
//	for(i=0;i*i<=n;i++){
//	}
//	(((i-1)*(i-1))==n)? i-- :false;
//	printf("%lld",i);
//	return 0;*/
//	// 형식 제대로 지켜라
//	// unsigned !!!!
//	//long double nn;
//	//unsigned long long n, i, res, tmpa, tmpb, tmp;
//	//scanf("%lf",&nn);
//	//nn = sqrt(nn);
//	//tmp = (unsigned long long)nn;
//	//(tmp*tmp <= nn) ? true : tmp++;
//	//tmpa = 0; 
//	//tmpb = n;
//	//printf("%lld\n\n",n);
//	/*while(1){
//		//0 4 2
//		tmp = ( (tmpa+tmpb)/2 );	
//		printf("%llu %llu %llu\n",tmpa,tmpb,tmp);
//		if(tmp*tmp >= n && (tmp-1)*(tmp-1) < n){
//			printf("%llu %llu %llu %llu %llu\n",n,tmp,tmp-1,tmp*tmp, (tmp-1)*(tmp-1));
//			break;
//		}
//		//else if((tmp-1)*(tmp-1) < n) break;
//		if(tmp*tmp < n) tmpa = tmp;
//		else if(tmp*tmp > n) tmpb = tmp;
//	}*/
//	unsigned long long n, i, tmpa
//	printf("%lld\n",tmp);
//	return 0;
//}