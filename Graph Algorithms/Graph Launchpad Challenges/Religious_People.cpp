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
	ll a,b;
	vector<vector<ll>> adjList;
	
public:

	// Constructor
	graph(ll n,ll p,ll q){
		V = n;
		a = p;
		b = q;
		adjList = vector<vector<ll>>(n+1); 
	}

	void add_edge(ll x,ll y){
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	void print_adjList(){
		ll i;

		for(i=0 ; i<V ; i++){ 
			// Assuming 0-based indexing

			cout<<"Vertex "<<i<<": ";

			for(auto nbr : adjList[i]){
				cout<<nbr<<" ";
			}
			cout<<"\n";
		}
	}

	void dfs_helper(ll src,vector<bool> &visited,ll &length){
		// Recursive Function- to traverse the graph

		visited[src] = true;
		length += 1;

		for(auto nbr : adjList[src]){
			if(visited[nbr] == false)
				dfs_helper(nbr,visited,length);
		}

		return;
	}

	void find_length_of_all_connected_components(ll &cost){

		ll count,i,length;
		
		vector<bool> visited(V+1,0);

		for(i=0 ; i<V ; i++){
			// Assuming, 0-based indexing

			ll current_node = i;

			if(visited[current_node] == false){

				length = 0;
				dfs_helper(current_node,visited,length);
				
				if(b < a)
					cost += (a + b*(length - 1));
				else
					cost += length*a;

			}
		}
	}

	ll find_cost(){

		ll cost;

		cost = 0;
		find_length_of_all_connected_components(cost);
		return cost;
	}
};

void run_case(){

	ll n,m,a,b,i,u,v;

	cin>>n>>m>>a>>b;

	graph G(n,a,b);

	for(i=0 ; i<m ; i++){
		cin>>u>>v;
		u -= 1;
		v -= 1;
		G.add_edge(u,v);
	}

	cout<<G.find_cost()<<"\n";;
    
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