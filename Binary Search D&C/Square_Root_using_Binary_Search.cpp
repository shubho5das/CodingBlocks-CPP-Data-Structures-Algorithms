#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"



ld find_square_root(ll n,ll p){

	// Time Complexity = O(logn + 10p)

	ll s,e,mid,i;
	ld ans;

	s = 0;
	e = n;
	while(s <= e){

		mid = (s+e)/2;

		if(mid*mid == n)
			return mid;

		if(mid*mid < n){
			ans = s*1.0;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	// Finding the decimal part of ans
	ld x = 0.1;
	for(i=1 ; i<=p ; i++){
		while(ans*ans <=n)
			ans += x;

		// We have overshooted the actual solution
		ans -= x; 
		
		x /= 10;
	}

	return ans;
	
}

void run_case(){

	ll n,p;

	cin>>n;
	p = 3;
	cout<<find_square_root(n,p)<<"\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin>>T;
    while(T--)
        run_case();

    return 0;
}