#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,k,num;
    vector<ll> V;

    while(cin>>num){
    	if(num==-1)
    		break;
    	V.push_back(num);
    }
    n = V.size();
    cin>>k;
    cout<<V[n-k]<<"\n";

    return 0;
}