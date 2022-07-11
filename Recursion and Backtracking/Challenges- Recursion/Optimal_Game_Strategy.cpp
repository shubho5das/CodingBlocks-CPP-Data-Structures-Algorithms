/* Explanation:
At first look , this looks like a Greedy problem but it is clearly not so. This can clearly be observed in a simple testcase like
4
5 4 8 6
Clearly , we would need an optimal solution for this. At each instance we would need to consider two possibilities that we can pick the first as well as the last element of the remaining array. Both these possibilities give rise to two more possibilities depending on the other player. Since the second player plays optimally and try to minimise our score. So overall we have two possibilities at each instance.
For the first possibility , where we could pick the first element , the other player will pick the next element from the side that would minimise our total score.
Similarly , for the second possibility , where we can pick the last element , the other player would still pick the next element from the side that would minimise our total score.
We entertain both these cases and take the maximum result of the two and return that result.
We take two pointer variables , say ‘i’ and ‘j’ which each represent the starting and the ending point of the remaining array currently in consideration. We work till the two pointers cross each other.
*/

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
using namespace std;

ll optimal_game(ll coin[],ll i,ll j)
{
	ll ans,picking_first_coin,picking_last_coin;

	//Base Case
	if(i>j)
		return 0;

	// Recursive Case

	// Case 1: Me picking 1st Coin,coin[i]
	picking_first_coin = coin[i] + min(optimal_game(coin,i+2,j),optimal_game(coin,i+1,j-1));
	// Case 2: Me picking last Coin,coin[j]
	picking_last_coin = coin[j] + min(optimal_game(coin,i+1,j-1),optimal_game(coin,i,j-2));

	ans = max(picking_first_coin,picking_last_coin);

	return(ans);
	
}


int main()
{
	ios_base::sync_with_stdio(false); // Remove for interactive I/O
	cin.tie(NULL);		

	ll n,i,ans;
	
	cin>>n;
	ll coin[n];
	for(i=0 ; i<n ; i++)
		cin>>coin[i];

	ans = optimal_game(coin,0,n-1);
	cout<<ans<<"\n";

	return 0;
}

