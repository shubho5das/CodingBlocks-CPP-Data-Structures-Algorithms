#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
using namespace std;

int main(){

    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    ll n,m,i,j;
    unordered_map<string,vector<string>> M;

   	cout<<"How many persons?\n";
    cin>>n;
    for(i=0 ; i<n ; i++){
    	
    	string name;
    	cout<<"Enter name\n";
    	cin>>name;	
    	cout<<"How many phone numbers?\n";
    	cin>>m;
    	cout<<"Enter "<<m<<" phone numbers\n";
    	for(j=0 ; j<m ; j++){
    		string phone_number;    		
    		cin>>phone_number;
    		M[name].push_back(phone_number);
    	}
    }

    for(auto x : M){
    	cout<<"Name : "<<x.first<<"\n";
    	for(auto s : x.second)
    		cout<<s<<" ";
    	cout<<"\n";
    }
    
    return 0;
}

