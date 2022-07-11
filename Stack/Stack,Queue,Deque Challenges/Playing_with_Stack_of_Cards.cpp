// KEEP CALM and Enjoy the Problem B-)

// Concept: Made use of Array of Stacks .. NICE!
// Also, a pure "implementation problem". Made me confident with Stack STL B-)

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void prime_sieve(ll X[],ll N)
{
    ll i,j;
    
    for(i=3 ; i<=N ; i=i+2)          // Step 1: First, we consider all odd numbers(3,5,7,...) as Prime 
        X[i] = 1;
        
    for(i=3 ; i<=N ; i=i+2)         // Step 2: Sieve Time B-)
    {
        if(X[i]==1)
        {
            for(j=(i*i) ; j<=N ; j=j+i)
            {
                X[j] = 0;
            }
        }
    }
    X[2] = 1;                      // Step 3: Special Cases
    X[1] = X[0] = 0;
}

ll prime[1299720] = {0};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N,Q,count,i,j,num,x,val;

    cin>>N>>Q;

    prime_sieve(prime,1299715);
    vector<ll> prime_collection;
    i = 0;
    for(count=1 ; count<=Q ; ){

    	if(prime[i] == 1){
    		prime_collection.push_back(i);
    		count += 1;
    	}

    	i += 1;
    }

    stack<ll> A[Q+1]; // Array of Stacks
    stack<ll> B[Q+1];

    for(i=0 ; i<N ; i++){
    	cin>>num;
    	A[0].push(num);
    }

    for(i=1 ; i<=Q ; i++){

    	x = prime_collection[i-1];
    	//cout<<"Prime = "<<x<<"\n";
    	while(A[i-1].size() >= 1){
    		
    		val = A[i-1].top();
    		//cout<<"Value = "<<val<<"\n";
    		
    		if(val%x == 0)
    			B[i].push(val);
    		else
    			A[i].push(val);

    		A[i-1].pop();
    	}    	
    }

    // Final Answer
    for(i=1 ; i<=Q ; i++){
    	if(B[i].size() >= 1){

    		while(B[i].size() >= 1){
    			cout<<B[i].top()<<"\n";
    			B[i].pop();
    		}
    	}
    }
    if(A[Q].size() >= 1){
    	while(A[Q].size() >= 1){
    		cout<<A[Q].top()<<"\n";
    		A[Q].pop();
    	}
    }

    return 0;
}


