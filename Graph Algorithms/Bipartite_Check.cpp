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
	map<ll,list<ll>> adjList;

public:

	void add_edge(ll u,ll v){
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	bool check_bipartite(ll src,map<ll,bool> &visited, map<ll,ll> &colour,ll current_colour){
		// dfs_helper() : Recursive Function to traverse the Graph

		ll nbr_colour;

		visited[src] = true;
		colour[src] = current_colour;

		if(current_colour == 1)
			nbr_colour = 2;
		else if(current_colour == 2)
			nbr_colour = 1;

		for(auto nbr : adjList[src]){

			/* Special Case: Nbr node is already visited and has
			 				 same colour as the current node */
			if(visited[nbr] == true && colour[nbr] == colour[src])
				return false;


			if(visited[nbr] == false){

				bool check = check_bipartite(nbr,visited,colour,nbr_colour);

				if(check == false)
					return false;
			}
		}

		return true;

	}

	bool dfs(ll src){

		map<ll,bool> visited;
		map<ll,ll> colour;

		// Step 1
		for(auto x : adjList){
			visited[x.first] = false;
			colour[x.first] = 0; // no colour assigned initially.
		}

		// Step 2
		bool check = check_bipartite(src,visited,colour,1LL);

		if(check == true)
			return true;
		else
			return false;
	}

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,u,v,i;

    graph G;

    cin>>n>>m;

    for(i=0 ; i<m ; i++){
    	cin>>u>>v;
    	G.add_edge(u,v);
    }

    bool check = G.dfs(1LL);

    if(check == true)
    	cout<<"Graph is Bipartite\n";
    else
    	cout<<"Graph is NOT Bipartite\n";

    return 0;
}