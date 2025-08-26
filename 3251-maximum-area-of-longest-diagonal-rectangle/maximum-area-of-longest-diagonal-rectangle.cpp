class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double l=0;
        int ans=0;
        for(int i=0;i<dimensions.size();i++){
            double x=sqrt(dimensions[i][0]*dimensions[i][0]+dimensions[i][1]*dimensions[i][1]);
            int area=dimensions[i][0]*dimensions[i][1];
            if(x>l){
                l=x;
                ans=area;
            } 
            else if(x==l){
                ans=max(ans,area);
            }
        }
        return ans;
    }
};
