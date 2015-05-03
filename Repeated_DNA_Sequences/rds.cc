// failed the oj, "Memory Limit Exceeded"
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = 10;        
        if(s.size() <= len) return vector<string>();

        unordered_map<string,int> ss;
        int i = 0;
        vector<string> res;
        while(i <= s.size()-len)
        {
            string cur = s.substr(i,len);
            if(ss.find(cur)==ss.end())
                ss[cur]=0;
            else if(ss[cur]==0)
            {
                res.push_back(cur);
                ss[cur]=1;
            }
            i++; 
        }
        return res;
    }
};
