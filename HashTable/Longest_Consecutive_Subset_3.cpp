/*
 Method 3: Using unordered_set
 Time Comlexity: O(n)
 Space Complexity: O(n)
    
    Here, using unordered set we can easily determine whether a 
    particular element,A[i] is present or not.
    
    Approach:
    [ *Insights* (stevenkplus style B) ]

    - We iterate over the array elements and check if the element
    just less than A[i],(A[i] - 1) is present or not.
    - If (A[i]-1) is not found, it implies A[i] is the starting 
    point of our streak
    - In that case, while(A[i+1] is found), we keep incrementing 
    our streak length by 1. 
  */

/* NOTE:
    If we use set then, n*logn time required to insert all elements
    Hence, unordered_set used instead. */

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll longest_consecutive_subset(ll A[],ll n){

    ll i,count,max_length;

    unordered_set<ll> P;

    for(i=0 ; i<n ; i++){
        P.insert(A[i]);
    }

    max_length = 1;
    for(i=0 ; i<n ; i++){
        
        // We check is element just less than A[i] is present or not
        // If not present, then A[i] is the start point of the streak
        if(P.find(A[i] - 1) == P.end()){

            count = 1;
            while(P.find(A[i] + 1) != P.end()){
                A[i] += 1;
                count += 1;
            }

            max_length = max(max_length,count);
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