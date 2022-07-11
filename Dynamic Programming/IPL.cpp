/*
Problem can be formulated as, 
Given a sequence of positive numbers, 
find the maximum sum that can be formed which has no three consecutive elements present.

Input: arr[]={1,2,3} Output: 5 We can’t take three of them, so answer is 2+3=5
Input: arr[]={3000,2000,1000,3,10} Output: 5013
Input: arr[]={100,1000,100,1000,1} Output: 2101 100+1000+1000+1=2101

sum[i] : Stores result for subarray arr[0..i], i.e.,maximum possible sum in subarray arr[0..i] such that no three elements are consecutive. sum[0] = arr[0] Note : All elements are positive sum[1] = arr[0] + arr[1] We have three cases 1) Exclude arr[2], i.e., sum[2] = sum[1] 2) Exclude arr[1], i.e., sum[2] = sum[0] + arr[2] 3) Exclude arr[0], i.e., sum[2] = arr[1] + arr[2] sum[2] = max(sum[1], arr[0] + arr[2], arr[1] + arr[2])

In general, We have three cases 
1) Exclude arr[i], i.e., sum[i] = sum[i-1] 
2) Exclude arr[i-1], i.e., sum[i] = sum[i-2] + arr[i] 
3) Exclude arr[i-2], i.e., sum[i-3] + arr[i] + arr[i-1] 
sum[i] = max(sum[i-1], sum[i-2] + arr[i], sum[i-3] + arr[i] + arr[i-1])

*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
    }
    
    size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
    }
};

ll dp[1000005];

ll find_max_earning(ll A[],ll n){
    // Bottom Up
    // dp[i] = Max earning till ith match

    ll i,op1,op2,op3;

    memset(dp,0,sizeof(dp));

    // Base Case
    if(n>=1)
        dp[0] = A[0];
    if(n>=2)
        dp[1] = (A[0] + A[1]);
    if(n>=2)
        dp[2] = max({dp[1],(A[0] + A[2]),(A[1] + A[2])});

    // General Case

    for(i=3 ; i<n ; i++){
        op1 = dp[i-1];                      // exclude A[i]
        op2 = A[i] + dp[i-2];               // exclude A[i-1]
        op3 = A[i] + A[i-1] + dp[i-3];      // exclude A[i-2]

        dp[i] = max({op1,op2,op3});
    }

    return dp[n-1];
}

void run_case(){
    
    ll n,i;

    cin>>n;
    ll A[n];
    for(i=0 ; i<n ; i++){
        cin>>A[i];
    }

    cout<<find_max_earning(A,n)<<"\n";

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