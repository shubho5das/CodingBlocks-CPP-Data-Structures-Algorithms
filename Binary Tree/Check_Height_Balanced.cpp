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

class Pair{
public:
	ll height;
	bool check;
};

Pair check_balanced(node *root){

	Pair p,left,right;

	// Base Case
	if(root == NULL){
		p.height = 0;
		p.check = true;
		return p;
	}

	// Recursive Case
	left = check_balanced(root->left);
	right = check_balanced(root->right);

	p.height = max(left.height,right.height) + 1;

	if( (left.check == false) || (right.check == false) )
		p.check = false;
	else if( abs(left.height - right.height) > 1)
		p.check = false;
	else
		p.check = true;

	return p;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    Pair p;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_BFS(root);
    cout<<"\n";
    p = check_balanced(root);
    cout<<"Height = "<<p.height<<"\n";
    if(p.check)
    	cout<<"YES\n";
    else
    	cout<<"NO\n";

    return 0;
}
// 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 7 -1 -1
// NO
// 1 2 4 -1 -1 5 -1 -1 3 -1 -1
// YES
