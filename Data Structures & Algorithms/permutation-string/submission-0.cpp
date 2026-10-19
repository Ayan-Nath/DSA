class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;  // ✅ safety check

        unordered_map<char,int> m1, m2;

        // Build frequency map for s1
        for (char c : s1) m1[c]++;

        int k = n1;
        // Build first window for s2
        for (int i = 0; i < k; i++) {
            m2[s2[i]]++;
        }

        if (m1 == m2) return true;

        // Slide the window across s2
        for (int i = k; i < n2; i++) {
            m2[s2[i - k]]--;
            if (m2[s2[i - k]] == 0) m2.erase(s2[i - k]);
            m2[s2[i]]++;

            if (m1 == m2) return true;
        }

        return false;
    }
};
