#include <iostream>
#include <queue>
using namespace std;
class node{
	public:
	node* left;
	node* right;
	int value =0;
	
	node(int v){
		value = v;
		left = NULL;
		right = NULL;
	}
};
class BST{
	public:
	node* root;
	
	BST() {
        root = NULL;
    }
	
	node* insert(node* root,int v){
		if(root == NULL){
			root = new node(v);
			return root;
		}
		if(v < root->value){
			root -> left = insert(root->left, v);
		}else if (v > root->value){
			root->right = insert(root->right,v);
		}
		return root;
	}
	
	node* remove(node* root,int v){
		if(root == NULL){
			return root;
		}
		if(v < root->value){
			root -> left = remove(root->left, v);
		}else if (v > root->value){
			root->right = remove(root->right,v);
		}else{
			//case 1 no child or one or 
			if(root->left == NULL){ //remove left  have right child  instead of 
				node* temp = root->right;
				delete root;
				return temp;
			}else if(root -> right == NULL){//remove right  have left child  instead of 
				node* temp = root->left;
				delete root;
				return temp;
			}
			// Node  two children: Get the inorder successor
			node* temp = root->right;
       		while (temp->left != NULL) {
            	temp = temp->left;
        	}

	        // Copy the inorder successor's content to this node
	        root->value = temp->value;
	
	        // Delete the inorder successor
	        root->right = remove(root->right, temp->value);
	   		}
    	return root;	
	}
	/*bool search(node* root, int v){
		if(root == NULL){
			return false;
		}
		if(root->value == v){
			return true;
		}else if (v < root->value){
			return search
			(root->left,v);
		}else{
			return search
			(root ->right,v);
		}
	}*/
	
	void insert(int v) {
        root = insert(root, v);
    }
    void remove(int v){
		root = remove(root,v);
	}
   /* bool search(int v){
    	return search(root,v);
	}*/
	void preorder (node* root){//Left
		if( root!= NULL){
			cout<<root->value<<",";
			preorder (root->left);
			preorder (root->right);
		}
	}
	void inorder (node* root){ //down
		if( root!= NULL){
			inorder (root->left);
			cout<<root->value<<",";
			inorder  (root->right);
		}
	}
	void postorder (node* root){//right
		if( root!= NULL){
			postorder (root->left);
			postorder (root->right);
			cout<<root->value<<",";
		}
	}
	void breadthFirstTraversal(node* root) {
        if (root == NULL) return;
        queue<node*> q;
        q.push(root);

        while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            node* current = q.front();
            q.pop();

            if (i > 0) {
                cout << ","; 
            }
            cout << current->value;

            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        cout << ","; 
        cout << "|"; 
        }
    }
	
};
int main(){
	BST tree;
	node* root = NULL;
	string str;
	int n;
	while(cin >> str && str != "x"){
		if(str == "a"){
			cin >> n;
			tree.insert(n);
		}else if(str == "b"){
			tree.breadthFirstTraversal(tree.root);
			cout << endl; 
		}else if(str == "i"){
			tree.inorder(tree.root);
			cout << endl; 
		}else if(str == "p"){
			tree.preorder(tree.root);
			cout << endl;
		}else if(str == "t"){
			tree.postorder(tree.root);
			cout << endl;
		}else if(str == "d"){
			cin >> n;
			tree.remove(n);
		}
		
	}
}