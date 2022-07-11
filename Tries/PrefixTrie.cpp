#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node{
public:
    char data;
    unordered_map<char,Node*> m;
    bool isTerminal;

    // Constructor
    Node(char data){
        this->data = data;
        isTerminal = false;
    }
};

class Trie{
public:
    Node *root;

    // Constructor
    Trie(){
        root = new Node('\0');
    }

    // Functions
    void insert(string word){
        int word_len,i;
        word_len = word.length();

        Node *current = root;
        for(i=0 ; i<word_len ; i++){
            char ch = word[i];

            if( (current->m).find(ch) == (current->m).end() ){
                Node *n = new Node(ch);
                (current->m)[ch] = n;
            }

            current = (current->m)[ch];
        }

        current->isTerminal = true;
    }

    bool search(string word){
        int word_len,i;
        word_len = word.length();

        Node *current = root;
        for(i=0 ; i<word_len ; i++){
            char ch = word[i];

            if((current->m).find(ch) == (current->m).end()){
                return false;
            }
            
            current = (current->m)[ch];
        }

        return (current->isTerminal)? true : false;
    }
};

int main(){
    
    int i,n,Q;

    vector<string> words = {"apple", "ape", "mango", "new", "news", "no"};
    n = words.size();

    Trie T;
    for(i=0 ; i<n ; i++){
        T.insert(words[i]);
    }

    cin>>Q;
    while(Q--){
        string key;
        cin>>key;

        if(T.search(key) == true){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

    return 0;
}