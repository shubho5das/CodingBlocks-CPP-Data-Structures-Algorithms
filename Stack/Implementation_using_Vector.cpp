#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

template<typename T>
class my_stack{
private:
	vector<T> V;
public:
	void push(T data){
		V.push_back(data);
	}
	bool empty(){
		return(V.size()==0);
	}
	void pop(){
		if(!empty())
			V.pop_back();
	}
	T top(){
		return(V[V.size()-1]);
	}
	T size(){
		return(V.size());
	}
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,num;
    my_stack<ll> X;

    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	X.push(num);
    }

    while(X.size()>0){
    	cout<<X.top()<<" ";
    	X.pop();
    }
    cout<<"\n";

    return 0;
}


