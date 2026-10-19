class Solution {
public:
    void solve(vector<int>& arr, vector<int>& ans, set<vector<int>>& result, int target, int sum, int i, int n) {
        if (i == n) {
            if (sum == target) {
                vector<int> temp = ans;
                sort(temp.begin(), temp.end()); // ensure uniqueness
                result.insert(temp);
            }
            return;
        }

        // include
        ans.push_back(arr[i]);
        solve(arr, ans, result, target, sum + arr[i], i + 1, n);
        ans.pop_back();

        // exclude
        solve(arr, ans, result, target, sum, i + 1, n);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> ans;
        set<vector<int>> result;
        solve(arr, ans, result, target, 0, 0, arr.size());

        // convert set → vector<vector<int>>
        vector<vector<int>> r(result.begin(), result.end());
        return r;
    }
};

