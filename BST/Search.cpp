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
	ll i;

	for(i=0 ; i<n ; i++){
		root = insert_node(root,A[i]);
	}
	return root;
}

node* search_in_BST(node *root,ll key){

	// Base Case
	if(root == NULL)
		return NULL;
	if(root->data == key)
		return root;

	// Recursive Case
	if(key <= root->data)
		search_in_BST(root->left,key);
	else
		search_in_BST(root->right,key);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    node *key_node;
    ll i,n,key;

    cin>>n;
    ll A[n];
    for(i=0 ; i<n ; i++){
    	cin>>A[i];
    }
    cin>>key;
    root = build_BST(A,n);
    key_node = search_in_BST(root,key);
    if(key_node == NULL)
    	cout<<"Absent\n";
    else
    	cout<<"Present\n";

    return 0;
}








