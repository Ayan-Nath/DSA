class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //jab fill karunga tabhi check
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            long long diff=target-nums[i];
            if(m.find(diff)!=m.end()) return {m[diff],i};
            m[nums[i]]=i;
        }
        return {-1,-1};
    }
};
