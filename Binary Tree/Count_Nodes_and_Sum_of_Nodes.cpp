// Here, we print each level in a new line
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

ll count_node(node *root){
	ll left_count,right_count,total_count;
	// Base Case
	if(root == NULL)
		return 0;
	// Recursive Case
	left_count = count_node(root->left);
	right_count = count_node(root->right);
	total_count = (1 + left_count + right_count);
	return(total_count);
}

ll find_sum(node *root){
	ll left_sum,right_sum,total_sum;
	// Base Case
	if(root == NULL)
		return 0;
	// Recursive Case
	left_sum = find_sum(root->left);
	right_sum = find_sum(root->right);
	total_sum = (root->data) + left_sum + right_sum;
	return(total_sum);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root;
    ll count,sum;

    root = build_tree_preorder(); // 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 (Pg 59)
    print_BFS_levelwise(root);
    count = count_node(root);
    cout<<count<<"\n";
    sum = find_sum(root);
    cout<<sum<<"\n";

    return 0;
}