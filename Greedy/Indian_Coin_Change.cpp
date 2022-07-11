/*
Problem:
Find minumum no. of coins/notes to obtain a given amount.

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll make_change(ll coin[],ll n,ll amount){

	ll rem,count,index;

	rem = amount;
	count = 0;
	while(rem > 0){

		auto lower = lower_bound(coin,coin+n,rem);
		index = lower - coin;

		if(coin[index] != rem)
			index -= 1;

		//cout<<coin[index]<<"\n";
		rem -= coin[index];
		count += 1;
	}

	return count;


}

void run_case(){

	ll amount,n;

	ll coin[] = {1,2,5,10,20,50,100,200,500,2000};
	n = sizeof(coin)/sizeof(coin[0]);

	cin>>amount;
	cout<<make_change(coin,n,amount)<<"\n";

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