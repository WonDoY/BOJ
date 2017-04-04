#include<cstdio>
//#define EOF -1
//int main(){
//	int a,b, n;
//	float ra,rb,Ra,Rb;
//	float res;
//	scanf("%d",&n);
//	while(n!=EOF){	
//		res=0;
//		scanf("%d%d",&a,&b);
//		if(n&1){
//			// equal dir
//			if(a==b){
//				res = -1;
//			}else{
//				 
//				ra = Ra = (1/100.0)*(10.0/a);
//				rb = Rb = (1/100.0)*(10.0/b);
//				while(1){
//					printf("%.2f %.2f\n",ra ,rb);
//					ra += Ra;
//					rb += Rb;
//					if(ra==rb){
//						res = ra;
//						break;
//					}
//				}
//			}
//			
//		}else if(!(n&1)){
//			// not eq dir
//			res = (float)(a*b)/(a+b);
//		}
//		if(res >= 0){
//			printf("%.2f\n",res);
//		}else if(res < 0){
//			printf("-1");
//		}
//
//		scanf("%d",&n);
//	}
//	return 0;
//}
int swap(double *a, double *b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}
int main(){
	// 10 km 이동시 배차 
	// 동일방향 1 , 반대방향 0 
	// input, 자기 배차시간, 다른 배차 시간
	int dir;
	double a, b;
	double time;
	while(scanf("%d %lf %lf", &dir, &a, &b) != EOF){
		//scanf("%d",&dir);
		//if(dir==-1){
		//	break;
		//}
		//scanf("%lf%lf", &a, &b);
		 
	// km / time = velo 
	// 10 = 분 * 10 / 이동거리 
	// 속도? velocity = distance / time ; 
	// linear 하게 
	// 걸린시간 / distance / velocity = time ;
	// 배차간격으로 분당 시간을 구할 수 있음.
	// 10km / input min = velocity; // 분당이동거리 
	// 10 / 15 = 2/3 분당 0.66666 ... km 이동 
	// 시간으로 환산 
	// 10 / 13 = 0.7692.... km 이동 
	// 시간을 출력해줘야함. 
	
	if(dir&1){
		(a<b)? true : swap(&a,&b);
		if(a==b) {
			time = -1;
		}else{
			time = 10 / ((10/a)-(10/b));
		}
	}else if(!(dir&1)){
		time = 10 / ((10/a)+(10/b));
	}
	if(time < 0){
		printf("-1\n");
	}else{
		printf("%.2lf\n",time);
	}
	}
	
	// equal
	// 배차간격a 15 느림 y = (10/15)x
	// 배차간격b 13 빠름 y = (10/13)x
	// y = ( (10/15) - (10/13) ) t 
	// 따라잡고있음 
	// 거리의 차이 : 10 ; 10 - ( (10/13) - (10/15) ) t 
	// y 간거리 x 시간 
	// 시간 차이 2분 
	// 속도비 
	

	
	
	return 0;
}