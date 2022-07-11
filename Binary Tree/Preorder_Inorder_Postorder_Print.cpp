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


void print_preorder(node *root){
// Root-Left-Right. IN.THAT.ORDER

	// Base Case
	if(root == NULL)
		return;
	// Recursive Case
	cout<<root->data<<" ";
	print_preorder(root->left);
	print_preorder(root->right);
	return;
}

void print_inorder(node *root){
// Left-Root-Right. IN.THAT.ORDER

	// Base Case
	if(root == NULL)
		return;
	// Recursive Case
	print_inorder(root->left);
	cout<<root->data<<" ";
	print_inorder(root->right);
	return;
}

void print_postorder(node *root){
// Left-Right-Root. IN.THAT.ORDER

	// Base Case
	if(root == NULL)
		return;
	// Recursive Case
	print_postorder(root->left);
	print_postorder(root->right);
	cout<<(root->data)<<" ";
	return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_preorder(root);
    cout<<"\n";
    print_inorder(root);
    cout<<"\n";
    print_postorder(root);
    cout<<"\n";

    return 0;
}







