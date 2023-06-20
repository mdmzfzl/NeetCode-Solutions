// We'll be using a min heap, where the first element will be the smallest
// So we keep popping the smallest elements until there are K elements remaining
// The kth element will be the kth largest

// We are using priority queue to implement heap

static int pr = []() { 
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL);  
    return 0; 
}();

class KthLargest {
private:
    // Variable to keep track of PQ size
    int k;
    // Min heap
    priority_queue<int, vector<int>, greater<int>> PQ;
public:
    KthLargest(int k, vector<int>& nums) {
        // this->k calls k of this object(private variable of this class)
        this->k = k;

        // Adding elements to priority queue
        for (int i = 0; i < nums.size(); i++) 
            PQ.push(nums[i]);
            
        // removing elements till k elements remain
        while (PQ.size() > this->k) 
            PQ.pop();
    }
    
    int add(int val) {
        PQ.push(val);
        // If more than K elements then remove
        if (PQ.size() > k) 
            PQ.pop();
        return PQ.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

/*
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
public:
    KthLargest(int k, vector<int>& nums) {
        n = k;
        for(auto const &i: nums) {
            if(pq.size() < k) 
                pq.push(i);
            else 
                if(pq.top() < i) {
                    pq.pop();
                    pq.push(i);
                }
        }
    }
    
    int add(int val) {
        if(pq.size() < n) 
            pq.push(val); 
        else 
            if(pq.top() < val) {
                pq.pop();
                pq.push(val);
            }
        return pq.top();
    }
};
*/