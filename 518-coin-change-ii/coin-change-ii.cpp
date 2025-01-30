class Solution {
public:
    int rec(vector<int> &coins,int amount,int curr,vector<vector<int>> &memo){
        if(curr>=coins.size() || amount<=0){
            return amount==0?1:0;
        }
        
        if(memo[curr][amount] != -1){
            return memo[curr][amount];
        }

        if(coins[curr]>amount){
            int notTake=rec(coins,amount,curr+1,memo);
            return memo[curr][amount]=notTake;
        }
        else{
            int take=rec(coins,amount-coins[curr],curr,memo);
            int notTake=rec(coins,amount,curr+1,memo);
            return memo[curr][amount]=take+notTake;
        }
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> memo(n,vector<int>(amount+1,-1));
        return rec(coins,amount,0,memo);
    }
};