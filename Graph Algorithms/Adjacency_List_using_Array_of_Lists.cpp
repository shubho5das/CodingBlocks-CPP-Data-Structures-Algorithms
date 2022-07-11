#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

class graph{
private:
	ll v;
	list<ll> *L;

public:
	// Constructor
	graph(ll a){
		v = a;
		L = new list<ll>[a];
	}

	void add_edge(ll a,ll b){
		L[a].push_back(b);
		L[b].push_back(a);
	}

	void print_AdjList(){
		ll i;

		for(i=0 ; i<v ; i++){
			cout<<"Vertex "<<i<<": ";
			for(auto nbr : L[i])
				cout<<nbr<<" ";
			cout<<"\n";
		}
	}
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph G(4);
    G.add_edge(0,1);
    G.add_edge(0,2);
    G.add_edge(2,3);
    G.add_edge(1,2);

    G.print_AdjList();

    return 0;
}