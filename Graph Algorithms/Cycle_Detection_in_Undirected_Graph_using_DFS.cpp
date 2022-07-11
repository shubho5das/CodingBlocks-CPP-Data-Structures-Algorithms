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

	bool dfs_helper(T src,map<T,bool> &visited,T parent){
		// Recursive Function- to traverse the graph
		// Slightly modified 

		visited[src] = true; 

		for(auto nbr : adjList[src]){
		
			// Special Case
			if(nbr == parent)
				continue;

			if(visited[nbr] == true)
				return true;
			
			bool cycle_present = dfs_helper(nbr,visited,src);
			if(cycle_present)
				return true;
		}

		return false;
	}

	bool check_cycle_present(){
		// DFS Approach

		map<T,bool> visited;

		// Step 1: Mark all nodes as "not visited"
		for(auto x : adjList){
			visited[x.first] = false;
		}

		// Step 2: Traverse the Graph and check for cycles	
		auto it = adjList.begin();
		T src = (*it).first;

		return dfs_helper(src,visited,src);
	}

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph<ll> G;

    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(3,4);
    G.add_edge(4,1);

    if(G.check_cycle_present() == true)
    	cout<<"Cycle is Present\n";
    else
    	cout<<"Cycle is NOT present\n";

    return 0;
} 