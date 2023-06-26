class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Initializing PQ with stones vector
        priority_queue<int> PQ(stones.begin(), stones.end());

        while(PQ.size() > 1) {
            int x = PQ.top(); PQ.pop();
            int y = PQ.top(); PQ.pop();
            if(x > y)
                PQ.push(x - y);
        }
        if(PQ.empty())
            return 0;
        
        return PQ.top();
    }
};