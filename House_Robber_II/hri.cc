class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size()==1) return nums[0];

        int ex=0;
        int mx=nums[0];
        int i=1;
        while(i<nums.size()-1)
        {
            int tmp = ex;
            ex = mx;
            mx = max(nums[i]+tmp,mx);
            i++; 
        }
        int res = mx;
        ex=0;
        mx=nums[1];
        i=2;
        while(i<nums.size())
        {
            int tmp = ex;
            ex = mx;
            mx = max(nums[i]+tmp,mx);
            i++;  
        }
        res=max(res,mx);
        return res;
    }
};
