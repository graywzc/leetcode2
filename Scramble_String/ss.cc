class Solution {
public:
    bool isScramble(string s1, string s2) {
        assert(s1.size()==s2.size());        
        
        int flag[128];
        memset(flag,0,sizeof(int)*128);
        for(const char& c: s1)
            flag[(int)c]++;
        for(const char& c: s2)
            if((--flag[(int)c])<0) 
                return false;
        if(s1.size()<=3)
            return true;

        int i = 1;
        while(i<s1.size())
        {
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && 
                isScramble(s1.substr(i),s2.substr(i)))
                return true;
            if(isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) &&
                isScramble(s1.substr(i),s2.substr(0,s2.size()-i)))
                return true;
            i++;
        }
        return false;
    }
};
