#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void permute(string &S,ll i,set<string>&M){
	
	ll j;

	// Base Case
	if(S[i] == '\0'){
		string str;
		str = S;
		M.insert(str);
		return;
	}

	// Recursive Case
	for(j=i ; j<S.length() ; j++){
		swap(S[i],S[j]);
		permute(S,i+1,M);

		// Backstorring- restoring the original array
		swap(S[i],S[j]);
	}
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	string S,str;
	set<string> M;

	cin>>S;
	permute(S,0,M);

	for(auto str:M){
		cout<<str<<"\n";
	}

	return 0;
}
