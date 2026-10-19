class Solution {
public:
    void solve(vector<int> &nums, vector<vector<int>> &result, int i, int n){
        if(i==n){
            result.push_back(nums);
        }
       //include
       for(int j=i; j<n; j++){
        swap(nums[i],nums[j]);
        solve(nums,result,i+1,n);
        swap(nums[i],nums[j]);
       }
       
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    
    int n=nums.size();
    solve(nums,result,0,n);
    return result;

    }
};
