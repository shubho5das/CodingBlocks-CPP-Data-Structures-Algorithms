// KEEP CALM and Enjoy the Problem B-)
// File Name: Print_BST_Nodes_in_given_range
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

void print_range_inorder(node *root,ll k1,ll k2){
// Had to refer GFG 
    
    // Base Case    
    if(root == NULL)  
        return;  
 
    if(root->data > k1)  
        print_range_inorder(root->left, k1, k2);  
    if( (root->data >= k1) && (root->data <=k2) )
        cout<<root->data<<" ";  
    if ( root->data < k2)  
        print_range_inorder(root->right, k1, k2);  
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

    ll T,n,i,k1,k2;

    cin>>T;
    while(T--){

        cin>>n;
        ll A[n];
        for(i=0 ; i<n ; i++){
            cin>>A[i];
        }
        cin>>k1>>k2;

        node *root;
        root = build_BST(A,n);
        cout<<"# Preorder : ";
        preorder_print(root);
        cout<<"\n";
        cout<<"# Nodes within range are : ";
        print_range_inorder(root,k1,k2);
        cout<<"\n";

    }

    return 0;
}
