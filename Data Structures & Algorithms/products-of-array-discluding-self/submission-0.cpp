class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     int pdt=1,withoutZero=1,n=nums.size(),zeroCount=0;
     vector<int> ans(n);

     //counting zeros

     for(int i=0;i<n;i++){
     if(nums[i]==0) zeroCount++;
     }

     //taking desicion for code part acc to that only
     if(zeroCount>1){
        fill(ans.begin(),ans.end(),0);        
     }

     else if(zeroCount==1){
     for(int i=0;i<n;i++){
      if(nums[i]!=0){
        withoutZero*=nums[i];
      }     
     }

     for(int i=0;i<n;i++){
        ans[i]=(nums[i]!=0)?0:withoutZero;
     }
     }


     else{
      
      for(int i=0;i<n;i++){
        pdt*=nums[i];
      }

      for(int i=0;i<n;i++){
        ans[i]=pdt/nums[i];
      }
     }

return ans;
    }
};
