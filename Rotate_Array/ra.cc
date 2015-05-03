class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n<=1)        
            return;

        k = k%n;
        if(k<0) k+=n; // now k is 0~n-1
        if(k==0) return; // now k is 1~n-1

        reverse(nums,nums+n); 
        reverse(nums,nums+k);
        reverse(nums+k,nums+n);

        return;
    }
};
