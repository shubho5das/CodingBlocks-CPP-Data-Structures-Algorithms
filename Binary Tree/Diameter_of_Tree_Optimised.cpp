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

class my_pair{
public:
	ll height;
	ll diameter;
};

my_pair find_diameter(node *root){
	my_pair p,left,right;
	// Base Case
	if(root == NULL){
		p.height = 0;
		p.diameter = 0;
		return p;
	}
	// Recursive Case
	left = find_diameter(root->left);
	right = find_diameter(root->right);
	p.height = max(left.height,right.height) + 1;
	p.diameter = max(left.height + right.height , max(left.diameter,right.diameter));
	return p;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll D,H;
    node *root;
    my_pair p;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_BFS(root);
    cout<<"\n";
    p = find_diameter(root);
    D = p.diameter;
    H = p.height;
    cout<<D<<" "<<H<<"\n";
    
    return 0;
}




