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
	map<T,list<pair<T,pair<ll,ll>>>> adjList;

public:

	void print_AdjList(){
		for(auto x : adjList){

			cout<<x.first<<" : ";

			list<pair<T,pair<ll,ll>>> L = x.second;
			for(auto nbr : L){
				cout<<nbr.first<<" "<<"("<<nbr.second.first<<","<<nbr.second.second<<"), ";
			}
			cout<<"\n";
		}
	}

	void add_edge(T x,T y,ll train,ll plane){
		adjList[x].push_back({y,{train,plane}});
		adjList[y].push_back({x,{train,plane}});
	}

	void djikstra_sssp(T src,unordered_map<T,ll> &dist){
		// NOTE: We need to apply djikstra_sssp() for train routes only.

		// We pass this as parameter to the function itself
		//unordered_map<T,ll> dist; 
		

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
				ll nbr_node_distance = nbr.second.first;

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

	}

	
	ll find_minimum_cost(T src,T dest){

		ll min_cost,cost;

		unordered_map<T,ll> train_price_1; 
		unordered_map<T,ll> train_price_2;

		djikstra_sssp(src,train_price_1);
		djikstra_sssp(dest,train_price_2);

		min_cost = LLONG_MAX;
		// Case 1: 0 Plane Tickets
		cost = 0;
		cost += train_price_1[dest];
		min_cost = min(min_cost,cost);
		
		// Case 2: 1 Plane ticket
		for(auto x : adjList){
			for(auto y : adjList){

				// X and Y must be connected with an edge  (ie, Y must be a neighbout of X)
				bool found = false;
				list<pair<T,pair<ll,ll>>> L = x.second;
				for(auto nbr : L){
					if(nbr.first == y.first){
						found = true;
						break;
					}
				}

				if(found){

					cost = 0;

					// src --> x , via train   
					cost += train_price_1[x.first];
					// x --> y   , via plane
					for(auto m : adjList[x.first]){
						if(m.first == y.first){
							cost += m.second.second;
							break;
						}
					}
					// dest --> y , via train
					cost += train_price_2[y.first];

					min_cost = min(min_cost,cost);
					
				}
			}
		}

		return min_cost;
	}
	
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph<string> G;

	G.add_edge("Amritsar", "Delhi", 1, 5);
	G.add_edge("Amritsar", "Jaipur", 4, 10);
	G.add_edge("Delhi", "Jaipur", 2, 1);
	G.add_edge("Mumbai", "Jaipur", 8, 1);
	G.add_edge("Bhopal", "Agra", 2, 2);
	G.add_edge("Mumbai", "Bhopal", 3, 5);
	G.add_edge("Agra", "Delhi", 1, 2);

	G.print_AdjList();

	cout<<G.find_minimum_cost("Delhi","Mumbai")<<"\n";
    return 0;
}