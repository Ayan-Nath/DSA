class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size();
        int currw = 0, maxw = 0;
        unordered_map<char, bool> m;
        
        while (j < n) {
            // If character is already in current window, move i forward
            while (m[s[j]] == true) {
                m[s[i]] = false;  // Remove character at i from map
                i++;
            }
            
            // Add current character to map
            m[s[j]] = true;
            
            currw = j - i + 1;
            maxw = max(currw, maxw);
            j++;
        } 
        return maxw;
    }
};
