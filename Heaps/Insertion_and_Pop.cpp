// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

class my_heap{
private:
	vector<ll> V;
	bool minHeap;

	bool compare(ll a,ll b){
		if(minHeap == true)
			return a < b;
		else
			return a > b;
	}

public:
	// Constructor
	my_heap(){
		V.reserve(101);
		V.push_back(-1);
		minHeap = true;
	}
	// Constructor
	my_heap(ll n,bool type){
		V.reserve(n+1);
		V.push_back(-1);
		minHeap = type;
	}

	void push(ll d){

		ll index,parent;

		V.push_back(d);
		index = V.size() - 1;
		parent = index/2;
		while( index >= 2 && compare(V[index],V[parent])){
			swap(V[index],V[parent]);
			index /= 2;
			parent /= 2;
		}
	}

	void heapify(ll index){

		ll left,right,last,min_index;

		left = 2*index;
		right = (2*index) + 1;
		last = V.size() - 1;

		min_index = index;
		if(left <= last && compare(V[left],V[min_index]))
			min_index = left;
		if(right <= last && compare(V[right],V[min_index]))
			min_index = right;

		// Base Case
		if(min_index == index)
			return;
		// Recursive Case
		swap(V[index],V[min_index]);
		heapify(min_index);
		return;
	}

	void pop(){

		ll last = V.size() - 1;

		// Step 1
		swap(V[1],V[last]);
		// Step 2
		V.pop_back();
		// Step 3
		heapify(1);
	}

	ll top(){
		return V[1];
	}

	ll size(){
		return(V.size() - 1);
	}

	bool empty(){
		return(V.size() == 1);
	}
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    my_heap H1; 			// Min Heap
    my_heap H2(1000,false);	// Max Heap - assuming max size = 1000 (n <= 1000; as given as Constraint in the Problem itself)
    ll num,i,n1,n2;

    // Min Heap
    cin>>n1;
    for(i=0 ; i<n1 ; i++){
    	cin>>num;
    	H1.push(num);
    }

    while(H1.size() >= 1){
    	cout<<H1.top()<<" ";
    	H1.pop();
    }
    cout<<"\n";

    
    // Max Heap
    cin>>n2;
    for(i=0 ; i<n2 ; i++){
    	cin>>num;
    	H2.push(num);
    }

    while(H2.size() >= 1){
    	cout<<H2.top()<<" ";
    	H2.pop();
    }
    cout<<"\n";

    return 0;
}


