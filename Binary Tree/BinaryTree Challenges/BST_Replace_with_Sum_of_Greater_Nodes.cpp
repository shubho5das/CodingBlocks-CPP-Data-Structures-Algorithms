// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class node {
public :
    ll data ; 
    node *right ;
    node *left ;

    node(ll d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

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

// Reverse Inorder Traversal -figured this on my own B)
// So, that I can traverse the BST from the largest-to-smallest element
void replace_with_sum(node *root,ll &sum){

	// Base Case
	if(root == NULL)
		return;

	// Recursive Case
	replace_with_sum(root->right,sum);
	sum += root->data;
	root->data = sum;
	replace_with_sum(root->left,sum);
	return;
}


void preorder_print(node *root){

	// Base Case
	if(root == NULL)
		return;
	// Recursive Case
	cout<<root->data<<" ";
	preorder_print(root->left);
	preorder_print(root->right);
	return;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,sum,s,e;
	node *root;

	cin>>n;
	ll A[n];
	for(i=0 ; i<n ; i++){
	    cin>>A[i];
	}

	s = 0;
	e = (n-1);
	root = build_from_array(A,s,e);        

	sum = 0;
	replace_with_sum(root,sum);
	
	preorder_print(root);
	
    return 0;
}
