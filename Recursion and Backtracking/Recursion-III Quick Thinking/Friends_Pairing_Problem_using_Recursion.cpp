#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll nCr(ll n,ll r)
{
	ll ans,i;

    if (r > n) 
    	return 0;

    if (r*2 > n)  
    	r = n-r;  
    
    if (r == 0) 
    	return 1;
 
    ans = n;
    for(i = 2; i <= r; i++) 
    {
        ans =  ans * (n-i+1);
        ans = ans/i;
    }

    return(ans);
}

ll f(ll N)
{
	ll a,b,ans;

	// Base Case
	if(N==2)
		return 2;
	if(N==1)
		return 1;

	// Recursive Case
	a = f(N-1);
	b = f(N-2);

	ans = ( (1*a) + (nCr(N-1,1)*b) );
	return(ans);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);			

	ll N,ans;

	cin>>N;
	ans = f(N);
	cout<<ans<<"\n";

	return 0;
}