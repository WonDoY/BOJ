#include<cstdio>
#define MAX 10101
#define INF 0x3FFFFFFF
int dist = 0;
int depth[MAX][2]; // 0 최소 1 최대
void depth_init(){
	for(int i = 1 ; i < MAX ; i++){
		depth[i][0] = INF;
		depth[i][1] = 0;
	}
}
class binTree;

class node{
	friend class binTree;
private:
	int data;
	int level;
	node* root;
	node* left;
	node* right;
	bool visit;
public:
	node(int input){
		data = input;
		root = NULL;
		left = NULL;
		right = NULL;
		visit = false;
		level = 0;
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
	void insert(int ROOT, int LEFTC, int RIGHTC ){
		node* tmp_left = NULL;
		node* tmp_right = NULL;
		if(LEFTC != -1) tmp_left = new node(LEFTC);
		if(RIGHTC != -1) tmp_right = new node(RIGHTC);

		if(root == NULL){
			root = new node(ROOT);
			root->level = 1;
			if(tmp_left != NULL){
				tmp_left->root = root;
				tmp_left->level = root->level+1;
				root->left = tmp_left;
			}
			if(tmp_right != NULL){
				tmp_right->root = root;
				tmp_right->level = root->level+1;
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
					tmp_left->level = current->level+1;
					current->left = tmp_left;
				}
				if(tmp_right != NULL){
					tmp_right->root = current;
					tmp_right->level = current->level+1;
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
	
	void inorder_traversal(){
		set_current_root();
		make_non_visit();
		while(1){
			if(current == NULL)	return ;

			if( is_not_visit(current->left) ){
				current = current->left;
			}else if(!current->visit){
				current->visit = true;
				if(depth[current->level][0] > dist){
					depth[current->level][0] = dist;
				}
				if(depth[current->level][1] < dist){
					depth[current->level][1] = dist;
				}
				dist++;
			}else if( is_not_visit(current->right) ){
				current = current->right;
			}else{
				current = current->root;
			}			
		}
	}
};


int main(){
	depth_init();
	int n;
	scanf("%d", &n);
	int ro, l, r;
	binTree bt;
	while(scanf("%d %d %d", &ro, &l, &r) == 3){
		bt.insert(ro, l, r);
	}
	bt.inorder_traversal();

	int resLevel = 0;
	int resWidth = 0;
	for(int i = 1 ; i <= n ; i++){
		int width = depth[i][1] - depth[i][0] + 1;
		if(resWidth < width){
			//printf("<%d> %d - %d\n",i, depth[i][0], depth[i][1]);
			resWidth = width;
			resLevel = i;
		}
	}
	printf("%d %d",resLevel, resWidth);
	return 0;
}