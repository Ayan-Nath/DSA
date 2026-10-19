class Solution {
public:
    int maxArea(vector<int>& heights) {
      int maxi=INT_MIN,i=0,n=heights.size(),j=n-1;
      while(i<j){
        int area=min(heights[i],heights[j])*(j-i);
        maxi=max(maxi,area);
        if(heights[i]<=heights[j]) i++;
        else j--;
      }  
      return maxi;
    }
};
