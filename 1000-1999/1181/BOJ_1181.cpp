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
		if(result > 0) return false; // 0���� ������ 0���� ū �� ����
		if(result < 0) return true;  // result == 1 / result == -1 ���� ������.
	}
	return false;
}

int main(){
	int tc; scanf("%d",&tc);
	for(int i = 0 ; i < tc ; i++){
		input[i] = new char[LEN];
		scanf("%s",input[i]);
	} 
	sort(input,input+tc,stringCompare); // ���� 1 : ���̺� ����
	
	// ���� 2: ���� �� ����
	//printf("1 : %s , 2 : %s // result : %d \n", input[1] ,input[3] ,strcmp(input[1] ,input[3] ));
	// 1 s1 > s2
	// -1 s1 < s2
	// no it // it�� �� ���� ���;���. 1
	// abcde fghij klmno pqrst uvwxy z
	for(int i = 0 ; i < tc ; i++){ 
		if(i+1 < tc){
			if( strcmp(input[i] ,input[i+1]) ){
				
				puts(input[i]);
			}
			//else if(!strcmp(input[i],input[i+1])){
			//	//puts(input[i]); i++; // ���� �ܾ 3�� �̻��̸� Ʋ�� ���̴�.
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
//	sort(string,string+tc); // ���� 1 : ���̺� ���� // character ���� ������ ���� ����.
//	
//	for(int i = 0 ; i < tc ; i++){ // ���� 2: ���� �� ����
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