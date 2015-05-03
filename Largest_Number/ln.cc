class Solution {
public:
    static bool comp(const int& a, const int& b)
    {
        assert(a>=0); 
        assert(b>=0);
        if(a==0)
            return false;
        if(b==0)
            return true;
        string s1 = to_string(a)+to_string(b);
        string s2 = to_string(b)+to_string(a);
        if(stol(s1) > stol(s2))
            return true;
        else
            return false;

    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);        
        if(!nums.empty() && nums[0]==0) return string("0");
        string res;
        for(const int& n: nums)
        {
            res += to_string(n);    
        }
        return res;
    }
};
