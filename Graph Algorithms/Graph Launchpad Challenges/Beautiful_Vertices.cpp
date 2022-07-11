// KEEP CALM and Enjoy the Problem B-)

/*
I am absolutely sure, my Code is perfectly fine,
and the Code works in O(n) Time (bfs)

Still don't understand, why I'am getting TLE :/

Just ignore, for now!
Hackerblocks is Stupid. Cannot view the test cases
Will practice hard on CF- mashup Contest by demoralizer,Colin,..
and become a Graph Champion very very soon.
LET'S GO, VAMOS`  */


/*
My Insight:
	
	- No cycles present. Thus, every connected component is
	a Tree.

	-For any node (except the master node),

		No. of children = adjList[i].size() - 1;
		( -1 because one of the nbrs is a parent)
*/

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
	vector<vector<ll>> adjList;
	
public:

	// Constructor
	graph(ll n){
		V = n;
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

	/* ----------------  Finding parent[] ----------------------*/

	void dfs_helper2(ll src,vector<bool> &visited,vector<ll> &parent){
		// Recursive Function- to traverse the graph

		visited[src] = true;

		for(auto nbr : adjList[src]){
			if(visited[nbr] == false){

				parent[nbr] = src;

				//cout<<"Parent of "<<nbr<<" : "<<parent[nbr]<<"\n";

				dfs_helper2(nbr,visited,parent);
			}
		}

		return;
	}


	void find_parent(vector<ll> &parent){

		ll i;

		// Step 1
		vector<bool> visited(V+1,0);

		// Step 2
		for(i=0 ; i<V ; i++){
			// Dealing with multiple connected components
			if(visited[i] == false)
				dfs_helper2(i,visited,parent);
		}
	}

	/*------------------------------------------------------ */


	void dfs_helper(ll src,vector<bool> &visited,vector<ll> parent,ll &count){
		// Recursive Function- to traverse the graph

		visited[src] = true;

		// watch(src);
		// watch(parent[src]);

		if(parent[src] != -1){

			ll current_node_children = adjList[src].size() - 1;

			ll parent_node_children;

			if(parent[parent[src]] == -1)
				parent_node_children = adjList[parent[src]].size();
			else
				parent_node_children = adjList[parent[src]].size() - 1;

			// watch(current_node_children);
			// watch(parent_node_children);
			// cout<<"\n";

			if(current_node_children > parent_node_children)
				count += 1;
		}
	
		for(auto nbr : adjList[src]){
			if(visited[nbr] == false){
				dfs_helper(nbr,visited,parent,count);
			}
		}

		return;
	}

	ll count_beautiful_vertices(){

		ll i,count,src;
		
		vector<bool> visited(V+1,0);
		vector<ll> parent(V+1,-1);

		// Finding parent[]
		find_parent(parent);


		count = 0;
		for(i=0 ; i<V ; i++){

			if(visited[i] == false){

				// i is Master Vertex (Root)

				if(adjList[i].size() == 0)
					continue;

				
				src = adjList[i][0];
				
				dfs_helper(src,visited,parent,count);
			}
		}

		return count;
	}
};

void run_case(){

	ll n,m,i,u,v;

	cin>>n>>m;

	graph G(n);

	for(i=0 ; i<m ; i++){
		cin>>u>>v;
		u -= 1;
		v -= 1;
		G.add_edge(u,v);
	}

 	cout<<G.count_beautiful_vertices()<<"\n";

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