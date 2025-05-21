class Solution {
public:
    vector<pair<int,int>> dir={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int countNeigh(int i,int j,vector<vector<int>>& b){
        int count=0;
        for(auto &it:dir){
            int r=i+it.first,c=j+it.second;
            if(r<0 || c<0 || r>=b.size() || c>=b[0].size()) continue;
            if(b[r][c]==1) count++;
        }
        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> nc(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nc[i][j]=countNeigh(i,j,board);
            }
        }
        //board=nc;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0 && nc[i][j]==3) board[i][j]=1;
                else if(board[i][j]==1 &&(nc[i][j]<2 || nc[i][j]>3)) board[i][j]=0;
            }
        }
    }
};