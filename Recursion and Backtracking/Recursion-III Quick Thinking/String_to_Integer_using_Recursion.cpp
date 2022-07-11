#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll string_to_integer(string S,ll n)
{
	ll small_ans,last_digit,ans;

	// Base Case
	if(n==0)
		return 0;

	// Recursive Case
	last_digit = (ll)(S[n-1] - '0');
	small_ans = string_to_integer(S,n-1);

	ans = (10 * small_ans)   + last_digit;
	return(ans);

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	ll N,n;

	string S;
	cin>>S;
	n = S.length();

	N = string_to_integer(S,n);
	cout<<N<<"\n";

	return 0;
}
