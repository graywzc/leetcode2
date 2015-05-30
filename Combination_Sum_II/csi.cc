#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:

    void combinationSum2(const vector<int>& candidates, vector<vector<int>>& res, vector<int>& tmp, int target, int idx)
    {
        if(idx == candidates.size()) 
        {
            if(target == 0) 
                res.push_back(tmp);
        }
        else
        {
            int j = idx+1;
            while(j<candidates.size() && candidates[j]==candidates[idx])
                j++;

            int count = 0;
            while(target>=0)
            {
                combinationSum2(candidates, res, tmp, target, j); 
                if(count==j-idx) break;
                tmp.push_back(candidates[idx]);
                target-= candidates[idx];
                count++;
            }
            while(count>0)
            {
                tmp.pop_back();
                count--; 
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());            

        vector<vector<int>> res;
        vector<int> tmp;

        combinationSum2(candidates, res, tmp, target, 0);

        return res;
    }
};

int main()
{
    vector<int> can = {10,1,2,7,6,1,5};
    Solution s;
    vector<vector<int>> res = s.combinationSum2(can,8);
    for(const vector<int>& v: res)
    {
        for(const int i: v) 
            cout<<i<<" ";
        cout<<endl;
    }
}
