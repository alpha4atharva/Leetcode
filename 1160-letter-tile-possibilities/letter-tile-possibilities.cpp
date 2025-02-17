class Solution {
private:
    set<string> st;
public:
    void rec(string &tiles,vector<bool> vis,string temp){
        st.insert(temp);
        for(int i=0;i<tiles.size();i++){
            if(!vis[i]){
                vis[i]=true;
                temp+=tiles[i];
                rec(tiles,vis,temp);
                vis[i]=false;
                temp.pop_back();
            }
        }
    }

    int numTilePossibilities(string tiles) {
        int n=tiles.size();
         vector<bool> vis(n,false);
         rec(tiles,vis,"");
         return st.size()-1;
    }
};