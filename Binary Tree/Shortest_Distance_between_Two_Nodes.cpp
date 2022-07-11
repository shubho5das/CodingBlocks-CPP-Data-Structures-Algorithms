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

ll find_level(node *root,ll key,ll level){

	ll left,right,ans;

	// Base Case
	if(root == NULL)
		return -1;
	if(root->data == key)
		return level;

	// Recursive Case
	left = find_level(root->left,key,level+1);
	if(left != -1)
		return left;
	right = find_level(root->right,key,level+1);
	if(right != -1)
		return right;
	return -1;
}

ll find_distance(node *root,ll a,ll b){

	node *lca_node;
	ll p1,p2,ans;

	lca_node = lca(root,a,b);
	p1 = find_level(lca_node,a,0);
	p2 = find_level(lca_node,b,0);
	ans = (p1 + p2);
	return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll a,b,ans;

    root = build_tree_preorder(); // 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
    print_BFS_levelwise(root);
    cin>>a>>b;
   	ans = find_distance(root,a,b);
   	cout<<ans<<"\n";

    return 0;
}


