#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<ll> V;
	ll num,i;

	while(cin>>num){
		V.push_back(num);
	}

	for(i=0 ; i<V.size() ; i++)
		cout<<V[i]<<" ";
	cout<<"\n";

	return 0;
}

