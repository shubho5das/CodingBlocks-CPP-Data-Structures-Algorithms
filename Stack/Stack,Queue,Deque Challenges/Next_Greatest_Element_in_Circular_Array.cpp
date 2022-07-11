// KEEP CALM and Enjoy the Problem B-)

/* Solution:
	O(N) Time
	O(N) Extra Space (for solution array[]) 

NOTE: It is always better to store index values in a Stack, than the values itself(as in G4G Soln.)	*/

/* IMP. NOTE:
In case, we are dealing with a normal array (and not a circular array),
 just remove the 2nd pass, that's it!
/*

/* Editorial:
This approach makes use of a stack. This stack stores the indices of the appropriate elements from nums array. The top of the stack refers to the index of the Next Greater Element found so far. We store the indices instead of the elements since there could be duplicates in the nums array. The description of the method will make the above statement clearer.
We start traversing the numsnums array from right towards the left. For an element nums[i] encountered, we pop all the elements stack[top] from the stack such that nums[stack[top]] ≤ nums[i]. We continue the popping till we encounter a stack[top] satisfying nums[stack[top]]>nums[i]. Now, it is obvious that the current stack[top] only can act as the Next Greater Element for nums[i](right now, considering only the elements lying to the right of nums[i]).
If no element remains on the top of the stack, it means no larger element than nums[i] exists to its right. Along with this, we also push the index of the element just encountered(nums[i]), i.e. ii over the top of the stack, so thatnums[i](or stack[topstack[top) now acts as the Next Greater Element for the elements lying to its left.
We go through two such passes over the complete nums array. This is done so as to complete a circular traversal over the nums array. The first pass could make some wrong entries in the res array since it considers only the elements lying to the right of nums[i], without a circular traversal. But, these entries are corrected in the second pass. 
*/

#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

void find_NGE(ll A[],ll n,ll solution[]){

	ll i;
	stack<ll> X;

	// 1st Pass
	for(i=(n-1) ; i>=0 ; i--){
		while( X.size() >= 1 && A[X.top()] <= A[i] )
			X.pop();

		if(X.empty())
			solution[i] = -1;
		else
			solution[i] = A[X.top()];

		X.push(i);
	}

	// 2nd Pass
	for(i=(n-1) ; i>=0 ; i--){
		while( X.size() >= 1 && A[X.top()] <= A[i] )
			X.pop();

		if(X.empty())
			solution[i] = -1;
		else
			solution[i] = A[X.top()];

		X.push(i);
	}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,i;

    cin>>n;
    ll A[n];
    for(i=0 ; i<n ; i++){
    	cin>>A[i];
    }
    ll solution[n];

    find_NGE(A,n,solution); 	// NGE->"Next Greater Element"
    
    for(i=0 ; i<n ; i++){
    	cout<<solution[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}



