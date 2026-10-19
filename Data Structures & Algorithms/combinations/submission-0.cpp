class Solution {
public:

    void solve(int k,vector<int> &arr, int i, int n, vector<int> &ans, vector<vector<int>> &result){
     //base case
     if(i==n){
        if(ans.size()==k){
            result.push_back(ans);
        }
        return;
     }  
     //include
     ans.push_back(arr[i]);
     solve(k,arr,i+1,n,ans,result);
     ans.pop_back();
     //exclude
     solve(k,arr,i+1,n,ans,result); 
    }
    vector<vector<int>> combine(int n, int k) {
        //construct the array
        vector<int> arr;
        for(int i=1; i<=n; i++){
            arr.push_back(i);           
        }
        vector<int> ans;
        vector<vector<int>> result;
        solve(k,arr,0,n,ans,result);
        return result;
    }
};