#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class my_queue{
private:
	stack<ll> X1;
	stack<ll> X2;
public:
	void push(ll data){
		X1.push(data);
	}

	bool empty(){
		return(X1.size()==0 && X2.size()==0);
	}

	ll size(){
		return(X1.size());
	}

	void pop(){
		ll n,i;
		if(X1.size() == 0)
			return;
		//Step 1
		n = X1.size();
		for(i=1 ; i<=(n-1) ; i++){
			X2.push(X1.top());
			X1.pop();
		}
		// Step 2
		X1.pop();
		// Step 3
		n = X2.size();
		for(i=1 ; i<=n ; i++){
			X1.push(X2.top());
			X2.pop();
		}
		// No swapping required here
	}

	ll front(){
		ll n,i,ans;
		if(X1.size() == 0)
			return -1;
		// Step 1
		n = X1.size();
		for(i=1 ; i<=(n-1) ; i++){
			X2.push(X1.top());
			X1.pop();
		}
		// Step 2
		ans = X1.top();
		X2.push(X1.top());
		X1.pop();
		// Step 3
		n = X2.size();
		for(i=1 ; i<=n ; i++){
			X1.push(X2.top());
			X2.pop();
		}
		// Step 4
		return(ans);
	}

	ll back(){
		if(X1.size() == 0)
			return -1;
		return(X1.top());
	}
};

void print_queue(my_queue Q){
	// Pass-by-value
	ll n,i;

	n = Q.size();
	for(i=1 ; i<=n ; i++){
		cout<<Q.front()<<" ";
		Q.pop();
	}
	cout<<"\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,num,i;
    my_queue Q;

    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	Q.push(num);
    }
    print_queue(Q);
    cout<<Q.front()<<"\n";
    cout<<Q.back()<<"\n";
    Q.pop();
    print_queue(Q);

    return 0;
}


