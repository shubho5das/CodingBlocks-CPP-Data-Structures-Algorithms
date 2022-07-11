/*
Problem: Find the smallest window in a String, contaning all
		 characters of a given Patern.

		For example:
		String -> "helllaoeeo world"
		Pattern -> "eelo"

		Ans = "laoee" (length = 5)
	

Time Complexity: O(n)

Concept: Sliding Window + Frequency Arrays 
	(No hashmaps required, lol!
	
	unless, we want to use freqeuncy maps instead of freq 
	arrays; which is totally unnecessary imo!)


Approach/Insights:
	
	Step 1. Make a Pattern Freq Map and initialize with freq of
			characters.
	
	Step 2. Sliding Window:
		
		- Right Expansion
		Expand window towards right, till the characters in
		window have frequency >= pattern_freq
		
		- Left Contraction
		On obtaining the window, contract window from left to 
		remove unnecessary characters.
		(either the char is not present OR its frequency is higher 
		than required)

	Every time we obtain a new window, update min_length

	Step 3: Ouput min_length. 
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18

#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y) cout<<(#x)<<" is "<<(x)<< " and "<<(#y)<< " is " <<(y)<<"\n"

string minimum_widnow_substring(string S,string pattern){

	ll i,count_matching;
	ll start,current_length,min_length,min_index;

	// Special Case
	if(pattern.length() > S.length()){
		return "none";
	}

	ll freq_pattern[256] = {0};
	ll freq_window[256] = {0};
	
	// Step 1
	for(i=0 ; i<pattern.length() ; i++){
		freq_pattern[pattern[i]] += 1;
	}

	// Step 2: Sliding Window
	min_length = LLONG_MAX;
	min_index = -1;
	count_matching = 0;
	start = 0;

	for(i=0 ; i<S.length() ; i++){

		freq_window[S[i]] += 1;

		// Expansion
		if(freq_window[S[i]] >= 1 && freq_window[S[i]] <= freq_pattern[S[i]]){
			count_matching += 1;
		}

		if(count_matching == pattern.length()){
			
			// Contraction 
			char left = S[start];
			while(freq_pattern[left] ==0 || freq_window[left] > freq_pattern[left]){
				// Removing unwanted characters
				freq_window[left] -= 1;

				start += 1;
				left = S[start];
			}

			current_length = (i - start) + 1;
			if(current_length < min_length){
				min_length = current_length;
				min_index = start;
	 		}
		}
	}


	if(min_index == -1){
		return "None";
	}

	string ans = S.substr(min_index,min_length);
	return ans;
}

void run_case(){

	string S = "helllaoeeo world";
	string pattern = "eelo";

	string ans = minimum_widnow_substring(S,pattern); 
	cout<<ans<<"\n";
	cout<<"Length = "<<ans.length()<<"\n";	
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

