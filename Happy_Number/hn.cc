class Solution {
public:
    int next(int n)
    {
        int res = 0;      
        while(n>0)
        {
            res += (n%10)*(n%10); 
            n /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        unordered_set<int> set;            
        while(set.find(n)==set.end() && n!=1)
        {
            set.insert(n);
            n = next(n);
        }

        if(n==1) 
            return true;
        else
            return false;
    }
};
