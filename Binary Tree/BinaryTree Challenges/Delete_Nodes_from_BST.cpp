// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class node {
public :
    ll data ; 
    node *right ;
    node *left ;

    node(ll d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

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

node* build_from_array(ll A[],ll s,ll e){
	node *root;
	ll mid;

	// Base Case
	if(s > e)
		return NULL;
	// Recursive Case
	mid = (s + e)/2;
	root = new node(A[mid]);
	root->left = build_from_array(A,s,mid-1);
	root->right = build_from_array(A,mid+1,e);
	return root;
}

void preorder_print(node *root){

	// Base Case
	if(root == NULL)
		return;
	// Recursive Case
	cout<<root->data<<" ";
	preorder_print(root->left);
	preorder_print(root->right);
	return;
}

node* delete_in_BST(node *root,ll key){

	// Base Case
	if(root == NULL)
		return NULL;

	// Recursive Case

	if(key < root->data)
		root->left = delete_in_BST(root->left,key);

	else if(key > root->data)
		root->right = delete_in_BST(root->right,key);

	else if(key == root->data){

		// Case 1: Node has 0 children (leaf node)
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}

		// Case 2: Node has 1 child
		if(root->left != NULL && root->right == NULL){
			node *temp = root->left;
			delete root;
			return temp;
		}
		if(root->right != NULL && root->left == NULL){
			node *temp = root->right;
			delete root;
			return temp;
		}

		// Case 3: Node has 2 children

		// Finding the Inorder Successor
		node *replace = root->right;
		while(replace->left != NULL)
			replace = replace->left;

		root->data = replace->data;
		root->right = delete_in_BST(root->right,replace->data);
	}

	return root;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll T,i,n,m,key;

	cin>>T;
	while(T--){

		cin>>n;
		ll A[n];
		for(i=0 ; i<n ; i++){
			cin>>A[i];
		}

		node *root;
		root = build_BST(A,n);

		cin>>m;
		while(m--){
			cin>>key;
			root = delete_in_BST(root,key);
		}

		preorder_print(root);
		cout<<"\n";
	}

    return 0;
}


