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

node* build_from_array(ll A[],ll s,ll e){
	node *root;
	ll mid;

	// Base Case
	if(s > e)
		return NULL;
	// Recursive Case
	mid = (s + e)/2;
	root = new node(A[mid]);
	root->left = build_from_array(A,s,mid-1);
	root->right = build_from_array(A,mid+1,e);
	return root;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    node *root;

    ll A[] = {1,2,3,4,5,6,7};
    n = sizeof(A)/sizeof(A[0]);
    root = build_from_array(A,0,n-1);
    print_BFS_levelwise(root);

    return 0;
}

