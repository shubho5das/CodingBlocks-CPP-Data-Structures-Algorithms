// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class node{
public:
	ll data;
	node *left;
	node *right;

	// Constructor
	node(ll d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

void print_BFS_levelwise(node *root){

	queue<node *> Q;

	// Step 1
	Q.push(root);
	Q.push(NULL);
	// Step 2
	while(!Q.empty()){
		node *f = Q.front();

		if(f == NULL){
			cout<<"\n";
			Q.pop();
			if(!Q.empty()) // to avoid Infinite Loop
				Q.push(NULL);
			continue;
		}

		cout<<f->data<<" ";
		Q.pop();
		if(f->left != NULL)
			Q.push(f->left);
		if(f->right != NULL)
			Q.push(f->right);
	}
	return;
}

node* insert_node(node* root,ll data){
	// Base Case
	if(root == NULL){
		node *n = new node(data);
		return n;
	}
	// Recursive Case
	if(data <= root->data)
		root->left = insert_node(root->left,data);
	else
		root->right = insert_node(root->right,data);
	return root;
}

node* build_BST(ll A[],ll n){
	node *root = NULL; 
	// NOTE: V. Imp to initialise the root with NULL
	ll i;

	for(i=0 ; i<n ; i++){
		root = insert_node(root,A[i]);
	}
	return root;
}

class LinkedList{
public:
	node *head;
	node *tail;
};

LinkedList flatten(node *root){

	LinkedList L;

	// Base Case
	if(root == NULL){
		L.head = NULL;
		L.tail = NULL;
		return L;
	}
	if(root->left == NULL && root->right == NULL){ // Leaf Node
		L.head = root;
		L.tail = root;
		return L;
	} 

	// Recursive Case

	// Case 1: Only Left Subtree is present
	if(root->left != NULL && root->right == NULL){

		LinkedList leftLL = flatten(root->left);

		L.head = leftLL.head;
		L.tail = root;
		return L;
	}
	// Case 2: Only Right Subtree is present
	if(root->right != NULL && root->left == NULL){
		LinkedList rightLL = flatten(root->right);

		L.head = root;
		L.tail = rightLL.tail;
		return L;
	}
	// Case 3: Both Right and Left Substrees are present
	if(root->left != NULL && root->right != NULL){
		LinkedList leftLL = flatten(root->left);
		LinkedList rightLL = flatten(root->right);
		
		leftLL.tail->right = root; // Had missed this initially, haha! 
		root->right = rightLL.head; 

		L.head = leftLL.head;
		L.tail = rightLL.tail;
		return L;
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll n,i,key;

    cin>>n;
    ll A[n]; // 4 5 2 3 1
    for(i=0 ; i<n ; i++){
    	cin>>A[i];
    }

    root = build_BST(A,n);
    print_BFS_levelwise(root);

    LinkedList L = flatten(root);
    node *temp = L.head;

    while(temp != NULL){
    	cout<<temp->data<<" ";
    	temp  = temp->right;
    }    
    cout<<"\n";
    
    return 0;
}

