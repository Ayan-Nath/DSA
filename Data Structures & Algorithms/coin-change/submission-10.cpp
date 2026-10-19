class Solution {
public:
const int INF=1e9;
int solve(int n,int amt,vector<int>&coins){
   vector<int> prev(amt+1,INF);
   //vector<int> curr(amt+1,INF);
    for(int j=0;j<=amt;j++){
        if(j%coins[0]==0) prev[j]=(j/coins[0]); 
    }
    
    //curr[0]=0;

    for(int i=1;i<n;i++){
        for(int j=coins[i];j<=amt;j++){
         //  int take=INF,notTake=INF;
           int take=1+prev[j-coins[i]];
        int notTake=prev[j];
           prev[j]=min(take,notTake);
        }
        //prev=curr;
    }
    return prev[amt];
}
    int coinChange(vector<int>& coins, int amount) {
       // if(amount==0) return 0;
        int n=coins.size();
        //vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans= solve(n,amount,coins);
        return (ans==INF)?-1:ans;
    }
};
