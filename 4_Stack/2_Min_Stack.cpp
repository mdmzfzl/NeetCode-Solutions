class MinStack {
private:
    stack<int> Stacc;           // Mains tack for stroing the elements 
    stack<int> minStacc;        // Min stack to store the min up until then

public:

    MinStack() {
        // return minStacc.top();
    }
    
    void push(int val) {
        Stacc.push(val); // Pushing in main stack
        if(minStacc.empty() || Stacc.top() <= minStacc.top())  // Pushing in minstack if its empty or if the element is smaller than current top in min stack
            minStacc.push(val);
    }
    
    void pop() {
        if(minStacc.top() == Stacc.top())
            minStacc.pop();
        Stacc.pop();
    }
    
    int top() {
        return Stacc.top();
    }
    
    int getMin() {
        return minStacc.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
class MinStack {
public:
    stack<pair<int, int>> st;
    long minSeen = LONG_MAX;
    MinStack() {
        // associate each value with min seen so far
        // {val, min so far}
    }
    
    void push(int val) {
        minSeen = min(minSeen, 1L * val);
        st.push({val, minSeen});
    }
    
    void pop() {
        st.pop();
        if(st.empty()){
            minSeen = LONG_MAX;
        }else{
            minSeen = st.top().second;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return (int)st.top().second;
    }
};

*/