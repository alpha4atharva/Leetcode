class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> s;
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(digits[i]%2==0){
                int num=digits[i];
                for(int j=0;j<n;j++){
                    if(j!=i){
                        for(int k=0;k<n;k++){
                            if(k!=j && k!=i && digits[k]!=0){
                                s.insert(num+10*digits[j]+100*digits[k]);
                            }
                        }
                    }
                }
            }
        }

        vector<int> ans;
        for(auto it:s){
            //if(it>99){
                ans.push_back(it);
            //}
        }

        return ans;
    }
};