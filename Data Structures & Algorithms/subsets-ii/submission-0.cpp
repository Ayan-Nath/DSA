class Solution {
public:
    void solve(vector<int> &nums, vector<int>& ans, set<vector<int>>& result, int i, int n) {
        if (i == n) {
            result.insert(ans); // ✅ insert into set
            return;
        }

        // include
        ans.push_back(nums[i]);
        solve(nums, ans, result, i + 1, n);
        ans.pop_back();

        // exclude
        solve(nums, ans, result, i + 1, n);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // ✅ sort first
        set<vector<int>> result;
        vector<int> ans;
        solve(nums, ans, result, 0, nums.size());

        return vector<vector<int>>(result.begin(), result.end()); // convert set → vector
    }
};
