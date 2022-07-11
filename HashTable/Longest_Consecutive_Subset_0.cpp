/* Method 0 (Naive approach)

 Simple sorting 
 O(N.LogN)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll longest_consecutive_subset(ll A[],ll n){

	ll i,j,current_length,max_length;

	sort(A,A+n);

	max_length = 1;
	for(i=0 ; i<=(n-2) ; ){

		if( (A[i+1] - A[i]) > 1)
			i += 1;
		else{
			current_length = 1;
			for(j=i ; j<=(n-2) && (A[j+1] - A[j] <=1) ; j++){

				if(A[j+1] == A[j])
					continue;

				current_length += 1;
			}
			
			i = j;
			max_length = max(current_length,max_length);
		}
	}

	return max_length;
}

void run_case(){
	
	ll i,n,ans;

	ll A[] = {14,5,1,2,6,3,7,8,7,9,13,15,11,12,13,17}; 
	// Ans = 5 [5,6,7,8,9]
	n = sizeof(A)/sizeof(A[0]);

	ans = longest_consecutive_subset(A,n);
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