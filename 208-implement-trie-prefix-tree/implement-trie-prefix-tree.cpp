class TrieNode{
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode(){
        isWord=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
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
            if(!node->child[c-'a'])
                node->child[c-'a']=new TrieNode();
            node=node->child[c-'a'];
        }
        node->isWord=true;
    }
    
    bool search(string word,bool c=false) {
        TrieNode *node=root;
        for(auto c:word){
            if(!node->child[c-'a']) return false;
            node=node->child[c-'a'];
        }

        return node->isWord||c;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */