class Solution {
public:
    typedef vector<string> StrVec;
    typedef unordered_map<string,StrVec> ParentsMap;
    typedef pair<string,StrVec> CPPair;
    typedef queue<string> Queue;
    typedef unordered_map<string,int> DistMap;
    typedef pair<string,int> DPair;
    typedef vector<StrVec> StrVecVec;

    void build_res(ParentsMap& pm, StrVec& temp, const string& str, StrVecVec &res)
    {
        if(pm[str].empty()) 
        {
            StrVec result = temp; 
            reverse(result.begin(), result.end());
            res.push_back(result);
        }
        else
        {
            for(const string& par: pm[str]) 
            {
                temp.push_back(par); 
                build_res(pm, temp, par, res);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        int wl = start.size();
        assert(wl == end.size());

        ParentsMap pm;
        pm.insert(CPPair(start,StrVec()));

        Queue q;
        q.push(start);

        DistMap dist;
        dist.insert(DPair(start,0));

        int maxDist = INT_MAX;
        
        while(!q.empty())
        {
            string cur = q.front();           
            q.pop();

            int cur_dist = dist[cur];     
            if(cur_dist>maxDist) break;

            for(int i = 0; i < wl; i++) 
            {
                string tmp = cur; 
                for(char c = 'a'; c <= 'z'; c++)
                {
                    tmp[i] = c; 
                    if(tmp!=cur)
                    {
                        if(tmp == end) 
                        {
                            if(pm.find(end) == pm.end())  
                            {
                                maxDist = cur_dist; 
                                pm.insert(CPPair(end,StrVec(1,cur)));
                            }
                            else
                            {
                                pm[end].push_back(cur);
                            }
                        }
                        else
                        {
                            if(dict.find(tmp)!=dict.end()) 
                            {
                                if(dist.find(tmp)==dist.end())  
                                {
                                    q.push(tmp); 
                                    dist.insert(DPair(tmp,cur_dist+1));
                                    pm.insert(CPPair(tmp,StrVec(1,cur)));
                                }
                                else if(dist[tmp]>cur_dist)
                                {
                                    pm[tmp].push_back(cur);
                                }
                            }
                        }
                    }
                }
            }
        }
        
        StrVecVec  res;
        if(pm.find(end)!=pm.end())
        {
            StrVec temp; 
            temp.push_back(end);
            build_res(pm, temp, end, res);
        }
        
        return res;
    }
};
