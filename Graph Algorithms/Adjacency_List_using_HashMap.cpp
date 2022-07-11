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
	unordered_map<string,list<pair<string,ll>>> adjList;

public:

	void add_edge(string x,string y,ll wt,bool is_directed){

		adjList[x].push_back(make_pair(y,wt));

		// Undirected Edge
		if(is_directed == false){ 
			adjList[y].push_back(make_pair(x,wt));
		}
	}

	void print_AdjList(){

		for(auto x: adjList){

			cout<<x.first<<": ";

			list<pair<string,ll>> L = x.second;
			for(auto nbr : L)
				cout<<"("<<nbr.first<<","<<nbr.second<<") ";
			cout<<"\n";
		}
		
	}

	ll count_vertices(){
		return(adjList.size());
	}

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    graph G;

    G.add_edge("A","B",20,false);
    G.add_edge("A","D",50,true);
    G.add_edge("A","C",10,false);
    G.add_edge("B","D",30,false);
    G.add_edge("C","D",40,false);

    G.print_AdjList();
    cout<<"\n";

    cout<<"Number of Vertices = "<<G.count_vertices()<<"\n";

    return 0;
}