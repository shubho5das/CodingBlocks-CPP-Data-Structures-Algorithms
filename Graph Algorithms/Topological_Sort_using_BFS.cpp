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

	void topological_sort(){

		map<T,ll> indegree;

		// Step 1: Calculating in-degree of all nodes

		for(auto x : adjList)
			indegree[x.first] = 0;

		for(auto x : adjList){
			for(auto node : x.second)
				indegree[node] += 1;
		}

		// Step 2: Performing Topological Sort
				
		queue<T> Q;
		// Pushing all nodes with in-degree = 0
		for(auto x : adjList){
			if(indegree[x.first] == 0)
				Q.push(x.first);
		}

		while( Q.size() >= 1){

			T current_node = Q.front();
			cout<<current_node<<" ";
			// Removing current_node from Graph
			Q.pop();
			// Decrementing "In-degree of nbrs" by 1
			for(auto nbr : adjList[current_node]){
				indegree[nbr] -= 1;

				// Pushing nodes with in-degree = 0
				if(indegree[nbr] == 0)
					Q.push(nbr);
			}
		}
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

	G.topological_sort();
	cout<<"\n";
 
    return 0;
}