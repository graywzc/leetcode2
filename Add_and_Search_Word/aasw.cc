#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class WordDictionary {
public:
typedef struct Node{
    bool flag;
    Node* children[26];
    Node():flag(false){}
}Node;

    WordDictionary()
    {
        root = new Node();
    }
    ~WordDictionary()
    {
        destroy(root); 
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        Node* cur = root;
        for(const char c: word)
        {
            if(!cur->children[c2i(c)])      
                cur->children[c2i(c)] = new Node();
            cur = cur->children[c2i(c)];
        }
        cur->flag = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root, 0);    
    }
private:

    bool search(string word, Node* n, int i)
    {
        if(i == word.size()) 
        {
            return n->flag; 
        }

        char c = word[i];
        if(c=='.')
        {
            int j=0;
            while(j<26)
            {
                if(n->children[j] && search(word, n->children[j], i+1))
                    return true;
                j++;
            }
            return false;
        }
        else
        {
            if(n->children[c2i(c)])     
                return search(word, n->children[c2i(c)], i+1);
            else
                return false;
        }
    }

    inline unsigned c2i(char c)
    {
        assert(c>='a' && c<='z');
        return c-'a'; 
    }
    
    void destroy(Node* n)
    {
        int i = 0;
        while(i<26)
        {
            if(n->children[i]) 
                destroy(n->children[i]);
            i++;
        }
        
        delete n;
    }


    Node* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
//
int main()
{
    WordDictionary wd;   
    wd.addWord("ab");
    cout<<wd.search("a")<<endl;
}
