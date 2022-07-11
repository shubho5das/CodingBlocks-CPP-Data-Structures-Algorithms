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
		// Directed Graph
		adjList[x].push_back(y);
	}

	bool dfs_helper(T src,map<T,bool> &visited,map<T,bool> &current_path){
		// Recursive Function- to traverse the graph
		// Slightly modified

		visited[src] = true;
		current_path[src] = true;

		for(auto nbr : adjList[src]){

			if(current_path[nbr] == true){
				// Back Edge present
				return true;
			}

			if(visited[nbr] == false){
				bool cycle_present = dfs_helper(nbr,visited,current_path);

				if(cycle_present)
					return true;
			}
		}

		current_path[src] = false;

		return false;
	}

	bool check_cycle_present(){
		// DFS Approach

		map<T,bool> visited;
		map<T,bool> current_path;

		// Step 1: Mark all nodes as "not visited"
		for(auto x : adjList){
			visited[x.first] = false;
			current_path[x.first] = false;
		}

		// Step 2: Traverse the Graph and check for cycles	
		auto it = adjList.begin();
		T src = (*it).first;

		return dfs_helper(src,visited,current_path);
	}

	
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph<ll> G;

    G.add_edge(0,1);
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(3,4);
    G.add_edge(1,5);
    G.add_edge(5,4);
	G.add_edge(5,6); 
	G.add_edge(4,2); // Back Edge
  
    if(G.check_cycle_present() == true)
    	cout<<"Cycle is Present\n";
    else
    	cout<<"Cycle is NOT present\n";

    return 0;
} 