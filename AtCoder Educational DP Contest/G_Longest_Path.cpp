#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

const ll N_max = 1e5;

ll dp[N_max+5];

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
        // adjList[y].push_back(x); // Directed Graph
    }

    void dfs_helper(ll src,vector<bool> &visited){
        // Recursive Function- to traverse the graph

        cout<<src<<" ";
        visited[src] = true;

        for(auto nbr : adjList[src]){
            if(visited[nbr] == false)
                dfs_helper(nbr,visited);
        }

        return;
    }

    void dfs(ll src){

        ll i;
        
        // Step 1: Mark all nodes as "not visited"
        vector<bool> visited(V+1,0);
        
        // Step 2: Traverse the Graph
        dfs_helper(src,visited);
    }

    ll find_longest_path(ll i,ll dp[]){
        // Top Down Approach

        ll ans;

        // Base Case
        if(adjList[i].size() == 0){
            return 0;            
        }

        // Recursive Case

        // Look Up
        if(dp[i] != -1)
            return dp[i];

        ans = -inf;
        for(auto nbr : adjList[i]){
            ans = max(ans,(1 + find_longest_path(nbr,dp)));
        }

        dp[i] = ans;
        return ans;
    }


    void solve(){

        ll i,ans;

        memset(dp,-1,sizeof(ll)*(V+1));

        for(i=0 ; i<V ; i++)
            find_longest_path(i,dp);

        ans = -inf;
        for(i=0 ; i<V ; i++){
            ans = max(ans,dp[i]);
        }

        cout<<ans<<"\n";
    }

};

void run_case(){
    
    ll n,m,u,v,i;

    cin>>n>>m;

    graph G(n);

    for(i=0 ; i<m ; i++){
        cin>>u>>v;
        u -= 1, v -= 1;
        G.add_edge(u,v);
    }

    G.solve();

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin>>T;
    while(T--)
        run_case();

    return 0;
}