class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())        
            return false;
        unordered_map<char,char> hm;
        unordered_set<char> hs;
        int i = 0;
        while(i<s.size())
        {
            char c = s[i];
            if(hm.find(c)==hm.end())
            {
                if(hs.find(t[i])==hs.end())
                {
                    hm[c] = t[i];
                    hs.insert(t[i]);
                }
                else
                    return false;
                    
            }
            else if(hm[c]!=t[i])
                return false;
            i++; 
        }
        return true;
    }
};
