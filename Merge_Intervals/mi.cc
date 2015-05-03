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

    static bool comp(const Interval& a, const Interval& b)
    {
        return a.start<b.start;
    }

    vector<Interval> merge(vector<Interval> &intervals) {
        
        sort(intervals.begin(), intervals.end(), Solution::comp);

        vector<Interval> res; 
        int last_end = INT_MIN;
        for(const Interval& cur: intervals)
        {
            int start = cur.start;
            int end = cur.end;

            if(start>last_end)
            {
                res.push_back(Interval(start,end)); 
                last_end = end;
            }
            else if(end>last_end)
            {
                res.back().end = end; 
                last_end = end;
            }
        }

        return res;
    }
};
