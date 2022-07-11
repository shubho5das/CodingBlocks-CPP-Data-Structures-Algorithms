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

node* lca(node *root,ll a,ll b){
	// Base Case
	if(root == NULL)
		return NULL;
	if(root->data == a || root->data == b)
		return root;

	// Recursive Case
	node *leftans = lca(root->left,a,b);
	node *rightans = lca(root->right,a,b);
	if( leftans != NULL && rightans != NULL )
		return root;
	else if( leftans != NULL && rightans == NULL )
		return leftans;
	else if( rightans != NULL && leftans == NULL )
		return rightans;
	else if( leftans == NULL && rightans == NULL )
		return NULL;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll a,b,ans;
    node *root;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_BFS_levelwise(root);
    cin>>a>>b;
    ans = lca(root,a,b)->data;
    cout<<ans<<"\n";

    return 0;
}

