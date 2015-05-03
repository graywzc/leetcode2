class Solution {
public:
    int rob(vector<int>& nums) {
        int mr = 0;           
        int mr_exc = 0;

        for(const int& n: nums)
        {
            int tmp = mr; 
            mr = max(mr_exc+n, mr);
            mr_exc = tmp;
        }

        return mr;
    }
};
