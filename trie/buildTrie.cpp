#include<iostream>
using namespace std;
class TrieNode{
public:
    char data;
    //each node may have char from a to z which equals to 26
    TrieNode*children[26];
    //making end terminal to mark last alphabet of a digit
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i =0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
public:
    TrieNode*current;

    Trie(){
        current  = new TrieNode('\0');
    }

    void insertUtil(TrieNode* current , string word){
        //base case 
        if(word.length()==0){
            current->isTerminal = true;
            return;
        }
        //let word will be small alphabets
        int index = word[0]-'a';
        TrieNode* child;

        //present
        if(current->children[index]!=NULL){
            //just follow the child
            child = current->children[index];
        }
        //absent
        else{
            //create a node
            child = new TrieNode(word[0]);
            //link it with the tree
            current->children[index] = child;
        }

        //recursion 
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(current,word);
    }

    bool searchUtil(TrieNode*current,string word){
        //if word length is 0 then return isEnd which will also verify that it is end or just substring
        if(word.length() == 0){
            return current->isTerminal;
        }
        int index = word[0]-'a';
        TrieNode*child;
        //while checking , check if the word is present node or not
        if (current->children[index] != NULL){
            child = current->children[index];
        }
        else{
            return false;
        }

        //recusrion
        return searchUtil(child, word.substr(1));

    }

    bool search(string word){
        return searchUtil(current, word);
    }

    bool removeUtil(TrieNode*current, string word, int depth){
        //base case , word is completely traversed
        if (depth == word.size()){
            //word does not exist
            if(!current->isTerminal){
                return false;
            }
            //unmark the end of word
            current -> isTerminal = false;

            //check if current has no children, then it can be deleted
            for(int i = 0; i< 26; i++){
                if (current->children[i] != NULL){
                    return false;
                }
                
            }
            return true;
        }

        
        
        int index = word[depth]-'a';
        TrieNode* child;
        child = current->children[index];

        //if child does not exist , word not found
        if (child == NULL){
            return false;
        }

        //recusrion 
        bool shouldDeleteChild = removeUtil(child ,word,depth+1);

        //if child should be deleted , free the node and set to null
        if (shouldDeleteChild){
            delete child;
            current->children[index]=NULL;

            //check if current should also be deleted 
            if (!current->isTerminal){
                for (int i =0 ; i<26 ; i++){
                    if (current -> children[i] != NULL){
                        return false ;
                    }
                    
                }
                return true;
            }
        }
        return false;
    }

    void deleteWord(string word){
        removeUtil(current,word,0);
    }
};

int main() {
    Trie* t = new Trie();
    t->insertWord("abced");
    cout<<"Present or not :"<<t->search("abced")<<endl;
    cout<<"Present or not :"<<t->search("abce")<<endl;
    t->deleteWord("abced");
    cout<<"Present or not :"<<t->search("abced")<<endl;
    t->insertWord("coke");
    t->insertWord("cone");
    t->insertWord("code");
    t->deleteWord("coke");
   
    cout<<"Present or not :"<<t->search("coke")<<endl;
    cout<<"Present or not :"<<t->search("code")<<endl;

    
    
    return 0;
}
