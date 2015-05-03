class Solution {
public:
    string minWindow(string S, string T) {
        if(T.empty() || S.size()<T.size())
            return string();

        typedef unordered_map<char,int> Map;             
        Map m;

        int count = 0;
        for(const char& c: T)
        {
            m[c]++;
            count++;
        }

        int p1=0,p2=0;
        string res; 
        int mwl = INT_MAX;
        
        while(1)
        {
            while(p1<S.size() && count>0)
            {
                if(m.find(S[p1])!=m.end())    
                {
                    m[S[p1]]--;
                    if(m[S[p1]]>=0) count--;
                }
                p1++; 
            }
            if(count>0) break;

            while(count==0)
            {
                if(m.find(S[p2])!=m.end()) 
                {
                    m[S[p2]]++;     
                    if(m[S[p2]]>0)
                    {
                        count++;
                    }
                }
                p2++;
            }

            int wl = p1-p2+1;
            if(wl<mwl)
            {
                mwl = wl; 
                res = S.substr(p2-1,wl);
            }
        }
        return res;
    }
};
