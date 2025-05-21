class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> count;
        for(int i=0;i<bank.size();i++){
            int c=0;
            for(auto &ch:bank[i]){
                if(ch=='1') c++; 
            }
            if(c>0) count.push_back(c);
        }

        int ans=0;
        for(int i=1;i<count.size();i++){
            ans+=count[i-1]*count[i];
        }

        return ans;
    }
};