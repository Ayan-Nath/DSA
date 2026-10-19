/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
     vector<int> starts;
     vector<int> ends;
     for(auto &it:intervals){
        starts.push_back(it.start);
        ends.push_back(it.end);
     }  
     sort(starts.begin(),starts.end());
     sort(ends.begin(),ends.end());
     int n=intervals.size();
     int rooms=0,ans=0;
        int i=0,j=0;
        while(i<n&&j<n){
            if(starts[i]<ends[j]){
                rooms++;
                ans=max(ans,rooms);
                i++;
            }
            else{
                rooms--;
                j++;
            }
        }
        return ans;
    }
};
