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

void print_leftview(node *root,ll current_level,ll &max_level){
    // Base Case
    if(root == NULL)
        return;
    // Recursive Case
    if(current_level > max_level){
        cout<<root->data<<" ";
        max_level = current_level;
    }
    print_leftview(root->left,current_level+1,max_level);
    print_leftview(root->right,current_level+1,max_level);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll max_level;

    level_order_build(root);
    max_level = INT_MIN;
    print_leftview(root,0,max_level);
    cout<<"\n";

    return 0;
}
