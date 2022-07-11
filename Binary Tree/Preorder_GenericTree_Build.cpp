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


//Generic Tree Input
//Used in problem - Sum at level k
void buildTreeGeneric(node*&root){

    ll d,n ;

    cin >> d >> n;
    root = new node(d);

    // Case 1: 0 children (leaf node)
    if(n==0){
        return; 
    }
    // Case 2: 1 child
    else if(n==1){
        buildTreeGeneric(root->left);
        return;
    }
    // Case 3: 2 children
    else {
        buildTreeGeneric(root->left);
        buildTreeGeneric(root->right) ; 
        return;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;

    buildTreeGeneric(root);          
    /* Sample Input:
    1 2
    2 2 
    3 0 
    4 0
    5 2 
    6 0 
    7 0 */
    print_BFS(root);

    return 0;
}
