class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int s=f.size();
        int count=0;
        for(int i=0;i<s;i++){
            if(f[i]==0){
                bool left=(i==0 || f[i-1]==0);
                bool right=(i==s-1 || f[i+1]==0);
                if(left && right){
                    f[i]=1;
                    count++;
                }
            }
        }

        return count>=n;
    }
};