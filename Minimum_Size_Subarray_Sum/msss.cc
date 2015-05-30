class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())        
            return 0;

        int i = 0;
        int j = 0;
        int tmp = 0;
        while( tmp<s && i<nums.size() )
        {
            tmp+=nums[i];
            i++;
        }

        if(i==nums.size() && tmp<s)
            return 0;

        while(tmp>=s)
        {
            tmp -= nums[j];
            j++;
        }

        int msal = i-j+1;
        while(i<nums.size())
        {
            while(i<nums.size() && tmp<s)
            {
                tmp+=nums[i];
                i++;
            }
            if(i == nums.size() && tmp<s)
                break;
            while(tmp>=s) 
            {
                tmp -= nums[j];
                j++;
            }
            msal = min(msal,i-j+1);
        }

        return msal;
    }
};
