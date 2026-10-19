class Solution {
public:
    
    int solve(int i,int amt,vector<int> &coins,vector<vector<int>>& dp){
    if(amt==0) return 1;
    if(i<0||amt<0) return 0;
    if(dp[i][amt]!=0) return dp[i][amt]; 
    return dp[i][amt]=solve(i,amt-coins[i],coins,dp)+solve(i-1,amt,coins,dp);
    }
    int change(int amt, vector<int>& coins) {
     int n=coins.size();  
     vector<vector<int>>dp(n,vector<int>(amt+1,0));
     return solve(n-1,amt,coins,dp); 
    }
};
