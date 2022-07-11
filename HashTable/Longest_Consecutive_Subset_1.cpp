/* Method 1:

Storing freq and iterating through min to max
O(max - min)

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

    ll minimum,maximum,count,max_count,i;

    minimum = LLONG_MAX;
    maximum = LLONG_MIN;
    for(i=0 ; i<n ; i++){
        minimum = min(A[i],minimum);
        maximum = max(A[i],maximum);
    }
    
    map<ll,bool> M;    
    // map(value,bool present)
    for(i=minimum ; i<= maximum ; i++){
        M[i] = false;
    }
    for(i=0 ; i<n ; i++){
        M[A[i]] = true;
    }

    max_count = 0;
    count = 0;
    for(i=minimum ; i<=maximum ; i++){

        if(M[i] == true){
            count += 1;
            max_count = max(count,max_count);
        }
        else{
            max_count = max(max_count,count);
            count = 0; // Resetting the value of count
        }
    }
    
    return max_count;
}

void run_case(){
	
	ll i,n;

    ll A[] = {14,5,1,2,6,3,7,8,7,9,13,15,11,12,13,17}; 
    // Ans = 5 [5,6,7,8,9]
	n = sizeof(A)/sizeof(A[0]);

    sort(A,A+n);
    for(i=0 ; i<n ; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    

    cout<<longest_consecutive_subset(A,n)<<"\n";

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