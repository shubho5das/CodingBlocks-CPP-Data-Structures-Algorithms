// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void heapify(vector<ll> &V,ll idx){

	ll left,right,last,max_index;

	left = 2*idx + 1;
	right = 2*idx + 2;
	last = V.size() - 1;

	max_index = idx;
	if( left <= last && V[left]>V[max_index] )
		max_index = left;
	if( right <= last && V[right]>V[max_index] )
		max_index = right;

	// Base Case
	if(max_index == idx)
		return;
	// Recursive Case
	swap(V[idx],V[max_index]);
	heapify(V,max_index);
	return;
}

void build_maxHeap(vector<ll> &V){
	
	ll i;

	for( i=(V.size()/2) - 1 ; i>=0 ; i--){
		heapify(V,i);
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i,n,num;

    cin>>n;					// 8
    vector<ll> V;
    V.reserve(n);		
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	V.push_back(num);	// 10 20 5 6 1 8 9 4
    }
    build_maxHeap(V);
    for(i=0 ; i<n ; i++){
    	cout<<V[i]<<" "; 
    }
    cout<<"\n";

    return 0;
}



