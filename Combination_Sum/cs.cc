#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:

    void combinationSum(const vector<int>& candidates, vector<vector<int>>& res, vector<int> & tmp, int target, int idx)
    {
        if(idx == candidates.size()) 
        {
            if(target==0) 
                res.push_back(tmp);
        }
        else
        {
            int count=0;
            while(target>=0) 
            {
                combinationSum(candidates, res, tmp, target, idx+1); 
                tmp.push_back(candidates[idx]);
                target-=candidates[idx];
                count++;
            }
            while(count>0)
            {
                tmp.pop_back();
                count--; 
            }
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());        

        vector<vector<int>> res;
        vector<int> tmp;

        combinationSum(candidates, res, tmp, target, 0);

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> can = {2,3,6,7};
    vector<vector<int>> res = s.combinationSum(can,7);

    for(const vector<int>& v: res)
    {
        for(const int i: v) 
            cout<<i<<" ";
        cout<<endl;
    }
}
