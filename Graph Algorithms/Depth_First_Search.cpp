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

	void dfs_helper(T src,map<T,bool> &visited){
		// Recursive Function- to traverse the graph

		cout<<src<<" ";
		visited[src] = true;

		for(auto nbr : adjList[src]){
			if(visited[nbr] == false)
				dfs_helper(nbr,visited);
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

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph<ll> G;

    G.add_edge(0,1);
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(3,0);
    G.add_edge(3,4);
    G.add_edge(4,5);

    G.dfs(0);
    cout<<"\n";

    return 0;
}