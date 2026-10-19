class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low,high;
        low=0,high=n-1;
         int mid=low+(high-low)/2;

        while(high>=low){
            
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mid=low+(high-mid)/2;
        }
        return -1;
    }
};
