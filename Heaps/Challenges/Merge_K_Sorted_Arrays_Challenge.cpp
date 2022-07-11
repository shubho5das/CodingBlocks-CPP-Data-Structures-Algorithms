// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class node{
public:
	ll value;
	ll row;
	ll col;

	// Constructor
	node(ll a,ll b,ll c){
		value = a;
		row = b;
		col = c;
	}
};

class custom_compare{
public:
	bool operator()(node a,node b){
		return(a.value > b.value);
	}
};

vector<ll> merge_k_sorted_arrays(vector<vector<ll>> V){

	ll n,k,i,next;

	vector<ll> solution;
	priority_queue<node,vector<node>,custom_compare> P; // Min Heap
	k = V.size();
	n = V[0].size();
	
	
	// Step 1: Inserting 0th element of each array into the Heap
	for(i=0 ; i<k ; i++){
		node x(V[i][0],i,0);
		P.push(x);
	}

	// Step 2
	while(P.size() >= 1 ){

		node minumum = P.top();
		P.pop();
		solution.push_back(minumum.value);

		if(minumum.col <=(n-2)){
			next = V[minumum.row][minumum.col + 1];
			node y(next,minumum.row,minumum.col+1);
			P.push(y);
		}
	}

	return solution;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,k,i,j,num;

    cin>>k>>n;

    vector<vector<ll>> V;
    for(i=0 ; i<k ; i++){
    	vector<ll> temp;
    	for(j=0 ; j<n ; j++){
    		cin>>num;
    		temp.push_back(num);
    	}
    	V.push_back(temp);
    }

    vector<ll> solution = merge_k_sorted_arrays(V);
    for(i=0 ; i<solution.size() ; i++)
    	cout<<solution[i]<<" ";
    cout<<"\n";

    return 0;
}

