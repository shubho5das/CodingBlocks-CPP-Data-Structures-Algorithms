#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18


#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

template<typename T>
class graph{
private:
	map<T,list<pair<T,ll>>> adjList;

public:

	void add_edge(T x,T y,ll wt){
		adjList[x].push_back({y,wt});
		adjList[y].push_back({x,wt});
	}

	void print_AdjList(){
		for(auto x : adjList){

			cout<<x.first<<" : ";

			list<pair<T,ll>> L = x.second;
			for(auto nbr : L){
				cout<<"("<<nbr.first<<","<<nbr.second<<"),";
			}
			cout<<"\n";
		}
	}

	void djikstra_sssp(T src, T dest){

		unordered_map<T,ll> dist;

		// Set all distances to infinity, initially
		for(auto x : adjList){
			dist[x.first] = LLONG_MAX;
		}

		set<pair<ll,T>> P;

		dist[src] = 0;
		P.insert({0,src});

		while(P.size() >= 1){

			T current_node = (*P.begin()).second;
			ll current_node_distance = (*P.begin()).first;

			// Step 1: Remove the node, which has acquired the shortest distance possible
			P.erase(P.begin());

			// Step 2: Visit nbrs of current node
			for(auto nbr : adjList[current_node]){

				T nbr_node = nbr.first;
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

		/*for(auto x : dist){
			cout<<x.first<<" is at a distace = "<<x.second<<"\n";
		}*/

		cout<<dist[dest];
	}

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph<string> G;

    G.add_edge("Amritsar", "Delhi", 1);
	G.add_edge("Amritsar", "Jaipur", 4);
	G.add_edge("Delhi", "Jaipur", 2);
	G.add_edge("Mumbai", "Jaipur", 8);
	G.add_edge("Bhopal", "Agra", 2);
	G.add_edge("Mumbai", "Bhopal", 3);
	G.add_edge("Agra", "Delhi", 1);

	G.print_AdjList();
	cout<<"\n";

	G.djikstra_sssp("Amritsar","Mumbai");
	cout<<"\n";

    return 0;
}