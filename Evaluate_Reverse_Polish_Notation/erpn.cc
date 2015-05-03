class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const string& s: tokens)
        {
            assert(!s.empty());
            if(!isdigit(s[0]) && s.size()==1)
            {
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                switch(s[0])
                {
                    case '+': 
                        st.push(op1+op2);
                        break;
                    case '-': 
                        st.push(op1-op2);
                        break;
                    case '*': 
                        st.push(op1*op2);
                        break;
                    case '/': 
                        st.push(op1/op2);
                        break;
                    default: 
                        assert(0);
                }
            }
            else
                st.push(stoi(s)); 
        }
        return st.top();
    }
};
