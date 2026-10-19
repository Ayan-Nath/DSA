class Solution {
public:

int solve(int i,int n,int &count){
    //base case
if(i==n){
    count++;
}
//ek step lo
int one=0,two=0;
if(i+1<=n){
one=solve(i+1,n,count);
}
if(i+2<=n){
two=solve(i+2,n,count);
}
return count;
}
    int climbStairs(int n) {
        int count=0;
        return solve(0,n,count);
    }
};
