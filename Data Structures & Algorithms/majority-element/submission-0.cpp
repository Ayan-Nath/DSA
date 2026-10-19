class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int,int> mapping;
      int ans;
       int n=nums.size();
       for(int i=0;i<n; i++){
    mapping[nums[i]]++;

       } 
       int k=n/2;
       for(auto it: mapping){
        if(it.second>k){
           ans=it.first;
        }
       }
       return ans;
    }
};