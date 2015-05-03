class Solution {
public:

    string convertToTitle(int n) {
        if(n==0)
            return string();
        else
            return convertToTitle((n-1)/26) + string(1,'A'+((n-1)%26));
    }
};
