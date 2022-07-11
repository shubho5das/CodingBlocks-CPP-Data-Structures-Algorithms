/*
Problem:
You are given number of pages in n different books and m students. The
books are arranged in ascending order of number of pages. 
Every book must be assigned to some student.

Our task is to assign books in such a way that the maximum number of
pages assigned to a student is minimum.
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

	ll i,count,current_sum;

	count = 1;	
	current_sum = 0;
	for(i=0 ; i<n ; i++){
		
		if(current_sum + A[i] > x){
			count += 1;  // New student
			if(count > m)
				return false;
			
			current_sum = 0;
		}
		
		current_sum += A[i];	
	}

	return true;
}

void run_case(){

	ll n,m,i,ans,sum,maximum;
	ll s,e,mid;

	cin>>n>>m;
	ll A[n];

	sum = 0;
	maximum = LLONG_MIN;
	for(i=0 ; i<n ; i++){
		cin>>A[i];
		sum += A[i];
		maximum = max(maximum,A[i]);
	}
	sort(A,A+n);

	// Binary Search Algorithm
	s = maximum;
	e = sum;
	while(s <= e){

		mid = (s + e)/2;

		if(check(A,n,m,mid) == true){
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
    cin>>T;
    while(T--)
        run_case();

    return 0;
}