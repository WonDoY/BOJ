#include<cstdio>
template<class T>
class stack;

template<class T>
class node{
	friend class stack<T>; // available to access private data
private :
	T data;
	node<T>* before;
public :
	node<T>(T inputData = 0){
		 data = inputData;		
		before = NULL;
	} // Construction node<T> 
	void set_before(node<T>* ptr){
		 before = ptr;
	} // class function setting before pointer
	node<T>* get_Before(){
		return  before;
	}
	T get_data(){
		return  data;
	}
};

template<class T>
class stack{
private :
	node<T>* top;
	int size;
public :
	stack(){
		 top = NULL;
		 size = 0;
	}
	bool isEmpty(){
		if( top == NULL){
			return true;
		}
		return false;
	}
	void push(T pushData){
		node<T>* temp = new node<T>(pushData);
		if( isEmpty()){
			top = temp;
			top->before = NULL;
		}else{
			temp->before = top;
			top = temp;
		}
		size++;
	}
	T pop(){
		T retData;
		if( isEmpty()){
			return -1;
		}else{
			retData = top->data;
			node<T>* del = top;
			top = top->before;
			delete del;
		}
		size--;
		return retData;
	}
	int get_size(){
		return  size;
	}
	T get_top(){
		return top->data;
	}
};

int main(){
	int commandCount = 0;
	stack<int>* s = new stack<int>();
	scanf("%d", &commandCount);
	
	for(int i = 0 ; i < commandCount ; i++){
		char command[10] = {0,};
		scanf("%s", command);

		switch(command[0]){
		case 'p':
			if(command[1] == 'u'){
				int inData;
				scanf("%d",&inData);
				s->push(inData);
			}else if(command[1] == 'o'){
				printf("%d\n",s->pop());
			} 
			break;
		case 's':
			printf("%d\n",s->get_size());
			break;
		case 'e':
			printf("%d\n",(s->isEmpty())? 1: 0);
			break;
		case 't':
			if(!s->isEmpty()){
				printf("%d\n",s->get_top() );
			}else{
				printf("%d\n", -1);
			}
			break;
		}
	}
	return 0;
}