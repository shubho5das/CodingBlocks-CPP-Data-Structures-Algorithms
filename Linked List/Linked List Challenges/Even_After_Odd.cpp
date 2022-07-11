#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,j;

    cin>>n;
    ll A[n];
    for(i=0 ; i<n ; i++)
    	cin>>A[i];
    
    vector<ll> V;
    // Inserting the odd elements
    for(i=0 ; i<n ; i++){
    	if(A[i]%2!=0)
    		V.push_back(A[i]);
    }
    // Then, inserting the even elements
    for(i=0 ; i<n ; i++){
    	if(A[i]%2==0)
    		V.push_back(A[i]);
    }
    for(i=0 ; i<V.size() ; i++)
    	cout<<V[i]<<" ";
    cout<<"\n";

    return 0;
}


