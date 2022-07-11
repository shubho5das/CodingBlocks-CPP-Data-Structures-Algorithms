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

ll replace_with_sum(node *root){
	
	ll left_sum,right_sum,temp;

	// Base Case
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right==NULL) // Child Node
		return(root->data);

	// Recursive Case
	temp = root->data;
	left_sum = replace_with_sum(root->left);
	right_sum = replace_with_sum(root->right);
	root->data = (left_sum + right_sum);
	return(temp + left_sum + right_sum);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll num;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_BFS(root);
    cout<<"\n";
	num = replace_with_sum(root);
	print_BFS(root);
	cout<<"\n";

    return 0;
}

