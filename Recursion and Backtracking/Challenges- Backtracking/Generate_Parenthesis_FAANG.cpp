#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void generate_brackets(char out[],ll N,ll i,ll open,ll close,vector<string> &V){

	// Base Case
	if(i== 2*N){
		out[i] = '\0';
		V.push_back(out);
		return;
	}

	// Recursive Case

	// Case 1: Fill with '('
	if(open < N){
		out[i] = '(';
		generate_brackets(out,N,i+1,open+1,close,V);
	}
	// Case 2: Fill with ')'
	if(close < open){
		out[i] = ')';
		generate_brackets(out,N,i+1,open,close+1,V);
	}
}

bool compare(string a,string b){
	return(a>b);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll n,i; 
	char out[20];
	vector<string> V;

	cin>>n;
	generate_brackets(out,n,0,0,0,V);
	// Sorting the stings in decreasing order- ie, ')' comes before '('
	sort(V.begin(),V.end(),compare);


	for(i=0 ; i<V.size() ; i++){
		cout<<V[i]<<"\n";
	}

	return 0;
}
