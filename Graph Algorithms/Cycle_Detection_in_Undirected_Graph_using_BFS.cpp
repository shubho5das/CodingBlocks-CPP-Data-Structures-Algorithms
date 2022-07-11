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

	bool check_cycle_present(){
		// BFS Approach

		queue<T> Q;
		map<T,bool> visited;

		map<T,T> parent;

		// Source Node
		auto it = adjList.begin();
		T src = (*it).first;

		Q.push(src);
		visited[src] = true;
		parent[src] = src;
		while(Q.size() >= 1){

			T current_node = Q.front();
			Q.pop();

			// Checking all neighbours of current_node
			for(auto nbr : adjList[current_node]){
				
				// Special Case
				if(nbr == parent[current_node])
					continue;

				if(visited[nbr] == true){
					return true;
				}
				else{
					Q.push(nbr);
					visited[nbr] = true;

					parent[nbr] = current_node;
				}
			}

		}
		return false;
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