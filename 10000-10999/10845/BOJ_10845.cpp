#include<cstdio>

template<class T>
class queue;

template<class T>
class node{
	friend class queue<T>;
private :
	T data;
	node<T>* next;
public :
	node<T>(T inputData){
		data = inputData;
	}
};

template<class T>
class queue{
private :
	node<T>* start;
	node<T>* end;
	int size;
public :
	queue<T>(){
		start = NULL;
		end = NULL;
		size = 0;
	}
	void push(T inputData){
		node<T>* tempNode = new node<T>(inputData);
		if(isEmpty()){
			start = tempNode;
			end = tempNode;
		}else{
			end->next = tempNode;
			end = end->next;
		}
		size++;
	}
	T pop(){
		T retData;
		if(isEmpty()){
			return -1;
		}else if(start == end && start != NULL){
			node<T>* del = start;
			retData = start->data;
			start = end = NULL;
			delete del;
		}else{
			node<T>* del = start;
			retData = start->data;
			start = start->next;
			delete del;
		}
		size--;
		return retData;
	}
	bool isEmpty(){
		if(start==NULL && end==NULL){
			return true;
		}
		return false;
	}
	int get_size(){
		return size;
	}
	T get_front(){
		if( start == NULL ) return -1;
		T retData = start->data;
		return retData;
	}
	T get_back(){
		if( end == NULL ) return -1;
		T retData = end->data;
		return retData;
	}
};

int main(){
	queue<int>* q = new queue<int>();
	int commandCount = 0 ;
	scanf("%d", &commandCount);
	for(int i = 0 ; i < commandCount ; i++){
		char command[10] = {0,};
		scanf("%s",command);

		switch(command[0]){
		case 'p': 
			if(command[1] == 'u'){
				int inData;
				scanf("%d", &inData);
				q->push(inData);
			}else if(command[1] == 'o'){
				printf("%d\n", q->pop());
			}
			break;
		case 's': 
			printf("%d\n",q->get_size());
			break;
		case 'e':
			printf("%d\n",(q->isEmpty())? 1 : 0);
			break;
		case 'f': 
			printf("%d\n",q->get_front());
			break;
		case 'b': 
			printf("%d\n",q->get_back());
			break;
		}
	}
	return 0;
}