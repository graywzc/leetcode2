class MinStack {
public:

    vector<long> st;
    long min;

    MinStack()
    :min(INT_MAX)
    {
    }

    void push(int x) {
        if(x>min)
        {
            st.push_back((long)x); 
        }
        else
        {
            st.push_back(2*(long)x - min);        
            min = (long)x;
        }
    }

    void pop() {
        if(st.back()>min)
        {
            st.pop_back(); 
        }
        else
        {
            min = 2*min - st.back(); 
            st.pop_back();
        }
    }

    int top() {
        if(st.back()>min) 
            return st.back();
        else
            return min;
    }

    int getMin() {
        return min;    
    }
};
