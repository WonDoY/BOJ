// 구현하려다가 실패함.
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <list>
#define MAX 1000001
using namespace std;

char command[MAX];
int main() {
	int tc;
	scanf("%d\n", &tc);
	list<char> l;

	for(int i = 0 ; i < tc ; i++){
		l.clear();

		auto iter = l.begin();

		
		memset(command,0,MAX);
		scanf("%s",command);
		int clen = strlen(command);
		for(int i = 0 ; i < clen ; i++){
			switch (command[i]) {
				case '<':
					if (iter != l.begin()) iter--;
					break;
				case '>':
					if (iter != l.end()) iter++;
					break;
				case '-':
					if (iter != l.begin()) iter = l.erase(--iter);
					break;
				default:
					iter = ++l.insert(iter, command[i]);
			}
		}

		auto p = l.begin();
		for( ; l.size() > 0 ; l.pop_front()){
			p = l.begin();
			printf("%c", *p);
		}
		printf("\n");
	}
	return 0;
}


//#include<cstdio>
//#include<cstring>
//#define MAX 200000
//using namespace std;
//template<class T>
//class list;
//
//template<class T>
//class node{
//	friend class list<T>;
//private:
//	T data;
//	node<T>* prev;
//	node<T>* next;
//public:
//	node<T>(T inputData){
//		data = inputData;
//		prev = NULL;
//		next = NULL;
//	}
//};
//
//template<class T>
//class list{
//private:
//	node<T>* cursor;
//	node<T>* front;
//	node<T>* end;
//public:
//	list<T>(){
//		cursor = NULL;
//		front = NULL;
//		end = NULL;
//	}
//	~list<T>(){
//		while(front!=NULL){
//			node<T>* del = front;
//			front = front->next;
//			delete del;
//		}
//	}
//	void init(){
//		while(front!=NULL){
//			node<T>* del = front;
//			front = front->next;
//			delete del;
//		}
//		front = NULL;
//		end = NULL;
//		cursor = NULL;
//	}
//	void insert(T inputData){
//		node<T>* newNode = new node<T>(inputData);
//		if(cursor==NULL){
//			if(front != NULL){
//				cursor = newNode;
//				front->prev = newNode;
//				newNode->next = front;
//				front = newNode;
//			}
//			else if(front == NULL){
//				cursor = newNode;
//				front = newNode;
//				end = newNode;
//			}
//		}else if(cursor != NULL){
//			newNode->prev = cursor;
//			newNode->next = cursor->next; // 
//			if(cursor->next == NULL){ // 끝임
//				cursor->next = newNode;
//				end = newNode;
//			}else if(cursor->next != NULL){
//				cursor->next->prev = newNode;
//				cursor->next = newNode;
//			}
//			cursor = newNode;
//		}
//	}
//	void move_left(){
//		if(cursor != NULL){
//			cursor = cursor->prev;
//		}
//	}
//	void move_right(){
//		if(cursor != NULL){
//			if(cursor->next != NULL){
//				cursor = cursor->next;
//			}
//		}else if(cursor == NULL){
//			cursor = front;
//		}
//	}
//	void remove(){
//		node<T>* del = cursor;
//		if(cursor != NULL){
//			if(cursor->prev == NULL){
//				if(cursor->next == NULL){
//					front = NULL;
//					cursor = NULL;
//				}
//				else if(cursor->next != NULL){					
//					front = front->next;
//					cursor = NULL;
//				}
//			}
//			else if(cursor->next == NULL){ // 후
//				cursor = cursor->prev;
//				cursor->next = NULL;
//			}
//			else if(cursor->prev != NULL){ // 전
//				cursor->next->prev = cursor->prev;
//				cursor->prev->next = cursor->next;
//				cursor = cursor->prev;
//			}
//			delete del;
//		}
//	}
//	void print(){
//		node<T>* tempNode = front;
//		while(tempNode!=NULL){
//			printf("%c",tempNode->data);
//			tempNode = tempNode->next;
//		}
//		printf("\n");
//	}
//};
//
//char command[MAX] = {0,};
//int main(){
//	int tc; scanf("%d", &tc);
//	list<char>* l = new list<char>();
//	for(int i = 0 ; i < tc ; i++){
//		memset(command,0,MAX);
//		l->init();
//		scanf("%s",command);
//		int clen = strlen(command);
//		for(int z = 0 ; z < clen ; z++){
//			//l->print();
//			switch(command[z]){
//			case '<': 
//				l->move_left();
//				break;
//			case '>': 
//				l->move_right();
//				break;
//			case '-': 
//				l->remove();
//				break;
//			default: 
//				l->insert(command[z]);
//				break;
//			}
//		}
//		l->print();
//	}
//	return 0;
//}