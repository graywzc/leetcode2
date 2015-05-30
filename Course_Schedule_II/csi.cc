class Solution {
public:
    
    void DFS(int i)
    {
        color[i] = 1;     
        for(const int& w: adj[i])
        {
            if(color[w] == 0) 
                DFS(w);
            else if(color[w] == 1)
                throw 1;
        }
        color[i] = 2;
        res.push_back(i);
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(numCourses <= 0)
            return vector<int>(); 
        
        adj = vector<int,vector<int>>(numCourses, vector<int>());
        for(const pair<int,int>& p: prerequisites)
        {
            adj[p.second].push_back(p.first); 
        }

        res.clear();
        color = vector<int>(numCourses,0);
        
        int i = 0;
        try
        {
            while(i<numCourses)
            {
                assert(color[i]==0 || color[i]==2);
                if(color[i] == 0)
                    DFS(i);
                i++;
            }
        }
        catch(int i)
        {
            return vector<int>();  
        }
        
        reverse(res.begin(), res.end()); 
        return res;
    }
private:
    vector<vector<int>> adj;
    vector<int> color;
    vector<int> res;
};
