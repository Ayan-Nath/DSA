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
    bool canAttendMeetings(vector<Interval>& intervals) {
       int n=intervals.size();
       sort(intervals.begin(),intervals.end(),[](Interval a,Interval b){
        return a.start<b.start;
       });
        bool ans=false;
        int st1=intervals[0].start,end1=intervals[0].end;
        for(int i=1;i<n;i++){
          int st2=intervals[i].start;
          int end2=intervals[i].end;
          if(st2<end1) {
              ans=true;
              break;
          }
          else{
            st1=st2;
            end1=end2;
          }
        }
    return !ans;
    }
};
