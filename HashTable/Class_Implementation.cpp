#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mod 1000000007 // 1e9+7
#define inf 1e18
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n"
using namespace std;

template<typename T>
class node{
public:
	string key;
	T value;
	node<T> *next;

	// Constructor
	node(string S,T val){
		key = S;
		value = val;
		next = NULL;
	}
	// Destructor
	~node(){
		if(next != NULL)
			delete next;
	}
};

template<typename T>
class Hashtable{
private:
	node<T> **table;
	ll current_size;
	ll max_size;

	ll hash_function(string key){
		ll index,p,i,M;

		M = max_size;
		p = 1;
		index = 0;
		for(i=0 ; i<key.length() ; i++){
			index += ((ll)(key[i]) * p)%M;
			index = index%M;

			p = (p*27)%M;
		}
		return index;
	}

	void rehash(){
		
		ll old_max_size,i;
		
		node<T> **old_table = table;

		old_max_size = max_size;
		max_size = 2 * max_size;

		// Creating the new table
		table = new node<T>*[max_size]; // try replacing T with ll
		for(i=0 ; i<max_size ; i++)
			table[i] = NULL;

		// Shifting elements from old table to new table
		current_size  = 0;
		for(i=0 ; i<old_max_size ; i++){
			node<T>* temp = old_table[i];
			while(temp != NULL){
				insert(temp->key,temp->value);
				temp = temp->next;
			}

			if(old_table[i] != NULL)
				delete old_table[i];
		}
		// Deleting old table
		delete[] old_table;
	}

public:
	// Constructor
	Hashtable(ll size = 7){
		max_size = size;
		table = new node<T>*[max_size]; 
		current_size = 0;
		for(ll i=0 ; i<max_size ; i++)
			table[i] = NULL;
	}

	void insert(string key,T val){
		ll index;

		index = hash_function(key);
		// Inserting at head of the LL
		node<T> *n = new node<T>(key,val);
		n->next = table[index];
		table[index] = n;

		current_size += 1;
		ld load_factor = current_size/(1.0 * max_size);
		if(load_factor > 0.75)
			rehash();
	}

	T* search(string key){
		ll index;

		index = hash_function(key);
		node<T>* temp = table[index];
		while(temp != NULL){
			if(temp->key == key)
				return &(temp->value);

			temp = temp->next;
		}
		return NULL;
	}

	void erase(string key){
		int index = hash_function(key);
		node<T>* temp = table[index];

		// toBeDeleted is at head
		if (temp && temp->key == key) {
			table[index] = temp->next;
			temp->next = NULL;
			delete temp;
			return;
		}

		while (temp->next && temp->next->key != key) 
			temp = temp->next;
		
		if (temp->next) {
			node<T> *toBeDeleted = temp->next;
			temp->next = toBeDeleted->next;
			// toBeDeleted->next has to be set to NULL, otherwise the delete function will recursively
			// delete the entire linked list after that
			toBeDeleted->next = NULL;
			delete toBeDeleted;
		}
	}

	void print(){
		ll i;

		for(i=0 ; i<max_size ; i++){
			cout<<"Bucket "<<i<<": ";

			// Traversing through the ith LL
			node<T> *temp = table[i];
			while(temp !=  NULL){
				cout<<temp->key<<" ";
				temp = temp->next;
			}
			cout<<"\n";
		}
	}
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Hashtable<ll> menu;

    cout<<"After inserting 4 entries: \n";
    menu.insert("Burger",220);
    menu.insert("Pizza",260);
    menu.insert("Coke",90);
    menu.insert("Wrap",175);
    menu.print();
    cout<<"\n";

    
    cout<<"After inserting 3 more entries:\n"; 
    // to demonstrate rehashing
    menu.insert("Pastry",70);
    menu.insert("Coffee",120);
    menu.insert("Wafer",80);
    menu.print();
    cout<<"\n";
    
    cout<<"After erasing \"burger\" from menu:\n";
    menu.erase("Burger");
    menu.print();
    cout<<"\n";

    // Searching for the value of a particular key
    ll *p = menu.search("Coke");
    if(p != NULL)
    	cout<<"Price of coke = "<<*p<<"\n";
	
    return 0;
}

