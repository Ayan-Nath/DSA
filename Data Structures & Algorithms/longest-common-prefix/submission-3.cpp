class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if (s.size() == 0) return "";

        string ans = s[0];

        for (int i = 1; i < s.size(); i++) {
            string curr = s[i];

            int j = 0;

            while (j < ans.size() && j < curr.size() && ans[j] == curr[j]) {
                j++;
            }

            ans = ans.substr(0, j);

            if (ans == "") return "";
        }

        return ans;
    }
};