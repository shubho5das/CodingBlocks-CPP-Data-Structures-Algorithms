/*
SPOJ: MST - Minimum Spanning Tree 
			(using Prims's)

Time Complexity: O(ElogV)
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
	map<ll,list<pair<ll,ll>>> adjList;

public:

	void add_edge(ll x,ll y,ll wt){
		adjList[x].push_back({y,wt});
		adjList[y].push_back({x,wt});
	}

	ll prim_MST(){

        ll cost,to,weight;

        ll n = adjList.size();
        /* NOTE: Here,We have considered Graph G has vertices in the 
         range [0,(n-1)].

         If in the Problem, we have to consider vertices in
         the range [1,n] instead, 
         do u -= 1,v -= 1; while adding edges to the Graph */  

        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> PQ;
        // Min Heap {wt,node}

        bool visited[n] = {0};


        // Step 1: Start from source vertex
        PQ.push({0,0});

        //Step 2: Keep adding minimum-wt active edges to MST (Greedy)
        cost = 0;
        while(PQ.size() >= 1){

            auto minimum_edge = PQ.top();
            ll to = minimum_edge.second;
            ll weight = minimum_edge.first;

            PQ.pop();

            if(visited[to] == true){
                // The edge is no longer an active edge. Hence, ignore it.
                continue;
            }

            cost += weight;
            visited[to] = true;

            // Pushing all active edges, connected to "to" vertex
            for(auto nbr : adjList[to]){

                ll node = nbr.first;
                ll wt = nbr.second;

                if(visited[node] == false){
                    PQ.push({wt,node});
                } 
            }
        }

        return cost;
	}
};


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,i,u,v,w;

    cin>>n>>m;

    graph G;

    for(i=0 ; i<m ; i++){
    	cin>>u>>v>>w;
    	u -= 1;
    	v -= 1;
    
    	G.add_edge(u,v,w);
    }

    cout<<G.prim_MST()<<"\n";
    
    return 0;
}