// failed the oj, "Memory Limit Exceeded"
class Solution {
public:
    int getflag(const char& c, int flag)
    {
        const int mask = 0xFFFFF;      
        flag = flag<<2;
        switch(c)
        {
            case 'A': 
                break;
            case 'C':
                flag += 1;
                break;
            case 'G':
                flag += 2;
                break;
            case 'T':
                flag += 3;
                break;
            default:
                assert(0);
        }
        flag=flag&mask;
        return flag;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int len = 10;        
        if(s.size() <= len) return vector<string>();

        unordered_map<int,bool> ss;
        vector<string> res;
        int flag = 0;
        
        int i = 0;
        while(i<len)
        {
            flag = getflag(s[i],flag); 
            i++; 
        }

        ss[flag] = false;
        while(i < s.size())
        {
            flag = getflag(s[i],flag);
            if(ss.find(flag)==ss.end())
                ss[flag]=false;
            else if(ss[flag]==false)
            {
                res.push_back(s.substr(i-len+1,len));
                ss[flag]=true;
            }
            i++; 
        }
        return res;
    }
};
