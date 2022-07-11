// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void build_maxHeap(vector<ll> &V){

	ll i,idx,parent;

	for(i=1 ; i<V.size() ; i++){
		idx = i;
		if(idx %2 == 0)
			parent = (idx - 2)/2;
		else
			parent = (idx - 1)/2;

		while( idx>=1 && (V[idx] > V[parent]) ){
			swap(V[idx],V[parent]);
			idx = parent;
			if(parent%2 == 0)
				parent = (parent - 2)/2;
			else
				parent = (parent - 1)/2;
		}
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i;

    vector<ll> V{10,20,5,6,1,8,9,4};
    n = V.size();
    for(i=0 ; i<n ; i++){
    	cout<<V[i]<<" ";
    }
    cout<<"\n";
    build_maxHeap(V);
    for(i=0 ; i<n ; i++){
    	cout<<V[i]<<" ";
    }
    cout<<"\n";

    return 0;
}


