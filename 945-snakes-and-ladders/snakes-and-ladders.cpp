class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<pair<int,int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(),columns.end(),0);
        int i=1;
        for(int row=n-1;row>=0;row--){
            for(int col:columns) cells[i++]={row,col};
            reverse(columns.begin(),columns.end());
        }

        vector<int> dist(n*n+1,-1);
        dist[1]=0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int i=cur+1;i<=min(cur+6,n*n);i++){
                auto [row,col]=cells[i];
                int dest=board[row][col]==-1?i:board[row][col];
                if(dist[dest]==-1){
                    dist[dest]=dist[cur]+1;
                    q.push(dest);
                }
            }
        }

        return dist[n*n];
    }
};