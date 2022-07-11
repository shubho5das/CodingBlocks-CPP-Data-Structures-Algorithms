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

node *build_tree_preorder(){
	ll d;

	cin>>d;
	// Base Case
	if(d == -1)
		return NULL;
	node *root = new node(d);
	root->left = build_tree_preorder();
	root->right = build_tree_preorder();
	return root;
}

void print_BFS(node *root){

	queue<node*> Q;
	// Step 1
	Q.push(root);
	// Step 2
	while( !Q.empty() ){
		node *f = Q.front();
		cout<<(f->data)<<" ";
		Q.pop();
		if(f->left != NULL)
			Q.push(f->left);
		if(f->right != NULL)
			Q.push(f->right);
	}
	return;
}

node *build_balanced_BST(ll A[],ll s,ll e){
	
	ll mid;

	// Base Case
	if(s > e)
		return NULL;

	// Recursive Case
	mid = (s+e)/2;
	node *root = new node(A[mid]);
	root->left = build_balanced_BST(A,s,mid-1);
	root->right = build_balanced_BST(A,mid+1,e);

	return root;
}

void print_preorder(node *root){

	// Base Case
	if(root == NULL)
		return;

	// Recursive Case
	cout<<root->data<<" ";
	print_preorder(root->left);
	print_preorder(root->right);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T,n,i,s,e;

    cin>>T;
    while(T--){

    	cin>>n;
    	ll A[n];
    	for(i=0 ; i<n ; i++){
    		cin>>A[i];
    	}

    	node *root;
    	s = 0;
    	e = (n-1);
    	root = build_balanced_BST(A,s,e);
    	print_preorder(root);
    	cout<<"\n"; // remove if get WA Verdict
    }

    return 0;
}


