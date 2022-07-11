/*
Problem:
Lumberjack Mirko needs to chop down M metres of wood. It is an easy job 
for him since he has a nifty new woodcutting machine that can take down 
forests like wildfire. However, Mirko is only allowed to cut a single 
row of trees.
Mirko's machine works as follows: Mirko sets a height parameter H (in 
metres), and the machine raises a giant sawblade to that height and 
cuts off all tree parts higher than H (of course, trees not higher than 
H meters remain intact). Mirko then takes the parts that were cut off. 
 Mirko is ecologically minded, so he doesn't want to cut off more wood 
than necessary. That's why he wants to set his sawblade as high as 
possible. 

Help Mirko find the maximum integer height of the sawblade that still 
allows him to cut off at least M metres of wood.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

bool check(ll A[],ll n,ll m,ll x){

	ll wood,i;

	wood = 0;
	for(i=0 ; i<n ; i++){
		wood += max(0LL,(A[i] - x));
	}
	//watch2(x,wood);

	if(wood >= m)
		return true;
	else
		return false;
}

void run_case(){

	ll n,m,i,s,e,mid,ans;

	cin>>n>>m;
	ll A[n];
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}

	// Binary Search Algo.
	s = 0;
	e = 1000000000000000;
	while(s <= e){

		mid = (s + e)/2;

		if(check(A,n,m,mid) == true){
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