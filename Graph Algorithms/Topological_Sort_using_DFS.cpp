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
		//adjList[y].push_back(x); (Directed Graph)
	}

	void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering){
		// Recursive Function- to traverse the graph

		//cout<<src<<" ";
		visited[src] = true;

		for(auto nbr : adjList[src]){
			if(visited[nbr] == false)
				dfs_helper(nbr,visited,ordering);
		}

		// Pushing src, after visiting all its neighbour branches
		// (Bottom-up execution)
		ordering.push_front(src);
		
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


	void print_topological_sorting(){

		map<T,bool> visited;
		list<T> ordering;

		// Step 1: Mark all nodes as "not visited"
		for(auto x : adjList)
			visited[x.first] = false;

		// Step 2: Perform Topological Sort
		for(auto x : adjList){

			T current_node = x.first;
			if(visited[current_node] == false)
				dfs_helper(current_node,visited,ordering);
		}


		// Printing the Topological Sorting
		for(auto x : ordering)
			cout<<x<<" ->";
		cout<<"\n";
	}

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph<string> G;
	
	G.add_edge("Python", "Data Preprocessing");
	G.add_edge("Python", "ML Basics");
	G.add_edge("Python", "Pytorch");
	G.add_edge("Data Preprocessing", "ML Basics");
	G.add_edge("Pytorch", "Deep Learning");
	G.add_edge("ML Basics", "Deep Learning");
	G.add_edge("Deep Learning", "Face Recognition");
	G.add_edge("Dataset", "Face Recognition");    

	G.print_topological_sorting();
 
    return 0;
}