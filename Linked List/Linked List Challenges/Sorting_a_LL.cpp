#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,num;

    cin>>n;
    list<ll> L;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	L.push_back(num);
    }
    L.sort();
    for(auto x:L)
    	cout<<x<<" ";
    cout<<"\n";

    return 0;
}