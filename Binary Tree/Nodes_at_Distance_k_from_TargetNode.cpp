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

void print_kth_level(node *root,ll k){
	// Base Case
	if(root == NULL)
		return;
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	// Recursive Case
	print_kth_level(root->left,k-1);
	print_kth_level(root->right,k-1);
	return;
}

ll print_nodes_at_distance_k(node *root,node *target,ll k){

	ll DL,DR;

	// Base Case
	if(root == NULL)
		return -1;
	if(root == target){
		print_kth_level(target,k);
		return 0;
	}

	// Recursive Case
	// Case 1: Target Node present in Left Subtree
	DL = print_nodes_at_distance_k(root->left,target,k);
	if(DL != -1){
		if(DL + 1 == k)
			cout<<root->data<<" ";
		else
			print_kth_level(root->right,(k-DL-2));
		return(DL + 1);
	}
	// Case 2: Target Node present in Right Subtree
	DR = print_nodes_at_distance_k(root->right,target,k);
	if(DR != 1){
		if(DR + 1 == k)
			cout<<root->data<<" ";
		else
			print_kth_level(root->left,(k-DR-2));
		return(DR + 1);

	}
	// Case 3: Target Node present neither in Left Subtree nor in Right Subtree
	return -1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll num,k;
    node *root;
    node *target;

    root = build_tree_preorder(); // 1 2 4 6 -1 -1 7 10 12 -1 -1 13 -1 -1 11 14 -1 -1 15 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
    print_BFS_levelwise(root);
    cout<<"\n"; 
    cin>>k;
    target = root->left->left;
    num = print_nodes_at_distance_k(root,target,k);
    cout<<"\n";

    return 0;
}



