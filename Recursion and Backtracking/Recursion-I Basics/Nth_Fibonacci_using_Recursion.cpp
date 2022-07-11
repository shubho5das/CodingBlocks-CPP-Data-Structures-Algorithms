/* We assume, 1st Term of Fibonacci Sequence is 1, not 0

ie, Fibonacci Sequence : 1 1 2 3 5 8 13 21 ...
				         not, 0 1 1 2 3 5 8 13 21 ... 
*/  

#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll fibonacci(ll N)
{
	ll ans;

	// Base Case
	if(N==0)
		return(0);
	if(N==1)
		return(1);

	// Recursive Case
	ans = ( fibonacci(N-1) + fibonacci(N-2) );
	return(ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N,ans;

	cin>>N;
	ans = fibonacci(N);
	cout<<ans<<"\n";

	return 0;
}