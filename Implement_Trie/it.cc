#include <iostream>
#include <string>
#include <cassert>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode():flag(false) {
    }
    bool flag;
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie()
    {
        destroy(root); 
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* cur = root;     
        int i = 0;
        while(i<s.size())
        {
            if(!cur->children[c2i(s[i])])
                cur->children[c2i(s[i])] = new TrieNode();
                
            cur = cur->children[c2i(s[i])]; 
            i++; 
        }
        cur->flag = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int i = 0;    
        TrieNode* cur = root;
        while(i < key.size())
        {
            char c = key[i];
            if(!cur->children[c2i(c)]) 
                return false;

            cur = cur->children[c2i(c)]; 
            i++; 
        }

        return cur->flag;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;    
        int i = 0;
        while(i < prefix.size())
        {
            if(!cur->children[c2i(prefix[i])])
                return false;
            cur = cur->children[c2i(prefix[i])]; 
            i++; 
        }

        return true; 
    }

private:
    void destroy(TrieNode* node)
    {
        int i = 0;     
        while(i<26)
        {
            if(node->children[i])
                destroy(node->children[i]);
            i++;
        }
        delete node;
    }
    inline unsigned c2i(char c) 
    {
        assert(c>='a' && c<='z');
        return c-'a';
    }
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
//
int main()
{
    Trie trie;    
    trie.insert("a");
    cout<<trie.search("a")<<endl;
    cout<<trie.startsWith("a")<<endl;
    return 0;
}
