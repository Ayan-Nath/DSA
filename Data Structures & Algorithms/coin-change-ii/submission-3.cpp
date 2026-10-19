class Solution {
public:
    
    int solve(int n,int amt,vector<int> &coins,vector<vector<int>>& dp){
        /*
    if(amt==0) return 1;
    if(i<0||amt<0) return 0;
    if(dp[i][amt]!=0) return dp[i][amt]; 
    return dp[i][amt]=solve(i,amt-coins[i],coins,dp)+solve(i-1,amt,coins,dp);*/
    for(int i=0;i<n;i++) dp[i][0]=1;
    //dp[i][j]=dp[i][j-coins[i]]+dp[i-1][j]

    for(int i=0;i<n;i++){
        for(int j=1;j<=amt;j++){
            int take=0,notTake=0;
            if(j-coins[i]>=0) take=dp[i][j-coins[i]];
            if(i-1>=0) notTake=dp[i-1][j]; 
           dp[i][j]=take+notTake;
        }
    }
    return dp[n-1][amt];
    }
    int change(int amt, vector<int>& coins) {
     int n=coins.size();  
     vector<vector<int>>dp(n,vector<int>(amt+1,0));
     return solve(n,amt,coins,dp); 
    }
};
