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

bool comp(const Interval &a, const Interval &b) {
    return a.start < b.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

       int n = intervals.size();
       if(n <= 1) return true;

       // use comparator separately
       sort(intervals.begin(), intervals.end(), comp);

       Interval prev = intervals[0];
       int i = 1;

       while(i < n){
           Interval curr = intervals[i];
           int prev_st = prev.start, prev_end = prev.end;
           int curr_st = curr.start, curr_end = curr.end;

           // fixed overlap condition
           if(prev_end > curr_st) return false;

           prev = curr;
           i++;
       }

       return true;
    }
};
