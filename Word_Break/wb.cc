class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()) return true;
        int size = s.size();
        vector<int> wb;        
        wb.push_back(size);
        int i = size-1;
        while(i>0)
        {
            for(const int& w: wb)
            {
                if(dict.find(s.substr(i,w-i))!=dict.end()) 
                {
                    wb.push_back(i); 
                    break;
                }
            }
            i--; 
        }
        for(const int& w: wb)
        {
            if(dict.find(s.substr(i,w-i))!=dict.end()) 
                return true;
        }
        return false;
    }
};
