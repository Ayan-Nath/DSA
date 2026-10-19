class Solution {
public:
void solve(vector<int> &arr,vector<int> &ans,vector<vector<int>> &result,int target, int i, int n){
    if(i==n){
        if(target==0){
        result.push_back(ans);
    }
        return;
    }
    
    //take and not take
    if(arr[i]<=target){
    ans.push_back(arr[i]);
    solve(arr,ans,result,target-arr[i],i,n);
    ans.pop_back();
    }
   
    solve(arr,ans,result,target,i+1,n);

}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> ans;
         vector<vector<int>> result;
        solve(arr,ans,result,target,0,n);
        return result;
    }
};
