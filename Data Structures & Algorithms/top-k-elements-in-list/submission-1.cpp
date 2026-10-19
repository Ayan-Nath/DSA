class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int x : nums) m[x]++;
        
        vector<pair<int,int>> freq;
        for (auto &it : m) {
            freq.push_back({it.second, it.first}); 
            // store as {frequency, number}
        }
        
        sort(freq.rbegin(), freq.rend()); // sort by frequency descending
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};

