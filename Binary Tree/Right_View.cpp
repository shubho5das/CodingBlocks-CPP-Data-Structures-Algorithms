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

void print_rightview(node *root,ll current_level,ll &max_level){
	// Base Case
	if(root == NULL)
		return;
	// Recursive Case
	if(current_level > max_level){
		cout<<root->data<<" ";
		max_level = current_level;
	}
	print_rightview(root->right,current_level+1,max_level);
	print_rightview(root->left,current_level+1,max_level);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll max_level;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_BFS_levelwise(root);
    cout<<"\n"; 
    max_level = INT_MIN;
    print_rightview(root,0,max_level);
    cout<<"\n";

    return 0;
}



