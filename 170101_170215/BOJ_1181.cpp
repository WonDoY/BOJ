#include<cstdio>
#include<algorithm>
#include<cstring>
#define IN 20100
#define LEN 51
using namespace std;
//pair<int,char*> string[IN];
char* input[IN];

bool stringCompare(const char*s1, const char* s2){
	if(strlen(s1)<strlen(s2)) return true;
	else if(strlen(s1)==strlen(s2)){
		int result =strcmp(s1,s2);
		if(result > 0) return false; // 0보다 작은수 0보다 큰 수 수정
		if(result < 0) return true;  // result == 1 / result == -1 에서 수정함.
	}
	return false;
}

int main(){
	int tc; scanf("%d",&tc);
	for(int i = 0 ; i < tc ; i++){
		input[i] = new char[LEN];
		scanf("%s",input[i]);
	} 
	sort(input,input+tc,stringCompare); // 조건 1 : 길이별 정렬
	
	// 조건 2: 사전 순 정렬
	//printf("1 : %s , 2 : %s // result : %d \n", input[1] ,input[3] ,strcmp(input[1] ,input[3] ));
	// 1 s1 > s2
	// -1 s1 < s2
	// no it // it이 더 먼저 나와야함. 1
	// abcde fghij klmno pqrst uvwxy z
	for(int i = 0 ; i < tc ; i++){ 
		if(i+1 < tc){
			if( strcmp(input[i] ,input[i+1]) ){
				
				puts(input[i]);
			}
			//else if(!strcmp(input[i],input[i+1])){
			//	//puts(input[i]); i++; // 같은 단어가 3개 이상이면 틀릴 것이다.
			//}
		}else{
			puts(input[i]);
		}
	}
	
	return 0;
}

//#include<cstdio>
//#include<algorithm>
//#include<cstring>
//#define IN 20100
//#define LEN 51
//using namespace std;
//pair<char*, int> string[IN];
//
//int main(){
//	int tc; scanf("%d",&tc);
//	for(int i = 0 ; i < tc ; i++){
//		string[i].first = new char[LEN];
//		scanf("%s",string[i].first);
//		string[i].second = strlen(string[i].first);
//	} 
//	sort(string,string+tc); // 조건 1 : 길이별 정렬 // character 형은 정렬이 되지 않음.
//	
//	for(int i = 0 ; i < tc ; i++){ // 조건 2: 사전 순 정렬
//		if(i+1 < tc){
//			if(!strcmp(string[i].first,string[i+1].first)){
//				puts(string[i].first); i++;
//			}else{
//				puts(string[i].first);
//			}
//		}else puts(string[i].first);
//	}
//	
//	return 0;
//}