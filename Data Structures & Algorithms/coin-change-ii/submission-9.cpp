class Solution {
public:
    
    int solve(int n,int amt,vector<int> &coins){
   vector<long long> prev(amt+1,0);
   prev[0]=1;
   
    for(int i=0;i<n;i++){
     
        for(int j=1;j<=amt;j++){
            int take=0,notTake=0;
            if(j-coins[i]>=0) take=prev[j-coins[i]];
            //if(i-1>=0) notTake=prev[j]; 
           prev[j]+=take;
        }
       
    }
    return prev[amt];
    }
    int change(int amt, vector<int>& coins) {
     int n=coins.size();  
     
     return solve(n,amt,coins); 
    }
};
