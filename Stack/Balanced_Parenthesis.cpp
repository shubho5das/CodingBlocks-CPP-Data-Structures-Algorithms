#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

bool check_balanced(string S){

	ll n,i;
	stack<char> X;

	n = S.length();
	for(i=0 ; i<n ; i++){
		if(S[i] == '(')
			X.push('(');
		else if(S[i] == ')'){
			// Special Case
			if(X.empty())
				return false;

			if(X.top() == '(')
				X.pop();
			else if(X.top() == ')')
					return false;
		}
	}

	if(X.empty())
		return true;
	else
		return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin>>S;
    bool check = check_balanced(S);
    if(check == true)
    	cout<<"YES\n";
    else 
    	cout<<"NO\n";

    return 0;
}
