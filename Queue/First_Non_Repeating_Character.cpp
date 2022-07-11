#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll i,n;
    string input;
    string output;
    queue<char> Q;

    ll freq[30] = {0};

    cin>>input;
    n = input.length();
    for(i=0 ; i<n ; i++){
    	// Step 1
    	Q.push(input[i]);
    	//Step 2
    	freq[(ll)(input[i] - 'a')] += 1;
    	// Step 3
    	if(freq[(ll)(Q.front() - 'a')] == 1)
    		output += Q.front();
    	else{
    		while(freq[(ll)(Q.front() - 'a')] > 1 && Q.size()>0){
    			Q.pop();
    		}
    		if(Q.size()==0){
    			output += "-1";
    		}
    		else
    			output += Q.front();
    	}
    }

    for(i=0 ; i<output.length() ; i++)
    	cout<<output[i];
    cout<<"\n";

    return 0;
}


