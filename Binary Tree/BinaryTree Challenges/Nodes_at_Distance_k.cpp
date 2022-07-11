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

void print_kth_level(node *root,ll k,vector<ll> &V){
	// Base Case
	if(root == NULL)
		return;
	if(k==0){
		//cout<<root->data<<" ";
		V.push_back(root->data);
		return;
	}
	// Recursive Case
	print_kth_level(root->left,k-1,V);
	print_kth_level(root->right,k-1,V);
	return;
}

ll print_nodes_at_distance_k(node *root,node *target,ll k,vector<ll> &V){

	ll DL,DR;

	// Base Case
	if(root == NULL)
		return -1;
	if(root == target){
		print_kth_level(target,k,V);
		return 0;
	}

	// Recursive Case
	// Case 1: Target Node present in Left Subtree
	DL = print_nodes_at_distance_k(root->left,target,k,V);
	if(DL != -1){
		if(DL + 1 == k)
			V.push_back(root->data);
		else
			print_kth_level(root->right,(k-DL-2),V);
		return(DL + 1);
	}
	// Case 2: Target Node present in Right Subtree
	DR = print_nodes_at_distance_k(root->right,target,k,V);
	if(DR != 1){
		if(DR + 1 == k)
			V.push_back(root->data);
		else
			print_kth_level(root->left,(k-DR-2),V);
		return(DR + 1);

	}
	// Case 3: Target Node present neither in Left Subtree nor in Right Subtree
	return -1;
}

node* search(node* root,ll key){
// Pre Order Traversal

	// Base Case
	if(root == NULL)
		return NULL;
	
	if(root->data == key)
		return root;

	// Recursive Case
	node * left = search(root->left,key);
	if(left != NULL)
		return left;
	node *right = search(root->right,key);
	if(right != NULL)
		return right;
	
	return NULL;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,s,e,T,key,k;

    cin>>n;
    ll pre[n];
    for(i=0 ; i<n ; i++){
    	cin>>pre[i];
    }
    ll in[n];
    for(i=0 ; i<n ; i++){
    	cin>>in[i];
    }


    node *root;
	s = 0;
	e = (n-1);
    root = build_tree_from_trav(pre,in,s,e);

    cin>>T;
    while(T--){

    	cin>>key>>k;

    	node *target;
    	target = search(root,key);

    	vector<ll> V;
    	print_nodes_at_distance_k(root,target,k,V);

    	if(V.size() == 0)
    		cout<<"0\n";
    	else{
    		sort(V.begin(),V.end());
    		for(auto x:V)
    			cout<<x<<" ";
    		cout<<"\n";
    	}
    }

    return 0;
}



