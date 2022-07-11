/*
Problem:
A super-fast computer has n processors. Given the number of jobs
initially assigned to each processor, determine the minimal number of
rounds needed to achieve the state when every processor has the same 
number of jobs, or to determine that such rebalancing is not possible.

In one round, every processor can transfer at most one job to each of 
its neighbors on the bus. 


Greedy Strategy:
Determine the max load transfer between 2 partitions of the array

Apporach:
Noted/Explained in Diary-II (Pg 211)

Time Complexity = O(n)
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

ll count_min_rounds(ll A[],ll n){

	ll sum,avg,i,diff,transfer,max_transfer;

	sum = 0;
	for(i=0 ; i<n ; i++){
		sum += A[i];
	}
		
	if(sum%n != 0)
		return -1;

	avg = sum/n;

	max_transfer = LLONG_MIN;
	diff = 0;
	for(i=0 ; i<n ; i++){
		// Deficiency/Surplus for the partition [0,i]
		diff += (A[i] - avg);
		// No. of transfers/rounds required to make the deficiecy/surplus = 0
		transfer = abs(diff);

		max_transfer = max(transfer,max_transfer);
	}

	return max_transfer;
	
}

void run_case(){

	ll n,i;

	while(1){

		cin>>n;
		if(n == -1){
			break;
		}

		ll A[n];
		for(i=0 ; i<n ; i++){
			cin>>A[i];
		}

		cout<<count_min_rounds(A,n)<<"\n";	
	}
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