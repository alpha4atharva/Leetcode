class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        // for(int i=0;i<k-1;i++){
        //     colors.push_back(colors[i]);
        // }
        int n=colors.size();
        int ans=0,l=0,r=1;
        while(r<(colors.size()+k-1)){
            if(colors[r%n]==colors[(r-1)%n]){
                l=r;
                r++;
                continue;
            }
            r++;
            if(r-l<k) continue;
            ans++;
        }
        return ans;
    }
};