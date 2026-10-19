class Solution {
public:
const int INF=1e9;
int solve(int n,int amt,vector<int>&coins,vector<vector<int>> &dp){
    /*if(i==0){
        if(amt%coins[0]==0) return amt/coins[0];
        else return INF;
    }
    if(amt==0) return 0;
    if(amt<0) return INF;
    if(dp[i][amt]!=-1) return dp[i][amt];
    int take=1+solve(i,amt-coins[i],coins,dp);
    int notTake=solve(i-1,amt,coins,dp);
    return min(take,notTake);*/
    for(int j=0;j<=amt;j++){
        dp[0][j]=(j%coins[0]==0)?(j/coins[0]):INF; 
    }
    for(int i=1;i<n;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<=amt;j++){
           int take=INF,notTake=INF;
           if(j-coins[i]>=0) take=1+dp[i][j-coins[i]];
           notTake=dp[i-1][j];
           dp[i][j]=min(take,notTake);
        }
    }
    return dp[n-1][amt];
}
    int coinChange(vector<int>& coins, int amount) {
       // if(amount==0) return 0;
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n,amount,coins,dp);
        return (ans==INF)?-1:ans;
    }
};
