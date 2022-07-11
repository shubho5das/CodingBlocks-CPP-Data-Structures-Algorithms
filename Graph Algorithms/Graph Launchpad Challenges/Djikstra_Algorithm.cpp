// KEEP CALM and Enjoy the Problem B-)
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
	vector<vector<pair<ll,ll>>> adjList; // {nbr,wt}
	
public:

	// Constructor
	graph(ll n){
		V = n;
		adjList = vector<vector<pair<ll,ll>>>(n+1); 
	}

	void add_edge(ll x,ll y,ll w){
		adjList[x].push_back({y,w});
		adjList[y].push_back({x,w});
	}

	void print_adjList(){
		ll i;

		for(i=0 ; i<V ; i++){ 
			// Assuming 0-based indexing

			cout<<"Vertex "<<i<<": ";

			for(auto nbr : adjList[i]){
				
				ll node = nbr.first;
				ll wt = nbr.second;

				cout<<"("<<node<<","<<wt<<") , ";
			}
			cout<<"\n";
		}
	}

	void djikstra_sssp(ll src){

		// Set all distances to infinity, initially
		vector<ll> dist(V+1,LLONG_MAX);


		set<pair<ll,ll>> P;

		dist[src] = 0;
		P.insert({0,src});

		while(P.size() >= 1){

			ll current_node = (*P.begin()).second;
			ll current_node_distance = (*P.begin()).first;

			// Step 1: Remove the node, which has acquired the shortest distance possible
			P.erase(P.begin());

			// Step 2: Visit nbrs of current node
			for(auto nbr : adjList[current_node]){

				ll nbr_node = nbr.first;
				ll nbr_node_distance = nbr.second;

				if( current_node_distance + nbr_node_distance < dist[nbr_node]){

					// Update dist of the nbr node
					// (removing nbr node followed by reinserting the updated nbr node)
					auto it = P.find({dist[nbr_node],nbr_node});
					if( it != P.end())
						P.erase(it);

					dist[nbr_node] = current_node_distance + nbr_node_distance;
					P.insert({dist[nbr_node],nbr_node});
					
				}
			}
		}

		
		for(ll i=0 ; i<V ; i++){
			// Assuming 0-based indexing
			
			if(i == src)
				continue;

			if(dist[i] == LLONG_MAX)
				cout<<"-1 ";
			else
				cout<<dist[i]<<" ";

		}
		
	}	

};

void run_case(){
    
    ll n,m,i,u,v,w,src;

    cin>>n>>m;

    graph G(n);

    for(i=0 ; i<m ; i++){
    	cin>>u>>v>>w;
    	u -= 1;
    	v -= 1;
    	G.add_edge(u,v,w);
    }

    cin>>src;
    src -= 1;

    G.djikstra_sssp(src);
    cout<<"\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    cin>>T;
    while(T--)
        run_case();

    return 0;
}