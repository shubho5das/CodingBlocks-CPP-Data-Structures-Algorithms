/*
Problem:
IEEE is having its AGM next week and the president wants to serve 
cheese prata after the meeting. The subcommittee members are asked to
go to food connection and get P(P<=1000) pratas packed for the 
function. The stall has L cooks(L<=50) and each cook has a rank 
R(1<=R<=8). A cook with a rank R can cook 1 prata in the first R 
minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes 
and so on(he can only cook a complete prata) 

 The webmaster wants to know the minimum time to get the order done. 
Please write a program to help him out.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

bool check(ll A[],ll n,ll P,ll t){

	ll count,i,R,x,current;

	count = 0;
	for(i=0 ; i<n ; i++){
		
		current = A[i];
		R = A[i];
		x = 1;
		while(current <= t){
			count += 1;

			x += 1;
			current += (x*R);
		}
	
		if(count >= P)
			return true;
	}

	return false;
}

void run_case(){

	ll P,n,i,s,e,mid,ans;

	cin>>P;
	cin>>n;
	ll A[n];
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}
	sort(A,A+n);

	// Binary Search Algo.
	s = 0;
	e = 1000000000000;
	while(s <= e){

		mid = (s+e)/2;

		if(check(A,n,P,mid) == true){
			ans = mid;
			//watch(ans);
			e = mid - 1;
		}
		else
			s = mid + 1;
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