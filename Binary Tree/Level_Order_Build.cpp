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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;

    level_order_build(root); // 8 10 3 1 6 -1 14 -1 -1 9 7 13 -1 -1 -1 -1 -1 -1 -1
    print_BFS(root);

    return 0;
}

