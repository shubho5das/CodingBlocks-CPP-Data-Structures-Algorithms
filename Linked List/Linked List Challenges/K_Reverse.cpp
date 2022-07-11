#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,K,i,num;

    cin>>N>>K;
    vector<ll> V;
    for(i=0 ; i<N ; i++){
    	cin>>num;
    	V.push_back(num);
    }

    for(i=0 ; i<=(N-1) ; i+=K){
    	reverse(V.begin()+i,V.begin()+i+K);
    }

    for(i=0 ; i<N ; i++)
    	cout<<V[i]<<" ";
    cout<<"\n";

    return 0;
}