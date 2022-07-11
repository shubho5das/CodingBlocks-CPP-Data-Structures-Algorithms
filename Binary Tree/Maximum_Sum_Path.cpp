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

class Pair{
public:
	ll branch_sum;
	ll max_sum;
};

Pair max_sum_path(node *root){

	Pair p;
	ll op1,op2,op3,op4,max_sum_root,max_sum_left,max_sum_right;

	// Base Case
	if(root == NULL){
		p.branch_sum = 0;
		p.max_sum = 0;
		return p;
	}

	// Recursive Case
	Pair left = max_sum_path(root->left);
	Pair right = max_sum_path(root->right);

	// Step 1: Finding Max Branch Sum
	p.branch_sum = max(root->data,max((root->data + left.branch_sum),(root->data + right.branch_sum)));
	
	// Step 2: Finding Max Path Sum
	// Case 1 
	op1 = root->data;
	op2 = root->data + left.branch_sum;
	op3 = root->data + right.branch_sum;
	op4 = root->data + left.branch_sum + right.branch_sum;
	max_sum_root = max(op1,max(op2,max(op3,op4)));
	// Case 2
	max_sum_left = left.max_sum;
	// Case 3
	max_sum_right = right.max_sum;
	p.max_sum = max(max_sum_root,max(max_sum_left,max_sum_right));

	return p;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll ans;

    root = build_tree_preorder(); // 10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
    print_BFS_levelwise(root);
    ans = max_sum_path(root).max_sum;
    cout<<ans<<"\n";

    return 0;
}

