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
		ll n,i;
		// Step 1
		Q2.push(data);
		n = Q1.size();
		// Step 2
		for(i=1 ; i<=n ; i++){
			Q2.push(Q1.front());
			Q1.pop();
		}
		// Step 3
		swap(Q1,Q2);
	}

	void pop(){
		Q1.pop();
	}

	ll top(){
		if(Q1.size() == 0)
			return -1;
		return(Q1.front());
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


