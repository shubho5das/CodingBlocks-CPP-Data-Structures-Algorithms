#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

class graph{

	/* NOTE: Here,We have considered Graph G has vertices in the 
			 range [0,(V-1)].

			 If in the Problem, we have to consider vertices in
			 the range [1,V] instead, 
			 keep doing u -= 1,v -= 1; while adding edges to the
			 Graph

	*/  
	
private:

	ll V;
	list<pair<ll,ll>> L; // Edge-List

public:

	// Constructor
	graph(ll x){
		V = x;
	}

	void add_edge(ll u,ll v){
		L.push_back({u,v}); 
	}

	// DSU Functions
	ll find_set(ll i,ll parent[]){
		// Base Case
		if(parent[i] == -1)
			return i;

		// Recursive Case
		return find_set(parent[i],parent);
	}

	void union_set(ll x,ll y,ll parent[]){

		ll S1 = find_set(x,parent);
		ll S2 = find_set(y,parent);

		if(S1 != S2)
			parent[S2] = S1;
	}

	bool check_cycle_present(){
		// DSU Approach

		ll i,j,S1,S2;

		ll parent[V];
		for(i=0 ; i<V ; i++)
			parent[i] = -1;

		// Adding all edges, one-by-one
		for(auto edge : L){

			i = edge.first;
			j = edge.second;

			S1 = find_set(i,parent);
			S2 = find_set(j,parent);

			if(S1 != S2)
				union_set(S1,S2,parent);
			else
				return true;
		}

		return false;
	}
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph G(4);

    G.add_edge(0,1);
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(3,0);

    if(G.check_cycle_present())
    	cout<<"Yes, cycle is present\n";
    else
    	cout<<"No, cycle is NOT present\n";

    return 0;
}