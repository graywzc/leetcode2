class Solution {
public:
    int trap(int A[], int n) {
        if(n<3) return 0;
        vector<int> height(n,0);      

        int i = 1;
        int maxh = A[0];
        while(i < (n-1))
        {
            height[i] = maxh>A[i]?(maxh-A[i]):0;             
            if(A[i]>maxh) maxh = A[i];
            i++;
        }

        int res = 0;
        i = n-2;
        maxh = A[n-1];
        while(i > 0)
        {
            if(maxh > A[i])     
                res += min(maxh-A[i],height[i]);
            else if(A[i] > maxh)
                maxh = A[i];
            i--;
        }

        return res;
    }
};
