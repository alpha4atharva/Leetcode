class Solution {
public:
    int digSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            int sum=digSum(i);
            mp[sum]++;
            maxi=max(maxi,mp[sum]);
        }

        int count=0;
        for(auto it:mp){
            if(it.second==maxi){
                count++;
            }
        }

        return count;
    }
};