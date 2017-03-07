#include<cstdio>

class binTree;

class node{
	friend class binTree;
private:
	char data;
	node* root;
	node* left;
	node* right;
	bool visit;
public:
	node(char input){
		data = input;
		root = NULL;
		left = NULL;
		right = NULL;
		visit = false;
	}
};

class binTree{
private :
	node* current;
	node* root;
public :
	binTree(){
		current = NULL;
		root = NULL;
	}
	// 삭제는 없구나!
	void insert(char ROOT, char LEFTC, char RIGHTC ){
		node* tmp_left = NULL;
		node* tmp_right = NULL;
		if(LEFTC != '.') tmp_left = new node(LEFTC);
		if(RIGHTC != '.') tmp_right = new node(RIGHTC);

		if(root == NULL){
			root = new node(ROOT);
			if(tmp_left != NULL){
				tmp_left->root = root;
				root->left = tmp_left;
			}
			if(tmp_right != NULL){
				tmp_right->root = root;
				root->right = tmp_right;
			}
		} // 트리에 노드가 없는 경우
		else{ // root != NULL
			while(current->data != ROOT){
				current->visit = true;
				if( is_not_visit(current->left) ){
					current = current->left;
				}else if( is_not_visit(current->right) ){
					current = current->right;
				}else{
					if(current->root != NULL) current = current->root;
				}
			}
			if(current->data == ROOT){
				if(tmp_left != NULL){
					tmp_left->root = current;
					current->left = tmp_left;
				}
				if(tmp_right != NULL){
					tmp_right->root = current;
					current->right = tmp_right;
				}
			}
		} // 트리에 노드가 있는 경우
		set_current_root();
		make_non_visit();
	}
	void set_current_root(){
		current = root;
	}
	void make_non_visit(){
		int rootCount = 0;
		while(1){
			if(current == NULL) break;
			current->visit = false;
			if(current->left != NULL && current->left->visit) current = current->left;
			else if(current->right != NULL &&current->right->visit) current = current->right;
			else current = current->root;
		}
		set_current_root();
	}
	bool is_not_visit(node* check){
		if(check != NULL && !check->visit) return true;
		return false;
	}
	
	void preorder_traversal(){ 
		set_current_root();
		make_non_visit();
		while(1){
			if(current == NULL){
				printf("\n"); break;
			}
			if(!current->visit){
				current->visit = true;
				printf("%c",current->data);
			}else if( is_not_visit(current->left) ){
				current = current->left;
			}else if( is_not_visit(current->right) ){
				current = current->right;
			}else{
				current = current->root;
			}			
		}
	}
	void inorder_traversal(){
		set_current_root();
		make_non_visit();
		while(1){
			if(current == NULL){
				printf("\n"); break;
			}
			if( is_not_visit(current->left) ){
				current = current->left;
			}else if(!current->visit){
				current->visit = true;
				printf("%c",current->data);
			}else if( is_not_visit(current->right) ){
				current = current->right;
			}else{
				current = current->root;
			}			
		}
	}
	void postorder_traversal(){
		set_current_root();
		make_non_visit();
		while(1){
			if(current == NULL){
				printf("\n"); break;
			}
			if( is_not_visit(current->left) ){
				current = current->left;
			}else if( is_not_visit(current->right) ){
				current = current->right;
			}else if(!current->visit){
				current->visit = true;
				printf("%c",current->data);
			}else{
				current = current->root;
			}			
		}
	}
};


int main(){
	int n;
	scanf("%d", &n);
	char ro, l, r;
	binTree bt;
	while(scanf(" %c %c %c", &ro, &l, &r) == 3){
		bt.insert(ro, l, r);
	}
	bt.preorder_traversal();
	bt.inorder_traversal();
	bt.postorder_traversal();

	return 0;
}