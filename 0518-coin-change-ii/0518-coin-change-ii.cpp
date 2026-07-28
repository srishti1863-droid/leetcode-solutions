class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int t=0;t<=amount;t++){
            dp[0][t]=(t%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                long long nottake=dp[i-1][t];
                long long take=0;
                if(coins[i]<=t){
                    take=dp[i][t-coins[i]];
                }
                dp[i][t]=nottake+take;
            }
        }
        return dp[n-1][amount];
    }
};