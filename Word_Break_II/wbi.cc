// Submission Result: Memory Limit Exceeded

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        typedef vector<string> StrVec;
        vector<int> wb;
        unordered_map<int, StrVec > wb_str;            
        if(s.empty()) return vector<string>();

        int size = s.size();
        wb.push_back(size);
        wb_str[size] = StrVec(1,string());
        
        int i = size-1;
        while(i>=0)
        {
            for(const int& n: wb)
            {
                if(dict.find(s.substr(i,n-i))!=dict.end())     
                {
                    if(wb_str.find(i)==wb_str.end()) 
                    {
                        wb.push_back(i); 
                        wb_str[i] = StrVec();
                        for(const string& str: wb_str[n])
                        {
                            wb_str[i].push_back(s.substr(i,n-i)+(str.empty()?string():(' '+str))); 
                        }
                    }
                    else
                    {
                        for(const string& str: wb_str[n])
                        {
                            wb_str[i].push_back(s.substr(i,n-i)+(str.empty()?string():(' '+str))); 
                        }
                    }
                }
            }
            i--; 
        }

        return wb_str[0];
    }
};
