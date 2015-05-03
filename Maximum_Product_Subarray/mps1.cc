// this is Yu's method, very clear
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mp = nums[0];
        int mn = nums[0];
        int mx = nums[0];
        int i = 1;
        while(i<nums.size())
        {
            int tmpmx = mx;
            int tmpmn = mn;
            mx = max(max(nums[i]*tmpmx,nums[i]*tmpmn),nums[i]);
            mn = min(min(nums[i]*tmpmx,nums[i]*tmpmn),nums[i]);
            mp = max(mp,mx);
            i++; 
        }
        return mp;
    }
};
