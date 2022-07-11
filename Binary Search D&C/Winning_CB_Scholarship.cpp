/*
Problem:
Prateek Bhaiya decided to give 100% scholarships to the needy students 
by taking an admission test. However in order to avoid any losses at 
the institute, he came up with a solution. Coding Blocks has N students 
and M discount coupons. A student will get 100% waiver if he gets X 
discount coupons.
However in order to get more discount coupons in addition to those M , 
Bhaiya decided that some students who perform badly in the admission 
tests, need to pay additional amount equivalent to Y discount coupons, 
i.e. good students earn discount coupons and weak students need to pay 
coupons to get admission.

Find out the maximum number of students who can get 100% waiver in their admission fees.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

bool check(ll n,ll m,ll x,ll y,ll num){

	ll total_coupon,required_coupon;

	total_coupon = m + (n - num)*y;
	required_coupon = num*x;

	if(required_coupon <= total_coupon)
		return true;
	else
		return false;
}

void run_case(){

	ll n,m,x,y,s,e,mid,ans;

	cin>>n>>m>>x>>y;

	// Binary Search Algo.
	s = 0;
	e = n;
	while(s <= e){

		mid = (s+e)/2;

		if(check(n,m,x,y,mid) == true){
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}

	cout<<ans<<"\n";

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