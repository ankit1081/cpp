#include <iostream>
#include <unordered_map>
using namespace std;

class Trie {
public:
    unordered_map<char, Trie*> children;
    bool isEnd;

    Trie() : isEnd(false) {}

    ~Trie() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        Trie* current = this;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new Trie();
            }
            current = current->children[ch];
        }
        current->isEnd = true;
    }

    // Search for a full word in the Trie
    bool search(const string& word) {
        Trie* current = this;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEnd;
    }

    // Check if any word starts with a given prefix
    bool startsWith(const string& prefix) {
        Trie* current = this;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return true;
    }

    // Delete a word from the Trie
    bool remove(const string& word, int index = 0) {
        if (index == word.length()) {
            if (!isEnd) return false;  // Word not found
            isEnd = false;
            return children.empty();   // If no children, node can be deleted
        }

        char ch = word[index];
        auto it = children.find(ch);
        if (it == children.end()) return false; // Word not found

        bool shouldDeleteChild = it->second->remove(word, index + 1);

        if (shouldDeleteChild) {
            delete it->second;
            children.erase(it);
            return !isEnd && children.empty();
        }

        return false;
    }
};
int main() {
    Trie root;

    root.insert("apple");
    root.insert("app");
    root.insert("bat");

    cout << root.search("apple") << endl;    // 1
    cout << root.search("app") << endl;      // 1
    cout << root.startsWith("ap") << endl;   // 1
    cout << root.search("bat") << endl;      // 1
    cout << root.search("bath") << endl;     // 0

    root.remove("apple");
    cout << root.search("apple") << endl;    // 0
    cout << root.search("app") << endl;      // 1 (still exists)

    return 0;
}

