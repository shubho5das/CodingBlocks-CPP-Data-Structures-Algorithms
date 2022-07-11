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

	void bfs(T src){

		queue<T> Q;
		map<T,bool> visited;

		Q.push(src);
		visited[src] = true;

		while(Q.size() >= 1){

			T current_node = Q.front();
			cout<<current_node<<" ";
			Q.pop();

			// Pushing all unvisited neighbours of current_node
			for(auto nbr: adjList[current_node]){
				if(visited[nbr] == 0){
					Q.push(nbr);
					visited[nbr] = true;
				}
			}

		}
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

    G.bfs(0);
    cout<<"\n";

    return 0;
}