/* Problem:
There are N cities numbered from 0 to N-1. You have to choose 2 
cities such that there is no path from first city to second city.
You are given information in the form of M pairs (X,Y) i.e there
is an undirected road between city X and city Y.

Find out the number of ways in which cities can be chosen. 


Here, I have determined the sizes of the connected components
using DSU. 
Time Complexity = O(V + E) */

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
	ll V;
	list<pair<ll,ll>> L; // Edge-List

public:

	// Constructor
	graph(ll x){
		V = x;
	}

	void add_edge(ll u,ll v){
		L.push_back({u,v}); 
		L.push_back({v,u}); // For Undirected Graph
	}

	// DSU Functions

	ll find_set(ll i,ll parent[]){
		// Path Compression Optimisation.
		
		// Base Case
		if(parent[i] == -1)
			return i;

		// Recursive Case
		parent[i] = find_set(parent[i],parent);
		return find_set(parent[i],parent);
	}

	void union_set(ll x,ll y,ll parent[],ll rank[]){
		// Union by Rank Optimisation
		
		ll S1 = find_set(x,parent);
		ll S2 = find_set(y,parent);

		if(S1 != S2){
			if(rank[S1] < rank[S2]){
				parent[S1] = S2;
				rank[S2] += rank[S1];
			}
			else{
				parent[S2] = S1;
				rank[S1] += rank[S2];
			}
		}
	}

	ll count_way(){
		
		ll i,j,S1,S2,count;

		ll parent[V];
		ll rank[V];

		for(i=0 ; i<V ; i++){
			parent[i] = -1;
			rank[i] = 1;
		}
			
		// Adding all edges, one-by-one
		for(auto edge : L){ 
			i = edge.first;
			j = edge.second;

			S1 = find_set(i,parent);
			S2 = find_set(j,parent);

			if(S1 != S2)
				union_set(S1,S2,parent,rank);
		}

		count = 0;
		for(i=0 ; i<V ; i++){
			count += ( (V-1) - (rank[find_set(i,parent)] - 1) );
		}

		count /= 2;

		return count;
	}
};

void run_case(){

	ll n,m,i,x,y;

	cin>>n>>m;

	graph G(n);

	// Constructing the Graph
	for(i=0 ; i<m ; i++){
		cin>>x>>y;
		G.add_edge(x,y);
	}

	cout<<G.count_way()<<"\n";
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