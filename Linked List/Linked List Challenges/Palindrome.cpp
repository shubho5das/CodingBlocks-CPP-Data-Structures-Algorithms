#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
using namespace std;

bool check_palindrome(vector<ll> V,ll n){

	ll i,j;

	i = 0;
	j = (n-1);
	while(i<j){
		if(V[i] != V[j]){
			return false;
		}
		i += 1;
		j -= 1;
	}
	return true;

}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n,num,i,flag;

	cin>>n;
	vector<ll> V;
	for(i=0 ; i<n ; i++){
		cin>>num;
		V.push_back(num);
	}
	flag = check_palindrome(V,n);
	if(flag == 1)
		cout<<"true\n";
	else
		cout<<"false\n";

	return 0;
}