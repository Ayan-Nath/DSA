class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    unordered_map<int,int> mapping;
    int n=nums.size();
    for(int i=0; i<n; i++){
        mapping[nums[i]]++;

    }
    for(auto it: mapping){
        if(it.second>=2){
            return true;
        }
    }
    return false;
    }
};
