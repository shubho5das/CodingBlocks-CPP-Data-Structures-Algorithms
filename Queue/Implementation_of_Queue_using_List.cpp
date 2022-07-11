#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

template<typename T>
class my_queue{
private:
	list<T> L;
public:
	
	bool empty(){
		return(L.size()==0);
	}

	void push(T data){
		L.push_back(data);
	}

	void pop(){
		if(!empty())
			L.pop_front();
	}

	T front(){
		return(L.front());
	}

	T back(){
		return(L.back());
	}

	ll size(){
		return(L.size());
	}
};

void print_queue(my_queue<ll> Q){ // Pass-by_value
	while(Q.size() > 0){
		cout<<Q.front()<<" ";
		Q.pop();
	}
	cout<<"\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i,num;
    my_queue<ll> Q;

    cin>>n;
    for(i=0 ; i<n ; i++){
    	cin>>num;
    	Q.push(num);
    }
    print_queue(Q);
    Q.pop();
    print_queue(Q);
    
    return 0;
}
