class TrieNode{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(){
        isWord=false;
        for(int i=0;i<26;i++)   child[i]=NULL;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node=root;
        for(auto c:word){
            if(!node->child[c-'a']){
                node->child[c-'a']=new TrieNode();
            }
            node=node->child[c-'a'];
        }
        node->isWord=true;
    }
    
    bool search(string word) {
        TrieNode *node=root;
        for(auto c:word){
            if(!node->child[c-'a']) return false;
            node=node->child[c-'a'];
        }

        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node=root;
        for(auto c:prefix){
            if(!node->child[c-'a']) return false;
            node=node->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */