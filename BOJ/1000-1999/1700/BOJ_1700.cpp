//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <string.h>
//#include <cstring>
//using namespace std;
//
//
//int getMaxIdx(int* arr, int size);
//
//int main() {
//	int plug_num;
//	int elect_num;
//	int* electrics;
//	int* present_plugs;
//	int* opt;
//	int* priority;
//	int count = 0;
//
//	cin >> plug_num >> elect_num;
//
//	electrics = new int[elect_num];
//	present_plugs = new int[plug_num];
//	opt = new int[plug_num];
//
//	for (int i = 0; i < plug_num; i++) {
//		opt[i] = 100000;
//	}
//
//	for (int i = 0; i < elect_num; i++) {
//		cin >> electrics[i];
//	}
//
//	for (int i = 0; i < plug_num; i++) {
//		present_plugs[i] = electrics[i];
//	}
//
//	int temp = 0;
//	bool isExist = false;
//	bool temp_flag = false;
//
//	for (int i = plug_num; i < elect_num; i++) {
//		for (int j = 0; j < plug_num; j++) {
//			if (electrics[i] == present_plugs[j]) {
//				isExist = true;
//				break;
//			}
//		}
//
//		if (!isExist) {
//			
//			for (int z = i +1 ; z < elect_num; z++) {
//				for (int f = 0; f < plug_num; f++) {
//					if (present_plugs[f] == electrics[z]) {
//						if (opt[f] < 100000)
//							break;
//						opt[f] = temp++;
//						break;
//					}
//				}
//			}
//
//			int idx = getMaxIdx(opt, plug_num);
//			present_plugs[idx] = electrics[i];
//			count++;
//		}
//
//		for (int i = 0; i < plug_num; i++) {
//			opt[i] = 100000;
//		}
//		
//		isExist = false;
//		temp = 0;
//	}
//
//	cout << count << endl;
//
//
//
//	return 0;
//}
//
//int getMaxIdx(int* arr, int size) {
//	int max;
//	int idx = 0;
//
//	max = arr[0];
//	
//	if (size == 1) {
//		return idx;
//	}
//		
//		for (int i = 1; i < size; i++) {
//		if (arr[i] > max) {
//			max = arr[i];
//			idx = i;
//		}
//	}
//
//	return idx;
//}
#include<cstdio>
#define MAX 200
int plug[MAX] = {0,};
int use[MAX] = {0,};
int n, k;
int main(){
	int res = 0; // 결과값
	bool plugout = false; // 플러그를 뺄 경우
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < k ; i++) scanf("%d",&use[i]);
	for(int i = 0 ; i < k ; i++){
		plugout = false;
		for(int j = n-1 ; j >= 0 ; j--){ 

			if(plug[j]!=0){ 
				if(plug[j] == use[i]){
					plugout = false;
					break;
				}
				if(j==0) plugout = true;
			}else if(plug[j]==0){
				plug[j] = use[i];
				plugout = false;
				break;
			}
		}

		if(plugout){ 
			res++; 
			int dist[MAX] = {0,};
			for(int d = i+1 ; d < k ; d++){
				for(int p = 0 ; p < n ; p++){
					if(dist[plug[p]]==0 && plug[p]==use[d]){
						dist[plug[p]] = d-i;
						break;
					}
				}
			}
			int selectIndex = 0;
			int maxDistance = 0;
			
			for(int p = 0 ; p < n ; p++){
				if(dist[plug[p]]==0){
					selectIndex = p;
					break;
				}else if(dist[plug[p]] > maxDistance){
					maxDistance = dist[plug[p]];
					selectIndex = p;
				}
			}
			plug[selectIndex] = use[i];
		}
	}
	printf("%d\n",res);
	return 0;
}
//3 20
//1 2 3 4 4 3 5 8 9 19 20 1 2 3 20 4 1 2 3 4
//10

//2 10
//1 2 3 2 3 2 2 2 1 2
//    v           v
//2

// wrong tc 
// 3 6
// 1 1 1 1 2 3
// 0

//2 15
//3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
//2

//1 3
//1 2 1
//2

 //3 10
 //2 3 1 4 2 3 2 4 1 4
 //2