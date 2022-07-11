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

node* build_tree_from_trav(ll pre[],ll in[],ll s,ll e){

	static ll i = 0;
	ll index,j;

	// Base Case
	if(s > e)
		return NULL;

	// Recursive Case
	
	// Step 1
	node *root = new node(pre[i]);
	// Step 2: Searching pre[i] in in[s,e]
	for(j=s ; j<=e ; j++){
		if(in[j] == pre[i]){
			index = j;
			break;
		}
	}
	i += 1;
	// Step 3
	root->left = build_tree_from_trav(pre,in,s,index-1);
	root->right = build_tree_from_trav(pre,in,index+1,e);

	return root;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	ll n;
	node *root;

	ll pre[] = {1,2,3,4,8,5,6,7};
	ll in[] = {3,2,8,4,1,6,7,5};
	n = sizeof(pre)/sizeof(pre[0]);
	root = build_tree_from_trav(pre,in,0,n-1);
	print_BFS_levelwise(root);
	cout<<"\n";

    return 0;
}



