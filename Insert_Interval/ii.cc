/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int i = 0; 
        int nstart = newInterval.start;
        int nend = newInterval.end;
        while(i < intervals.size() && intervals[i].end < nstart)
        {
            res.push_back(intervals[i]);
            i++; 
        }

        if(i == intervals.size())
        {
            res.push_back(newInterval); 
            return res;
        }
        
        // i != intervals.size()
        int newstart;
        if(nstart < intervals[i].start)
            newstart = nstart;
        else
            newstart = intervals[i].start;

        while(i < intervals.size() && nend >= intervals[i].start)
            i++; 

        int newend;
        if(nend > intervals[i-1].end)
            newend = nend;
        else
            newend = intervals[i-1].end;

        res.push_back(Interval(newstart, newend));  

        while(i < intervals.size()) 
        {
            res.push_back(intervals[i]);
            i++; 
        }

        return res;
    }
};
