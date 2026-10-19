class Solution {
public:
    
    int solve(int n,int amt,vector<int> &coins){
   vector<int> prev(amt+1,0);
   prev[0]=1;
    //for(int i=0;i<n;i++) dp[i][0]=1;
    for(int i=0;i<n;i++){
       // vector<int> curr(amt+1,0);
       // curr[0]=1;
        for(int j=1;j<=amt;j++){
            int take=0,notTake=0;
            if(j-coins[i]>=0) take=prev[j-coins[i]];
            if(i-1>=0) notTake=prev[j]; 
           prev[j]=take+notTake;
        }
       // prev=curr;
    }
    return prev[amt];
    }
    int change(int amt, vector<int>& coins) {
     int n=coins.size();  
     
     return solve(n,amt,coins); 
    }
};
