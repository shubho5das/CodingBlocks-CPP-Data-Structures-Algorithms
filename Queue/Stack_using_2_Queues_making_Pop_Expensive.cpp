#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class my_stack{
private:
	queue<ll> Q1,Q2;
public:
	void push(ll data){
		Q1.push(data);
	}

	void pop(){
		if(Q1.size() == 0)
			return;
		// Step 1
		ll n = Q1.size();
		for(ll i=1 ; i<=(n-1) ; i++){
			Q2.push(Q1.front());
			Q1.pop();
		}
		// Step 2
		Q1.pop();
		// Step 3
		swap(Q1,Q2); 
	}

	ll top(){
		ll ans,n;

		if(Q1.size() == 0)
			return -1;
		// Step 1
		n = Q1.size();
		for(ll i=1 ; i<=(n-1) ; i++){
			Q2.push(Q1.front());
			Q1.pop();
		}
		// Step 2
		ans = Q1.front();
		// Step 3
		Q2.push(Q1.front());
		Q1.pop();
		// Step 4
		swap(Q1,Q2);
		// Step 5
		return(ans);
	}

	bool empty(){
		return(Q1.size()==0);
	}

	ll size(){
		return(Q1.size());
	}
};

void print_stack(my_stack X){
	// Pass-by-value
	while(X.size() >= 1){
		cout<<X.top()<<" ";
		X.pop();
	}
	cout<<"\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,num;
    my_stack X;

    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	X.push(num);
    }
    print_stack(X);
    cout<<X.top()<<"\n";
    X.pop();
    print_stack(X);

    return 0;
}

