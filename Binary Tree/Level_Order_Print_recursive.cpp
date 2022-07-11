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

void print_kth_root(node *root,ll k){
	// Base Case
	if(root == NULL)
		return;
	if(k == 1){
		cout<<(root->data)<<" ";
		return;
	}
	// Recursive Case
	print_kth_root(root->left,k-1);
	print_kth_root(root->right,k-1);
	return;
}

void print_level_order(node *root){

	ll i,H;

	// Step 1
	H = find_height(root);
	// Step 2
	for(i=1 ; i<=H ; i++){
		print_kth_root(root,i);
		cout<<"\n";
	}
	return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_level_order(root);
    cout<<"\n";

    return 0;
}

