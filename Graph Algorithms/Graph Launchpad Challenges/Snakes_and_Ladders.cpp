// KEEP CALM and Enjoy the Problem B-)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

class graph{
private:
	ll V;
	vector<vector<ll>> adjList;
	
public:

	// Constructor
	graph(ll n){
		V = n;
		adjList = vector<vector<ll>>(n+1); 
	}

	void add_edge(ll x,ll y){
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}

	void print_adjList(){
		ll i;

		for(i=0 ; i<V ; i++){ 
			// Assuming 0-based indexing

			cout<<"Vertex "<<i<<": ";

			for(auto nbr : adjList[i]){
				cout<<nbr<<" ";
			}
			cout<<"\n";
		}
	}

	ll bfs_sssp(ll src,ll dest){

		ll i;
		queue<ll> Q;
		//map<T,ll> dist;
		vector<ll> dist(V+1);

		// for(auto x : adjList)
		// 	dist[x.first] = LLONG_MAX;
		for(i=0 ; i<=V ; i++)
			dist[i] = LLONG_MAX;

		Q.push(src);
		dist[src] = 0;
		while(Q.size() >= 1){

			ll current_node = Q.front();
			Q.pop();

			// Pushing all unvisited neighbours of current_node
			for(auto nbr : adjList[current_node]){

				if(dist[nbr] == LLONG_MAX){
					Q.push(nbr);
					dist[nbr] = dist[current_node] + 1;
				}
			}
		}

		// Printing distances of all nodes from scr
		/*
		for(i=0 ; i<V ; i++){
			// Assuming 0-based indexing
			cout<<i<<": shortest distance = "<<dist[i]<<"\n";
		}
		*/

		return dist[dest];
	}

};

ll find_minimum_move(ll board[],ll n){

	ll i,dice;

	// Step 1: Building the Graph
	graph G(n);

	for(i=0 ; i<=(n-1) ; i++){

		if(board[i] != -1)
			continue;

		for(dice=1 ; dice <=6 ; dice++){
			if( (i + dice) > n)
				continue;

			if(board[i+dice] == -1)
				G.add_edge(i,i+dice);
			else
				// Ladder/Snake encountered
				G.add_edge(i,board[i+dice]);
		}
	}

	// Step 2: Finding the shortest path
	return G.bfs_sssp(0,n);
}


void run_case(){
	
	ll n,l,s,i,x,y;

	cin>>n>>l>>s;

	ll board[n+2];
	for(i=0 ; i<(n+2) ; i++){
		board[i] = -1;
	}

	// Ladders
	for(i=0 ; i<l ; i++){
		cin>>x>>y;
		board[x] = y;
	}
	// Snakes
	for(i=0 ; i<s ; i++){
		cin>>x>>y;
		board[x] = y;
	}

	cout<<find_minimum_move(board,n)<<"\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    cin>>T;
    while(T--)
        run_case();

    return 0;
}