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

ll find_height(node *root){
	ll left_subtree,right_subtree,height;
	// Base Case
	if(root == NULL)
		return 0;
	// Recursive Case
	left_subtree = find_height(root->left);
	right_subtree = find_height(root->right);
	height = ( 1 + max(left_subtree,right_subtree) );
	return(height);
}

ll find_diamater(node *root){

	ll D,d1,d2,d3;
	// Base Case
	if(root == NULL)
		return 0;
	// Recursive Case
	d1 = find_height(root->left) + find_height(root->right);
	d2 = find_diamater(root->left);
	d3 = find_diamater(root->right);
	D = max(d1,max(d2,d3));
	return D;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll diameter;
    node *root;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_BFS(root);
    cout<<"\n";
    diameter = find_diamater(root);
    cout<<diameter<<"\n";

    return 0;
}


