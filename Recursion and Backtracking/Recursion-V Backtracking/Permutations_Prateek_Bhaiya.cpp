#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

void permute(string &S,ll i)
{
	ll j;

	// Base Case
	if(S[i] == '\0')
	{
		cout<<S<<"\n";
		return;
	}

	// Recursive Case
	for(j=i ; j<S.length() ; j++)
	{
		swap(S[i],S[j]);

		permute(S,i+1);

		// Backtracking- restoring the original string
		swap(S[j],S[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	string S;

	cin>>S;
	permute(S,0);

	return 0;

}

 