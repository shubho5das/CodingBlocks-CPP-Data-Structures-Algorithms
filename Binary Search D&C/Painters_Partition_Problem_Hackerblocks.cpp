/*
Painters_Partition_Problem_Hackerblocks
(Very similar to "Book Allocation Problem")

Giving WA Verdict on Hackerblocks, don't know why! :(
Must be something wrong with the HB OJ. Everything seems fine from
my end.


Problem:
Given K painters to paint N boards where each painter takes 1 unit of 
time to paint 1 unit of boards i.e. if the length of a particular 
board is 5, it will take 5 units of time to paint the board. 
 Compute the minimum amount of time to paint all the boards.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

bool check(ll A[],ll n,ll k,ll t){

	ll i,count,current;

	count = 1;
	current = 0;
	for(i=0 ; i<n ; i++){

		if( (current + A[i]) > t){
			count += 1;
			current = 0;
		}

		current += A[i];
	}

	if(count <= k)
		return true;
	else
		return false;
}

void run_case(){

	ll k,n,i,s,e,mid,ans;
	ll sum,maximum;

	cin>>k;
	cin>>n;
	ll A[n];
	
	sum = 0;
	maximum = LLONG_MIN;
	for(i=0 ; i<n ; i++){
		cin>>A[i];
		sum += A[i];
		maximum = max(maximum,A[i]);
	}
	sort(A,A+n);
	
	// Binary Seach Algo.
	s = maximum;
	e = sum;
	while(s <= e){

		mid = (s+e)/2;

		if(check(A,n,k,mid) == true){
			ans = mid;
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