class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int ans=INT_MAX;
        for(int i=1;i<7;i++){
            bool flag=true;
            int up=0,down=0;
            for(int j=0;j<n;j++){
                if(tops[j]!=i && bottoms[j]!=i){
                    flag=false;
                    break;
                }
                if(tops[j]==i && bottoms[j]!=i){
                    down++;
                }
                else if(bottoms[j]==i && tops[j]!=i){
                    up++;
                }
            }
            if(flag) ans=min(ans,min(up,down));
        }

        return ans==INT_MAX?-1:ans;
    }
};