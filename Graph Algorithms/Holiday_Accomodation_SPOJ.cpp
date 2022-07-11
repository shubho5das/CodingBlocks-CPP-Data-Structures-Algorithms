/*
	Problem : Holiday Accomodation- HOLI (SPOJ)

	Time Complexity : O(n) (graph traversal using Djikstra)


	NOTE:
	- The logic implemented by me, is fully corrcect and the 
	below code is totally bug-free as well.

	- As I have used Map to implement the Graph, and as Maps
	are slow, I got TLEed on SPOJ
	- Remedy: Since nodes lie in [1,N] range, 
		use Vector Implementaion of Graph (as noted in Black Diary) 

	- Otherwise, is totally fine B-)
*/

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
	map<ll,list<pair<ll,ll>>> adjList;

public:

	void add_edge(ll u,ll v,ll wt){
		adjList[u].push_back({v,wt});
		adjList[v].push_back({u,wt});
	}

	ll find_max_travel_dist_sum(ll src,map<ll,bool> &visited,ll &ans){
		// dfs_helper() - Recursive Function to traverse the Graph
		
		ll count,nbr_node,wt,left,right,current_count;
		ll n = adjList.size();


		visited[src] = true;

		count = 0;
		for(auto nbr : adjList[src]){

			if(visited[nbr.first] == false){

				nbr_node = nbr.first;
				wt = nbr.second;

				current_count = find_max_travel_dist_sum(nbr_node,visited,ans); // Recursive Function Call

				left = current_count;			   
				right = (n - current_count);	   
				ans += ( wt * (2 * min(left,right)) ); // Bottom Up (code implemented after the Recursive Call)
				
				//watch2(nbr_node,current_count);
				//watch2(left,right);
				//watch(ans);
				//cout<<"\n";

				count += current_count;				   // Bottom Up
			}
		}

		return (count+1);

	}

	ll dfs(ll src){

		ll ans,count;
		map<ll,bool> visited;

		// Step 1: Mark all nodes as "not visited"
		for(auto x : adjList)
			visited[x.first] = false;

		// Step 2: Traverse the Graph
		ans = 0;
		count = find_max_travel_dist_sum(src,visited,ans);

		return ans;
	}

};

void run_case(ll T){

	ll n,i,u,v,w,src;

	cin>>n;

	graph G;

	for(i=0 ; i<(n-1) ; i++){
		cin>>u>>v>>w;
		G.add_edge(u,v,w);
	}

	src = 1;
	cout<<"Case #"<<T<<": "<<G.dfs(src)<<"\n";

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T,i;
    cin>>T;
    for(i=1 ; i<=T ; i++){
        run_case(i);
    }

    return 0;
}