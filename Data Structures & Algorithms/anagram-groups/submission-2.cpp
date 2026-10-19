class Solution {
public:


    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(int i=0; i<arr.size(); i++){
            string curr=arr[i];
            sort(curr.begin(),curr.end());
            m[curr].push_back(arr[i]);
        }
      for(auto it: m){
        ans.push_back(it.second);
      }
      return ans;
    }
};
