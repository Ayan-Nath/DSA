class Solution {
public:
   int n;
   unordered_map<int,string> m;
    string encode(vector<string>& strs) {
     n=strs.size();
     string ans="";
     for(int i=0;i<n;i++){
        ans+=strs[i];
        m[i]=strs[i];
     }
     return ans;
    }

    vector<string> decode(string s) {
    vector<string> ans(n);
    for(int i=0;i<n;i++){
        string curr=m[i];
        ans[i]=curr;
    }
    return ans;
    }
};
