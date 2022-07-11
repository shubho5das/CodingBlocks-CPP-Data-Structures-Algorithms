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

// Preorder Build
node* build_tree(){ 
	ll d;

	cin>>d;
	// Base Case
	if(d == -1)
		return NULL;
	// Recursive Case
	node *root = new node(d);
	root->left = build_tree();
	root->right = build_tree();
	return(root);
}

// Preorder Print
void print_tree(node *root){
	// Base Case
	if(root == NULL)
		return;
	// Recursive Case
	cout<<root->data<<" ";
	print_tree(root->left);
	print_tree(root->right);
	return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	

    node *root;

    root = build_tree(); // 3 4 -1 6 -1 -1 5 1 -1 -1 -1
    print_tree(root);
    cout<<"\n";

    return 0;
}



