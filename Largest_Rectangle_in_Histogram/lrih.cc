class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> st;        

        int lra = 0;
        int i;
        for(i = 0; i < height.size(); i++)
        {
            while(!st.empty() && height[st.top()]>height[i]) 
            {
                int top = height[st.top()];  
                st.pop();
                int left = st.empty()?-1:st.top();
                lra = max(lra, (i-left-1)*top); 
            }
            
            st.push(i);
        }

        while(!st.empty())
        {
            int top = height[st.top()]; 
            st.pop();
            int left = st.empty()?-1:st.top();
            lra = max(lra, (i-left-1)*top);
        }

        return lra;
    }
};
