#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void generate_subset(ll in[],ll out[],ll i,ll j,ll T,ll N,vector<ll> &V,set<vector<ll>> &M){

	ll k,l,sum,num;

	// Base Case
	if(i==N){
		sum = 0;
		for(k=0 ; k<j ; k++)
			sum += out[k];

		if(sum == T){
			for(k=0 ; k<j ; k++){
				num = out[k];
				V.push_back(num);
			}
			M.insert(V);
			// Imp Step- clearing the vector contents, so that a fresh vector is available for us when we hit the base case again
			V.clear();
		}
		return;		
	}

	// Recursive Case

	out[j] = in[i];
	// Case 1: include in[i]
	generate_subset(in,out,i+1,j+1,T,N,V,M);
	// Case 2: exclude in[i]
	generate_subset(in,out,i+1,j,T,N,V,M);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N,i,T;
	ll out[20];
	vector<ll> V;
	set<vector<ll>> M;

	cin>>N;
	ll in[N];
	for(i=0 ; i<N ; i++)
		cin>>in[i];
	// Sorting the input array- IMP. step for removing the duplicated elements
	sort(in,in+N);
	cin>>T;
	generate_subset(in,out,0,0,T,N,V,M);

	for(auto vec:M){
		for(i=0;i<vec.size();i++)
			cout<<vec[i]<<" ";
		cout<<"\n";
	}

	return 0;
}
