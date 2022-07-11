/* Problem:
There are N cities numbered from 0 to N-1. You have to choose 2 
cities such that there is no path from first city to second city.
You are given information in the form of M pairs (X,Y) i.e there
is an undirected road between city X and city Y.

Find out the number of ways in which cities can be chosen. 

My Approach: 

Here, I have determined the sizes of the connected components
using DFS. 

Time Complexity = O(V + E)
*/

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
	map<T,list<T>> adjList;

public:

	void add_edge(T x,T y){
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	void dfs_helper(T src,map<T,bool> &visited,ll &current_size){
		// Recursive Function- to traverse the graph

		//cout<<src<<" ";
		current_size += 1;
		visited[src] = true;

		for(auto nbr : adjList[src]){
			if(visited[nbr] == false)
				dfs_helper(nbr,visited,current_size);
		}

		return;
	}

	void dfs(T src){

		map<T,bool> visited;

		// Step 1: Mark all nodes as "not visited"
		for(auto x : adjList)
			visited[x.first] = false;

		// Step 2: Traverse the Graph
		dfs_helper(src,visited);
	}

	void find_size_of_all_connected_component(vector<ll> &V){

		ll count,current_size;
		
		map<ll,bool> visited;

		for(auto x : adjList)
			visited[x.first] = false;


		for(auto x : adjList){
			T current_node = x.first;

			if(visited[current_node] == false){
				current_size = 0;
				dfs_helper(current_node,visited,current_size);
				V.push_back(current_size);
			}
		}
	}

	ll count_way(){

		ll i,n,k,count;

		vector<ll> V;

		find_size_of_all_connected_component(V);
		n = adjList.size(); // No. of vertices in the Graph

		count = 0;
		for(i=0 ; i<V.size() ; i++){
			
			k = V[i]; // Size of the ith connected component

			count += ( k * ((n-1) - (k-1)) );
		}

		count /= 2;

		return count;
	}



};

void run_case(){

	ll n,m,i,x,y;

	cin>>n>>m;

	graph<ll> G;

	// Adding all the single vertexes to the Graph (Imp. Step)
	for(i=0 ; i<n ; i++){
		G.add_edge(i,i);
	}

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