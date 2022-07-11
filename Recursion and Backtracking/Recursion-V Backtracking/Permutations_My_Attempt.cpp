#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void find_permutations(string &S,ll n,char out[],ll i,ll j)
{
	ll k;

	// Base Case
	if(j==n)
	{
		out[j] = '\0';
		cout<<out<<"\n";
		return;
	}

	// Recursive Case
	for(k=i;k<=(n-1);k++)
	{
		swap(S[k],S[i]);
		out[j] = S[i];
		find_permutations(S,n,out,i+1,j+1);

		// Backtracking- to restore the Original Array
		swap(S[k],S[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll n;

	string S;
	char out[100];

	cin>>S;
	n = S.length();
	find_permutations(S,n,out,0,0);

	return 0;
}
