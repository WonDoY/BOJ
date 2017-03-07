#include<cstdio>

template<class T>
class deque;

template<class T>
class node{
	friend class deque<T>;
private :
	T data;
	node<T>* before;
	node<T>* next;
public :
	node<T>(T inputData){
		data = inputData;
		before = NULL;
		next = NULL;
	}
};

template<class T>
class deque{
private :
	node<T>* front;
	node<T>* back;
	int size;
public :
	deque<T>(){
		front = NULL;
		back = NULL;
		size = 0;
	}
	void push_front(T inputData){
		node<T>* newNode = new node<T>(inputData);
		if(isEmpty()){
			front = newNode;
			back = newNode;
		}else{
			newNode->next = front;
			front->before = newNode;
			front = front->before;
		}
		size++;
	}
	void push_back(T inputData){
		node<T>* newNode = new node<T>(inputData);
		if(isEmpty()){
			back = newNode;
			front = newNode;
		}else{
			newNode->before = back;
			back->next = newNode;
			back = back->next;
		}
		size++;
	}
	T pop_front(){
		T retData;
		if(front == NULL){
			return -1;
		}else if(front == back){
			node<T>* del = front;
			retData = front->data;
			front = NULL;
			back = NULL;
			delete del;					
		}else{
			node<T>* del = front;
			retData = front->data;
			front = front->next;
			delete del;		
		}
		size--;

		return retData;
	}
	T pop_back(){
		T retData;
		if(back == NULL){
			return -1;
		}else if(back == front){
			node<T>* del = back;
			retData = back->data;
			back = NULL;
			front = NULL;
			delete del;
		}else{
			node<T>* del = back;
			retData = back->data;
			back = back->before;
			delete del;
		}
		size--;
		return retData;
	}

	bool isEmpty(){
		if(back == NULL && front == NULL) return true;
		return false;
	}
	int get_size(){
		return size;
	}
	T get_front(){
		if(isEmpty()) return -1;
		T retData = front->data;
		return retData;
	}
	T get_back(){
		if(isEmpty()) return -1;
		T retData = back->data;
		return retData;
	}
};

int main(){
	int commandCount = 0;
	deque<int>* d = new deque<int>();
	scanf("%d", &commandCount);

	for(int i = 0 ; i < commandCount ; i++){
		char command[20] = {0,};
		scanf("%s", command);
		switch(command[0]){
		case 'p':
			if(command[1] == 'u'){
				int inData = 0;
				scanf("%d", &inData);
				switch(command[5]){
				case 'f': 
					d->push_front(inData);
					break;
				case 'b': 
					d->push_back(inData);
					break;
				}
			}
			else if(command[1] == 'o'){
				switch(command[4]){
				case 'f': 
					printf("%d\n",d->pop_front());
					break;
				case 'b': 
					printf("%d\n",d->pop_back());
					break;
				}
			}
			break;
		case 's': 
			printf("%d\n", d->get_size());
			break;
		case 'e': 
			printf("%d\n", (d->isEmpty())? 1: 0);
			break;			
		case 'f': 
			printf("%d\n", d->get_front());
			break;
		case 'b': 
			printf("%d\n", d->get_back());
			break;
		}
	}
}