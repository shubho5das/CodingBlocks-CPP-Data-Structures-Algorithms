/*
My Code givng WA Verdict, don't know why :(

[Try implementing Code Prateek Bhaiya style (some time later)
Though, my Logic is exactly same as Prateek Bhaiya's :(         ]


Problem:
There's a truck, initilally having fuel = P. It has to reach a town
L units away. For covering 1 unit distance, 1 unit of fuel gets 
consumed. There are N fuel stations between the Origin and destination.
Find the minimum no. of stops needed to reach the destination.
(Assume capacity of the truck's tank is infinity)

Greedy Strategy:

- Check if we have sufficent fuel to reach the next fuel station/destiation.
-If yes, do nothing. 
If no, keep picking the largest fuel station encounted till then, till 
fuel becomes sufficent.
(for this, we use a max heap)


NOTE:
(Advice for me- to improve my thought-process)
- *Don't think of it as a simulation problem.*
- After reaching fuel station F4, if don't have sufficent fuel to 
reach F5;
it's not that we can choose F4 only.
-We need keep choosing the largest fuel in {F1,F2,F3,F4}. 
-It's not that we had neglected F1 earlier, so we cannot consider again
later on; remember that!


Apporach:

Implement above Logic, using MaxHeaps (priotity queue).

Time Complexity = O(n*logn).
(n for iterating, logn for searching in max heap)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

class fuel_station{

public:	
	ll dist;
	ll fuel;

	// Constructor
	fuel_station(ll a,ll b){
		dist = a;
		fuel = b;
	}
};

bool custom_compare(fuel_station p,fuel_station q){
	return(p.dist < q.dist);
}

void run_case(){

	ll P,L,n,d,f,i,current_dist,current_fuel,count;

	cin>>n;

	vector<fuel_station> V;
	V.reserve(n);

	for(i=0 ; i<n ; i++){
		cin>>d>>f;
		fuel_station x(d,f);
		V.push_back(x);
	}
	

	cin>>L>>P;

	for(i=0 ; i<n ; i++){
		V[i].dist = (L - V[i].dist);
	}
	sort(V.begin(),V.end(),custom_compare);

	
	priority_queue<ll> PQ; // Max Heap

	count = 0;
	current_fuel = P;
	current_dist = 0;
	// Moving from Origin (to station 0)
	if( (V[0].dist - current_dist) > current_fuel){
		cout<<"-1\n";
		return;
	}
	current_dist += V[0].dist;
	current_fuel -= V[0].fuel;
	// Moving from station[i] to station[i+1] for i in [0,(n-2)]
	for(i=0 ; i<=(n-2) ; i++){

		PQ.push(V[i].fuel);

		while((V[i+1].dist - current_dist) > current_fuel){

			if(PQ.size() == 0){
				cout<<"-1\n";
				return;
			}

			current_fuel += PQ.top();
			PQ.pop();
			count += 1;
		}

		// Moving forward
		current_dist += (V[i+1].dist - V[i].dist);
		current_fuel -= (V[i+1].dist - V[i].dist);
	}
	
	// Moving from station[n-1] to destination.
	PQ.push(V[n-1].fuel);
	while((L - current_dist) > current_fuel){
		if(PQ.size() == 0){
			cout<<"-1\n";
			return;
		}
		current_fuel += PQ.top();
		PQ.pop();
		count += 1;
	}


	// Final Answer
	cout<<count<<"\n";
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
