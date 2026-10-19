class Solution {
public:
   bool solve(vector<int>& nums,int i,int target,vector<vector<bool>>& dp){
    if(i==0){
        return target==0;
    }
    if(target==0) return true;
    if(dp[i][target]){
        return dp[i][target];
    }
    bool notTake=solve(nums,i-1,target,dp);
    bool take=false;
    if(target>=nums[i]){
        take=solve(nums,i-1,target-nums[i],dp);       
    }
    dp[i][target]=take||notTake;
    return dp[i][target];
   }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;
        int n=nums.size();
        int target=sum>>1;
        vector<vector<bool>> dp(n+1,vector<bool> (target+1,false));
        return solve(nums,n-1,target,dp);
    }
};
