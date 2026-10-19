class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());
        
        int i = 0, j = nums.size() - 1;
        int boats = 0;
        
        while (i <= j) {
            if (nums[i] + nums[j] <= limit) {
                i++;   // pair lightest
            }
            j--;       // heaviest always boards
            boats++;
        }
        return boats;
    }
};
