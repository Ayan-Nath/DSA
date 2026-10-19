class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size() == 0) return 0;

        unordered_set<int> s;
        for(int x : arr) s.insert(x);   // remove duplicates

        int ans = 1;

        for(int x : s){
            // start only if x is the beginning of a sequence
            if(s.find(x - 1) == s.end()){
                int curr = x;
                int count = 1;

                while(s.find(curr + 1) != s.end()){
                    curr++;
                    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};
