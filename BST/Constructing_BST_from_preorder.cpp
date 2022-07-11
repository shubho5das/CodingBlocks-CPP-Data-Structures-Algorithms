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

node* construct_BST_from_preorder(ll pre[],ll s,ll e){

	node *root;
	ll i,m;

	// Base Case
	if(s == e){ 
		// size == 1
		root = new node(pre[s]);
		root->left = NULL;
		root ->right = NULL;
		return root;
	}
	if( (e - s) == 1){
		// size == 2
		root = new node(pre[s]);
		if(pre[e] <= pre[s]){
			root->left = construct_BST_from_preorder(pre,e,e);
			root->right = NULL;
		}
		else{
			root->left = NULL;
			root->right = construct_BST_from_preorder(pre,e,e);
		}
		return root;
	}

	// Recursive Case
	
	root = new node(pre[s]);
	
	for(i=(s+1) ; i<=e ; i++){
		if(pre[i] > pre[s]){
			m = i;
			break;
		}
	}

	root->left = construct_BST_from_preorder(pre,s+1,m-1);
	root->right = construct_BST_from_preorder(pre,m,e);

	return root;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll n,i,s,e;
    
    ll pre[] = {5,3,1,7,6,8};
    n = sizeof(pre)/sizeof(pre[0]);
    s = 0;
    e = (n-1);
    root = construct_BST_from_preorder(pre,s,e);
    print_BFS_levelwise(root);
 
    return 0;
}







