/*
Problem: 
Help Rahul - Pivot Element (Coding Blocks Hackerblocks)

Rahul had a sorted array of numbers from which he had to find a given
number quickly. His friend by mistake rotated the array. Now Rahul 
doesn't have time to sort the elements again. Help him to quickly find
the given number from the rotated array.

Hint: Think Binary Search.

Appraoch: Noted in Diary II (Page 215)

Time Complexity = O(logn).
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<< " is " <<(y)<<"\n"

ll binary_search_in_rotated_array(ll A[],ll n,ll key){

	ll s,e,mid;

	s = 0;
	e = (n-1);
	while(s <= e){

		mid = (s + e)/2;

		if(A[mid] == key)
			return mid;

		if(A[mid] > A[s]){
			
			if( (key >= A[s]) && (key <= A[mid]) )
				e = mid - 1;
			else
				s = mid + 1;
		}
		else{

			if( (key >= A[mid]) && (key <=A[e]) )
				s = mid + 1;
			else
				e = mid - 1;
		}
	}

	return -1;
}

void run_case(){

	ll n,i,key;

	cin>>n;
	ll A[n];
	for(i=0 ; i<n ; i++){
		cin>>A[i];
	}

	cin>>key;

	cout<<binary_search_in_rotated_array(A,n,key)<<"\n";

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