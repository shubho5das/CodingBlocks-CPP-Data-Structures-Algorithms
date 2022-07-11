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

node* insert_node(node* root,ll data){
	// Base Case
	if(root == NULL){
		node *n = new node(data);
		return n;
	}
	// Recursive Case
	if(data <= root->data)
		root->left = insert_node(root->left,data);
	else
		root->right = insert_node(root->right,data);
	return root;
}

node* build_BST(ll A[],ll n){

	node *root = NULL; 
	// NOTE: V. Imp to initialise the root with NULL
	ll i;

	for(i=0 ; i<n ; i++){
		root = insert_node(root,A[i]);
	}
	return root;
}

bool check_BST(node* root,ll lower = INT_MIN,ll upper = INT_MAX){

	bool check_left,check_right;

	// Base Case
	if(root == NULL)
		return true;

	if( (root->data > upper) || (root->data <= lower) )
		return false;

	// Recursive Case
	check_left = check_BST( root->left , lower , root->data );
	check_right = check_BST( root->right , root->data , upper );
	if(check_left==false || check_right==false)
		return false;
	else
		return true;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    
    root = build_tree(); // 3 4 -1 6 -1 -1 5 1 -1 -1 -1
    print_BFS_levelwise(root);
    if(check_BST(root))
    	cout<<"YES\n";
    else
    	cout<<"NO\n";
 
    return 0;
}

