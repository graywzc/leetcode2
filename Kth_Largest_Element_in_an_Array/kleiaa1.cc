// using iterative method
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


    int findKthLargest(vector<int>& nums, int k) {
        assert(k>=1 && k<=nums.size());                
        
        int l = 0;
        int r = nums.size()-1;
        k = nums.size()-k;
        while(l<r)
        {
            int i = partition(nums,l,r);
            if(k>i)
                l = i+1;
            else if(k<i)
                r = i-1;
            else
                return nums[k];
        }
        return nums[k];
    }
};

int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution s;
    cout<<s.findKthLargest(nums,4)<<endl;
}
