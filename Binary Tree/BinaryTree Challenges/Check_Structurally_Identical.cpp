// KEEP CALM and Enjoy the Problem B-)

/* Editorial: 
	
Here, the question says to find out if the two given binary trees are structurally identical or not.
Algorithm:

Here the smaller problem is to find out whether the left subtree and right subtree of the root node for the two trees are structurally similar or not.
If true, return true. Else even if one the condition is false, return false.
There will be two base cases for the given question.
a) If both the trees are empty, return true.
b) If one of the trees remain null and other one does not, then return false.

*/

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

bool areTreesStructurallyIdentical(node *root1, node *root2) {
    if(root1==NULL and root2==NULL) {
        return true;
    }
    if(root1!=NULL and root2!=NULL) {
        int leftAns = areTreesStructurallyIdentical(root1->left, root2->left);
        int rightAns = areTreesStructurallyIdentical(root1->right, root2->right);
        return leftAns and rightAns;
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root1,*root2;

    root1 = build_tree_preorder();
    root2 = build_tree_preorder();
    bool check = areTreesStructurallyIdentical(root1,root2);

    if(check)
    	cout<<"true\n";
    else
    	cout<<"false\n";

    return 0;
}


