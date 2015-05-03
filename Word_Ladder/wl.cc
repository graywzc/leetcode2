class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        
        int wl = start.size();
        if(wl<=1 || start==end) return 2;

        queue<string> q;
        q.push(start); 
        unordered_set<string> s;
        s.insert(start);

        int lvl = 1;

        while(!q.empty())
        {
            int count = q.size(); 
            while(count>0)
            {
                string cur = q.front();
                q.pop();
                
                for(int i = 0; i < wl; i++)                
                {
                    string tmp = cur; 
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        tmp[i] = c; 
                        if(tmp!=cur)
                        {
                            if(tmp==end) 
                            {
                                return lvl+1; 
                            }
                            else if(s.find(tmp)==s.end() && dict.find(tmp)!=dict.end())
                            {
                                q.push(tmp); 
                                s.insert(tmp);
                            }
                        }
                    }
                }

                count--; 
            }
            lvl++;
        }

        return 0;
        
    }
};
