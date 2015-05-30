#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:

    int partition(vector<int>& nums, int start, int end)
    {
        assert(start<end); 
        int i = start+1;
        int j = end;
        while(true)
        {
            while(i<=end && nums[i]<=nums[start])    
                i++;
            while(j>start && nums[start]<nums[j])
                j--;

            if(i>=j) break;
            swap(nums[i],nums[j]);
            i++;j--;
        }

        swap(nums[start],nums[j]);
        return j;

    }

    int findKth(vector<int>& nums, int start, int end, int idx)
    {
        if(start==end) return nums[idx];

        int pv = partition(nums,start, end); 
        if(pv == idx)
            return nums[pv];
        else if(pv>idx)
            return findKth(nums, start, pv-1, idx);
        else
            return findKth(nums, pv+1, end, idx);
    }

    int findKthLargest(vector<int>& nums, int k) {
        assert(k>=1 && k<=nums.size());                
        
        return findKth(nums, 0, nums.size()-1, nums.size()-k); 
    }
};

int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution s;
    cout<<s.findKthLargest(nums,4)<<endl;
}
