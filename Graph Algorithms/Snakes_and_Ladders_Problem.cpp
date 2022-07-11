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
	}

	void print_AdjList(){

		for(auto x: adjList){

			cout<<x.first<<": ";

			list<T> L = x.second;
			for(auto nbr : L)
				cout<<nbr<<" ";
			cout<<"\n";
		}
		
	}

	ll bfs(T src,T dest){

		queue<T> Q;
  		map<T,ll> dist;
		
		map<T,T> parent;

		for(auto x: adjList)
			dist[x.first] = LLONG_MAX;

		Q.push(src);
		dist[src] = 0;
		parent[src] = src;
		while(Q.size() >= 1){

			T current_node = Q.front();
			Q.pop();

			// Pushing all unvisited neighbours of current_node
			for(auto nbr : adjList[current_node]){

				if(dist[nbr] == LLONG_MAX){
					Q.push(nbr);
					dist[nbr] = dist[current_node] + 1;

					parent[nbr] = current_node;
				}
			}
		}

		// Backtracing the shortest path, from dest to src
		T temp = dest; 
		while(temp != src){
			cout<<temp<<"->";
			temp = parent[temp];
		}
		cout<<temp<<" ";
		cout<<"\n";

		return dist[dest];
	}

};

ll find_minimum_move(ll board[37]){

	ll i,dice;

	// Step 1: Building the Graph
	graph<ll> G;

	for(i=0 ; i<=35 ; i++){

		if(board[i] != -1)
			continue;

		for(dice=1 ; dice <=6 ; dice++){
			if( (i + dice) > 36)
				continue;

			if(board[i+dice] == -1)
				G.add_edge(i,i+dice);
			else
				// Ladder/Snake encountered
				G.add_edge(i,board[i+dice]);
		}
	}
	// IMP Step: To include Vertex 36, in our AdjList.
	G.add_edge(36,36); 

	// Step 2: Finding the shortest path
	return G.bfs(0,36);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i;

    ll board[37];
    for(i=0 ; i<37 ; i++){
    	board[i] = -1;
    }
    
    // Ladders
    board[2] = 15;
   	board[5] = 7;
   	board[9] = 27;
   	board[18] = 29;
   	board[25] = 35;
   	// Snakes
   	board[17] = 4;
   	board[20] = 6;
   	board[24] = 16;
   	board[32] = 30;
   	board[34] = 12; 

   	cout<<find_minimum_move(board)<<"\n";

    return 0;
} 