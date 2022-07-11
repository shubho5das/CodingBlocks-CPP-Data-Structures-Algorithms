/*
 Method 2: Hashing, using urordered_map
 Time Comlexity: O(n)

When we insert a new element:
    Case 1: New streak of length 1
    Case 2: Left expansion 
    Case 3: Right expansion
    Case 4: Join left and right streaks */

/* NOTE:
    If we use map then, n*logn time required to insert all elements
    Hence, unordered_map used. */

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll longest_consecutive_subset(ll A[],ll n){

    ll i,len,len1,len2,new_len,max_length;

    unordered_map<ll,ll> M;
    // unordered_map<A[i], streak_length>

    // NOTE: We store streak length at only the leftmost and 
    // rightmost values of the streak.

    for(i=0 ; i<n ; i++){
        
        bool left_present = false;
        bool right_present = false;

        if(M.find(A[i] - 1) != M.end())
            left_present = true;
        if(M.find(A[i] + 1) != M.end())
            right_present = true;

        //Case 1: New streak of length 1
        if(!left_present && !right_present){
            M[A[i]] = 1;
        }
        //Case 2: Left expansion 
        else if(right_present && !left_present){
            len = M[A[i] + 1];

            new_len = len + 1;

            M[A[i] + len] = new_len;
            M[A[i]] = new_len;
        }
        //Case 3: Right expansion
        else if(left_present && !right_present){
            len = M[A[i] - 1];

            new_len = len + 1;

            M[A[i] - len] = new_len;
            M[A[i]] = new_len;
        }
        //Case 4: Join left and right streaks 
        else if(right_present && left_present){
            len1 = M[A[i] - 1];
            len2 = M[A[i] + 1];

            new_len = len1 + 1 + len2;

            M[A[i] - len1] = new_len;
            M[A[i] + len2] = new_len;
        }
    }

    max_length = 1;
    for(auto x : M){
        max_length = max(max_length,x.second);
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