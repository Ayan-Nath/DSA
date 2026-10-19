class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int ans=0,freq=0;
      int n=nums.size();
      for(int i=0; i<n; i++){
        if(freq==0){
            ans=nums[i];
            freq=1;
        }
      else if(ans==nums[i]){
    freq++;
        }
        else{
            freq--;
        }
      }
      int c=0;
      for(int val: nums){
        if(val==ans){
            c++;
        }
      }
      if(c>n/2){
            return ans;
        }
      return -1;
    }
};