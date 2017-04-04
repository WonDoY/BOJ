#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> VI;
int p(int a){
	return a*a;
}
int main(){
	int numOfHill;
	scanf("%d", &numOfHill);
	VI hill = VI(numOfHill, 0);
	for(int i = 0 ; i < numOfHill ; i++) scanf("%d", &hill[i]);

	sort(hill.begin(), hill.end());

	int cost = 100000000;

	for(int h = 1 ; h <= 100 ; h++){
		int temp_cost = 0;
		for(int i = 0 ; i < numOfHill ; i++){
			int hi = hill[i];

			if(hi < h){
				temp_cost += p(h - hi);
			}else if(h+17 < hi){
				temp_cost += p(hi - h - 17);
			}
		}
		cost = min(cost, temp_cost);
	}
	printf("%d", cost);

	return 0;
}

// Fail 
//int main(){
//	int numOfHill;
//	scanf("%d", &numOfHill);
//	VI hill = VI(numOfHill, 0);
//	for(int i = 0 ; i < numOfHill ; i++) scanf("%d", &hill[i]);
//
//	sort(hill.begin(), hill.end());
//
//	int& minh = hill[0];
//	int& maxh = hill[numOfHill-1];
//	int cost = 0;
//	while(abs(maxh - minh) > 17){
//		//for(auto it = hill.begin() ; it != hill.end() ; it++) printf("%d ", *it); 
//		//puts("");
//
//		int tempcost = ((maxh - minh)-17)/2;
//		if(tempcost == 0 || (((maxh - minh)-17)/2)%1 > 0 ) tempcost++; 
//		cost += 2*(tempcost*tempcost);
//
//		maxh -= tempcost;
//		minh += tempcost;
//		
//		sort(hill.begin(), hill.end());
//		minh = hill[0];
//		maxh = hill[numOfHill-1];
//	}
//	//for(auto it = hill.begin() ; it != hill.end() ; it++) printf("%d ", *it); 
//	//puts("");
//
//	printf("%d", cost);
//
//	return 0;
//}