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

void insert(string word, Node *root){
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


int main(){
    
    int i,j,n,Q,words_len;

    string document = "little cute cat loves to code in c++, java & python";
    n = document.length();

    vector<string> words = {"cute cat", "ttle", "cutest", "dog", "c++", "big"};
    words_len = words.size();

    // Declaring a Trie
    Node *root = new Node('\0');

    // Step 1: Insert all keys in the Trie
    unordered_map<string,bool> isPresent;

    for(i=0 ; i<words_len ; i++){
        insert(words[i],root);
        isPresent[words[i]] = false;
    }

    // Step 2
    for(i=0 ; i<n ; i++){
        j = i;
        Node *current = root;
        string str;
        while(j<n && (current->m).find(document[j]) != (current->m).end()){
            current = (current->m)[document[j]];
            str += document[j];

            if(current->isTerminal == true){
                isPresent[str] = true;
            }

            j++;
        }
    }

    for(i=0 ; i<words_len ; i++){        
        if(isPresent[words[i]]){
            cout<<"\""<<words[i]<<"\" is present\n";
        }
        else{
            cout<<"\""<<words[i]<<"\" is NOT present\n";
        }
    }

    return 0;
}