class Solution {
public:

   void solve(vector<int> &nums,set<vector<int>>& result,int i,int n){
    if(i==n) {
        result.insert(nums);
        return;
    }
    for(int j=i; j<n; j++){
        swap(nums[i],nums[j]);
        solve(nums,result,i+1,n);
        swap(nums[i],nums[j]);
    }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        sort(nums.begin(),nums.end());

        solve(nums,result,0,nums.size());
        return vector<vector<int>> (result.begin(),result.end());
    }
};