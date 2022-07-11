// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void heapify_modified(vector<ll> &V,ll idx,ll size){

	ll left,right,last,max_index;

	left = 2*idx + 1;
	right = 2*idx + 2;
	last = size - 1;

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
	heapify_modified(V,max_index,size);
	return;
}

void build_maxHeap(vector<ll> &V){

	ll i,n;

	n = V.size();
	for( i=(n/2) - 1 ; i>=0 ; i--){
		heapify_modified(V,i,n);
	}
}

void heap_sort(vector<ll> &V){

	ll n;

	// Step 1
	build_maxHeap(V);
	// Step 2
	n = V.size();
	while(n >= 2){
		swap(V[0],V[n-1]);
		n -= 1;
		heapify_modified(V,0,n);
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,num;

    cin>>n;
    vector<ll> V;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	V.push_back(num);
    }

    heap_sort(V);
    for(i=0 ; i<n ; i++){
    	cout<<V[i]<<" ";
    }
    cout<<"\n";
   
    return 0;
}

