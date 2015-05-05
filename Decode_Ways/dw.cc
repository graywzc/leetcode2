class Solution {
public:
    inline bool between(char c, char a, char b)
    {
        return c>=a&&c<=b; 
    }
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0')        
            return 0;

        int minus2 = 1; 
        int minus1 = 1;
        int i = 1;
        while(i<s.size())
        {
            int cur = between(s[i],'1','9')?minus1:0;
            cur += ((s[i-1]=='1'||(s[i-1]=='2'&& between(s[i],'0','6')))?minus2:0);
            minus2 = minus1;
            minus1 = cur;
            i++; 
        }

        return minus1;
    }
};
