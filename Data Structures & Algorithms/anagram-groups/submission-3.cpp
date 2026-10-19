class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        unordered_map<string,vector<string>> m;
        for(int i=0;i<s.size();i++){
        string curr=s[i];
        sort(curr.begin(),curr.end());
        m[curr].push_back(s[i]);
        }
        vector<vector<string>> ans;
        for(auto &it:m){
          ans.push_back(it.second);
        }
        return ans;
    }
};
