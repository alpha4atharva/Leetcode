class Solution {
public:
    int rec(vector<int> &coins,int amount,int curr,vector<vector<int>>&memo){
        if(curr>=coins.size() || amount<=0){
            return amount==0?0:INT_MAX-1;
        }

        if(memo[curr][amount] != -1){
            return memo[curr][amount];
        }
        
        if(coins[curr]>amount){
            int notTake=rec(coins,amount,curr+1,memo);
            memo[curr][amount]=notTake;
        }
        else{
            int take=1+rec(coins,amount-coins[curr],curr,memo);
            int notTake=rec(coins,amount,curr+1,memo);
            memo[curr][amount]=min(take,notTake);
        }   
        return memo[curr][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> memo(n,vector<int>(amount+1,-1));
        int maxcount=rec(coins,amount,0,memo);
        return maxcount==INT_MAX-1?-1:maxcount;
    }
};