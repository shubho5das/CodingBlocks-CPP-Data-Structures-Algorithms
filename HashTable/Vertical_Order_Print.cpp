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

void level_order_build(node *&root){

	ll d,c1,c2;
	queue<node*> Q;

	cin>>d;
	root = new node(d);
	Q.push(root);

	while(Q.size() >= 1){

		node *n = Q.front();
		Q.pop();

		cin>>c1>>c2; // Children of n->data
		if(c1 != -1){
			n->left = new node(c1);
			Q.push(n->left);
		}
		if(c2 != -1){
			n->right = new node(c2);
			Q.push(n->right);
		}
	}
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


void find_horizontal_distance(node *root,map<ll,vector<ll>> &M,ll dist){
// Simple preorder traversal

	// Base Case
	if(root == NULL)
		return;

	// Recursive Case
	M[dist].push_back(root->data);
	find_horizontal_distance(root->left,M,dist-1);
	find_horizontal_distance(root->right,M,dist+1);
}

void vertical_order_print(node *root){

	ll i;
	map<ll,vector<ll>> M;

	find_horizontal_distance(root,M,0LL);
	for(auto x : M){
		for(i=0 ; i<x.second.size() ; i++)
			cout<<x.second[i]<<" ";
		cout<<"\n";
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;

    level_order_build(root); // 1 2 3 4 5 6 7 -1 -1 -1 8 -1 -1 -1 9 -1 -1 -1 -1
    print_BFS(root);
    cout<<"\n\n";
    vertical_order_print(root);
    cout<<"\n";

    return 0;
}

