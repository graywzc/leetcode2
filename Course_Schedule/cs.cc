class Solution {
public:
    
    vector<int> color;
    vector<vector<int>> adj;

    void DFS(int i)
    {
        color[i] = 1;     
        for(const int& e: adj[i])
        {
            if(color[e]==0) 
                DFS(e);
            else if(color[e]==1)
                throw e;
        }
        color[i] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses<=1)
            return true;

        color = vector<int>(numCourses,0);
        adj = vector<vector<int>>(numCourses,vector<int>());
        for(const vector<int>& p: prerequisites)            
            adj[p[1]].push_back(p[0]); 

        try{
            for(int i=0; i<numCourses; i++)
                if(color[i]==0) 
                    DFS(i); 
        }
        catch(int e)
        {
            return false; 
        }
        return true;
    }
};
