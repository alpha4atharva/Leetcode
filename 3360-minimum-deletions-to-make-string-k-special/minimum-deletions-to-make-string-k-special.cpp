class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);
        for(auto &c:word){
            freq[c-'a']++;
        }

        vector<int> counts;
        for(int i=0;i<26;i++){
            if(freq[i]>0) counts.push_back(freq[i]);
        }

        int ans=INT_MAX;
        for(int i=0;i<counts.size();i++){
            int deletion=0;
            int target=counts[i];
            for(int j=0;j<26;j++){
                if(freq[j]<target){
                    deletion+=freq[j];
                }
                else if(freq[j]>target+k){
                    deletion+=freq[j]-(target+k);
                }
            }
            ans=min(ans,deletion);
        }
        return ans;
    }
};