class Solution {
public:

   void solve(vector<int>& nums, vector<int> &ans, vector<vector<int>> &result,int i, int n){
    if(i==n){
        result.push_back(ans);
        return;
    }
    //include
    ans.push_back(nums[i]);
    solve(nums,ans,result,i+1,n);
    ans.pop_back();
    //exclude
    solve(nums,ans,result,i+1,n);
   }
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> result;
      vector<int> ans;
      int n=nums.size();
      solve(nums,ans,result,0,n);
      return result;
    }
};
