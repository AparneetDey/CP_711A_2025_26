class Solution {
  public:
      int coinChange(vector<int>& coins, int amount) {
          vector<int> dp(amount+1, INT_MAX);
          dp[0] = 0;
  
          for(auto c : coins) {
              for(int i=c; i<amount+1; i++) {
                  if(dp[i-c] != INT_MAX) {
                      dp[i] = min(dp[i], dp[i-c] + 1);
                  }
              }
          }
  
          if(dp[amount]!=INT_MAX) {
              return dp[amount];
          }
  
          return -1;
      }
  };