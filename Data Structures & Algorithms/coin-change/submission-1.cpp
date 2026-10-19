class Solution {
public:
const int INF=1e9;
int solve(int i,int amt,vector<int>&coins){
    if(i==0){
        if(amt%coins[0]==0) return amt/coins[0];
        else return INF;
    }
    if(amt==0) return 0;
    if(amt<0) return INF;
    int take=1+solve(i,amt-coins[i],coins);
    int notTake=solve(i-1,amt,coins);
    return min(take,notTake);
}
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        int n=coins.size();
        int ans= solve(n-1,amount,coins);
        return (ans==INF)?-1:ans;
    }
};
